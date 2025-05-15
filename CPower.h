/*! @file CPower.h
    @brief File h della classe Power
    @author Federico Maria Biasioli Loris Costanzo
*/

#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

class Power:public Function{
private:
    double k_coeff;
    double e_coeff;

public:
    /// @name Costruttori/Distruttore
    /// @{
    Power();
    Power(double k_coeff, double e_coeff);
    Power(const Power &p);
    ~Power();
    /// @}

    /// @name Operatori
    /// @{
    Power &operator=(const Power &p);
    bool operator==(const Power &p);
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump();
    /// @}
    
    /// @name Altre funzioni
    /// @{
    double GetValue(double in);
    void Reset();
    void SetPower(double k_coef, double e_coeff);
    /// @}
};
#endif