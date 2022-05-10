#ifndef BACKENDCLASS_H
#define BACKENDCLASS_H

#include <QObject>
#include "favouritelist.h"
class BackendClass : public QObject
{
    Q_OBJECT
public:
    explicit BackendClass(QObject *parent = nullptr);

signals:

};

#endif // BACKENDCLASS_H
