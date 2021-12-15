#include "GTSubWindow.h"

#include <QColorDialog>
#include <QColorSpace>
#include <QFontDatabase>
#include <QFontDialog>
#include <QImageReader>
#include <QInputDialog>
#include <QMessageBox>
#include <QScreen>
#include <QScrollBar>
#include <QStandardPaths>
#include <QStringList>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableView>

#include <tuple>
#include <memory>
#include <optional>
#include <stdexcept>

#include "MyDialog.h"
#include "PreComRE.h"
#include "Version.h"

GtSubWindow::GtSubWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(),
	mX(),
	mY(),
	gtFont(QApplication::font()),
	gtFontMetrics(gtFont),
	gtTab(GTSPE::t),
	gtColor(Qt::black)
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
	input.replace(GTRE::findSlasht, gtTab);

	const auto height = gtFontMetrics.height();
	const auto width = gtFontMetrics.horizontalAdvance(input);
	if (mY > ui.scrollArea->height())
	{
		const auto newHeight = mY + height;
		ui.scrollAreaWidgetContents->setFixedHeight(newHeight);
		ui.scrollArea->verticalScrollBar()->setValue(newHeight);
	}

	const auto newLabel = new QLabel(ui.scrollAreaWidgetContents);

	newLabel->setText(input);
	newLabel->setFont(gtFont);
	newLabel->setStyleSheet(QStringLiteral("color: %1").arg(gtColor.name()));
	newLabel->setGeometry(mX, mY, width, height);
	newLabel->show();

	mX += width;
	if (mX > ui.scrollArea->width())
	{
		ui.scrollAreaWidgetContents->setFixedWidth(mX);
	}
}

