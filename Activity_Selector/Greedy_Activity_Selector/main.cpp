#include <iostream>
#include <vector>

using namespace std;

vector<int> Greedy_Activity_Selector(vector<int> S,vector<int> F)
{
    vector<int> A;
    int k=1;
    unsigned int m;
    A.push_back(0);
    for(m=2;m<=S.size();m++)
    {
        if(S[m]>=F[k])
        {
            A.push_back(m);
            k=m;
        }
    }
    return A;
}

int main()
{
    vector<int> S={1,3,0,5,3,5,6,8,8,2,12};
    vector<int> F={4,5,6,7,9,9,10,11,12,14,16};
    vector<int> A=Greedy_Activity_Selector(S,F);

    cout<<"las actividades son: "<<endl;
    for(unsigned int i=0;i<A.size()-1;i++)
    {
            cout<<A[i]+1<<" , ";
    }
    cout<<A[A.size()-1]+1<<endl;
    return 0;
}
