#include "gtmain.h"

GtMain::GtMain(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
}

GtMain::~GtMain()
{
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
    gtGroupBox->setGeometry(QRect(0, 0, 1280, 720));
    gtGroupBox->setObjectName(QString::fromUtf8("groupBox"));

    QFont buttonFont;
    buttonFont.setFamily("Arial");
    buttonFont.setBold(true);
    buttonFont.setPixelSize(15);

    getInputStringButton = new QPushButton(gtGroupBox);
    getInputStringButton->setGeometry(QRect(0, 0, 130, 60));
    getInputStringButton->setText(QCoreApplication::translate("gtmain", "Get Input", nullptr));
    getInputStringButton->setFont(buttonFont);

    showMessageDialogButton = new QPushButton(gtGroupBox);
    showMessageDialogButton->setGeometry(QRect(160, 0, 250, 60));
    showMessageDialogButton->setText(QCoreApplication::translate("gtmain", "Show Message Dialog", nullptr));
    showMessageDialogButton->setFont(buttonFont);

    connect(getInputStringButton, &QPushButton::clicked, this, qOverload<>(&GtMain::getInputString));
    connect(showMessageDialogButton, &QPushButton::clicked, this, qOverload<>(&GtMain::showMessageDialog));
    QMetaObject::connectSlotsByName(this);
}

void GtMain::showHelp()
{

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

    QMessageBox::StandardButton result = QMessageBox::information(this, 
                                                                  QString("Show Message Dialog"), 
                                                                  userInput,
                                                                  QMessageBox::Ok);
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

QString GtMain::getFilePath()
{
    return QString();
}
