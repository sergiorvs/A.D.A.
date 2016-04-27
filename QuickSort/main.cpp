#include <iostream>

using namespace std;
int Partition(int*,int,int);
void Quick_Sort(int* a,int p,int r)
{
    if(p<r)
    {
        int q=Partition(a,p,r);
        Quick_Sort(a,p,q-1);
        Quick_Sort(a,q,r);
    }
}

int Partition(int* a,int p,int r)
{
    int x=a[r];
    int i=p-1;
    int aux;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }
    }
    aux=a[i+1];
    a[i+1]=a[r];
    a[r]=aux;
    return i+1;
}


int main()
{
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    Quick_Sort(a,0,9);
    cout<<"<";
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<a[9]<<">"<<endl;
    return 0;
}
