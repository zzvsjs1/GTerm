#include <QColorSpace>
#include <QInputDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPair>
#include <QRegularExpression>
#include <QScrollArea>
#include <QScrollBar>
#include <QScreen>
#include <QStringList>
#include <QStandardPaths>
#include <QFontDialog>
#include <QFontDatabase>
#include <QColorDialog>

#include <tuple>

#include "GTSubWindow.h"
#include "PreComRE.h"
#include "Version.h"
#include "MyDialog.h"

GtSubWindow::GtSubWindow(QWidget* parent)
	: QMainWindow(parent), ui(), x(), y(),
	gtFont(new QFont(QApplication::font())),
	gtFontMetrics(new QFontMetrics(*gtFont)),
	gtTab(GTSPE::t), gtColor(new QColor(Qt::black))
{
	ui.setupUi(this);
}

void GtSubWindow::print()
{
	auto input = getInputStringImpl();
	if (input.isEmpty())
	{
		return;
	}

	printImpl(input);
}

void GtSubWindow::println()
{
	auto input = getInputStringImpl();
	if (input.isEmpty())
	{
		return;
	}

	printImpl(input);
	setNewLine();
}

void GtSubWindow::printImpl(QString& input)
{
	if (x + input.size() > static_cast<QString::size_type>((std::numeric_limits<decltype(x)>::max)()) ||
				y + input.size() > static_cast<QString::size_type>((std::numeric_limits<decltype(y)>::max)()))
	{
		static_cast<void>(QMessageBox::critical(this, tr("Show Error Dialog"), tr("Overflow"), QMessageBox::Ok));
		return;
	}

	input.replace(GTRE::findSlasht, gtTab);

	const auto height = gtFontMetrics->height();
	const auto width = gtFontMetrics->horizontalAdvance(input);

	const auto newLabel = new (std::nothrow) QLabel(ui.scrollAreaWidgetContents);
	newLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

	if (!newLabel)
	{
		static_cast<void>(QMessageBox::critical(this, tr("Show Error Dialog"), tr("No enough memory space"), QMessageBox::Ok));
		QApplication::exit(1);
	}

	newLabel->setText(input);
	newLabel->setFont(*gtFont);
	auto a = gtColor->name();
	newLabel->setStyleSheet(tr("color: %1").arg(gtColor->name()));

	newLabel->setGeometry(x, y, width, height);
	newLabel->show();

#ifdef QT_DEBUG
	Q_ASSERT(x < std::numeric_limits<int>::max() - width);
#endif // QT_DEBUG

	x += width;
	if (x > ui.scrollArea->width())
	{
		ui.scrollAreaWidgetContents->setFixedWidth(x);
	}

	if (y > ui.scrollArea->height())
	{
		y += height;
		ui.scrollAreaWidgetContents->setFixedHeight(y);
	}
}

void GtSubWindow::setNewLine()
{
	x = 0;
	y += gtFontMetrics->height();
	if (y > ui.scrollArea->height())
	{
		ui.scrollAreaWidgetContents->setFixedHeight(y);
	}
}

void GtSubWindow::getInputString()
{
	showMessageDialog();
}

