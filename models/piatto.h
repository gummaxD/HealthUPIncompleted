#ifndef PIATTO_H
#define PIATTO_H

#include <QString>

class Piatto
{
public:
    explicit Piatto(const QString& nome, const int cal, const int carbs, const int grassi, const int prot);
    /**
     * @brief Server per controllare se due piatti sono uguali. Viene usata quando controlliamo
     *        che due items siamo uguali
     * @param "p" parametr
     * @return true sse "p" è uguale al piatto di invocazione
     */
    bool operator==(const Piatto& p) const;

    //GETTERs
    const QString& getNome() const;
    unsigned int getCalorie() const;
    unsigned int getCaroidrati() const;
    unsigned int getGrassi() const;
    unsigned int getProteine() const;



private:
    const QString      mNome;
    const unsigned int mCalorie;
    const unsigned int mCarboidrati;
    const unsigned int mGrassi;
    const unsigned int mProteine;

};

#endif // PIATTO_H
