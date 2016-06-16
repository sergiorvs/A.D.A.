#include <iostream>
#include <vector>
#include <deque>

#define INF 999999;

using namespace std;


class Nodo
{
public:
    int m_color;
    int m_id;
    int m_d;
    Nodo* m_pi;
    vector<Nodo*> m_adj;
    Nodo(int id)
    {
        m_id = id;
        m_d = 0;
        m_color = 0;
        m_pi = NULL;
    }
};

void BFS(vector<Nodo*>& graph, int s)
{
    Nodo* u;
    Nodo* v;
    for(int i = 0; i < graph.size(); i++)
    {
        graph[i]->m_color = 0;
        graph[i]->m_d = INF;
        graph[i]->m_pi = NULL;
    }
    graph[s]->m_color = 1;
    graph[s]->m_d = 0;
    graph[s]->m_pi = NULL;
    deque<Nodo*> Q;
    Q.push_front(graph[s]);
    while(!Q.empty())
    {
        u = Q.front();
        cout<<u->m_id<<endl;
        for(int i = 0; i < u->m_adj.size(); i++)
        {
            v = u->m_adj[i];
            if(v->m_color == 0)
            {
                v->m_color = 1;
                v->m_d = u->m_d+1;
                v->m_pi = u;
                Q.push_back(v);
            }
        }
        u->m_color = 2;
        cout<<u->m_id;
        Q.pop_front();

    }
}

int main()
{
    int v,e,a,b;
    cout<<"numero de vertices: ";cin>>v;
    cout<<"numero de aristas: ";cin>>e;
    vector<Nodo*> graph;
    cout<<"ingresando vertices: "<<endl;
    cout<<"| ";
    for(int i = 0; i < v; i++)
    {
        graph.push_back(new Nodo(i));
        cout<<i<<" | ";
    }
    cout<<endl;
    cout<<"ingresando aristas: "<<endl;
    for(int i = 0; i < e ; i++)
    {
        cout<<"nodo :";
        cin>>a;
        cout<<"adyacente con:";cin>>b;
        graph[a]->m_adj.push_back(graph[b]);
    }
    BFS(graph,0);
    return 0;
}
