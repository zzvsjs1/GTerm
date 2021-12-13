#ifndef GTMAIN
#define GTMAIN

#include "GTSubWindow.h"
#include "ui_GTMainWindow.h"

class GTMainWindow final: public QMainWindow
{
    Q_OBJECT
	Q_DISABLE_COPY_MOVE(GTMainWindow)

public:

    explicit GTMainWindow(QWidget* parent = Q_NULLPTR);
    ~GTMainWindow() override = default;

public slots:

    void menuSystemAboutAction();
    void menuSystemAboutQtAction();
    void newGTermBtn();

private:

    Ui::GTMainWindow ui;
    GtSubWindow* gtSubWindow;
    void resetBtnState() noexcept ;
    void connectSignalToSubWin();
    void deleteGTSub() noexcept;

};
#endif // GTMAIN
