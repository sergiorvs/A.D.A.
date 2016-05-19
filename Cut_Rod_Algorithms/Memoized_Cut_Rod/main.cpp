#include <iostream>

using namespace std;

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int Memoized_Cut_Rod_Aux(int* p,int n, int* r)
{
    int q;
    if(r[n]>0)
    {
        return r[n];
    }
    if(n==0)
    {
        q=0;
    }
    else
    {
        q=-1;
        for(int i=0;i<n;i++)
        {
            q=max(q,p[i]+Memoized_Cut_Rod_Aux(p,n-(i+1),r));
        }
    }
    r[n]=q;
    return q;
}

int Memoized_Cut_Rod(int*p,int n)
{
    int r[n];
    for(int i=0;i<n;i++)
    {
        r[i]=0;
    }
    return Memoized_Cut_Rod_Aux(p,n,r);

}


