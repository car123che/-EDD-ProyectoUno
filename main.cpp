#include <iostream>
#include "Double_Circular_List.h"
#include <conio.h>
struct Persona{
    std::string nombre;
    int edad;
}p1;
int main()
{
    std::cout << "Hello world!" <<std:: endl;
    Double_Circular_List<int> *intLista = new Double_Circular_List<int>();
    Double_Circular_List<double> *doubleLista = new Double_Circular_List<double>();
    Double_Circular_List<char> *charLista = new Double_Circular_List<char>();
    Double_Circular_List<float> *floatLista = new Double_Circular_List<float>();
    Double_Circular_List<std::string> *stringLista = new Double_Circular_List<std::string>();
    Double_Circular_List<Persona> *personaLista = new Double_Circular_List<Persona>();

    p1.edad=5;
    p1.nombre="Juan";

    personaLista->insertTop(p1,0);
    personaLista->show();
    intLista->insertTop(5,0);
    intLista->insertTop(50,1);
    intLista->insertTop(500,2);
    intLista->insertTop(5000,3);

    doubleLista->insertTop(4.36,0);
    doubleLista->insertTop(4.36,1);
    doubleLista->insertTop(4.36,2);

    charLista->insertTop('a',0);
    charLista->insertTop('i',1);
    charLista->insertTop('e',2);
    charLista->insertTop('u',3);
    charLista->insertTop('o',4);

    floatLista->insertTop(4.3,0);
    floatLista->insertTop(1.1,1);

    stringLista->insertTop("HOALA",0);

    std::cout<<"LISTA DE ENTEROS"<<std::endl;
    intLista->show();
    std::cout<<"\nLISTA DE DOUBLES"<<std::endl;
    doubleLista->show();
    std::cout<<"\nLISTA DE CHAR"<<std::endl;
    charLista->show();
    std::cout<<"\nLISTA DE FLOAT"<<std::endl;
    floatLista->show();
    std::cout<<"\nLISTA DE STRINGS"<<std::endl;
    stringLista->show();

    getch();
    return 0;
}
