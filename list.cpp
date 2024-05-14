#include "list.h"

list::list()
{
}
void list::addCompany(QObject* _company)
{

    const QMetaObject *mo = _company->metaObject();
    QString tmp = mo->className();
    if(tmp == "CompanyNonProfit")
    {
       companynonList.append(_company);
    }
    else if(tmp == "CompanyProfit")
    {
        companyproList.append(_company);
    }
}
QList<QObject*> list::getCompany(QString comp)
{
    if(comp == "profit")
    {
        return companyproList;
    }
    else if(comp == "non")
    {
        return companynonList;
    }

}
