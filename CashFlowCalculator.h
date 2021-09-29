#include "vector"
class CashFlowCalculator
{
private:
    /* data */
    double m_rate;
    std::vector <int> m_numberPeriods;
    std::vector <double> m_cashPayments;
    double presentValue(double futureValue, int timePeriod);
public:
    CashFlowCalculator(double rate);
    CashFlowCalculator(const CashFlowCalculator &v);
    CashFlowCalculator &operator=(const CashFlowCalculator &v);
    ~CashFlowCalculator();
    void addCashPayement(double value, int timePeriod);
    double presentValue();
};
