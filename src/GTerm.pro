QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    main.cpp \
    gtMain.cppain.cpp \
    gtSubWindow.cpp \
    gtAboutDialog.cpp \
    Version.cpp


HEADERS += \
    gtMain.h \
    gtSubWindow.h \
    gtAboutDialog.h \
    Version.cpp

TRANSLATIONS += \
    GTerm_en_AU.ts

RESOURCES += \
    gtResource.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
