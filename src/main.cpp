#include <QApplication>
#include <QFontDatabase>

#include "GTMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication GTerm(argc, argv);

    const auto id = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/segoeui.ttf");
    if (id == -1)
    {
#ifdef WIN32
	    QApplication::setFont(QFont(QString("Segoe UI"), 12));
#elif __APPLE__
        GTerm.setFont(QFont(QString("SF Pro"), 12));
#endif
    }
    else
    {
	    QApplication::setFont(QFont(QFontDatabase::applicationFontFamilies(id).at(0), 12));
    }

    QCoreApplication::setApplicationName(QString("GTerm"));
    QCoreApplication::setOrganizationName(QString("RMIT University"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    GTMainWindow gtMain;
    gtMain.show();

    return QApplication::exec();
}
