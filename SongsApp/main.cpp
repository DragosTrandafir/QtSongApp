#include "SongsApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SongRepo songRepo{};
    SongController songController{ songRepo };

    MainWindow w{ songController };

    w.show();
    return a.exec();
}
