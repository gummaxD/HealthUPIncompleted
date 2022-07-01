#ifndef GIORNO_H
#define GIORNO_H

#include<QDate>
#include<QList>
#include <models/item.h>
#include<QString>



class Giorno
{
public:
    explicit Giorno(const QDate);

    unsigned int CalorieTotali() const;

    /**
     * @brief Calcola  i carboidrati assunti in un giorno
     * @return carboidrati assunti in un giorno
     */
    unsigned int CarboidratiTotali() const;

    /**
     * @brief Calcola tutti i grassi assunti in un giorno
     * @return grassi assunti in un giorno
     */
    unsigned int GrassiTotali() const;

    /**
     * @brief Calcola le proteine assunte in un giorno
     * @return proteine assunte in un giorno
     */
    unsigned int ProteineTotali() const;

    //distruttore profondo
    ~Giorno();


    //Giorno(const Giorno&) = delete;
    //Giorno& operator =(const Giorno&) = delete;

    /**
     * @brief Aggiunge un item nella lista. Se un item con lo stesso piatto e lo stesso tipo, l'item non
     *        viene aggiungo, ma bensì viene modificata la quantità di grammi dell'item presente nella lista
     *
     * @param i: item che si vuole aggiungere
     */
    void AggiungiItem(Item* i);

    /**
     * @brief Rimuove un item dalla lista degli item
     * @param i: item che si vuole rimuovere dalla lista
     */
    void RimuoviItem(Item* i);

    /**
     * @brief Per iterare la lista degli item all'interno, prima bisogna salvare la lista e poi
     *        si può usare l'iterator
     *
     * @return ritorna la lista delgli item del giorno corrente per riferimento
     */
    QList<Item*>& getItemsList();


    const QDate& getData() const;

private:
    QDate        mData;
    QList<Item*> mItems;
};

#endif // GIORNO_H
