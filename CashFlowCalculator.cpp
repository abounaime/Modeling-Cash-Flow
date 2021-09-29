#include "CashFlowCalculator.h"
#include <cmath>
#include <iostream>
CashFlowCalculator::CashFlowCalculator(double rate)
:m_rate(rate)
{
}

CashFlowCalculator::CashFlowCalculator(const CashFlowCalculator &v)
:m_rate(v.m_rate)
{
}

CashFlowCalculator &CashFlowCalculator::operator=(const CashFlowCalculator &v)
{
    if(this != &v){
        this->m_rate = v.m_rate;
        this->m_cashPayments = v.m_cashPayments;
        this->m_numberPeriods = v.m_numberPeriods;
    }
    return *this;
}

CashFlowCalculator::~CashFlowCalculator()
{
}

void CashFlowCalculator::addCashPayement(double value, int timePeriod){
    m_numberPeriods.push_back(timePeriod);
    m_cashPayments.push_back(value);
}

double CashFlowCalculator::presentValue(double futureValue, int timePeriod){
    double pValue = futureValue / pow(1+m_rate,timePeriod);
    std::cout << " value " << pValue << std::endl;
    return pValue;
}
double CashFlowCalculator::presentValue (){
    double total = 0;
    for(int i=0; i< m_cashPayments.size(); ++i){
        total += presentValue(m_cashPayments[i], m_numberPeriods[i]);
    }
    return total;   
}
