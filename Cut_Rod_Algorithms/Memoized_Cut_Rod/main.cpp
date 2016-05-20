#include <iostream>
#include <time.h>

using namespace std;

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int Memoized_Cut_Rod_Aux(int* p,int n, int* r)
{
    int q;
    if(r[n]>=0)
    {
        return r[n];
    }
    if(n==0)
    {
        q=0;
    }
    else
    {
        q=INT_MIN;
        for(int i=0;i<n;i++)
        {
            q=max(q,p[i]+Memoized_Cut_Rod_Aux(p,n-i-1,r));
        }
    }
    r[n]=q;
    return q;
}

int Memoized_Cut_Rod(int*p,int n)
{
    int r[n+1];
    for(int i=0;i<=n;i++)
    {
        r[i]=INT_MIN;
    }
    return Memoized_Cut_Rod_Aux(p,n,r);

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
    cout<<Memoized_Cut_Rod(p,50)<<endl; ///tiempo estimado de 50:  0.000100
    end = clock();
    printf("El tiempo es: %f\n", (end - start) / CLK_TCK1);
    return 0;
}

