#include <iostream>
#include <list>
#include <queue>
using namespace std;

const int n = 11;
//thanhpho
string city[n + 1] = {
    "",
    "Ha Noi",
    "Thai Nguyen",
    "Bac Ninh",
    "Bac Giang",
    "Uong Bi",
    "Hai Phong",
    "Hai Duong",
    "Hung Yen",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay"
};

list<int> adj[n + 1];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(int start)
{
    bool visited[n + 1] = {false};

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << city[u] << endl;

        for(int v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    // dsthanhpho
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,7);
    addEdge(1,9);
    addEdge(1,10);
    addEdge(1,11);

    addEdge(3,4);
    addEdge(3,5);

    addEdge(4,5);

    addEdge(5,6);

    addEdge(6,7);

    addEdge(7,8);

    addEdge(8,9);

    cout << "BFS tu Ha Noi:\n";
    BFS(1);

    return 0;
}