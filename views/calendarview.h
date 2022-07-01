#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QCalendarWidget>
#include <QGroupBox>
#include <QDate>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTableWidget>
#include <QSpinBox>
#include <QPushButton>

#include "views/view.h"

class CalendarView : public View
{
    Q_OBJECT
public:
    CalendarView(View* parent = nullptr);
    /**
     * @brief Distruttore di CalendarView profondo che cancella tutti i layouts creati
     *  nel costruttore, i quali se lasciati li potrebbero creare memory leak
     */
    virtual ~CalendarView();

protected:
    void connettiSignals()const override;
private:
    QVBoxLayout* mainLayout;

    QMenuBar*        barraMenu;
    QMenu*           menuFile;
    QAction*         apri;
    QAction*         salva;
    QMenu*           menuGrafici;
    QAction*         grafico1;
    QAction*         grafico2;
    QAction*         grafico3;
    QCalendarWidget* calendario;
    QGroupBox*       GPcolazione;
    QGroupBox*       GPpranzo;
    QGroupBox*       GPcena;
    QGroupBox*       GPaggiungiPasto;
    QComboBox*       CBpiatto;
    QSpinBox*        SBgrammi;
    QComboBox*       CBtipo;
    QTableWidget*    TWcolazione;
    QTableWidget*    TWpranzo;
    QTableWidget*    TWcena;
    QPushButton*     PBAggiungi;

    QList<QLayout*>  layouts;
};

#endif // CALENDARVIEW_H
