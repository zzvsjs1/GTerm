#include "gtSubWindow.h"

#include <QColorSpace>
#include <QImageReader>
#include <QScrollArea>
#include <QScrollBar>
#include <QScreen>
#include "gtImageView.h"

GtSubWindow::GtSubWindow(QWidget* parent) 
	: QMainWindow(parent), gtLabel(new QLabel)
	, gtScrollArea(new QScrollArea)
{
	setWindowTitle(tr("GTerm"));
	setWindowIcon(QIcon(":/gtres/resources/logo/java.ico"));
	resize(QSize(1024, 768));
	
	gtScrollArea->setWidget(gtLabel);
	gtScrollArea->setVisible(true);
	
	setCentralWidget(gtScrollArea);

	gtFont =  new QFont(QString("Arial"), 10, 1, false);
	gtGroupBox = nullptr;
	x = 0;
	y = 0;
}

GtSubWindow::~GtSubWindow()
{
	if (!gtTable.isEmpty())
	{
		for (auto& e : gtTable)
		{
			delete e;
		}
	}


	delete gtFont;
}

void GtSubWindow::showHelp()
{
	QMessageBox::about(this, tr("Show Help"),
		tr("GTerm version 2021.03.01 by Gayan Wijesinghe\nhttps://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));

	QDesktopServices::openUrl(QUrl("https://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));
}

void GtSubWindow::getInputString()
{
	QString userInput = QInputDialog::getText(this, QString("GTerm Input Dialog"), QString("Please enter a String"));
	if (userInput.isEmpty())
		userInput = QString("Null");

	showMessageDialog(userInput);
}

void GtSubWindow::showMessageDialog(QString& inputString)
{
	(void)QMessageBox::information(this, QString("Show Message Dialog"), inputString, QMessageBox::Ok);
}

void GtSubWindow::showErrorDialog()
{
	(void)QMessageBox::critical(this, QString("Show Error Dialog"), "Error!", QMessageBox::Ok);
}

void GtSubWindow::addImageIcon()
{
	/*
	const QString imageIconPath = QFileDialog::getOpenFileName(this, tr("Select a image icon"), 
		QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("Image Icon (*.png *.xpm *.jpg)"));

	if (imageIconPath.isNull())
		return;
	
	QImageReader reader(imageIconPath);
	QImage image = reader.read();
	if (image.isNull())
	{
		(void)QMessageBox::information(this, QGuiApplication::applicationDisplayName(), 
			tr("Not GTerm error, cannot load %1: %2").arg(QDir::toNativeSeparators(imageIconPath), reader.errorString()));
		return;
	}

	if (image.colorSpace().isValid())
		image.convertToColorSpace(QColorSpace::SRgb);

		*/


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
	(void)QFileDialog::getSaveFileName(this);
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
	return QFileDialog::getOpenFileName(this);
}

void GtSubWindow::retranslateUi()
{
}

inline void GtSubWindow::setupUi()
{
}

void GtSubWindow::showDialog()
{
}
