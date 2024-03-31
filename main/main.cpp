#include "main/presentation/ui/appWindow/AppWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppWindow w;
    w.show();
    return a.exec();
}
