#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include "views/view.h"

//classe astratta
class ChartView: public View
{
public:
    explicit ChartView(View *parent = nullptr);
    virtual void showChart() const = 0;
};

#endif // CHARTVIEW_H
