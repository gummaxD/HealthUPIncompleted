#include "view.h"

View::View(View *parent) : QWidget(parent,Qt::Window){

}

/*View::View(const QString &t, QWidget *parent)
    : QWidget(parent)
{}*/

void View::setTitolo(const QString &t){
    setWindowTitle(t);
}

View::~View(){
    setParent(nullptr);
}

