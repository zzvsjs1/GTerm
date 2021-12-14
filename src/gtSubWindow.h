#pragma once
#ifndef GTSUB
#define GTSUB

#include <QWidget>
#include <QFont>
#include <QFontMetrics>
#include <QVector>
#include <QColor>
#include <QFileDialog>
#include <QResizeEvent>

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
	void addImageIcon();

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
	int mX;
	int mY;
	QFont gtFont;
	QFontMetrics gtFontMetrics;
	QString gtTab;
	QColor gtColor;

	inline QString getInputStringImpl();
	QString getImagePath();
	void resizeEvent(QResizeEvent* event) override;

};

#endif // GTSUB