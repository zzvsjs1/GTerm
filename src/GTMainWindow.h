#ifndef GTMAIN
#define GTMAIN

#include <QMainWindow>
#include <QPointer>

#include "gtSubWindow.h"
#include "ui_GTMainWindow.h"

class GtMain final: public QMainWindow
{
    Q_OBJECT
	Q_DISABLE_COPY_MOVE(GtMain)

public:
    explicit GtMain(QWidget* parent = Q_NULLPTR);
    ~GtMain() override = default;

public slots:
    void menuSystemAboutAction();
    void menuSystemAboutQtAction();
    void newGTermBtn();

private:
    Ui::GTMainWindow ui;
    GtSubWindow* gtSubWindow;
    void resetBtnState() noexcept;
    void connectSignalToSubWin();
    void deleteGTSub() noexcept;
};
#endif // GTMAIN