void GtSubWindow::setNewLine()
{
	mX = 0;
	mY += gtFontMetrics.height();
	if (mY > ui.scrollArea->height())
	{
		ui.scrollAreaWidgetContents->setFixedHeight(mY);
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
	if (const auto userInput = getInputStringImpl(); !userInput.isEmpty())
	{
		QMessageBox::information(
			this, QStringLiteral("Show Message Dialog / Get Input String"), userInput, QMessageBox::Ok | QMessageBox::Cancel);
	}
}

void GtSubWindow::showErrorDialog()
{
	if (const auto userInput = getInputStringImpl(); !userInput.isEmpty())
	{
		static_cast<void>(QMessageBox::critical(this, QStringLiteral("Show Error Dialog"), userInput, QMessageBox::Ok));
	}
}

void GtSubWindow::showWarningDialog()
{
	if (const auto userInput = getInputStringImpl(); !userInput.isEmpty())
	{
		static_cast<void>(QMessageBox::warning(this, QStringLiteral("Show Warning Dialog"), userInput, QMessageBox::Ok));
	}
}
	
void GtSubWindow::setXY()
{
	if (const auto xY = MyDialog::getXY(); xY)
	{
		const auto &[x, y] = *xY;
		mX = x;
		mY = y;
	}
}

void GtSubWindow::setFontNameStyleSize()
{
	bool ok;
	const auto newFont = QFontDialog::getFont(&ok, gtFont, this, QStringLiteral("GTrem Font Chooser"));
	if (ok)
	{
		gtFont = newFont;
		gtFontMetrics = QFontMetrics(gtFont);
	}
}

void GtSubWindow::setFontColorRGB()
{
	if (const auto rgb = MyDialog::getRGB(); rgb)
	{
		const auto &[r, g, b] = *rgb;
		gtColor.setRgb(r, g, b);
	}
}

void GtSubWindow::setFontColorColorChooser()
{
	if (const auto color = QColorDialog::getColor(Qt::white, this, QStringLiteral("GTerm Color Chooser")); color.isValid())
	{
		gtColor = color;
	}
}

void GtSubWindow::setFontName()
{
	const auto newName = getInputStringImpl();
	if (newName.isEmpty())
	{
		return;
	}

	gtFont.setFamily(newName);
	gtFontMetrics = QFontMetrics(gtFont);
}

void GtSubWindow::setFontSize()
{
	const auto pointSizeList = QFontDatabase::pointSizes(gtFont.family(), gtFont.styleName());
	if (pointSizeList.isEmpty())
	{
		static_cast<void>(QMessageBox::critical(this, QStringLiteral("Error raise"), QStringLiteral("Size is empty."), QMessageBox::Ok));
		return;
	}

	bool ok;
	const auto newSize = QInputDialog::getInt(
				this, QStringLiteral("GTerm Font Size Chooser"), QStringLiteral("Please enter a font size"), 
		0, gtFont.pointSize(), pointSizeList.last(), 1, &ok);

	if (ok)
	{
		gtFont.setPointSize(newSize);
		gtFontMetrics = QFontMetrics(gtFont);
	}
}

void GtSubWindow::setFontStyle()
{
	



}

void GtSubWindow::setTabSize()
{
	bool ok;
	const auto newTabSize = static_cast<QString::size_type>(
		QInputDialog::getInt(this, QStringLiteral("Set Tab Size"), 
			QStringLiteral("Please enter a new tab size"), 1, 1, 50, 1, &ok));

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

	static_cast<void>(QMessageBox::information(this, QStringLiteral("File Path"), filePath, QMessageBox::StandardButton::Ok));
}

void GtSubWindow::setBackgroundColorColorChooser()
{
	if (const auto color = QColorDialog::getColor(Qt::white, this, QStringLiteral("GTerm Color Chooser")); color.isValid())
	{
		ui.subCentralwidget->setStyleSheet(QStringLiteral("background-color: %1").arg(color.name()));
	}
}

void GtSubWindow::setBackgroundColorRGB()
{
	if (const auto rgb  = MyDialog::getRGB(); rgb)
	{
		const auto &[r, g, b] = *rgb;
		ui.subCentralwidget->setStyleSheet(QStringLiteral("background-color: %1").arg(QColor(r, g, b).name()));
	}
}

void GtSubWindow::getFilePath()
{
	const auto filePath = QFileDialog::getSaveFileName(
		this, QString{}, QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

	if (filePath.isEmpty())
	{
		return;
	}

	static_cast<void>(QMessageBox::information(this, QStringLiteral("File Path"), filePath, QMessageBox::StandardButton::Ok));
}

void GtSubWindow::getPasswordFromDialog()
{
	bool ok;
	auto userInput = QInputDialog::getText(
		this, QStringLiteral("GTerm Password Dialog"), QStringLiteral("Please enter a Password"), QLineEdit::Password, QString(), &ok);

	if (!ok)
	{
		return;
	}

	[[unlikely]] if (userInput.isEmpty())
	{
		userInput = "null";
	}

	static_cast<void>(QMessageBox::information(this, QStringLiteral("You enter password"), userInput, QMessageBox::Ok));
}

void GtSubWindow::addTextArea()
{
	bool ok;
	const auto text = QInputDialog::getText(this, 
		tr("Enter default text"), tr("Enter default text"), QLineEdit::Normal, QString{}, &ok);
	if (!ok)
	{
		return;
	}

	const auto width = QInputDialog::getText(this,
		tr("Enter width"), tr("Enter width"), QLineEdit::Normal, QString{}, &ok);
	if (!ok)
	{
		return;
	}

	const auto widthInt = width.toInt(&ok);
	if (!ok)
	{
		QMessageBox::critical(this, tr("Not a digit or out of range."), tr("Not a digit or out of range."));
		return;
	}

	const auto height = QInputDialog::getText(this,
		tr("Enter height"), tr("Enter height"), QLineEdit::Normal, QString{}, &ok);
	if (!ok)
	{
		return;
	}

	const auto heightInt = height.toInt(&ok);
	if (!ok)
	{
		QMessageBox::critical(this, tr("Not a digit or out of range."), tr("Not a digit or out of range."));
		return;
	}

	QTextEdit* textEdit = nullptr;
	try
	{
		textEdit = new QTextEdit(ui.scrollAreaWidgetContents);
	}
	catch (const ::std::bad_alloc& e)
	{
		QMessageBox::critical(this, tr("Error."), tr(e.what()));
		return;
	}

	textEdit->setText(text);
	textEdit->setFont(gtFont);
	textEdit->setFixedSize(widthInt, heightInt);
	textEdit->setGeometry(mX, mY, textEdit->width(), textEdit->height());
	textEdit->show();

	mY += textEdit->height();
}

void GtSubWindow::clear()
{
	ui.subCentralwidget->deleteLater();
	ui.setupUi(this);
	mX = 0;
	mY = 0;
}

inline QString GtSubWindow::getInputStringImpl()
{
	bool ok = false;
	QString userInput = QInputDialog::getText(
		this, QStringLiteral("GTerm Input Dialog"), QStringLiteral("Please enter a String"), QLineEdit::Normal, QString(), &ok);

	if (!ok)
	{
		return QString{};
	}

	if (userInput.isEmpty())
	{
		return QStringLiteral("null");
	}

	return userInput;
}

QString GtSubWindow::getImagePath()
{
	QFileDialog dialog(this, tr("Open File"));

	const auto format = QImageReader::supportedMimeTypes();
	QStringList formatList;
	for (const auto& eachName : format)
	{
		formatList.emplaceBack(eachName);
	}

	formatList.sort();

	dialog.setMimeTypeFilters(formatList);
	dialog.selectMimeTypeFilter("image/jpeg");
	dialog.setAcceptMode(QFileDialog::AcceptOpen);
	dialog.setDirectory(QDir::currentPath());
	dialog.setWindowModality(Qt::ApplicationModal);

	return dialog.exec() == QDialog::Accepted ? dialog.selectedFiles().first() : QString{};
}

void GtSubWindow::addImageIcon()
{
	const auto filePath = getImagePath();
	if (filePath.isEmpty())
	{
		return;
	}

	QImageReader reader(filePath);
	reader.setAutoTransform(true);
	auto newImage = reader.read();
	if (newImage.isNull())
	{
		QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
			tr("Cannot load %1: %2")
			.arg(QDir::toNativeSeparators(filePath), reader.errorString()));
		return;
	}

	if (newImage.colorSpace().isValid())
	{
		newImage.convertToColorSpace(QColorSpace::SRgb);
	}

	QLabel* newLabel = nullptr;

	try
	{
		newLabel = new QLabel(ui.scrollAreaWidgetContents);
	}
	catch (const ::std::bad_alloc& e)
	{
		QMessageBox::critical(this, tr("Error."), tr(e.what()));
		return;
	}

	int newWidth = newImage.width();
	int newHeight = newImage.height();
	if (newImage.width() > width() || newImage.height() > height())
	{
		if (const auto button = QMessageBox::information(
			this, QGuiApplication::applicationDisplayName(),tr("Image too big. Resize?"),
			QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel); 
			button == QMessageBox::Ok)
		{
			newHeight = height() / 3 * 2;
			const double radio = static_cast<double>(newHeight) / newImage.height();
			newWidth = static_cast<int>(newWidth * radio);
			newImage = newImage.scaled(newWidth, newHeight);
		}
	}

	newLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	newLabel->setPixmap(QPixmap::fromImage(newImage));
	newLabel->setGeometry(mX, mY, newWidth, newHeight);
	newLabel->show();

	if (const auto temp = mX + newLabel->width(); temp > ui.scrollArea->width())
	{
		ui.scrollAreaWidgetContents->setFixedWidth(temp);
	}

	mY += newHeight;
	if (mY > ui.scrollArea->height())
	{
		ui.scrollAreaWidgetContents->setFixedHeight(mY);
	}
}

void GtSubWindow::addPasswordField()
{
	bool ok;
	const auto input =
		QInputDialog::getText(this, tr("Enter default text"), tr("Enter default text"), QLineEdit::Normal, QString{}, &ok);
	if (!ok)
	{
		return;
	}

	const auto width =
		QInputDialog::getText(this, tr("Enter width in pixel"), tr("Enter width in pixel"), QLineEdit::Normal, QString{}, &ok);
	if (!ok)
	{
		return;
	}

	const auto widthInt = width.toInt(&ok);
	if (!ok)
	{
		QMessageBox::critical(this, tr("Error."), tr("Out of range or not a digit."));
		return;
	}

	auto* qLineEdit = new QLineEdit(ui.scrollAreaWidgetContents);

	qLineEdit->setEchoMode(QLineEdit::Password);
	qLineEdit->setFixedWidth(widthInt);
	qLineEdit->setGeometry(mY, mY, qLineEdit->width(), qLineEdit->height());
	qLineEdit->setText(input);
	qLineEdit->setFont(gtFont);

	mY += qLineEdit->height();

	qLineEdit->show();
}

void GtSubWindow::addTable()
{
	
}

void GtSubWindow::addRowToTable()
{

}

void GtSubWindow::getIndexOfSelectedRowFromTable()
{

}

void GtSubWindow::getSelectedRowFromTable()
{

}

void GtSubWindow::resizeEvent(QResizeEvent* event)
{
	ui.subCentralwidget->setFixedSize(event->size());
	ui.scrollArea->setFixedSize(event->size());
	event->accept();
}

