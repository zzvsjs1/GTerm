#include <Qmessagebox>

#include "gtMain.h"
#include "gtAboutDialog.h"
#include "Version.h"

GtMain::GtMain(QWidget* parent)
	: QMainWindow(parent), gtSubWindow(Q_NULLPTR)
{
    ui.setupUi(this);
}

void GtMain::retranslateUi()
{
	
}

void GtMain::connectGTWindowSignal()
{
    
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
    if (gtSubWindow)
    {
        static_cast<void>(QMessageBox::critical(this, tr("Error"),
            tr("You only allow to create one GTerm object."), QMessageBox::Ok));
        return;
    }

    gtSubWindow = new GtSubWindow;
    gtSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    connectGTWindowSignal();
    gtSubWindow->show();
}

void GtMain::closeGTermButtonAction()
{
    if (gtSubWindow)
    {
        gtSubWindow->close();
    }
}

void GtMain::closeGtSub()
{
    gtSubWindow = nullptr;
    connectGTWindowSignal();
}
