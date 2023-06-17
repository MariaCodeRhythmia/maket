#include "widgets.h"

using namespace std;

footer::footer(QWidget *parent,
               graphics *grphcs)
{
    // кониейнер дляподвала страницы
    QHBoxLayout* FOOTER = new QHBoxLayout;
    // список для отображения действий

    footerList = new QListWidget();
    footerList->setStyleSheet(grphcs->get_FOOTER_COLOR());
    this->setFixedHeight(parent->size().height()/2.3);
    FOOTER->setAlignment(Qt::AlignBaseline);
    FOOTER->addWidget(footerList);
    this->setLayout(FOOTER);
}

QComboBox * widgets::createComboBox( QLayout *panelWidgets,
                                     widgetMapCombobox items, QString objName)
{
    QComboBox * comboBox =  new QComboBox();
    comboBox->setObjectName(objName);
    Label* labelName = new Label(QString::fromStdString(items.at(0).second), " ", this);


    QHBoxLayout *layout = new QHBoxLayout;

    for(int i = 1; i < (int)items.size(); i++)
        comboBox->addItem(QString::fromStdString(items.at(i).second));

    comboBox->setParent(this);

    comboBox->setFocusPolicy(Qt::NoFocus);
    layout->setAlignment(Qt::AlignTop);
    layout->setSpacing(6);
    layout->addWidget(labelName);
    layout->addWidget(comboBox);
    panelWidgets->addItem(layout);
    comboBox->setMinimumSize(this->size().width()/4, 28);

    return comboBox;

}

int widgets::seachCurrentIndex(widgetMapCombobox items,
                               int key)  {
    for(int i = 0; i < (int)items.size(); i++){

        if(items.at(i).first == key)
            return i;
    }
    return 0;
}

int widgets::setDataIndex(QComboBox *box,
                          widgetMapCombobox items)  {
    int index = box->currentIndex() + 1;
    return items.at(index).first;
}

footer *widgets::getFooter()
{
    return foot;
}

void widgets::creatFooter( int msec)   {
    foot = new footer(this, grphcs);
    foot->timer = new QTimer();
    connect(foot->timer, SIGNAL(timeout()), this, SLOT(updateInput()));
    foot->timer->start(msec);
}


widgets::widgets(QWidget *widget,
                 graphics *grcs
                 )  {
    if(!widget || !grcs  ){
        QMessageBox* msg = new QMessageBox(this);
        msg->setWindowTitle("Класс widget");

        QString error_message;
        if(!widget) error_message += "Проверьте, что экземпляр родительского класса унаследован от QWidget и передан классу drawW.\n";
        if(!grcs) error_message += "Проверьте, что экземпляр класса для работы с графикой graphics создан и передан классу drawW.\n";

        if(!error_message.isEmpty()) {
            msg->setText("Класс widget:\n" + error_message);
            msg->setIcon(QMessageBox::Critical);
            msg->setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
        } else {
            msg->setText("Продолжить или выйти?");
            msg->setIcon(QMessageBox::Question);
            msg->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        }

        QObject::connect(msg, &QMessageBox::finished, [=](int result){
            if(result == QMessageBox::Ok || result == QMessageBox::Retry) {
                // Обработка нажатия на кнопку "Продолжить" или "Ok"
                // ...
            } else if(result == QMessageBox::Cancel) {
                // Обработка нажатия на кнопку "Выход" или "Cancel"
                exit(2);
            }
        });

        msg->exec();

    }

    this->sizeScreen = widget->size();
    this->parent = widget;
    this->grphcs = grcs;

}
QLayout *widgets::createButton(widgetMapBtn key,
                               QList<Button*> &buttonList)  {

    QVBoxLayout* panelWidgets = new QVBoxLayout;
    Button* button ;
    for(int i = 0; i < (int)key.size(); i++) {
        auto wgtDescription = key.at(i);
        QString    name = QString::fromStdString(std::get<0>(wgtDescription));
        QString    tool = QString::fromStdString(std::get<1>(wgtDescription));
        QString objName = QString::fromStdString(std::get<2>(wgtDescription));
        button = new Button(name, objName, this);
        button->setToolTip(tool);
        panelWidgets->addWidget(button);
        connect(button, SIGNAL(clicked(bool)), grphcs, SLOT(add_graphics(bool)));
        connect(button, SIGNAL(pressed()), grphcs, SLOT(press()));
        buttonList.append(button);
    }

    grphcs->set_graphics(panelWidgets);
    return  panelWidgets;
}

