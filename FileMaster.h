#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>
#include <QListWidget>
#include <QObject>
#include <QMessageBox>
#include <graphics.h>
#include <widgets.h>

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QString dirPath, QString filter, graphics *g = nullptr);
    ~FileDialog();
    QString getDirPath();
    QString getFilter();

    void setReadFileFunction(void (widgets::*functionReadFile)(QString));
    void setWriteFileFunction(void (widgets::*functionWriteFile)(QString));


private:
    widgets* dw;

    void (widgets::*functionReadFile)(QString) = nullptr;
    void (widgets::*functionWriteFile)(QString) = nullptr;

    QLabel *labelWrite;
    QLabel *labelRead;
    QListWidget *dirList;
    QComboBox *dirBoxOpen;
    QSpinBox *nameFileWrite;
    QString filter;
    QPushButton *ButtonRead;
    QPushButton *ButtonWrite;
    QPushButton *ButtonExit;
    QGridLayout *layout;
    QString dirPath;
    graphics *grphcs;

private slots:
    void createWidgets();
    void setupLayout();
    void connectSignals();
    void filterFilesOpen();
    void filterFilesWrite();
    void filterFilesRead();
    void onItemSelected();
    void onComboBoxSelected();
    bool checkFileExists(QString filename);
    void update();
    QFrame *createFrame();
};

