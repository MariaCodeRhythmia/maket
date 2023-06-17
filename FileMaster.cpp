#include "FileMaster.h"
#include <iostream>
using namespace std;

FileDialog::FileDialog(QString dirPath, QString filter, graphics *g) :
    QDialog()
{
    this->dirPath = QString(dirPath);
    this->filter = filter;


    createWidgets();

    filterFilesOpen();
    setupLayout();

    if(g != nullptr) {
        this->grphcs = g;
        this->setStyleSheet(g->get_MAIN_COLOR());
        g->set_graphics(this->layout);
    }
    else{
        this->grphcs = new graphics(this);
    }

    connectSignals();

}

FileDialog::~FileDialog()
{

}
/*
void FileDialog::setDirPath(QString dirPath)
    {
        this->dirPath = dirPath;
    }
void FileDialog::setFilter(QString filter)
    {
        this->filter = filter;
    }
*/
QString FileDialog::getDirPath()
{
    return dirPath;
}
QString FileDialog::getFilter()
{
    return filter;
}

void FileDialog::setReadFileFunction(void (widgets::* functionReadFile)(QString)) {
    this->functionReadFile = functionReadFile;
}

void FileDialog::setWriteFileFunction(void (widgets::*functionWriteFile)(QString)) {
    this->functionWriteFile = functionWriteFile;
}

void FileDialog::createWidgets()
{
    dirList = new QListWidget();
    dirBoxOpen = new QComboBox();
    nameFileWrite = new QSpinBox();
    labelRead = new QLabel("Читение файла");
    labelRead->setMinimumHeight(28);
    ButtonRead = new QPushButton("Читать");
    ButtonRead->setMinimumHeight(28);
    labelWrite = new QLabel("Запись файла");
    ButtonWrite = new QPushButton("Записать");
    ButtonWrite->setMinimumHeight(28);
    ButtonExit = new QPushButton("Выход");
    ButtonExit->setMinimumHeight(28);

    labelRead->setAlignment(Qt::AlignCenter);
    labelWrite->setAlignment(Qt::AlignCenter);
    ButtonWrite->setFocusPolicy(Qt::NoFocus);
    ButtonRead->setFocusPolicy(Qt::NoFocus);

    nameFileWrite->setFixedWidth(this->size().width()/3);
    dirBoxOpen->setFixedWidth(this->size().width()/3);

    nameFileWrite->setPrefix(filter);

}
QFrame* FileDialog::createFrame()
{
    QFrame* frame = new QFrame(this);
    return frame;
}
void FileDialog::setupLayout()
{
    layout = new QGridLayout(this);
    layout->setSpacing(10);

    //добавление фрейма на сетку - рамки для блока
    layout->addWidget(createFrame(), 1, 0, 3, 1);
    layout->addWidget(createFrame(), 1, 1, 3, 1);

    //занимает всю строку
    layout->addWidget(dirList,       0, 0, 1, 2);

    //блок чтения
    layout->addWidget(labelRead,     1, 0);
    layout->addWidget(dirBoxOpen,    2, 0);
    layout->addWidget(ButtonRead,    3, 0);

    //блок записи
    layout->addWidget(labelWrite,    1, 1);
    layout->addWidget(nameFileWrite, 2, 1);
    layout->addWidget(ButtonWrite,   3, 1);

    //занимает всю строку
    layout->addWidget(ButtonExit,    4, 0, 1, 2);

    //расстяшиваем солбец
    layout->setColumnStretch(0, 0);
    layout->setColumnStretch(4, 0);

    setLayout(layout); // установка сетки в качестве главного макета
}
void FileDialog::connectSignals()
{
    connect(ButtonRead,  SIGNAL(clicked(bool)),                this,          SLOT(filterFilesRead()));
    connect(ButtonWrite, SIGNAL(clicked(bool)),                this,          SLOT(filterFilesWrite()));
    connect(ButtonExit,  SIGNAL(clicked(bool)),                this,          SLOT(close()));
    connect(dirList,     SIGNAL(itemSelectionChanged()),       this,          SLOT(onItemSelected()));
    connect(dirBoxOpen,  SIGNAL(currentIndexChanged(QString)), this,          SLOT(onComboBoxSelected()));
    connect(ButtonRead,  SIGNAL(pressed()),                    this->grphcs,  SLOT(press()));
    connect(ButtonWrite, SIGNAL(pressed()),                    this->grphcs,  SLOT(press()));
    connect(ButtonExit,  SIGNAL(pressed()),                    this->grphcs,  SLOT(press()));
}
void FileDialog::onItemSelected()
{

    dirBoxOpen->setCurrentText(dirList->selectedItems()[0]->text());

}
void FileDialog::onComboBoxSelected()
{
    QString selectedText = dirBoxOpen->currentText();
    QList<QListWidgetItem*> items = dirList->findItems(selectedText, Qt::MatchExactly);
    if (!items.isEmpty()) {
        dirList->setCurrentItem(items.first());
    }
}
bool FileDialog::checkFileExists(QString filename)
{
    QFileInfo checkFile(filename);

    if (checkFile.exists() && checkFile.isFile())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void FileDialog::filterFilesOpen()
{
    QDir dir(dirPath);
    QStringList filters;
    QStringList files = dir.entryList(filters);

    dirBoxOpen->clear();

    for (int i = 0; i < files.count(); ++i) {
        QFileInfo fileInfo(files.at(i));
        if (fileInfo.fileName().startsWith(filter)) {
            dirBoxOpen->addItem(fileInfo.fileName());
            dirList->addItem(fileInfo.fileName());
        }
    }
}
void FileDialog::update()
{
    dirList->clear();
    filterFilesOpen();
}
void FileDialog::filterFilesWrite()
{
    QString filename = dirPath + nameFileWrite->text();

    if(functionWriteFile == nullptr){
        QMessageBox::information(this, "", "Извините, функция записи не указана. Обратитесь к программисту");
    } else {
        //сушествует ли файл
        if(checkFileExists(filename)){
            QMessageBox::information(this, "", "Извините, файл " + filename + " уже создан.");
            return;
        }
        else {
            (this->dw->*functionWriteFile)(filename);
        }

        update();
    }
}
void FileDialog::filterFilesRead()
{
    if(functionReadFile == nullptr) {
        QMessageBox::information(this, "", "Извините, функция записи не указана. Обратитесь к программисту");
    }else{
        QString filename = dirPath + dirBoxOpen->currentText();
        (this->dw->*functionReadFile)(filename);
    }
}
