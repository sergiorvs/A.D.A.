#include <iostream>
#include <vector>
using namespace std;
/*
void imprime_grafo(vector < vector <int> >A,int tam)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void ingresar_nodo(vector <vector <int> >A,int tam)
{
    bool ap;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            cout<<"nodo "<<i+1<<" apuanta a "<<j+1<<"?(1=S/0=N): ";
            cin>>ap;
            if(ap)
            {
                A[i].push_back(1);
            }
            else
            {
                A[i].push_back(0);
            }
        }
        cout<<"*********************************************\n"<<endl;
    }
}
*/

int main()
{
/*    vector <int> aux(20);
    aux[0]=5;
    aux[1]=7;
    A.push_back(aux);
    cout<<A[0][1]<<endl;*/
    int tam;
    cout<<"ingrese el nuemero de nodos del grafo: ";cin>>tam;
    vector < vector <int> >A(tam);
    bool ap;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            cout<<"nodo "<<i+1<<" apuanta a "<<j+1<<"?(1=S/0=N): ";
            cin>>ap;
            if(ap)
            {
                A[i].push_back(1);
            }
            else
            {
                A[i].push_back(0);
            }
        }
        cout<<"*********************************************\n"<<endl;
    }

    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
