#pragma once
#ifndef GTSUB
#define GTSUB

#include <QMainWindow>
#include <QWidget>
#include <QFont>
#include <QFontMetrics>
#include <QVector>
#include <QPalette>
#include <QColor>
#include <QFileDialog>

//#include <tuple>
#include <memory>

#include "GTImageView.h"
#include "GTAboutDialog.h"
#include "ui_GTsubWindow.h"


class GtSubWindow final : public QMainWindow
{
    Q_OBJECT
	Q_DISABLE_COPY_MOVE(GtSubWindow)

public:
    explicit GtSubWindow(QWidget* parent = Q_NULLPTR);
	~GtSubWindow() override = default;

public slots:
	void print();
	void println();

private:
	void printImpl(QString& input);
	void setNewLine();

public slots:
	void getInputString();
	void showHelp();
	void showMessageDialog();
	void showErrorDialog();
	void showWarningDialog();
	void setXY();
	void setFontNameStyleSize();
	void setFontColorRGB();
	void setFontColorColorChooser();
	void setFontName();
	void setFontSize();
	void setFontStyle();
	void setTabSize();
	void setFilePath();
	void setBackgroundColorColorChooser();
	void setBackgroundColorRGB();
	void getFilePath();

	//void addImageIcon​();
	/*
	void addPasswordField();
	void addTable​();
	void addRowToTable();
	void getIndexOfSelectedRowFromTable​();
	void getSelectedRowFromTable();
	*/

	void getPasswordFromDialog();
	void addTextArea();
	void clear();

private:
	Ui::GTSubWindow ui;
	int x;
	int y;
	std::unique_ptr<QFont> gtFont;
	std::unique_ptr<QFontMetrics> gtFontMetrics;
	QString gtTab;
	std::unique_ptr<QColor> gtColor;
	inline QString getInputStringImpl();
	inline static bool isAddingOverFlow(int a, int b, int first, int second) noexcept;
	static void initializeImageFileDialog(QFileDialog& dialog, QFileDialog::AcceptMode acceptMode);

	// inline std::tuple<QString::size_type, QString::size_type, QString> calNumOfStAndSn(const QString &string);
};

#endif // GTSUB