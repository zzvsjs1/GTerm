#include <QApplication>
#include "gtmain.h"

int main(int argc, char *argv[])
{
    QApplication gterm(argc, argv);

#ifdef _WIN32
    gterm.setFont(QFont(QString("Arial")));
#elif __APPLE__
    gterm.setFont(QFont(QString("Helvetica")));
#endif

    QCoreApplication::setApplicationName(QString("GTerm"));
    QCoreApplication::setOrganizationName(QString("RMIT University"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    GtMain gtMain;
    gtMain.show();
    return gterm.exec();
}
