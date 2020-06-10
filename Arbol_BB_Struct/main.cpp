#include <iostream>
#include<conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

//Prototipos
void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&arbol, int, Nodo *padre);
void mostrarArbol(Nodo*, int);
void preOrden(Nodo *arbol);
void inOrden(Nodo *arbol);
Nodo* busqueda(Nodo*arbol, int n);
void postOrden(Nodo *arbol);
void eliminar(Nodo *arbol, int n);
void eliminarNodo(Nodo *nodoElim);
Nodo *minimo(Nodo *arbol);
void reemplazar(Nodo *arbol, Nodo* nuevo);
void destruir(Nodo *nod);

Nodo *arbol = NULL;
int main()
{
    menu();
    getch();
    return 0;
}

//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n, Nodo * padre)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->der=0;
    nuevo_nodo->izq=0;
    nuevo_nodo->dato=n;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo* padre)
{   //si arbol esta vacio
    if(arbol==0)
    {
        Nodo *nuevo_nodo = crearNodo(n, padre);

        arbol = nuevo_nodo;
    }else//si el arbol tiene más de un nodo
    {
        int valorRaiz = arbol->dato;//obtener valor de raiz
        if(n<valorRaiz)
        {//si elemento es menor insertar a la izq
            insertarNodo(arbol->izq,n,arbol);
        }else
        {//si elemento es mayo insertar a la der
            insertarNodo(arbol->der,n,arbol);
        }
    }
}

void menu()
{
    int dato, opcion, cont=0;
    do
    {
        cout<<"\t.**MENU**"<<endl;
        cout<<"1. Insertar nuevo nodo"<<endl;
        cout<<"2. Mostrar el arbol completo"<<endl;
        cout<<"3. Buscar un elemento"<<endl;
        cout<<"4. Recorrer el arbol en preoOden"<<endl;
        cout<<"5. Recorrer el arbol en inOrden"<<endl;
        cout<<"6. Recorrer el abol en postOrden"<<endl;
        cout<<"7. Eliminar nodo"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            {
                cout<<"\nDigite un numero: ";
                cin>>dato;
                insertarNodo(arbol, dato, 0);
                cout<<"\n";
                system("pause");
                break;
            }

        case 2:
            {
                cout<<"\nMostrando el arbol completo\n\n";
                mostrarArbol(arbol, cont);
                cout<<"\n";
                system("pause");
                break;
            }
        case 3:
            {
                cout<<"\nDigite el elemento a buscar";
                cin>>dato;
                if(busqueda(arbol, dato)!=0)
                {
                    cout<<"\nDATO ENCONTRADO=>"<<busqueda(arbol,dato)->dato;
                }else
                {
                    cout<<"\nEL ELEMENTO NO EXISTE";
                }
                cout<<"\n";
                system("pause");
                break;
            }
        case 4:
            {
                cout<<"\nRECORRIENDO EN PREORDEN: ";
                preOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
            }
        case 5:
            {
                cout<<"\nRECORRIDO INORDEN: ";
                inOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
            }
        case 6:
            {
                cout<<"\nRECORRIDO POSTORDEN: ";
                postOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
            }
        case 7:
            {
                cout<<"\nDigite el numero del nodo a eliminar: ";
                cin>>dato;
                eliminar(arbol,dato);
                cout<<"\n";
                system("pause");
                break;
            }
        }
        system("cls");
    }while(opcion!=8);
}
//Mostrar el arbol
void mostrarArbol(Nodo* arbol, int i  )
{
    if(arbol==0)
    {
        return;
    }else
    {
        mostrarArbol(arbol->der, i+1);
        for(int j=0; j<i; j++)
        {
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq, i+1);
    }
}

//buscar en el arbol
Nodo* busqueda(Nodo*arbol, int n)
{
    if(arbol==0)
    {
        return 0;
    }
    else if(arbol->dato==n)
    {
        return arbol;
    }
    else if(n<arbol->dato)
    {
        return busqueda(arbol->izq, n);
    }
    else
    {
        return busqueda(arbol->der, n);
    }
}

//Recorrido en preOrden
void preOrden(Nodo *arbol)
{
    if(arbol==0)
    {
        return;
    }else
    {
        cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//Funcion para inOrden
void inOrden(Nodo *arbol)
{
    if(arbol==0)
    {
        return;
    }
    else
    {
        inOrden(arbol->izq);
        cout<<arbol->dato<<" - ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol)
{
    if(arbol==0)
    {
        return;
    }else
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->dato<<" - ";
    }
}

//eliminnar
void eliminar(Nodo *arbol, int n)
{
    if(arbol==0)
    {
        return;
    }
    else if(n<arbol->dato)
    {
        eliminar(arbol->izq, n);
    }
    else if(n>arbol->dato)
    {
        eliminar(arbol->der,n);
    }
    else
    {
        eliminarNodo(arbol);
    }
}

void eliminarNodo(Nodo *nodoElim)
{
    if(nodoElim->izq&&nodoElim->der)//nodo tiene dos hijos
    {
        Nodo *menor = minimo(nodoElim->der);
        nodoElim->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoElim->izq)//nodo tiene hijo izq
    {
        reemplazar(nodoElim,nodoElim->izq);
        destruir(nodoElim);
    }
    else if(nodoElim->der)//nodo tiene hijo der
    {
     reemplazar(nodoElim, nodoElim->der);
     destruir(nodoElim);
    }
    else//mpdp es jpka
    {
        reemplazar(nodoElim, 0);
        destruir(nodoElim);
    }
}

//Funcion para determinar nodo más izquier
Nodo *minimo(Nodo* arbol)
{
    if(arbol==0)
    {
        return 0;
    }
    if(arbol->izq)
    {
        return minimo(arbol->izq);
    }
    else
    {
        return arbol;
    }
}
//Funcion reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo* nuevo)
{
 if(arbol->padre)
 {
     if(arbol->dato==arbol->padre->izq->dato)
     {
         arbol->padre->izq=nuevo;
     }
     else if(arbol->dato==arbol->padre->der->dato)
     {
         arbol->padre->der=nuevo;
     }
 }
 if(nuevo)
 {
     nuevo->padre=arbol->padre;
 }
}

//destruir nodo
void destruir(Nodo *nod)
{
    nod->izq=0;
    nod->der=0;
    delete nod;
}
