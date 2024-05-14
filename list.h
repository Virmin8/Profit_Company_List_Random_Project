#ifndef LIST_H
#define LIST_H
#include "company.h"
#include <QList>

class list
{
public:
    list();
    void addCompany(QObject*);
    QList<QObject*> getCompany(QString);
private:
    QList<QObject*> companynonList;
    QList<QObject*> companyproList;
};

#endif // LIST_H
