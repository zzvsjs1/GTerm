#include <Qmessagebox>

#include "gtMain.h"
#include "gtAboutDialog.h"
#include "Version.h"

GtMain::GtMain(QWidget* parent)
	: QMainWindow(parent), gtSubWindow(Q_NULLPTR)
{
    ui.setupUi(this);
}

void GtMain::resetBtnState()
{
    ui.newGTerm->setEnabled(!gtSubWindow);
    ui.getInputString->setEnabled(gtSubWindow);
    ui.showHelp->setEnabled(gtSubWindow);
    ui.print->setEnabled(gtSubWindow);
    ui.println->setEnabled(gtSubWindow);
    ui.showMessageDialog->setEnabled(gtSubWindow);
    ui.showErrorDialog->setEnabled(gtSubWindow);
    ui.showWarningDialog->setEnabled(gtSubWindow);
}

void GtMain::connectSignalToSubWin()
{
    connect(gtSubWindow, &GtSubWindow::destroyed, this, &GtMain::closeGTSub);
    connect(ui.getInputString, &QPushButton::clicked, gtSubWindow, &GtSubWindow::getInputString);
    connect(ui.showHelp, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showHelp);
    connect(ui.print, &QPushButton::clicked, gtSubWindow, &GtSubWindow::print);
    connect(ui.println, &QPushButton::clicked, gtSubWindow, &GtSubWindow::println);
    connect(ui.showMessageDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showMessageDialog);
    connect(ui.showErrorDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showErrorDialog);
    connect(ui.showWarningDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showWarningDialog);
}

void GtMain::menuSystemAboutAction()
{
    GtAboutDialog about(this);
    about.exec();
}

void GtMain::menuSystemAboutQtAction()
{
    QMessageBox::aboutQt(this, tr("GTerm Qt Information"));
}

void GtMain::newGTermBtn()
{
    gtSubWindow = new GtSubWindow(this);
    gtSubWindow->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    resetBtnState();
    connectSignalToSubWin();
    gtSubWindow->show();
}

void GtMain::closeGTSub()
{
    gtSubWindow = Q_NULLPTR;
    resetBtnState();
}
