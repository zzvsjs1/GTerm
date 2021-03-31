#include "gtSubWindow.h"

GtSubWindow::GtSubWindow(QWidget* parent) : QWidget(parent)
{
	setWindowTitle(tr("GTerm"));
	resize(QSize(1024, 768));
	gtCentralWidget = new QWidget(this);
	gtCentralWidget->resize(QSize(1024, 768));
	gtCentralWidget->setMaximumSize(QSize(1024, 768));

	gtTable = nullptr;
	gtFont = nullptr;
	gtGroupBox = nullptr;
}

GtSubWindow::~GtSubWindow()
{

}

void GtSubWindow::showHelp()
{
	QMessageBox::about(this, tr("Show Help"),
		tr("GTerm version 2021.03.01 by Gayan Wijesinghe\nhttps://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));
	QDesktopServices::openUrl(QUrl("https://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));
}

void GtSubWindow::getInputString()
{
	showMessageDialog();
}

void GtSubWindow::showMessageDialog()
{
	QString userInput = QInputDialog::getText(this, QString("GTerm Input Dialog"), QString("Please enter a String"));
	if (userInput.isEmpty())
		userInput = QString("Null");

	QMessageBox::StandardButton result = QMessageBox::information(this, QString("Show Message Dialog"),
		userInput, QMessageBox::Ok);
}

void GtSubWindow::showErrorDialog()
{
}

void GtSubWindow::addImageIcon()
{
}

void GtSubWindow::addTable()
{
}

void GtSubWindow::addRowToTable()
{
}

void GtSubWindow::getSelectRowFromTable()
{
}

void GtSubWindow::getRowIndexFromSelectTable()
{
}

void GtSubWindow::addButton()
{
}

void GtSubWindow::print()
{
}

void GtSubWindow::println()
{
}

void GtSubWindow::setFont()
{
}

void GtSubWindow::setFontSize()
{
}

void GtSubWindow::setBackgroundColor()
{
}

void GtSubWindow::setXY()
{
}

void GtSubWindow::setFilePath()
{
}

void GtSubWindow::clear()
{
}

void GtSubWindow::addTextArea()
{
}

void GtSubWindow::addTextField()
{
}

void GtSubWindow::clearRowsOfTable()
{
}

void GtSubWindow::getColorFromDialog()
{
}

void GtSubWindow::getPasswordFromDialog()
{
}

void GtSubWindow::getTextFromEntry()
{
}

void GtSubWindow::setTextInEntry()
{
}

void GtSubWindow::showWarningDialog()
{
}

QString GtSubWindow::getFilePath()
{
	return QString();
}

void GtSubWindow::retranslateUi()
{
}

inline void GtSubWindow::setupUi()
{
}