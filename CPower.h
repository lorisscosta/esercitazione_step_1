/*! @file CPower.h
    @brief File h della classe Power
    @author Federico Maria Biasioli Loris Costanzo

    Details.
*/

#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

class Power:public Function{
protected:
    double k_coeff;
    double e_coeff;

public:
    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    Power();
    Power(double k_coeff, double e_coeff);
    Power(const Power &p);
    ~Power();
    /// @}

    /// @name OPERATORS
    /// @{
    Power &operator=(const Power &p);
    bool operator==(const Power &p);
    /// @}

    void Reset();
    void SetPower(double k_coef, double e_coeff);
    /// @name DEBUG and SERIALIZATION
    /// @{
    void ErrorMessage(const char *string);
    void WarningMessage(const char *string);
    void Dump();
    /// @}

    double GetValue(double x, const Power &p);
};
#endif