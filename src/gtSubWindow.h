#pragma once
#ifndef GTSUB
#define GTSUB

#include <QMainWindow>
#include <QWidget>
#include <QFont>
#include <QFontMetrics>
//#include <tuple>
#include <memory>

#include "gtImageView.h"
#include "gtAboutDialog.h"
#include "ui_GTsubWindow.h"

class GtSubWindow final : public QMainWindow
{
    Q_OBJECT
	Q_DISABLE_COPY_MOVE(GtSubWindow)

public:
    explicit GtSubWindow(QWidget* parent = Q_NULLPTR);
	~GtSubWindow() override;

public slots:
	void print();
	void println();

private:
	void printImpl(QString& input);
	void printlnImpl(QString& input);

public slots:
	void getInputString();
	void showHelp();
	void showMessageDialog();
	void showErrorDialog();
	void showWarningDialog();
	void setXY();

private:
	Ui::GTSubWindow ui;
	int x;
	int y;
	std::unique_ptr<QFont> gtFont;
	std::unique_ptr<QFontMetrics> gtFontMetrics;
	inline QString getInputStringImpl();
	// inline std::tuple<QString::size_type, QString::size_type, QString> calNumOfStAndSn(const QString &string);

};

#endif // GTSUB