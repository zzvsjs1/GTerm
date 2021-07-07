#pragma once
#ifndef GTSUB
#define GTSUB

#include <QMainWindow>
#include <QWidget>

#include "gtImageView.h"
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
	QString getInputString();

private:
	Ui::GTSubWindow ui;
	int x;
	int y;

};

#endif // GTSUB