#include <iostream>
#include <vector>



using namespace std;


int time;

class Nodo
{
public:
    int m_color;            ///Color:::::> 0->white 1->gray 2->black
    int m_id;
    int m_d;
    int m_f;
    Nodo* m_pi;
    vector<Nodo*> m_adj;
    Nodo(int id)
    {
        m_id = id;
        m_d = 0;
        m_color = 0;
        m_pi = NULL;
        m_f = 0;
    }
};

void DFS_VISIT(vector<Nodo*>& graph, Nodo* u)
{
    cout<<u->m_id<<endl;
    Nodo* v;
    time = time+1;
    u->m_d = time;
    u->m_color = 1;
    for(int i = 0; i < u->m_adj.size(); i++)
    {
        v = u->m_adj[i];
        if(v->m_color == 0)
        {
            v->m_pi = u;
            DFS_VISIT(graph,v);
        }
    }
    u->m_color = 2;
    time = time + 1;
    u->m_f = time;
}

void DFS(vector<Nodo*>& graph)
{
    for(int i = 0; i < graph.size(); i++)
    {
        graph[i]->m_color = 0;
        graph[i]->m_pi = NULL;
    }
    time = 0;
    for(int i = 0; i < graph.size(); i++)
    {
        if(graph[i]->m_color == 0)
        {
            DFS_VISIT(graph,graph[i]);
        }
    }
}



int main()
{
    int v,e,a,b;
    cout<<"ingrese numero de vertices: ";cin>>v;
    cout<<"ingrese numero de aristas: ";cin>>e;
    vector<Nodo*> graph;
    cout<<"| ";
    for(int i = 0; i < v; i++)
    {
        graph.push_back(new Nodo(i));
        cout<<i<<" | ";
    }
    cout<<endl;

    for(int i = 0; i < e ; i++)
    {
        cout<<"vertice: ";cin>>a;
        cout<<"adyacente con: ";cin>>b;
        graph[a]->m_adj.push_back(graph[b]);
    }
    DFS(graph);
    return 0;
}
