#include <iostream>

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
    int p[]={1,5,8,9,10,17,17,20,24,30};
    cout<<Cut_Rod(p,4)<<endl;
    return 0;
}
