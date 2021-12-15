#pragma once
#ifndef GTRGB_CHOOSER
#define GTRGB_CHOOSER

#include <QDialog>
#include <tuple>

#include "ui_GTRGBChooser.h"

class GTRGBChooser final : public QDialog
{
	Q_OBJECT
	Q_DISABLE_COPY_MOVE(GTRGBChooser)

public:

	explicit GTRGBChooser(QWidget* parent = Q_NULLPTR)
	: QDialog(parent), ui()
	{
		ui.setupUi(this);
	}

	GTRGBChooser(QWidget* parent, const int r, const int g, const int b)
		: GTRGBChooser(parent)
	{
		ui.R->setValue(r);
		ui.G->setValue(g);
		ui.B->setValue(b);
	}

	~GTRGBChooser() override = default;

	[[nodiscard]] std::tuple<int, int, int> getRGB() const
	{
		return { ui.R->value(), ui.G->value(), ui.B->value() };
	}

private:

	Ui::GTermRGBChooser ui;

};
#endif // !GTRGB_CHOOSER
