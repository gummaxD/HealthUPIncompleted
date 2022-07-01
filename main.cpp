#include "mainwindow.h"
#include <QApplication>
#include "views/calendarview.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    CalendarView* cw = new CalendarView();
    cw->show();



    return a.exec();
}
