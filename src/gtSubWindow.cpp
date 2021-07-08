#include <QColorSpace>
#include <QImageReader>
#include <QScrollArea>
#include <QScrollBar>
#include <QScreen>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QStringList>
#include <QRegularExpression>

#include "gtSubWindow.h"
#include "PreComRE.h"

GtSubWindow::GtSubWindow(QWidget* parent) 
	: QMainWindow(parent), ui(), x(), y(),
	gtFont(new QFont("Segoe UI", 12)), gtFontMetrics(new QFontMetrics(*gtFont))
{
	ui.setupUi(this);
}

GtSubWindow::~GtSubWindow()
{
	
}

void GtSubWindow::print()
{
	QString string(std::move(getInputStringImpl()));
	printImpl(string);
}

void GtSubWindow::println()
{
	QString string(std::move(getInputStringImpl()));
	printlnImpl(string);
}

void GtSubWindow::printImpl(QString& input)
{
	if (x + input.size() > static_cast<QString::size_type>((std::numeric_limits<decltype(x)>::max)()) ||
				y + input.size() > static_cast<QString::size_type>((std::numeric_limits<decltype(y)>::max)()))
	{
		// TODO
		static_cast<void>(QMessageBox::critical(this, tr("Show Error Dialog"), "Overflow", QMessageBox::Ok));
		return;
	}

	input.replace(GTRE::findSlasht, GTSPE::tab);

	auto height = gtFontMetrics->height();
	auto width = gtFontMetrics->horizontalAdvance(input);

	auto newLabel = new (std::nothrow) QLabel(ui.scrollAreaWidgetContents);

	if (!newLabel)
	{
		//TODO
		return;
	}

	newLabel->setText(input);
	newLabel->setFont(*gtFont);

	newLabel->setGeometry(x, y, width, height);
	newLabel->show();

	x += width;

	/*
	int backUpx = x;
	auto eachLine = input.split(GTRE::findSlashn);
	auto height = gtFontMetrics->height();
	try
	{
		for (auto start = eachLine.cbegin(), end = eachLine.cend(); start != end; ++start)
		{
			if (start->isEmpty())
			{
				y += height;
				continue;
			}

			x = 0;
			auto width = gtFontMetrics->horizontalAdvance(*start);
			auto newLabel = new QLabel(ui.subCentralwidget);

			newLabel->setText(*start);
			newLabel->setFont(*gtFont);

			newLabel->setGeometry(x, y, width, height);
			newLabel->show();

			x += width;
			y += height;
		}
	}
	catch (const std::exception&)
	{
		x = backUpx;
	}

	if (eachLine.size() < 2)
	{
		y -= height;
	}
	*/

}

void GtSubWindow::printlnImpl(QString& input)
{
	printImpl(input);
	x = 0;
	y += gtFontMetrics->height();
}

void GtSubWindow::getInputString()
{
	showMessageDialog();
}

void GtSubWindow::showHelp()
{
	QString a("GTerm version 2021.03.01 by Gayan Wijesinghe");
	QString b("https://jupiter.csit.rmit.edu.au/~e58140/GTerm/");
	printlnImpl(a);
	printlnImpl(b);
}

void GtSubWindow::showMessageDialog()
{
	static_cast<void>(QMessageBox::information(
		this, tr("Show Message Dialog/ Get Input String"), getInputStringImpl(), QMessageBox::Ok | QMessageBox::Cancel));
}

void GtSubWindow::showErrorDialog()
{
	static_cast<void>(QMessageBox::critical(this, tr("Show Error Dialog"), getInputStringImpl(), QMessageBox::Ok));
}

void GtSubWindow::showWarningDialog()
{
	static_cast<void>(QMessageBox::warning(this, tr("Show Warning Dialog"), getInputStringImpl(), QMessageBox::Ok));
}

inline QString GtSubWindow::getInputStringImpl()
{
	QString userInput(std::move(QInputDialog::getText(this, tr("GTerm Input Dialog"), tr("Please enter a String"))));
	if (userInput.isEmpty())
	{
		return QString("null");
	}

	return userInput;
}

inline std::tuple<QString::size_type, QString::size_type, QString> GtSubWindow::calNumOfStAndSn(const QString& string)
{
	QString reString;
	decltype(string.size()) numberOfSlashT = 0;
	decltype(string.size()) numberOfSlashN = 0;

	for (decltype(string.size()) i = 0; i < string.size(); i++)
	{
		if (string[i] == GTSPE::slash)
		{
			if (i + 1 < string.size())
			{
				if (string[i + 1] == GTSPE::t)
				{
					++numberOfSlashT;
					reString += GTSPE::tab;
					++i;
				}
				else if (string[i + 1] == GTSPE::n)
				{
					++numberOfSlashN;
					reString += GTSPE::newline;
					++i;
				}
				else
				{
					reString += string[i];
				}
			}
			else
			{
				reString += string[i];
			}
		}
		else
		{
			reString += string[i];
		}
	}

	return { numberOfSlashT, numberOfSlashN, reString };
}

/*

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