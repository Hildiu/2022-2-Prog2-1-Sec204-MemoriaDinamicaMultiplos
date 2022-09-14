#include <iostream>
#include <iomanip>
using namespace  std;

void imprimir( int *pArreglo, int n);
int * dimensionar(int n);
void llenarDatos(int *pA, int n);
int  contarMultiplos(int *pArreglo, int n, int multiplo);
void eliminar(int * & pA);

int main()
{   int *pA=nullptr;
    int ne;
    int cm5, cm7;

    srand(time(nullptr));
    cout << "Numero de elementos del arreglo:";
    cin >> ne;
    pA = dimensionar(ne);
    llenarDatos(pA,ne);
    imprimir(pA,ne);
    cm5 = contarMultiplos(pA, ne, 5);
    cm7 = contarMultiplos(pA, ne, 7);
    int *pM5 = dimensionar(cm5);
    int *pM7 = dimensionar(cm7);
    llenarMultiplos(pA,ne,pM5,5);
    llenarMultiplos(pA, ne, pM7, 7);
    cout << "\nArreglo con los multiplos de 5 \n";
    imprimir(pM5,cm5);
    cout << "\nArreglo con los multiplos de 7 \n";
    imprimir(pM7, cm7);
//---- eliminamos el espacio de memoria


    eliminar(pA);
    eliminar(pM5);
    eliminar(pM7);

   return 0;
}

void eliminar(int * & pArreglo)
{
    delete []pArreglo;
    pArreglo = nullptr;
}

int  contarMultiplos(int *pArreglo, int n, int multiplo)
{
    int contador=0;
    for(int i=0; i<n; i++)
        if (pArreglo[i] % multiplo == 0)
            contador++;
    return contador;
}



int * dimensionar(int n)
{
    return  new int[n];
}

void llenarDatos(int *pA, int n)
{
    for(int i=0; i<n; i++)
        pA[i] = rand() % 1000;
}

void imprimir( int *pArreglo, int n)
{
  for(unsigned int i=0; i<n; i++)
      cout << setw(6) << pArreglo[i];
}