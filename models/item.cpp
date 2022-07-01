#include "item.h"

Item::Item(const Piatto& pi,unsigned int grams,Tipo tipo)
    : mPiatto(pi),
      mGrammi(grams),
      mTipo(tipo){}

unsigned int Item::getGrammi() const{
    return mGrammi;
}

Item::Tipo Item::getTipo() const{
    return mTipo;
}

void Item::setGrammi(unsigned int grams){
    mGrammi = grams;
}

void Item::setTipo(Item::Tipo type){
    mTipo = type;
}

const Piatto& Item::getPiatto() const{
    return mPiatto;
}

bool Item::operator==(const Item& i) const{
    return mPiatto == i.getPiatto() &&
           mTipo == i.mTipo;
}

unsigned int Item::calcolaCarbs() const{
    return ((mGrammi * mPiatto.getCaroidrati())/100);
}

unsigned int Item::calcolaGrassi() const{
    return ((mGrammi * mPiatto.getGrassi())/100);
}

unsigned int Item::calcolaProteine() const{
    return ((mGrammi * mPiatto.getProteine())/100);
}
