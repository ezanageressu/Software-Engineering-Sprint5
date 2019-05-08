#include "welcomescreen.h"
#include <QApplication>


/**
 * @param argc
 * @param argv
 * @return app.exec()
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow welcomescreen;
    welcomescreen.show();
    return a.exec();
}
