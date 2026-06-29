#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int N = 11;
const int INF = 1000000;

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
int mst[N][N];

void initGraph()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            a[i][j]=0;
            mst[i][j]=0;
        }

 a[0][6]=a[6][0]=1;
    a[6][7]=a[7][6]=2;
    a[7][8]=a[8][7]=3;
    a[8][0]=a[0][8]=4;
    a[9][0]=a[0][9]=5;
    a[10][0]=a[0][10]=6;
    a[1][0]=a[0][1]=7;
    a[2][0]=a[0][2]=8;
    a[2][3]=a[3][2]=9;
    a[3][4]=a[4][3]=10;
    a[2][4]=a[4][2]=11;
    a[4][5]=a[5][4]=12;
    a[6][5]=a[5][6]=13;
}

void Prim(int start)
{
    bool selected[N]={false};

    selected[start]=true;

    int edges=0;
    int total=0;

    cout<<"CAC CANH CUA CAY KHUNG:\n\n";

    while(edges<N-1)
    {
        int min=INF;
        int x=-1;
        int y=-1;

        for(int i=0;i<N;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<N;j++)
                {
                    if(!selected[j] && a[i][j]!=0)
                    {
                        if(a[i][j]<min)
                        {
                            min=a[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }

        cout<<city[x]
            <<" - "
            <<city[y]
            <<" : "
            <<min<<endl;

        mst[x][y]=min;
        mst[y][x]=min;

        total+=min;

        selected[y]=true;

        edges++;
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

    cout<<"Dinh bat dau: Hoa Binh\n\n";

    Prim(9);

    printMatrix();

    return 0;
}