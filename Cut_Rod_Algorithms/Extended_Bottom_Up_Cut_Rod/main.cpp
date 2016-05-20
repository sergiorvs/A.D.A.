#include <iostream>
#include <time.h>

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

int main()
{
    cout<<"Hola"<<endl;
    const double CLK_TCK1 = 1000.0;
    clock_t start, end;
    int p[]={1,5,8,9,10,17,17,20,24,30,
             31,35,40,43,50,57,58,59,63,68,
             70,73,75,77,80,89,90,93,95,100,
             105,109,113,125,126,127,130,134,135,136,
             138,143,147,150,156,159,171,172,174,176};
    pair<int*,int*> a;
    start = clock();
    a=Extended_Bottom_Up_Cut_Rod(p,50); ///tiempo estimado de 50:  inferior a 0.000100
    end = clock();
    cout<<"r::::::>";
    for(int i=0;i<31;i++)
    {
        cout<<a.first[i]<<", ";
    }
    cout<<endl;
    cout<<"s::::::>";
    for(int i=0;i<31;i++)
    {
        cout<<a.second[i]<<", ";
    }
    cout<<endl;

    printf("El tiempo es: %f\n", (end - start) / CLK_TCK1);
    return 0;
}
