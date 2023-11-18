#ifndef IJEU_H
#define IJEU_H

class IJeu {
public:
    virtual void jouer() = 0;
    virtual ~IJeu() = default;
    virtual bool aGagne(char jeton) const = 0;
    virtual bool estEgalite() const = 0;
};

#endif // IJEU_H
