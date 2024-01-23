#ifndef ISAUVEGARDER_H
#define ISAUVEGARDER_H

#include <QJsonArray>
#include <QString>

class ISauvegarder {
public :
    virtual void Sauvegarder() const = 0;
    virtual void Charger(const QJsonArray&, const QString&) = 0;
    virtual ~ISauvegarder() = default;

};

#endif // ISAUVEGARDER_H


