#include <QApplication>
#include <QRegularExpression>

#include "gtMain.h"

int main(int argc, char *argv[])
{
    QApplication GTerm(argc, argv);

#ifdef _WIN32
    GTerm.setFont(QFont(QString("Segoe UI")));
#elif __APPLE__
    GTerm.setFont(QFont(QString("Helvetica")));
#endif


    QCoreApplication::setApplicationName(QString("GTerm"));
    QCoreApplication::setOrganizationName(QString("RMIT University"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    GtMain gtMain;
    gtMain.show();
    return GTerm.exec();
}
