#include<iostream>
#include<math.h>

using namespace std;
int* LCS(int N,int* X)
{
    int P[N];
    int M[N+1];

    int L=0;
    for(int i=0;i<N;i++)
    {
        int lo=1;
        int hi=L;
        while(lo <= hi)
        {

            int mid=ceil((lo+hi)/2);
            if(X[M[mid]] < X[i])
            {
                lo=mid+1;
            }else{hi=mid-1;}
        }
        int newL=lo;
        P[i]=M[newL-1];
        M[newL]=i;
        if(newL > L)
        {
            L=newL;
        }
    }
    int* S=new int[L];
    int k=M[L];
    for(int i=L-1;i>=0;i--)
    {
        S[i]=X[k];
        k=P[k];
    }
    for(int i=0;i<L;i++)
    {
        cout<<S[i]<<",";
    }
    return S;
}


int main()
{
    int a[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    LCS(16,a);
    return 0;
}
