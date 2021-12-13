#pragma once
#ifndef SETXYDIALOG
#define SETXYDIALOG

#include <QDialog>
#include <QPair>
#include <memory>

#include "ui_SetXYDialog.h"

class SetXYDialog final : public QDialog
{
	Q_OBJECT

public:

	explicit SetXYDialog(QWidget* parent = Q_NULLPTR)
		: QDialog(parent), ui()
	{
		ui.setupUi(this);
	}

	~SetXYDialog() override = default;

	[[nodiscard]] QPair<int, int> getXY() const
	{
		return { ui.X->value() , ui.Y->value() };
	}

private:

	Ui::SetXYDialog ui;
};

#endif // !SETXYDIALOG
