#ifndef ITEM_H
#define ITEM_H

#include "models/piatto.h"


class Item
{
public:
    /**
     * @brief Tipo rappresenta il tipo del pasto
     */
    enum Tipo
    {
        COLAZIONE, ///< Pasto consumato durante la colazione
        PRANZO,    ///< Pasto consumato durante il pranzo
        CENA,      ///< Pasto consumato durante la cena
        SNACK,     ///< Pasto consumato durante la giornata che non sia colazione, pranzo o cena
    };

    /**
     * @brief Costruttore per l'item
     * @param "p" è il piatto usato per costuire il l'oggetti dell'item che verrà presso
     *          dalla lista di Piatti caricati da file
     * @param "grams" grammi mangiati
     * @param "tipo" speficatore del tipo di pasto
     */
    explicit Item(const Piatto& p, unsigned int grams, Tipo tipo);

    /**
     * @brief Controlla se due item hanno lo stesso nome del piatto e lo stesso tipo di tipo
     *         Usa anche l'"operator ==" del pasto
     * @param "i" item passato per vedere se è uguale
     * @return true sse l'item ha lo stesso piatto e lo stesso tipo ( non controlla i grammi)
     */
    bool operator==(const Item& i)const;

    unsigned int getGrammi() const;
    Tipo getTipo() const;
    const Piatto& getPiatto()const;
    void setGrammi(unsigned int grams);
    void setTipo(Tipo type);

    /**
     * @brief Calcola i carboidrati del piatto in corrispondenza dei grammi mangiati
     * @return carboidrati del pasto
     */
    unsigned int calcolaCarbs() const;

    /**
     * @brief Calcola i grassi del piatto in corrispondenza dei grammi mangiati
     * @return grassi del pasto
     */
    unsigned int calcolaGrassi() const;

    /**
     * @brief Calcola le proteine del piatto in corrispondenza dei grammi mangiati
     * @return proteine del pasto
     */
    unsigned int calcolaProteine() const;

private:
    Piatto       mPiatto;
    unsigned int mGrammi;
    Tipo         mTipo;
};

#endif // ITEM_H