void GtSubWindow::showHelp()
{
	printImpl(Common::show_help1);
	setNewLine();
	printImpl(Common::show_help2);
	setNewLine();
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

void GtSubWindow::setXY()
{
	const auto xAndY = MyDialog::getXY();
	if (xAndY.first == MyDialog::Status::ERROR)
	{
		static_cast<void>(QMessageBox::critical(this, tr("Error raise"), tr("The error occurs when getting the XY."), QMessageBox::Ok));
		return;
	}

	x = xAndY.first;
	y = xAndY.second;
}

void GtSubWindow::setFontNameStyleSize()
{
	bool ok;
	auto newFont = QFontDialog::getFont(&ok, *gtFont, this, tr("GTrem Font Chooser"));
	if (ok)
	{
		*gtFont = newFont;
		*gtFontMetrics = QFontMetrics(*gtFont);
	}
}

void GtSubWindow::setFontColorRGB()
{
	auto colorTuple = MyDialog::getRGB();
	if (std::get<MyDialog::ColorPos::R>(colorTuple) == MyDialog::Status::ERROR)
	{
		static_cast<void>(QMessageBox::critical(this, tr("Error raise"), tr("The error occurs when getting the RGB."), QMessageBox::Ok));
		return;
	}

	gtColor->setRgb(
		std::get<MyDialog::ColorPos::R>(colorTuple), std::get<MyDialog::ColorPos::G>(colorTuple), std::get<MyDialog::ColorPos::B>(colorTuple));
}

void GtSubWindow::setFontColorColorChooser()
{
	auto color = QColorDialog::getColor(Qt::white, this, tr("GTerm Color Chooser"));
	if (color.isValid())
	{
		*gtColor = std::move(color);
	}
}

void GtSubWindow::setFontName()
{
	auto newName = getInputStringImpl();
	if (newName.isEmpty())
	{
		return;
	}

	gtFont->setFamily(getInputStringImpl());
	*gtFontMetrics = QFontMetrics(*gtFont);
}

void GtSubWindow::setFontSize()
{
	const auto pointSizeList = QFontDatabase::pointSizes(gtFont->family(), gtFont->styleName());
	if (pointSizeList.isEmpty())
	{
		static_cast<void>(QMessageBox::critical(this, tr("Error raise"), tr("Size is empty."), QMessageBox::Ok));
		return;
	}

	bool ok;
	const auto newSize = QInputDialog::getInt(
		this, tr("GTerm Font Size Chooser"), tr("Please enter a font size"), 0, gtFont->pointSize(), pointSizeList.last(), 1, &ok);
	if (ok)
	{
		gtFont->setPointSize(newSize);
		*gtFontMetrics = QFontMetrics(*gtFont);
	}
}

void GtSubWindow::setFontStyle()
{
	



}

void GtSubWindow::setTabSize()
{
	bool ok;
	const auto newTabSize = static_cast<QString::size_type>(
		QInputDialog::getInt(this, tr("Set Tab Size"), tr("Please enter a new tab size"), 1, 1, 50, 1, &ok));

	if (ok)
	{
		gtTab = QString(newTabSize, GTSPE::space);
	}
}

void GtSubWindow::setFilePath()
{	
	const auto filePath = QFileDialog::getOpenFileName(
		this, QString(), QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

	if (filePath.isEmpty())
	{
		return;
	}

	static_cast<void>(QMessageBox::information(this, tr("File Path"), filePath, QMessageBox::StandardButton::Ok));
}

void GtSubWindow::setBackgroundColorColorChooser()
{
	auto color = QColorDialog::getColor(Qt::white, this, tr("GTerm Color Chooser"));
	if (color.isValid())
	{
		ui.subCentralwidget->setStyleSheet(tr("background-color: %1").arg(color.name()));
	}
}

void GtSubWindow::setBackgroundColorRGB()
{
	auto colorTuple = MyDialog::getRGB();
	if (std::get<MyDialog::ColorPos::R>(colorTuple) == MyDialog::Status::ERROR)
	{
		static_cast<void>(QMessageBox::critical(this, tr("Error raise"), tr("The error occurs when getting the RGB."), QMessageBox::Ok));
		return;
	}

	ui.subCentralwidget->setStyleSheet(tr("background-color: %1").arg(
		QColor(std::get<MyDialog::ColorPos::R>(colorTuple), 
			std::get<MyDialog::ColorPos::G>(colorTuple), 
			std::get<MyDialog::ColorPos::B>(colorTuple)).name()));
}

void GtSubWindow::getFilePath()
{
	const auto filePath = QFileDialog::getSaveFileName(
		this, QString(), QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

	if (filePath.isEmpty())
	{
		return;
	}

	static_cast<void>(QMessageBox::information(this, tr("File Path"), filePath, QMessageBox::StandardButton::Ok));
}

/*
void GtSubWindow::addImageIcon​​()
{

}
*/

void GtSubWindow::getPasswordFromDialog()
{
	bool ok;
	auto userInput = QInputDialog::getText(
		this, tr("GTerm Password Dialog"), tr("Please enter a Password"), QLineEdit::Password, QString(), &ok);

	if (!ok)
	{
		return;
	}

	if (userInput.isEmpty())
	{
		userInput = "null";
	}

	static_cast<void>(QMessageBox::information(this, tr("You enter password"), userInput, QMessageBox::Ok));
}

void GtSubWindow::addTextArea()
{

}

void GtSubWindow::clear()
{
	ui.subCentralwidget->deleteLater();
	ui.setupUi(this);
	x = 0;
	y = 0;
}

inline QString GtSubWindow::getInputStringImpl()
{
	bool ok = false;
	QString userInput = QInputDialog::getText(
		this, tr("GTerm Input Dialog"), tr("Please enter a String"), QLineEdit::Normal, QString(), &ok);

	if (!ok)
	{
		return QString();
	}

	if (userInput.isEmpty())
	{
		return tr("null");
	}

	return userInput;
}

inline bool GtSubWindow::isAddingOverFlow(int a, int b, int first, int second) noexcept
{
	return (a > 0 && a > std::numeric_limits<int>::max() - first) || (b > 0 && b > std::numeric_limits<int>::max() - second);
}

void GtSubWindow::initializeImageFileDialog(QFileDialog& dialog, QFileDialog::AcceptMode acceptMode)
{
	static bool firstDialog = true;

	if (firstDialog) 
	{
		firstDialog = false;
		const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
		dialog.setDirectory(picturesLocations.isEmpty() ? QDir::home() : picturesLocations.last());
	}

	QStringList mimeTypeFilters;
	const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
		? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();

	for (const QByteArray& mimeTypeName : supportedMimeTypes)
	{
		mimeTypeFilters.append(mimeTypeName);
	}

	mimeTypeFilters.sort();
	dialog.setMimeTypeFilters(mimeTypeFilters);
	dialog.selectMimeTypeFilter("image/jpeg");
	dialog.setAcceptMode(acceptMode);

	if (acceptMode == QFileDialog::AcceptSave)
	{
		dialog.setDefaultSuffix("jpg");
	}
}

/*
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
					reString += gtTab;
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
*/

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