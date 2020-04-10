#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DApplicationSettings>
#include <QDebug>
#include "chooseISO.h"
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
   // a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("帮助");
    a.setApplicationVersion("s1.0.4");
    a.setProductIcon(QIcon::fromTheme("iso_logo"));
    a.setProductName("ISO定制工具");
    a.setApplicationDescription("ISO定制工具是通信提供给装机厂商的一款系统镜像定制工具。");
    a.setWindowIcon(QIcon::fromTheme("iso_logo"));

    //主题记忆
    DApplicationSettings savetheme;
    qDebug()<<"1111111";

    mainwindow w;

//    w.setMinimumSize(800, 600);
    w.setFixedSize(800, 600);

    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
