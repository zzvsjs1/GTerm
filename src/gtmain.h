#ifndef GTMAIN_H
#define GTMAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include "gtSubWindow.h"

class GtMain : public QMainWindow
{
    Q_OBJECT

public:
    GtMain(QWidget* parent = nullptr);
    ~GtMain(); 
    void menuButtonAbout();
    void newGTerm();
    void closeGTerm();
    void closeGtSub();

private:
    GtSubWindow* gtSubWindow;
    void connectButtonSignal();
    void connectMenuSignal();
    void retranslateUi();
    void setupUi();
    QAction* actionMenuAbout;
    QWidget* gtCentralWidget;
    QGroupBox* gtGroupBox;
    QPushButton* newGTermObjectButton;
    QPushButton* getInputStringButton;
    QPushButton* showHelpButton;
    QPushButton* closeButton;
    QPushButton* showMessageDialogButton;
    QPushButton* showErrorDialogButton;
    QPushButton* addImageIconButton;
    QPushButton* setXYButton;
    QMenuBar* gtMenuBar;
    QMenu* gtMenuSystem;
    QStatusBar* gtStatusBar;
};
#endif // GTMAIN_H
