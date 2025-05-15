/** 
 * @file CPolynomial.cpp
 *	@brief Implementazione della classe CPolynomial.h
 *	@author Federico Maria Biasioli Loris Costanzo
 */ 
#include "CPolynomial.h"

/**
 * @brief costruttore di default
 */
Polynomial::Polynomial() {
	degree=-1;
	coeff = NULL;
}


/**
 * @brief costruttore
 * @param coefficients array con i coefficienti
 * @param size dimensione degli array
 */
Polynomial::Polynomial(const double* coefficients, int size) {
	degree = -1;
	coeff = NULL;
	SetPolynomial(coefficients,size);
}

/**
 * @brief distruttore
 */
Polynomial::~Polynomial() {
    
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/**
 * @brief copia costruttore
 */
Polynomial::Polynomial(const Polynomial& p) {
	
	int i;
	
	if (p.coeff == NULL) {
		ErrorMessage("Copy constructor: the object to be copied has no coefficients");
		exit(-1);
	}
	degree = p.degree;
	coeff = new double[degree + 1];
	if (coeff == NULL) {
		ErrorMessage("Copy constructor: cannot allocate memory");
		exit(-1);
	}
	
    for (i=0;i<=degree;i++)
		coeff[i]= p.coeff[i];
}

/**
 * @brief overload operatore =
 * @param p oggetto da copiare
 * @return copia dell'oggetto
 */
Polynomial& Polynomial::operator=(const Polynomial& p) {
    
	int i; 
	
	if (this != &p) {
		if (coeff != NULL)
			delete coeff;
        degree = p.degree;
        coeff = new double[degree + 1];
		if (coeff == NULL) {
			ErrorMessage("Operator =: cannot allocate memory");
			exit(-1);
		}
        for (i=0;i<=degree;i++)
			coeff[i]= p.coeff[i];
    }
    return *this;
}

/// @brief overload operatore ==
bool Polynomial::operator==(const Polynomial& p) {
	
	int i;
	
	if (degree != p.degree)
		return false;
	
	for (i=0; i<=degree; i++) {
		if (coeff[i] != p.coeff[i])
			return false;
	}
	
	return true;
	
}

/**
 * @brief imposta i coefficienti del polinomio
 * @param coefficients array con i coefficients (format: c0+c1*x+ ...)
 * @param size dimensioni dell'array
 */
void Polynomial::SetPolynomial(const double* coefficients, int size) {
	
	int i=0;
	
	if (size < 1) {
		ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
		exit(-1);
	}
	
	if (coeff != NULL)
		Reset();
	
	degree = size - 1;
    coeff = new double[size]; // restituisce double* dove 
	if (coeff == NULL) {
		ErrorMessage("SetPolynomial: cannot allocate memory");
		exit(-1);
	}
	
	for (i=0; i<=degree; i++)
		coeff[i] = coefficients[i];
	
}

/**
 * @brief ristituisce il valore della funzione
 * @param in input
 * @return valore della funzione
 */
double Polynomial::GetValue(double in) const {
    int i;
	double x = in;
	double result = 0.0;
        
	result = coeff[0];
	for (i=1; i<=degree; i++) {
		result += coeff[i]*x;
		x *= in;			/* x^i */
	}
        
	return result;
}

/**
 * @brief resetta il polinomio
 */ 
void Polynomial::Reset() {
	
	degree = -1; 
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/**
 * @brief scrive un messaggio di errore 
 * @param string messaggio da stampare
 */
void Polynomial::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Polynomial --";
	cout << string << endl;

}

/**
 * @brief scrive un messaggio di warning
 * @param string messaggio da stampare
 */ 
void Polynomial::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Polynomial --";
	cout << string << endl;

}

/**
 * @brief da lo stato dell'oggetto
 */ 
void Polynomial::Dump() {

	int i;
	
	if (degree == -1) {
		cout << "Uninitialized polynomial" << endl;
		return;
	}
	
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "No coefficients available" << endl;
		return;
	}
	
    for (i = 0; i <= degree; ++i) {
		if (coeff[i] != 0.) {
			cout << (coeff[i] > 0 && i > 0 ? " +" : " ") << coeff[i];
            if (i > 0) {
                cout << "x";
                if (i > 1) 
                    cout << "^" << i;
            }
        }
    }
	cout << endl;
}