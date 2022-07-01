#include "giorno.h"

Giorno::Giorno(const QDate d): mData(d)
{}

Giorno::~Giorno(){
    for (auto i : mItems)
        delete i;
}
/*void Giorno::AggiungiItem(Item *i){

    if(!mItems.isEmpty()){  //controllo che non sia vuota

        auto it = mItems.begin();
        bool trovato = false;

        for (; it != mItems.end() && !trovato; ++it){
            //controllo che non l'item non esita (controllo sia piatto che tipo di pasto)
            if ((**it).getPiatto() == i->getPiatto() && (**it).getTipo() == i->getTipo()){
                //Faccio la somma dei grammi del piatto nella lista con i grammi del piatto che voglio aggiungere
                (**it).setGrammi((**it).getGrammi() + i->getGrammi());
                //Mi salvo il fatto che l'ho trovato così da non andare fino in fondo
                trovato = true;
            }
         }
        //se non l'ho trovato posso aggiungerlo alla lista
        if (trovato == false)
            mItems.push_back(i);
     }
    //se è vuota aggiungo direttamente l'item
    else
        mItems.push_back(i);
}*/

void Giorno::AggiungiItem(Item *i){

    if(!mItems.isEmpty()){  //controllo che non sia vuota

        bool trovato = false;

        for (auto it = mItems.begin(); it != mItems.end() && !trovato; ++it){
            //controllo che non l'item non esita (controllo sia piatto che tipo di pasto)
            if (**it == *i){
                //Faccio la somma dei grammi del piatto nella lista con i grammi del piatto che voglio aggiungere
                (**it).setGrammi((**it).getGrammi() + i->getGrammi());
                //Mi salvo il fatto che l'ho trovato così da non andare fino in fondo
                trovato = true;
            }
         }
        //se non l'ho trovato posso aggiungerlo alla lista
        if (trovato == false)
            mItems.push_back(i);
     }
    //se è vuota aggiungo direttamente l'item
    else
        mItems.push_back(i);
}



QList<Item*>& Giorno::getItemsList(){
    return mItems;
}
void Giorno::RimuoviItem(Item* i){
    if(!mItems.isEmpty()){
        for (auto it = mItems.begin(); it != mItems.end(); ++it){
            if (**it == *i){
                //elimino l'elemento puntato dall' iteratore
                delete *it;
                //rimuovo il puntatore dalla lista
               mItems.erase(it);
            }
        }
    }
}

const QDate& Giorno::getData() const{
    return mData;
}

unsigned int Giorno::CarboidratiTotali()const{
    unsigned int n = 0;

    // se la lista degli items è vuota non devo calcolare nulla
    if(!mItems.empty()){
        for (auto it : mItems)
            n += it->calcolaCarbs();
    }
    return n;
}

unsigned int Giorno::GrassiTotali()const{
    unsigned int n = 0;

    if (!mItems.empty()){
        for (auto it : mItems)
            n += it->calcolaGrassi();
    }
    return n;
}

unsigned int Giorno::ProteineTotali()const{
    unsigned int n = 0;

    if (!mItems.empty()){
        for (auto it : mItems)
            n += it->calcolaProteine();
    }
    return n;
}












