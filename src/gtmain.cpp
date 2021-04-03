#include "gtmain.h"
#include "gtAboutDialog.h"
#include "Version.h"

GtMain::GtMain(QWidget* parent): QMainWindow(parent)
{
    setWindowTitle(QString::fromStdString(Common::gt_title_str));
    setAcceptDrops(true);
    setAttribute(Qt::WA_NativeWindow);
    resize(1280, 720);
    setMaximumSize(QSize(1920, 1080));

    setupUi();
    retranslateUi();
    connectButtonSignal();
    connectMenuSignal();
}

GtMain::~GtMain()
{
    delete showHelpButton;
    delete getInputStringButton;
    delete gtFont;
    delete showMessageDialogButton;
}

void GtMain::setupUi()
{
    gtCentralWidget = new QWidget(this);
    gtCentralWidget->setObjectName(QString::fromUtf8("gtCentralWidget"));
    gtCentralWidget->resize(QSize(1280, 720));
    gtCentralWidget->setMaximumSize(QSize(1280, 720));

    gtGroupBox = new QGroupBox(gtCentralWidget);
    gtGroupBox->setGeometry(QRect(0, 25, 1280, 720));
    gtGroupBox->setObjectName(QString::fromUtf8("groupBox"));

    gtFont = new QFont(QString("Arial"), 12, 1, false);

    newGTermObjectButton = new QPushButton(gtGroupBox);
    newGTermObjectButton->setGeometry(QRect(0, 0, 300, 60));
    newGTermObjectButton->setFont(*gtFont);

    getInputStringButton = new QPushButton(gtGroupBox);
    getInputStringButton->setGeometry(QRect(330, 0, 130, 60));
    getInputStringButton->setFont(*gtFont);
    getInputStringButton->setDisabled(true);

    showMessageDialogButton = new QPushButton(gtGroupBox);
    showMessageDialogButton->setGeometry(QRect(0, 150, 250, 60));
    showMessageDialogButton->setFont(*gtFont);
    showMessageDialogButton->setDisabled(true);

    showHelpButton = new QPushButton(gtGroupBox);
    showHelpButton->setGeometry(QRect(0, 80, 200, 60));
    showHelpButton->setFont(*gtFont);
    showHelpButton->setDisabled(true);
    
    actionMenuAbout = new QAction(this);

    gtMenuBar = new QMenuBar(this);
    gtMenuBar->setGeometry(QRect(0, 0, 1280, 22));

    gtMenuSystem = new QMenu(gtMenuBar);
    setMenuBar(gtMenuBar);

    //gtToolBar = new QToolBar(this);
    //addToolBar(Qt::TopToolBarArea, gtToolBar);

    gtStatusBar = new QStatusBar(this);
    setStatusBar(gtStatusBar);

    gtSubWindow = nullptr;

    gtMenuBar->addAction(gtMenuSystem->menuAction());
    gtMenuSystem->addSeparator();
    gtMenuSystem->addSeparator();
    gtMenuSystem->addAction(actionMenuAbout);


    //setAttribute(Qt::WA_QuitOnClose, false);
}

void GtMain::connectMenuSignal()
{
    connect(actionMenuAbout, &QAction::triggered, this, qOverload<>(&GtMain::menuButtonAbout));
}


void GtMain::connectButtonSignal()
{
    
    connect(newGTermObjectButton, &QPushButton::clicked, this, qOverload<>(&GtMain::newGTerm));
}



void GtMain::retranslateUi()
{
    newGTermObjectButton->setText(QCoreApplication::translate("gtmain", "GTerm gt = new GTerm(1024, 768);", nullptr));
    showMessageDialogButton->setText(QCoreApplication::translate("gtmain", "Show Message Dialog", nullptr));
    getInputStringButton->setText(QCoreApplication::translate("gtmain", "Get Input", nullptr));
    showHelpButton->setText(QCoreApplication::translate("gtmain", "Show Help", nullptr));
    gtMenuSystem->setTitle(QCoreApplication::translate("gtMain", "System", nullptr));
    actionMenuAbout->setText(QCoreApplication::translate("gtMain", "About", nullptr));
}

void GtMain::menuButtonAbout()
{
    GtAboutDialog about{ this };
    about.exec();
}

void GtMain::newGTerm()
{
    if (gtSubWindow)
    {
        (void)QMessageBox::critical(this, tr("Error"),
            tr("You only allow to create one GTerm object."), QMessageBox::Ok);
        return;
    }


    gtSubWindow = new GtSubWindow();
    gtSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    gtSubWindow->show();
    getInputStringButton->setDisabled(false);
    showMessageDialogButton->setDisabled(false);
    showHelpButton->setDisabled(false);
    connect(getInputStringButton, &QPushButton::clicked, gtSubWindow, qOverload<>(&GtSubWindow::getInputString));
    connect(showMessageDialogButton, &QPushButton::clicked, gtSubWindow, qOverload<>(&GtSubWindow::showMessageDialog));
    connect(showHelpButton, &QPushButton::clicked, gtSubWindow, qOverload<>(&GtSubWindow::showHelp));
    //connect(closeButton, &QPushButton::clicked, this, qOverload<>(&GtMain::closeGTerm));
    connect(gtSubWindow, &QWidget::destroyed, this, qOverload<>(&GtMain::clearGtSub));
}

void GtMain::closeGTerm()
{
    if (gtSubWindow)
        gtSubWindow->close();
}

void GtMain::clearGtSub()
{
    gtSubWindow = nullptr;
    getInputStringButton->setDisabled(true);
    showMessageDialogButton->setDisabled(true);
    showHelpButton->setDisabled(true);
}
