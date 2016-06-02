#include <iostream>
#include <vector>

using namespace std;


vector<int> A;

void Recursive_Activity_Selector(vector<int>S,vector<int>F,int k)
{

    unsigned int m=k+1;
    while(m<=S.size() and S[m]<F[k])
    {
        m=m+1;
    }
    if(m<=S.size())
    {
        B.push_back(m);
        Recursive_Activity_Selector(S,F,m);
    }
}

int main()
{
    vector<int> S={1,3,0,5,3,5,6,8,8,2,12};
    vector<int> F={4,5,6,7,9,9,10,11,12,14,16};
    Recursive_Activity_Selector(S,F,0);

    cout<<"las actividades son: "<<endl;
    for(unsigned int i=0;i<A.size()-1;i++)
    {
            cout<<A[i]+1<<" , ";
    }
    cout<<A[A.size()-1]+1<<endl;
    return 0;

}
