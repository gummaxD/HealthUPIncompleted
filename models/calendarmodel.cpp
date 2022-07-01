#include "calendarmodel.h"


CalendarModel::CalendarModel(const QDate q)
    : dataCorrente(q),
      currentGiorno(nullptr)
{
    //  viene creato il nuovo giorno a partire dalla data
    Giorno* t = new Giorno(q);
    //  il giorno viene inserito nel vettore dei giorni
    giorni.push_back(t);
    //  current viene settato al nuovo giorno creato
    currentGiorno = t;
}

CalendarModel::~CalendarModel(){
    for (auto p : giorni)
        delete p;
    delete currentGiorno;
}

/*void CalendarModel::AggiungiItem(const Piatto &p, unsigned int grams, Item::Tipo tipo){
    // INVARIANTE: so già che current punta sempre a qualcosa di valido
    //             quindi evito di fare il controllo su currentGiorno
    currentGiorno->AggiungiItem(new Item(p,grams,tipo));
}*/

void CalendarModel::AggiungiItem(const QString nome, unsigned int grams, Item::Tipo tipo){
    currentGiorno->AggiungiItem(new Item(*(Piatti::getPiatto(nome)),grams,tipo));

}

void CalendarModel::setData(QDate d){
    //setto la data
    dataCorrente = d;
    //cerco se esiste il giorno la data "d"
    bool trovato = false;
    for (auto it = giorni.begin(); it!= giorni.end() && !trovato; ++it){
        if((**it).getData() == d){
            //mi ricordo che l'ho trovato
            trovato = true;
            //setto il current = al giorno con la data "d"
            currentGiorno = *it;
        }
    }
    //se non l'ho trovato devo creare un nuovo giorno e aggiungerlo al vettore dei giorni
    if (!trovato){
        // creo il nuovo giorno
        Giorno* t = new Giorno(d);
        // inserisco il giorno nel vettore dei giorni
        giorni.push_back(t);
        // setto il current al giorno appena creato
        currentGiorno = t;
    }
}

const QDate& CalendarModel::getData()const{
    return dataCorrente;
}

unsigned int CalendarModel::CarbsGiornalieri()const{
    return currentGiorno->CarboidratiTotali();
}

Giorno* CalendarModel::getCurrentGiorno()const{
    return currentGiorno;
}










