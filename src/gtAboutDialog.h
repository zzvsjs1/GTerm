#pragma once
#ifndef GTABOUTDIALOG
#define GTABOUTDIALOG
#include <QDialog>

class GTAboutDialog final : public QDialog
{
	Q_OBJECT
	Q_DISABLE_COPY_MOVE(GTAboutDialog)

public:
	explicit GTAboutDialog(QWidget* parent = Q_NULLPTR);
};

#endif // GTABOUTDIALOG
