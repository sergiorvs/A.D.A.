#include <iostream>

using namespace std;

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int Bottom_Up_Cut_Rod(int* p,int n)
{
    int q;
    int r[n];
    r[0]=0;
    q=-9999;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<=j;i++)
        {
            q=max(q,p[i]+r[j-i]);
        }
        r[j+1]=q;
    }
    return q;
}

int main()
{
    int p[]={1,5,8,9,10,17,17,20,24,30};
    cout<<Bottom_Up_Cut_Rod(p,10)<<endl;
    return 0;
}
