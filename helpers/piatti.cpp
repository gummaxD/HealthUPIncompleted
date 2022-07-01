#include "piatti.h"
Piatti::Piatti(){}

Piatti& Piatti::getIstance(){
    static Piatti instance;
    return instance;
}

Piatto* Piatti::getPlate(QString s) const{
    for (auto it = plates.begin(); it!= plates.end(); ++it){
        if((**it).getNome() == s)
            return *it;
    }
    return nullptr;
}

Piatto* Piatti::getPiatto(QString s){
  return getIstance().getPlate(s);
}

Piatti::~Piatti(){
    for (auto p : plates)
        delete p;
}
