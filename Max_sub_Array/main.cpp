#include <iostream>

using namespace std;

int* max_crossing_subarray(int *a,int low,int mid,int high)
{
    int* b;                     ///la variable del return;
    int sum_left=-9999999;
    int sum=0;
    int sum_right=-9999999;
    int max_left;
    int max_right;
    for(int i=mid;i>=low;i--)
    {
        sum+=a[i];
        if(sum > sum_left)
        {
            sum_left=sum;
            max_left=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if(sum>sum_right)
        {
            sum_right=sum;
            max_right=i;
        }
    }
    b=new int[3];
    b[0]=max_left;
    b[1]=max_right;
    b[2]=sum_left+sum_right;
    return b;
}


int* find_max_subarray(int* a,int low,int high)
{
    if(high==low)                           ///caso base!
    {
        int* b=new int[3];
        b[0]=low;b[1]=high;b[2]=a[low];
        return b;
    }
    int mid=(low+high)/2;
    int* c=find_max_subarray(a,low,mid);
    int* d=find_max_subarray(a,mid+1,high);
    int* e=max_crossing_subarray(a,low,mid,high);
    if(c[2]>=d[2] && c[2]>=e[2])  return c;
    if(d[2]>=c[2] && d[2]>=e[2])  return d;
/*  if(e[2]>=c[2] && e[2]>=d[2])*/return e;
}


int main()
{
    int a[]={8,-5,-30,20,-3,-16,-23,18,20,7,-9};
    int* b=find_max_subarray(a,0,10);
    cout<<"inicia en: "<<b[0]<<endl<<"termina en: "<<b[1]<<endl<<"la suma es:"<<b[2]<<endl;
    cout<<"el maximo array es: [";
    for(int i=b[0];i<b[1];i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<a[b[1]]<<"]\n";
    return 0;
}
