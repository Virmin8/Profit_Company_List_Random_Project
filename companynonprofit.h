#ifndef COMPANYNONPROFIT_H
#define COMPANYNONPROFIT_H
#include "company.h"

class CompanyNonProfit : public Company
{
    Q_OBJECT
        Q_PROPERTY(bool charitable READ getCharitable)

public:
    CompanyNonProfit(QString,QDate,int,bool,bool);
    ~CompanyNonProfit();
    bool getCharitable();


private:
    bool charitable;

};

#endif // COMPANYNONPROFIT_H
