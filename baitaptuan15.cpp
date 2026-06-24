#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 12;

vector<int> adj[N];

string city[N] = {
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

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// ================= DFS TIM DUONG DI =================

bool visited[N];
int parentDFS[N];

bool DFS(int u, int target)
{
    visited[u] = true;

    if (u == target)
        return true;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parentDFS[v] = u;

            if (DFS(v, target))
                return true;
        }
    }

    return false;
}

void printDFSPath(int start, int target)
{
    vector<int> path;

    for (int v = target; v != -1; v = parentDFS[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nDUONG DI TIM DUOC (DFS):\n";

    for (size_t i = 0; i < path.size(); i++)
    {
        cout << city[path[i]];
        if (i < path.size() - 1)
            cout << " -> ";
    }

    cout << endl;
}

// ================= BFS TIM DUONG NGAN NHAT =================

void BFSShortestPath(int start, int target)
{
    bool visited[N] = {false};
    int parent[N];

    for (int i = 1; i < N; i++)
        parent[i] = -1;

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == target)
            break;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[target])
    {
        cout << "\nKhong ton tai duong di!\n";
        return;
    }

    vector<int> path;

    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nDUONG DI NGAN NHAT (BFS):\n";

    for (size_t i = 0; i < path.size(); i++)
    {
        cout << city[path[i]];
        if (i < path.size() - 1)
            cout << " -> ";
    }

    cout << "\nSo canh: " << path.size() - 1 << endl;
}

// ================= MAIN =================

int main()
{
    // Tao do thi

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

    // Hien thi danh sach thanh pho

    cout << "===== DANH SACH THANH PHO =====\n";

    for (int i = 1; i <= 11; i++)
    {
        cout << i << ". " << city[i] << endl;
    }

    int start, target;

    cout << "\nNhap thanh pho bat dau (1-11): ";
    cin >> start;

    cout << "Nhap thanh pho ket thuc (1-11): ";
    cin >> target;

    // DFS

    for (int i = 1; i <= 11; i++)
    {
        visited[i] = false;
        parentDFS[i] = -1;
    }

    if (DFS(start, target))
    {
        printDFSPath(start, target);
    }
    else
    {
        cout << "\nKhong tim thay duong di!\n";
    }

    // BFS

    BFSShortestPath(start, target);

    return 0;
}