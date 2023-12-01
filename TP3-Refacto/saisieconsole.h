#ifndef SAISIECONSOLE_H
#define SAISIECONSOLE_H


#include <iostream>
#include <limits>

class SaisieConsole
{
public:
    static std::string getString(const std::string& message);
    static int getInt(const std::string&);
private:
    static void ViderBuffer();
};

#endif // SAISIECONSOLE_H
