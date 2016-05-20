#include <iostream>
#include <time.h>

using namespace std;
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int Cut_Rod(int* p,int n)
{
    int q=0;
    if(n==0)
    {
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        q=max(q,p[i]+Cut_Rod(p,n-(i+1)));
    }
    return q;
}

int main()
{
    const double CLK_TCK1 = 1000.0;
    clock_t start, end;
    int p[]={1,5,8,9,10,17,17,20,24,30,
             31,35,40,43,50,57,58,59,63,68,
             70,73,75,77,80,89,90,93,95,100,
             105,109,113,125,126,127,130,134,135,136,
             138,143,147,150,156,159,171,172,174,176};
    start = clock();
    cout<<Cut_Rod(p,33)<<endl;      ///tiempo estimado para 33:   26.24800.
    end = clock();
    printf("El tiempo es: %f\n", (end - start) / CLK_TCK1);
    return 0;
}
