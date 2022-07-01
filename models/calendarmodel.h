#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H


#include"models/giorno.h"
#include "models/model.h"
#include "models/item.h"
#include "helpers/piatti.h"

#include <QVector>
#include <QDate>

class CalendarModel : public Model
{
public:
    /**
     * @brief Crea un nuovo Model a partire da una data
     *        Ovviamente la prima volta che si crea un modello il vettore dei giorni sarà vuoto
     *        quindi viene creato il nuovo un nuovo giorno, viene aggiunto alla lista dei giorni
     *        e current viene fatto puntare al nuovo giorno creato
     *
     * @param q: data nel nuovo giorno creato
     */
    explicit CalendarModel(const QDate q);
    CalendarModel& operator =(const CalendarModel&) = delete;
    CalendarModel (const CalendarModel&) = delete;

    ~CalendarModel() override;


    //void AggiungiItem(const Piatto& p, unsigned int grams, Item::Tipo tipo);

    /**
     * @brief Aggiunge un item al giornoCorrente
     *
     * @param "nome" nome del piatto
     * @param "grams" grammi mangiati
     * @param "tipo" tipo del pasto
     */
    void AggiungiItem(const QString nome, unsigned int grams, Item::Tipo tipo);


    /**
     * @brief imposto la data corrente = alla data "d" e cerco all'interno del vettore dei
     *        giorni se esiste un giorno con la stessa data "d", se ci fosse allora
     *        setto il currentGiorno = al giorno con la stessa data nel vettore
     *        In caso negativo creo un nuovo giorno con la data d
     *
     * @param "d" data che voglio impostare alla dataCorrente
     */
    void setData(QDate d);
    const QDate& getData()const;
    unsigned int CarbsGiornalieri()const;
    Giorno* getCurrentGiorno()const;

private:
    QVector<Giorno*> giorni;

    QDate dataCorrente;
    //  giorno dove andrò a fare le modifiche
    Giorno* currentGiorno;


};

#endif // CALENDARMODEL_H
