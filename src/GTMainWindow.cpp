#include <Qmessagebox>

#include "GTMainWindow.h"
#include "GTAboutDialog.h"
#include "Version.h"

GtMain::GtMain(QWidget* parent)
	: QMainWindow(parent), gtSubWindow()
{
    ui.setupUi(this);
}

void GtMain::resetBtnState() noexcept
{
    ui.newGTerm->setEnabled(!gtSubWindow);
    ui.getInputString->setEnabled(gtSubWindow);
    ui.showHelp->setEnabled(gtSubWindow);
    ui.print->setEnabled(gtSubWindow);
    ui.println->setEnabled(gtSubWindow);
    ui.showMessageDialog->setEnabled(gtSubWindow);
    ui.showErrorDialog->setEnabled(gtSubWindow);
    ui.showWarningDialog->setEnabled(gtSubWindow);
    ui.setXY->setEnabled(gtSubWindow);
    ui.setFontNameStyleSize->setEnabled(gtSubWindow);
    ui.setFontColorRGB->setEnabled(gtSubWindow);
    ui.setFontColorColorChooser->setEnabled(gtSubWindow);
    ui.setFontName->setEnabled(gtSubWindow);
    ui.setFontSize->setEnabled(gtSubWindow);
    //ui.setFontStyle->setEnabled(gtSubWindow);
    ui.setTabSize->setEnabled(gtSubWindow);
    ui.setFilePath->setEnabled(gtSubWindow);
    ui.setBackgroundColorColorChooser->setEnabled(gtSubWindow);
    ui.setBackgroundColorRGB->setEnabled(gtSubWindow);
    ui.getFilePath->setEnabled(gtSubWindow);
    /*
    ui.addImageIcon->setEnabled(gtSubWindow);
    ui.addPasswordField->setEnabled(gtSubWindow);
    ui.addTable​->setEnabled(gtSubWindow);
    ui.addRowToTable->setEnabled(gtSubWindow);
    ui.getIndexOfSelectedRowFromTable->setEnabled(gtSubWindow);
    ui.getSelectedRowFromTable->setEnabled(gtSubWindow);
    */
    ui.getPasswordFromDialog->setEnabled(gtSubWindow);
    //ui.addTextArea->setEnabled(gtSubWindow);
    ui.clear->setEnabled(gtSubWindow);
    ui.close->setEnabled(gtSubWindow);
}

void GtMain::connectSignalToSubWin()
{
    connect(gtSubWindow, &GtSubWindow::destroyed, this, &GtMain::deleteGTSub);
    connect(ui.getInputString, &QPushButton::clicked, gtSubWindow, &GtSubWindow::getInputString);
    connect(ui.showHelp, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showHelp);
    connect(ui.print, &QPushButton::clicked, gtSubWindow, &GtSubWindow::print);
    connect(ui.println, &QPushButton::clicked, gtSubWindow, &GtSubWindow::println);
    connect(ui.showMessageDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showMessageDialog);
    connect(ui.showErrorDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showErrorDialog);
    connect(ui.showWarningDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::showWarningDialog);
    connect(ui.setXY, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setXY);
    connect(ui.setFontNameStyleSize, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFontNameStyleSize);
    connect(ui.setFontColorRGB, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFontColorRGB);
    connect(ui.setFontColorColorChooser, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFontColorColorChooser);
    connect(ui.setFontName, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFontName);
    connect(ui.setFontSize, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFontSize);
    //connect(ui.setFontStyle, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFontStyle);
    connect(ui.setTabSize, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setTabSize);
    connect(ui.setFilePath, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setFilePath);
    connect(ui.setBackgroundColorColorChooser, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setBackgroundColorColorChooser);
    connect(ui.setBackgroundColorRGB, &QPushButton::clicked, gtSubWindow, &GtSubWindow::setBackgroundColorRGB);
    connect(ui.getFilePath, &QPushButton::clicked, gtSubWindow, &GtSubWindow::getFilePath);
    /*

    */
    connect(ui.getPasswordFromDialog, &QPushButton::clicked, gtSubWindow, &GtSubWindow::getPasswordFromDialog);
    //connect(ui.addTextArea, &QPushButton::clicked, gtSubWindow, &GtSubWindow::addTextArea);
    connect(ui.clear, &QPushButton::clicked, gtSubWindow, &GtSubWindow::clear);
    connect(ui.close, &QPushButton::clicked, gtSubWindow, &GtSubWindow::deleteLater);
}

void GtMain::menuSystemAboutAction()
{
    GTAboutDialog about(this);
    about.exec();
}

void GtMain::menuSystemAboutQtAction()
{
    QMessageBox::aboutQt(this, QStringLiteral("GTerm Qt Information"));
}

void GtMain::newGTermBtn()
{
    gtSubWindow = new GtSubWindow(this);
    gtSubWindow->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    resetBtnState();
    connectSignalToSubWin();
    gtSubWindow->show();
}

void GtMain::deleteGTSub() noexcept
{
    gtSubWindow = Q_NULLPTR;
    resetBtnState();
}