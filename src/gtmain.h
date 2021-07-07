#ifndef GTMAIN
#define GTMAIN

#include <QMainWindow>

#include "gtSubWindow.h"
#include "ui_GTMainWindow.h"

class GtMain final: public QMainWindow
{
    Q_OBJECT
	Q_DISABLE_COPY_MOVE(GtMain)

public:
    GtMain(QWidget* parent = Q_NULLPTR);
    ~GtMain()override = default;

public slots:
    void menuSystemAboutAction();
    void menuSystemAboutQtAction();
    void newGTermBtn();
    void closeGtSub();

private:
    Ui::GTMainWindow ui;
    GtSubWindow* gtSubWindow;
    void connectGTWindowSignal();
};
#endif // GTMAIN
