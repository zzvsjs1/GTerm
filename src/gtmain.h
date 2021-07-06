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

#include <memory>

#include "gtSubWindow.h"

class GtMain : public QMainWindow
{
    Q_OBJECT
	Q_DISABLE_COPY_MOVE(GtMain)

public:
    GtMain(QWidget* parent = nullptr);
    ~GtMain() override; 
    void menuAboutButtonAction();
    void newGTerm();
    void closeGTermButtonAction();
    void closeGtSub();

private:
    GtSubWindow* gtSubWindow;
    void connectButtonSignal();
    void connectMenuSignal();
    void retranslateUi();
    void connectGTWindowSignal();
    void setupUi();
    QAction* actionMenuAbout;
    QWidget* gtCentralWidget;
    QGroupBox* gtGroupBox;
    QPushButton* newGTermObjectButton;
    QPushButton* getInputStringButton;
    QPushButton* showHelpButton;
    QPushButton* closeButton;
    QPushButton* printButton;
    QPushButton* showMessageDialogButton;
    QPushButton* showErrorDialogButton;
    QPushButton* addImageIconButton;
    QPushButton* setXYButton;
    QMenuBar* gtMenuBar;
    QMenu* gtMenuSystem;
    QStatusBar* gtStatusBar;
};
#endif // GTMAIN_H
