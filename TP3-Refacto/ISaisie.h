#ifndef ISAISIE_H
#define ISAISIE_H

#include <string>

class ISaisie {
public:
    virtual std::string getString(const std::string&) const = 0;
    virtual int getInt(const std::string&) const = 0;
};

#endif // ISAISIE_H
