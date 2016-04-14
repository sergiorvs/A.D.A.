#include <iostream>

using namespace std;


class Matriz
{
public:
    int **p;
    int rows;

    Matriz(int n)
    {
        rows=n;
        p=new int*[rows];
        for (int i=0; i<rows; i++)
            p[i]= new int[rows];
    }
    void insertar()
    {
        cout<<"Ingrese los elementos Matriz:\n";
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<rows; j++)
                cin>> p[i][j];
        }
    }
    void mostrar()
    {
        cout <<"Matriz: \n";
        for(int i=0; i<rows; i++)
        {
            cout <<endl;
            for(int j=0; j<rows; j++)
                cout<< p[i][j]<<" ";
        }
    }
};

Matriz square_matrix_multiply(Matriz A,Matriz B)
{
    int n=A.rows;
    Matriz C(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            C.p[i][j]=0;
            for(int k=0; k<n; k++)
                C.p[i][j]+=(A.p[i][k]*B.p[k][j]);
        }
    }
    return C;
}

Matriz Strassen(Matriz A,Matriz B,int n)
{
    Matriz C(n);

    if(n==1)
    {
        C=square_matrix_multiply(A,B);
    }
    int M1=(A.p[1][2]-A.p[2][2])*(B.p[2][1]+B.p[2][2]);
    int M2=(A.p[1][1]+A.p[2][2])*(B.p[1][1]+B.p[2][2]);
    int M3=(A.p[1][1]-A.p[2][1])*(B.p[1][1]+B.p[1][2]);
    int M4=(A.p[1][1]+A.p[1][2])*B.p[2][2];
    int M5=A.p[1][1]*(B.p[1][2]-B.p[2][2]);
    int M6=A.p[2][2]*(B.p[2][1]-B.p[1][1]);
    int M7=(A.p[2][1]+A.p[2][2])*B.p[1][1];

    C.p[1][1]=M1+M2-M4+M6;
    C.p[1][2]=M4+M5;
    C.p[2][1]=M6+M7;
    C.p[2][2]=M2-M3+M5-M7;

    return C;
}

