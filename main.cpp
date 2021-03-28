#include <QApplication>
#include "gtmain.h"

int main(int argc, char *argv[])
{
    QApplication gterm(argc, argv);
    gterm.setFont(QFont(QString("Microsoft YaHei UI")));
    QCoreApplication::setApplicationName(QString("GTerm"));
    QCoreApplication::setOrganizationName(QString("RMIT University"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    GtMain gtMain;
    gtMain.show();
    return gterm.exec();
}
