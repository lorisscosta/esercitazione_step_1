#include <iostream>
#include "CPower.h"
#include "CLogarithmic.h"
#include "CPolynomial.h"

int main() {
    std::cout << "Test della classe Power, Logarithm e Polinomial\n" << std::endl;
    double coefficient[3] = {5.0,2.5,3.2};
    // Test costruttore di default
    Power p1;
    Logarithmic l1;
    Polinomial po1;

    //Dump dei costruttori di default
    p1.Dump();
    l1.Dump();
    po1.Dump();

    // Test costruttore parametrico
    Power p2(3.0, 5.0); 
    Logarithmic l2(4.0, 2.0); 
    Polinomial po2(coefficient,3); 
    p2.Dump();
    l2.Dump();
    po2.Dump();

    // Test funzione GetValue
    double x;
    std::cout << "Inserisci un valore double su cui calcolare la potenza, il logaritmo e il polinomio: ";
    cin >> x;
    cout << "Valore inserito: " << x << endl;
    double risultato = p2.GetValue(x);
    std::cout << "Risultato di "<<x<< " Con la seguente potenza" <<std::endl;
    p2.Dump();
    std::cout <<risultato<< std::endl;
    risultato = l2.GetValue(x);
    std::cout << "Risultato di "<<x<< " Con il seguente logaritmo" <<std::endl;
    l2.Dump();
    std::cout <<risultato<< std::endl;
    risultato = po2.GetValue(x);
    std::cout << "Risultato di "<<x<< " Con il seguente polinomio" <<std::endl;
    po2.Dump();
    std::cout <<risultato<< std::endl;

    // Test copy constructor
    Power p3(p2);
    Logarithmic l3(l2);
    Polinomial po3(po2);
    p3.Dump();
    l3.Dump();
    po3.Dump();

    // Test operatore ==
    std::cout << "p2 == p3? " << (p2 == p3 ? "true" : "false") << std::endl;
    std::cout << "l2 == l3? " << (l2 == l3 ? "true" : "false") << std::endl;
    std::cout << "po2 == po3? " << (po2 == po3 ? "true" : "false") << std::endl;

    // Test operatore =
    p1 = p3;
    po1 = po3;
    l1 = l3;
    std::cout << "p1, l1 e po1 dopo l'assegnazione di p3, l3 e po3:" << std::endl;
    p1.Dump();
    l1.Dump();
    po1.Dump();

    // Test Reset
    p1.Reset();
    l1.Reset();
    po1.Reset();
    std::cout << "p1 dopo Reset:" << std::endl;
    p1.Dump();
    l1.Dump();
    po1.Dump();

    return 0;
}