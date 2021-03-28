#ifndef GTMAIN_H
#define GTMAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QtCore/QVariant>
#include <QTableView>
#include <QApplication>
#include <QWidget>

class GtMain : public QMainWindow
{
    Q_OBJECT

public:
    GtMain(QWidget *parent = nullptr);
    ~GtMain();
    inline void setupUi();
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
    QString getFilePath();


private:
    int X;
    int Y;
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
    QMenu* gtMenuAbout;
    QStatusBar* gtStatusBar;
    QToolBar* gtToolBar;
    QTableView* gtTable;
};
#endif // GTMAIN_H
