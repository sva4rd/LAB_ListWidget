#include "listswidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListsWidget window;
    window.setWindowTitle("ListsWidget");
    window.resize(600,400);
    window.show();
    return a.exec();
}
