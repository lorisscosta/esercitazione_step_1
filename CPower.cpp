/*! @file CPower.cpp
    @brief File CPP della classe Power
    @author Federico Maria Biasioli Loris Costanzo

    Details.
*/

#include "CPower.h"

/// @brief costruttore di default
Power::Power(){
    e_coeff=-1;
    k_coeff=-1;
}

/// @brief costruttore
/// @param e_coeff esponente dell'esponenziale
/// @param k_coeff coefficiente dell'esponenziale
Power::Power(double e_coefficient, double k_coefficient){
    e_coeff=-1;
    k_coeff=-1;
    SetPower(e_coefficient,k_coefficient);
}

/// @brief costruttore di copia
Power::Power(const Power& p){
    if(p.e_coeff==-1){
        ErrorMessage("Costruttore di copia: L'oggetto non ha esponente");
        exit(-1);
    }
    if(p.k_coeff==-1){
        ErrorMessage("Costruttore di copia: L'oggetto non ha coefficiente");
        exit(-1);
    }
    e_coeff = p.e_coeff;
    k_coeff = p.k_coeff;
}

/** 
* @brief destructor
*/
Power::~Power(){}

/** 
* @brief overload operatore =
* @param p oggetto da copiare
* @return copia dell'oggetto
*/
Power& Power::operator=(const Power& p){
    if(p.e_coeff==-1){
        ErrorMessage("Costruttore di copia: L'oggetto non ha esponente");
        exit(-1);
    }
    if(p.k_coeff==-1){
        ErrorMessage("Costruttore di copia: L'oggetto non ha coefficiente");
        exit(-1);
    }
    e_coeff = p.e_coeff;
    k_coeff = p.k_coeff;
    return *this;
}

/** 
* @brief overload operatore ==
*/
bool Power::operator==(const Power& p){
    if(e_coeff!=p.e_coeff)
    {
        return false;
    }
    if(k_coeff!=p.k_coeff)
    {
        return false;
    }
    return true;
}

/** 
* @brief setta i parametri della potenza
* @param e_coeff esponente dell'esponenziale
* @param k_coeff coefficiente dell'esponenziale
*/
void Power::SetPower(double new_k_coeff, double new_e_coeff)
{
    if(k_coeff!=-1&&e_coeff!=-1)
    {
        Reset();
    }
    e_coeff=new_e_coeff;
    k_coeff=new_k_coeff;
}

/**
 * @brief resetta la potenza
 */
void Power::Reset(){
    e_coeff=-1;
    k_coeff=-1;
}

/**
 * @brief writes an error message 
 * @param string message to be printed
 */
void Power::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Power --";
	cout << string << endl;

}

/**
 * @brief writes a warning message
 * @param string message to be printed
 */ 
void Power::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Power --";
	cout << string << endl;

}

/**
 * @brief gives the status of the object
 */ 
void Power::Dump() {
	
	if (k_coeff == -1 || e_coeff == -1) {
		cout << "Uninitialized power" << endl;
		return;
	}
	cout << "Potenza: " << e_coeff << endl;
    cout << "Coefficiente della potenza: " << k_coeff <<endl;
	cout << endl;
}

double Power::GetValue(double x,const Power& p){
    double result;
    double pow=x;
    int i;
    for(i=0;i<p.e_coeff;i++)
    {
        pow=pow*x;
    }
    result=pow*p.k_coeff;
	return result;
}
