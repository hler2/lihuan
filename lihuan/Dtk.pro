QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dtk
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    chooseISO.cpp \
    selectframe.cpp \
    programconfiguration.cpp \
    preparation.cpp \
    midinstallation.cpp \
    postcleaning.cpp \
    choosekermel.cpp \
    output.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    chooseISO.h \
    selectframe.h \
    programconfiguration.h \
    preparation.h \
    midinstallation.h \
    postcleaning.h \
    choosekermel.h \
    output.h

DISTFILES +=

CONFIG(release, debug|release) {
TRANSLATIONS = $$files($$PWD/translations/*.ts)
#遍历目录中的ts文件，调用lrelease将其生成为qm文件
for(tsfile, TRANSLATIONS) {
qmfile = $$replace(tsfile, .ts$, .qm)
system(lrelease $$tsfile -qm $$qmfile) | error("Failed to lrelease")
}
#将qm文件添加到安装包
dtk_translations.path = /usr/share/$$TARGET/translations
dtk_translations.files = $$PWD/translations/*.qm
INSTALLS += dtk_translations
}
