#include <Qmessagebox>

#include "gtMain.h"
#include "gtAboutDialog.h"
#include "Version.h"

GtMain::GtMain(QWidget* parent)
	: QMainWindow(parent), gtSubWindow(Q_NULLPTR)
{
    ui.setupUi(this);
}

void GtMain::connectGTWindowSignal()
{
    ui.newGTerm->setEnabled(!gtSubWindow);
    ui.print->setEnabled(gtSubWindow);
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
    connectGTWindowSignal();
    gtSubWindow->show();
    connect(gtSubWindow, &GtSubWindow::destroyed, this, &GtMain::closeGtSub);
    connect(ui.print, &QAbstractButton::clicked, gtSubWindow, &GtSubWindow::print);
}

void GtMain::closeGtSub()
{
    gtSubWindow = nullptr;
    connectGTWindowSignal();
}
