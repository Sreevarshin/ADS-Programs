
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{

private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int v, int w) {

        adj[v].push_back(w);
    }
    void BFS(int startVertex)
    {

        vector<bool> visited(V, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);
        while (!q.empty()) {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            for (const auto& neighbor : adj[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};


int main()
{

   int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    Graph g(vertices);
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int n;
    cout<<"Enter the starting vertex for traversal";
    cin>>n;
    cout<<"Traversed graph:";
    g.BFS(n);
    cout<<endl;

    return 0;

}

