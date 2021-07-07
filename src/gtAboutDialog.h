#pragma once
#ifndef GTABOUTDIALOG
#define GTABOUTDIALOG
#include <QDialog>

class GtAboutDialog final : public QDialog
{
	Q_OBJECT
public:
	explicit GtAboutDialog(QWidget* parent = nullptr);
};

#endif // GTABOUTDIALOG
