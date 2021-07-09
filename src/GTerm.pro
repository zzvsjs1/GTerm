QT       += core widgets gui

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    main.cpp \
    GTMainWindow.cpp \
    GTSubWindow.cpp \
    GTAboutDialog.cpp \
    MyDialog.cpp \
    GTImageView.cpp


HEADERS += \
    SetXYDialog.h \
    Version.h \
    PreComRE.h \
    MyDialog.h \
    GTSubWindow.h \
    GTMainWindow.h \
    GTImageView.h \
    GTAboutDialog.h

TRANSLATIONS += \
    GTerm_en_AU.ts

RESOURCES += \
    gtResource.qrc

RC_ICONS = /gtres/resources/logo/java.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
