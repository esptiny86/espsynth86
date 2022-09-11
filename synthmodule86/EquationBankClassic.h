#ifndef EquationBankSobek_h
#define EquationBankSobek_h

#include "EquationBank.h"

class EquationBankClassic : public EquationBank
{
    public:    
    EquationBankClassic();
    uint32_t compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3);
};

#endif
