#include <QColorSpace>
#include <QImageReader>
#include <QScrollArea>
#include <QScrollBar>
#include <QScreen>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>

#include "gtSubWindow.h"

GtSubWindow::GtSubWindow(QWidget* parent) 
	: QMainWindow(parent), ui(), x(0), y(0)
{
	ui.setupUi(this);
}

GtSubWindow::~GtSubWindow()
{
	
}

void GtSubWindow::print()
{
	auto newLabel = new QLabel(ui.widget);
	newLabel->setText(getInputString());
	
	newLabel->setGeometry(QRect(x, y, 20, 20));
	newLabel->show();
	x += 20;
}

QString GtSubWindow::getInputString()
{
	QString userInput = QInputDialog::getText(this, tr("GTerm Input Dialog"), tr("Please enter a String"));
	if (userInput.isEmpty())
		userInput = QString("Null");

	return userInput;
}

/*
void GtSubWindow::showHelp()
{
	QMessageBox::about(this, tr("Show Help"),
		tr("GTerm version 2021.03.01 by Gayan Wijesinghe\nhttps://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));

	QDesktopServices::openUrl(QUrl("https://jupiter.csit.rmit.edu.au/~e58140/GTerm/"));
}




void GtSubWindow::showMessageDialog(QString& inputString)
{
	(void)QMessageBox::information(this, tr("Show Message Dialog"), inputString, QMessageBox::Ok);
}

void GtSubWindow::showErrorDialog()
{
	(void)QMessageBox::critical(this, tr("Show Error Dialog"), "Error!", QMessageBox::Ok);
}

void GtSubWindow::addImageIcon()
{
	const QString imageIconPath = QFileDialog::getOpenFileName(this, tr("Select a image icon"), 
		QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), tr("Image Icon (*.png *.xpm *.jpg)"));

	if (imageIconPath.isNull())
		return;
	
	if (!gtImageViewer)
	{
		gtImageViewer = new GtImageViewer();
		gtImageViewer->setAttribute(Qt::WA_DeleteOnClose);
		connect(gtImageViewer, &QWidget::destroyed, this, qOverload<>(&GtSubWindow::deleteImageView));
	}

	gtImageViewer->loadFile(imageIconPath);
	gtImageViewer->show();
}
*/