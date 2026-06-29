#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

const int N = 11;

string city[N] = {
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

struct Edge
{
    int us;
    int v;
    int w;
};

Edge edge[20];

int parent[N];
int mst[N][N];

int Find(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x,int y)
{
    parent[Find(x)] = Find(y);
}

int cmp(Edge a,Edge b)
{
    return a.w < b.w;
}

void initGraph()
{
    edge[0]={0,6,1};
    edge[1]={6,7,2};
    edge[2]={7,8,3};
    edge[3]={8,0,4};
    edge[4]={9,0,5};
    edge[5]={10,0,6};
    edge[6]={1,0,7};
    edge[7]={2,0,8};
    edge[8]={2,3,9};
    edge[9]={3,4,10};
    edge[10]={2,4,11};
    edge[11]={4,5,12};
    edge[12]={6,5,13};

    for(int i=0;i<N;i++)
    {
        parent[i]=i;
        for(int j=0;j<N;j++)
            mst[i][j]=0;
    }
}

void Kruskal()
{
    sort(edge,edge+13,cmp);

    int total=0;
    int cnt=0;

    cout<<"CAC CANH CUA CAY KHUNG\n\n";

    for(int i=0;i<13 && cnt<N-1;i++)
    {
        int us=edge[i].us;
        int v=edge[i].v;

        if(Find(u)!=Find(v))
        {
            Union(u,v);

            mst[us][v]=edge[i].w;
            mst[v][us]=edge[i].w;

            cout<<city[u]
                <<" - "
                <<city[v]
                <<" : "
                <<edge[i].w<<endl;

            total+=edge[i].w;
            cnt++;
        }
    }

    cout<<"\nTong trong so = "<<total<<endl;
}

void printMatrix()
{
    cout<<"\nMA TRAN KE CUA CAY KHUNG\n\n";

    cout<<setw(12)<<"";

    for(int i=0;i<N;i++)
        cout<<setw(5)<<i+1;

    cout<<endl;

    for(int i=0;i<N;i++)
    {
        cout<<setw(12)<<i+1;

        for(int j=0;j<N;j++)
            cout<<setw(5)<<mst[i][j];

        cout<<endl;
    }
}

int main()
{
    initGraph();

    Kruskal();

    printMatrix();

    return 0;
} 