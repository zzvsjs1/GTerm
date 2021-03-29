#include "gtmain.h"
#include "gtAboutDialog.h"

GtMain::GtMain(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    retranslateUi();
}

GtMain::~GtMain()
{
    delete showHelpButton;
    delete getInputStringButton;
}

inline void GtMain::setupUi()
{
    setWindowTitle(QString("GTerm"));
    setObjectName(QString::fromUtf8("gtmain"));
    resize(1280, 720);
    setMaximumSize(QSize(1920, 1080));

    gtCentralWidget = new QWidget(this);
    gtCentralWidget->setObjectName(QString::fromUtf8("gtCentralWidget"));
    gtCentralWidget->resize(QSize(1280, 720));
    gtCentralWidget->setMaximumSize(QSize(1280, 720));

    gtGroupBox = new QGroupBox(gtCentralWidget);
    gtGroupBox->setGeometry(QRect(0, 25, 1280, 720));
    gtGroupBox->setObjectName(QString::fromUtf8("groupBox"));

    QFont buttonFont;
    buttonFont.setFamily("Arial");
    buttonFont.setBold(true);
    buttonFont.setPixelSize(15);

    getInputStringButton = new QPushButton(gtGroupBox);
    getInputStringButton->setGeometry(QRect(0, 0, 130, 60));
    getInputStringButton->setFont(buttonFont);

    showMessageDialogButton = new QPushButton(gtGroupBox);
    showMessageDialogButton->setGeometry(QRect(160, 0, 250, 60));
    showMessageDialogButton->setFont(buttonFont);

    showHelpButton = new QPushButton(gtGroupBox);
    showHelpButton->setGeometry(QRect(430, 0, 200, 60));

    showHelpButton->setFont(buttonFont);

    actionMenuAbout = new QAction(this);

    gtMenuBar = new QMenuBar(this);
    gtMenuBar->setGeometry(QRect(0, 0, 1280, 22));

    gtMenuSystem = new QMenu(gtMenuBar);
    setMenuBar(gtMenuBar);

    //gtToolBar = new QToolBar(this);
    //addToolBar(Qt::TopToolBarArea, gtToolBar);

    gtStatusBar = new QStatusBar(this);
    setStatusBar(gtStatusBar);


    gtMenuBar->addAction(gtMenuSystem->menuAction());
    gtMenuSystem->addSeparator();
    gtMenuSystem->addSeparator();
    gtMenuSystem->addAction(actionMenuAbout);

    connect(getInputStringButton, &QPushButton::clicked, this, qOverload<>(&GtMain::getInputString));
    connect(showMessageDialogButton, &QPushButton::clicked, this, qOverload<>(&GtMain::showMessageDialog));
    connect(showHelpButton, &QPushButton::clicked, this, qOverload<>(&GtMain::showHelp));
    connect(actionMenuAbout, &QAction::triggered, this, qOverload<>(&GtMain::menuButtonAbout));
}

void GtMain::retranslateUi()
{
    showMessageDialogButton->setText(QCoreApplication::translate("gtmain", "Show Message Dialog", nullptr));
    getInputStringButton->setText(QCoreApplication::translate("gtmain", "Get Input", nullptr));
    showHelpButton->setText(QCoreApplication::translate("gtmain", "Show Help", nullptr));
    gtMenuSystem->setTitle(QCoreApplication::translate("gtMain", "System", nullptr));
    actionMenuAbout->setText(QCoreApplication::translate("gtMain", "About", nullptr));
}

void GtMain::showHelp()
{
    QDesktopServices::openUrl(QUrl("https://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));
}

QString GtMain::getInputString()
{
    return QInputDialog::getText(this, "GTerm Get Input String", "Please enter a String");
}

void GtMain::showMessageDialog()
{
    QString userInput = getInputString();
    if (userInput.isEmpty())
        userInput = QString("Null");

    QMessageBox::StandardButton result = QMessageBox::information(this, QString("Show Message Dialog"), 
        userInput, QMessageBox::Ok);
}

void GtMain::showErrorDialog()
{

}

void GtMain::addImageIcon()
{
   
}

void GtMain::setXY()
{

}

void GtMain::addTable()
{

}

void GtMain::addRowToTable()
{

}

void GtMain::selectRowFromTable()
{

}

void GtMain::getRowIndexFromSelectTable()
{

}

void GtMain::addButton()
{

}

void GtMain::menuButtonAbout()
{
    GtAboutDialog about{ this };
    about.exec();
}

QString GtMain::getFilePath()
{
    return QString();
}
