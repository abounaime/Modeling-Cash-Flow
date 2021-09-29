#include "CashFlowCalculator.h"
#include <iostream>
// the main function receives parameters passed to the program

int main()
{
    double value;
    int period;
    double rate = 0.05;
    CashFlowCalculator cfc (rate);
    do{
        std::cout << "enter period : " << std::endl;
        std::cin >> period;
        if(period == -1)
        break;
        std::cout << "enter future value : " << std::endl;
        std::cin >> value;
        cfc.addCashPayement(value, period);
    }while(1);

    double res = cfc.presentValue();
    std::cout << "present value : " << res << std::endl;
    return 0;
}