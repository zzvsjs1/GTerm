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

void GtMain::setupUi()
{
    setWindowTitle(QString("GTerm"));
    setObjectName(QString::fromUtf8("gtmain"));
    resize(1280, 720);
    setMaximumSize(QSize(1920, 1080));

    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMaximumSize(QSize(1080, 1920));

    groupBox = new QGroupBox(centralwidget);
    groupBox->setGeometry(QRect(0, 0, 1080, 1920));
    groupBox->setVisible(true);

    QFont buttonFont;
    buttonFont.setFamily("Arial");

    getInputStringButton = new QPushButton(groupBox);
    getInputStringButton->setGeometry(QRect(10, 10, 130, 60));
    getInputStringButton->setText(QCoreApplication::translate("GTerm", "Get Input", nullptr));
    getInputStringButton->setFont(buttonFont);

    showMessageDialogButton = new QPushButton(groupBox);
    showMessageDialogButton->setGeometry(QRect(20, 20, 130, 60));
    showMessageDialogButton->setText(QCoreApplication::translate("GTerm", "Show Message Dialog", nullptr));
    showMessageDialogButton->setFont(buttonFont);

    connect(getInputStringButton, &QPushButton::clicked, this, qOverload<>(&GtMain::getInputString));
    connect(showMessageDialogButton, &QPushButton::clicked, this, qOverload<>(&GtMain::showMessageDialog));
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
