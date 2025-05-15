/*! @file CPolynomial.h
	@brief A class for polynomial functions 
	@author Federico Maria Biasioli Loris Costanzo

	Details.
*/ 

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Polynomial:public Function {
private:
    double* coeff;  											// puntatore ad array di double
    int degree; 												// grado del polinomio 

public:
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Polynomial();  // costruttore di default 
	Polynomial(const double* coefficients, int size); 			// costruttore di default con passaggio di parametri 
    Polynomial(const Polynomial& p); 							// costruttore di copia 
    ~Polynomial();												// distruttore dei Polynomial
	/// @}

	/// @name OPERATORS 
	/// @{
    Polynomial& operator=(const Polynomial& p); 				// overload dell'operatore =
	Polynomial operator+(const Polynomial& p); 					// overload dell'operatore +
	bool operator==(const Polynomial& p); 						// overload dell'operatore ==
	/// @}


	void SetPolynomial(const double* coefficients, int size);	// SETTER per l'attributo
    double GetValue(double in) const;							// metodo che restituisce il valore del polinomio valutato in (in)
	
	void Reset();												// metodo per resettare l'oggetto

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 						// metodo che stampa gli errori
	void WarningMessage(const char *string);					// metodo che stampa i warning
	void Dump();												// metodo dump
	/// @}
};

#endif