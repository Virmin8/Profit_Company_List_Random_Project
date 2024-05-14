#include "companynonprofit.h"


CompanyNonProfit::CompanyNonProfit(QString n,QDate d,int i,bool t,bool p):Company(n,d,i,t)
{
    charitable = p;
}
bool CompanyNonProfit::getCharitable()
{
    return charitable;
}

CompanyNonProfit::~CompanyNonProfit(){}
