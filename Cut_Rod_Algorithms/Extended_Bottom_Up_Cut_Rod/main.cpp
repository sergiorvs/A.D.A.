#include <iostream>

using namespace std;

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

pair<int*,int*> Extended_Bottom_Up_Cut_Rod(int* p,int n)
{
    pair<int*,int*> a;
    a.first=new int[n+1];
    a.second=new int[n+1];
    a.first[0]=0;
    a.second[0]=0;
    int q=-9999;
    for(int j=0;j<n+1;j++)
    {
        for(int i=0;i<=j;i++)
        {
            if(q<(p[i]+a.first[j-i]))
            {
                q=p[i]+a.first[j-i];
                a.second[j+1]=i+1;
            }
        }
        a.first[j+1]=q;
    }
    return a;
}
/*
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
}*/

int main()
{
    int p[]={1,5,8,9,10,17,17,20,24,30};
    pair<int*,int*> a;
    a=Extended_Bottom_Up_Cut_Rod(p,10);
    cout<<"r::::::>";
    for(int i=0;i<11;i++)
    {
        cout<<a.first[i]<<", ";
    }
    cout<<endl;
    cout<<"s::::::>";
    for(int i=0;i<11;i++)
    {
        cout<<a.second[i]<<", ";
    }

    return 0;
}
