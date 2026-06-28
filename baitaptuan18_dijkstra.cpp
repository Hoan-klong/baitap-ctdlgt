#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

const int N = 11;
const int INF = 1000000;

// Danh sách thành phố
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

int a[N][N];

// Khởi tạo đồ thị
void initGraph()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=0;

    a[0][6]=a[6][0]=1;   // Ha Noi - Hai Duong
    a[6][7]=a[7][6]=2;   // Hai Duong - Hung Yen
    a[7][8]=a[8][7]=3;   // Hung Yen - Phu Ly
    a[8][0]=a[0][8]=4;   // Phu Ly - Ha Noi
    a[9][0]=a[0][9]=5;   // Hoa Binh - Ha Noi
    a[10][0]=a[0][10]=6; // Son Tay - Ha Noi
    a[1][0]=a[0][1]=7;   // Thai Nguyen - Ha Noi
    a[2][0]=a[0][2]=8;   // Bac Ninh - Ha Noi
    a[2][3]=a[3][2]=9;   // Bac Ninh - Bac Giang
    a[3][4]=a[4][3]=10;  // Bac Giang - Uong Bi
    a[2][4]=a[4][2]=11;  // Bac Ninh - Uong Bi
    a[4][5]=a[5][4]=12;  // Uong Bi - Hai Phong
    a[6][5]=a[5][6]=13;  // Hai Duong - Hai Phong
}

void printCities()
{
    cout << "===== DANH SACH THANH PHO =====\n";
    for(int i=0;i<N;i++)
        cout << setw(2) << i+1 << ". " << city[i] << endl;
}

void dijkstra(int start,int finish)
{
    int d[N];
    bool visited[N];
    int parent[N];

    for(int i=0;i<N;i++)
    {
        d[i]=INF;
        visited[i]=false;
        parent[i]=-1;
    }

    d[start]=0;

    for(int k=0;k<N;k++)
    {
        int u=-1;
        int Min=INF;

        for(int i=0;i<N;i++)
        {
            if(!visited[i] && d[i]<Min)
            {
                Min=d[i];
                u=i;
            }
        }

        if(u==-1) break;

        visited[u]=true;

        for(int v=0;v<N;v++)
        {
            if(a[u][v]!=0 && !visited[v])
            {
                if(d[v]>d[u]+a[u][v])
                {
                    d[v]=d[u]+a[u][v];
                    parent[v]=u;
                }
            }
        }
    }

    if(d[finish]==INF)
    {
        cout<<"\nKhong ton tai duong di!\n";
        return;
    }

    cout<<"\nTong trong so: "<<d[finish]<<endl;

    int path[N];
    int cnt=0;

    for(int v=finish;v!=-1;v=parent[v])
        path[cnt++]=v;

    reverse(path,path+cnt);

    cout<<"\nDuong di ngan nhat:\n";

    for(int i=0;i<cnt;i++)
    {
        cout<<city[path[i]];
        if(i!=cnt-1)
            cout<<" -> ";
    }

    cout<<endl;
}

int main()
{
    initGraph();

    printCities();

    int s,t;

    cout<<"\nNhap thanh pho bat dau (1-11): ";
    cin>>s;

    cout<<"Nhap thanh pho ket thuc (1-11): ";
    cin>>t;

    dijkstra(s-1,t-1);

    return 0;
}