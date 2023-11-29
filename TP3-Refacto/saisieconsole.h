#ifndef SAISIECONSOLE_H
#define SAISIECONSOLE_H


#include "ISaisie.h"
#include <iostream>
#include <limits>

class SaisieConsole : public ISaisie
{
public:
    std::string getString(const std::string& message) const;
    int getInt(const std::string&) const;
private:
    void ViderBuffer() const;
};

#endif // SAISIECONSOLE_H