QList<Label *> widgets::createLabel(QLayout *panelWidgets,
                                    widgetMapBtn key)
{
    QList<Label*> labelList;

    for(int i = 0; i < (int)key.size(); i++) {
        auto wgtDescription = key.at(i);
        QString name = QString::fromStdString(std::get<0>(wgtDescription));
        QString tool = QString::fromStdString(std::get<1>(wgtDescription));
        QString objName = QString::fromStdString(std::get<2>(wgtDescription));

        Label* labelName = new Label(name, " ", this);

        labelName->setToolTip(tool);
        QHBoxLayout *layout = new QHBoxLayout;
         layout->setSpacing(6);
        layout->setAlignment(Qt::AlignTop);
        Label *labelMain = new Label(objName, this);
        labelMain->addLabelName(labelName);
        layout->addWidget(labelName);
        layout->addWidget(labelMain);
        panelWidgets->addItem(layout);
        labelMain->setAlignment(Qt::AlignCenter);
        labelList.append(labelMain);
    }

    return labelList;
}
QList<Label *> widgets::createLabels(QLayout *panelWidgets,
                                     QString nameLabels,
                                     int count,
                                     QString tool)
{
    QList<Label*> labelList;
    Label* labelName = new Label(nameLabels, " ", this);
    labelName->setToolTip(tool);
    QHBoxLayout *layout = new QHBoxLayout;
     layout->setSpacing(1);
    layout->addWidget(labelName);
    layout->setAlignment(Qt::AlignTop);
    labelName->setMinimumWidth(60);
    labelName->setMaximumWidth(145);

    for (int i = 0; i < count; i++)  {

        Label *labelMain = new Label(this);
        if(count > 2) labelMain->setFixedWidth(this->size().width()/20);
        layout->addWidget(labelMain);
        labelMain->setAlignment(Qt::AlignCenter);
        labelList.append(labelMain);
    }
    panelWidgets->addItem(layout);
    return labelList;

}
QList<QDoubleSpinBox *> widgets::createSpin(QLayout *panelWidgets,
                                            widgetMapIO key){

    QList < QDoubleSpinBox *> spinList;

    for(int i = 0; i < (int)key.size(); i++) {
        QHBoxLayout *layout = new QHBoxLayout;
        auto wgtDescription = key.at(i);
        QString name    = QString::fromStdString(std::get<0>(wgtDescription));
        QString tool    = QString::fromStdString(std::get<1>(wgtDescription));
        QString objName = QString::fromStdString(std::get<2>(wgtDescription));
        int decimal  = std::get<3>(wgtDescription);
        int minimum  = std::get<4>(wgtDescription);
        int maximum  = std::get<5>(wgtDescription);

        SpinBox* spinBox = new SpinBox(objName, this);//создаем дробный спин-бокс
        Label* label = new Label(name, "", this);
        label->setToolTip(tool);
        spinBox->setDecimals(decimal);
        spinBox->setMinimum(minimum);
        spinBox->setMaximum(maximum);
        layout->addWidget(label);
        layout->addWidget(spinBox);
        layout->setSpacing(6);
        panelWidgets->addItem(layout);
        spinList.append(spinBox);
    }

    return spinList;
}
void widgets::setSize(QSize sizescreen) {

    this->sizeScreen = sizescreen;
}

void widgets::read_file(QString namefile)
{
    char str_data[550];
    char *name_var = namefile.toLocal8Bit().data();

    FILE *fvar=fopen(name_var,"w");

    if (fvar==NULL) return;

    memset(str_data,'\0',sizeof(str_data));
    sprintf(str_data,"%d %s\n",1,"s Some awesome text ");
    fputs(str_data,fvar);

    fclose(fvar);

    return;
}

void widgets::write_tofile(QString namefile)
{
    char *name_var = namefile.toLocal8Bit().data();
    char str_data[550];

    FILE *fvar=fopen(name_var,"r");
    if (fvar==NULL) return;

    memset(str_data,'\0',sizeof(str_data));
    if (fgets(str_data,550,fvar)==NULL) return;

    qDebug () << str_data;

    fclose(fvar);

    return;
}
