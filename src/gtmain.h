#ifndef GTMAIN_H
#define GTMAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QtCore/QVariant>
#include <QTableView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QDesktopServices>
#include <QUrl>

class GtMain : public QMainWindow
{
    Q_OBJECT

public:
    GtMain(QWidget *parent = nullptr);
    ~GtMain(); 
    void showHelp();
    QString getInputString();
    void showMessageDialog();
    void showErrorDialog();
    void addImageIcon();
    void setXY();
    void addTable();
    void addRowToTable();
    void selectRowFromTable();
    void getRowIndexFromSelectTable();
    void addButton();
    void menuButtonAbout();
    QString getFilePath();


private:
    int X;
    int Y;
    void retranslateUi();
    inline void setupUi();
    QAction* actionMenuAbout;
    QWidget* gtCentralWidget;
    QGroupBox* gtGroupBox;
    QPushButton* getInputStringButton;
    QPushButton* showHelpButton;
    QPushButton* showMessageDialogButton;
    QPushButton* showErrorDialogButton;
    QPushButton* addImageIconButton;
    QPushButton* setXYButton;
    QMenuBar* gtMenuBar;
    QMenu* gtMenuSystem;
    QStatusBar* gtStatusBar;
    QToolBar* gtToolBar;
    QTableView* gtTable;
};
#endif // GTMAIN_H
