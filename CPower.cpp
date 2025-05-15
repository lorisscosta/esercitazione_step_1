/*! @file CPower.cpp
    @brief File CPP della classe Power
    @author Federico Maria Biasioli Loris Costanzo
*/

#include "CPower.h"

/// @brief costruttore di default
Power::Power(){
    e_coeff=0;
    k_coeff=0;
}

/// @brief costruttore
/// @param e_coeff esponente dell'esponenziale
/// @param k_coeff coefficiente dell'esponenziale
Power::Power(double e_coefficient, double k_coefficient){
    e_coeff=0;
    k_coeff=0;
    SetPower(e_coefficient,k_coefficient);
}

/// @brief costruttore di copia
Power::Power(const Power& p){
    e_coeff = p.e_coeff;
    k_coeff = p.k_coeff;
}

/** 
* @brief distruttore
*/
Power::~Power(){
    Reset();
}

/** 
* @brief overload operatore =
* @param p oggetto da copiare
* @return copia dell'oggetto
*/
Power& Power::operator=(const Power& p){
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
    if(k_coeff!=0||e_coeff!=0)
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
    e_coeff=0;
    k_coeff=0;
}

/**
 * @brief da lo stato dell'oggetto
 */ 
void Power::Dump() {
	cout << "Potenza: " << e_coeff << endl;
    cout << "Coefficiente della potenza: " << k_coeff <<endl;
	cout << endl;
}

/**
 * @brief da il risultato
 * @param in valore della base dell'esponente
 */ 
double Power::GetValue(double in){
    double result;
    double x=in;
    int i;
    for(i=1;i<e_coeff;i++)
    {
        x=x*in;
    }
    result=x*k_coeff;
	return result;
}