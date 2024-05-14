#ifndef COMPANYPROFIT_H
#define COMPANYPROFIT_H
#include "company.h"

class CompanyProfit : public Company
{
    Q_OBJECT

public:
    CompanyProfit(QString,QDate,int,bool);
    ~CompanyProfit();

};

#endif // COMPANYPROFIT_H
