#include<iostream>

using namespace std;

int* find_max_subarray(int* a,int n)
{
    int left = 0;
    int right = 0;
    int sum=a[0];
    int auxsum=a[0];
    int *b=new int[3];
    for(int i=1;i<n;i++)
    {
        if(a[i]>sum)
        {
            sum=a[i];
        }
        auxsum=a[i];
        for(int j=i-1;j>0;j--)
        {
            auxsum+=a[j];
            if(auxsum>sum)
            {
                sum=auxsum;
            }
            left=j;
            right=i;
        }
    }
    b[0]=left;
    b[1]=right;
    b[2]=sum;
    return b;
}

int main()
{
    int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int* b;
    b=new int[3];
    b=find_max_subarray(a,16);
    cout<<"inicio: "<<b[0]<<"\nfin: "<<b[1]<<"\nsum:"<<b[2];
    return 0;
}
