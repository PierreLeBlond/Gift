#include <QApplication>
#include <mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* fenetre = new MainWindow(0);

    fenetre->show();

    return a.exec();
}
