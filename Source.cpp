
#include<iostream>
#include <list>
#include <queue>
using namespace std;
# define INF 0x3f3f3f3f 

 
typedef pair<int, int> iPair;


class Graph
{
    int V;    
    list< pair<int, int> >* adj;

public:
    Graph(int V);  // Constructor 

    // function to add an edge to graph 
    void insertEdge(int u, int v, int w);

    // prints shortest path from s 
    void SP(int s);
};

// Allocates memory for adjacency list 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::insertEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices 
void Graph::SP(int src)
{
   
    priority_queue< iPair, vector <iPair>, greater<iPair> > priorq;
    vector<int> dist(V, INF);
    priorq.push(make_pair(0, src));
    dist[src] = 0;
    while (!priorq.empty())
    {
        int su = priorq.top().second;
        priorq.pop();
        list< pair<int, int> >::iterator i;
        for (i = adj[su].begin(); i != adj[su].end(); ++i)
        {
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u. 
            if (dist[v] > dist[su] + weight)
            {
                // Updating distance of v 
                dist[v] = dist[su] + weight;
                priorq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class 
int main()
{
    // create the graph given in above fugure 
    int V;
    cout << "enter the no.of vertices:";
    cin >> V;
    cout << endl;
    int max = 0;
    Graph g(V);
 
    //  making above shown graph //the program will take source as 0
    for (int i = 0; i < V; i++)
    {
     
        for (int j = i+1; j <V; j++)
        {
            for (int k = j+1; j < V; j++)
            {
                cout << "Enter the egdes(enter the source as 0):";
                cin >> i >> j >> k;
               
                g.insertEdge(i, j, k);
             
            }
        }
        
    }

   
    g.SP(0);
    return 0;
}