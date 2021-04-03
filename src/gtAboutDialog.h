#pragma once

#include <QDialog>

class GtAboutDialog final : public QDialog
{
	Q_OBJECT
public:
	explicit GtAboutDialog(QWidget* parent = nullptr);
};