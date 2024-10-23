#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i <= b ; i++ )


typedef long long ll;



const int MAXN = 25;

int M;

string city[MAXN] = { "Oradea" , "Zerind"         , "Arad"    , "Timisoara" , "Lugoj"   , "Mehadia"   , "Dobreta" ,
                /**    0             1                 2            3             4           5             6       */
                      "Sibiu"  , "Rimnicu Vilcea" , "Craiova" , "Fagaras"   , "Pitesti" , "Bucharest" , "Giurgiu" ,
                /**    7             8                 9            10            11          12             13      */
                      "Neamt"  , "Lasi"           , "Vaslui"  , "Urziceni"  , "Hirsova" , "Eforie"
                /**   14             15                16           17            18          19     */  }  ;


int road[MAXN][MAXN];

bool kt[MAXN];
bool tim_thay;
int road_cost = 0 , des , start;

void DFS( int x )
{
    kt[x] = true;

    cout << "in " << x << endl;

    if( x == des )
    {
        tim_thay = true;
        cout << "chi phi duong di tu diem bat dau den ket thuc duoc tim thay dau tien la: " << road_cost << endl;
        return;
    }


    FOR(i , 0 , 19) if( road[x][i] != -1 && kt[i] == false )
    {
        road_cost += road[x][i];
        DFS( i );
        if( tim_thay == true ) return;
    }

    kt[x] = false;
    cout << "out " << x << endl;
}


queue<int> qu;
int cost_BFS[MAXN]; /// tuc la gia tri cua duong di dau tien duoc phat hien tu thanh pho bat dau den thanh pho i

void BFS()
{
    FOR(i , 0 , 19) cost_BFS[i] = -1; /// tuc la chua den

    cost_BFS[start] = 0;
    qu.push(start); /// cho diem bat dau vao queue
    kt[start] = true;

    while( qu.empty() == false )
    {
        int u = qu.front();
        qu.pop();

        if( u == des )
        {
            cout << "chi phi duong di tu diem bat dau den ket thuc duoc tim thay dau tien la: " << cost_BFS[des] << endl;
            return;
        }

        cout << u << endl;

        FOR(i , 0 , 19) if( road[u][i] != -1 && kt[i] == false )
        {
            qu.push(i);
            cost_BFS[i] = cost_BFS[u] + road[u][i];
            kt[i] = true; /// dam bao chi cap nhat dung 1 lan
        }
    }

}

int main()
{
    freopen("nhap.inp" , "r" , stdin);
    freopen("xuat.out" , "w" , stdout );



    FOR(i , 0 , 19) FOR(j , 0 , 19) road[i][j] = -1;

    cin >> M;


    while( M-- )
    {
        int u , v , cost;
        cin >> u >> v >> cost;

        road[u][v] = road[v][u] = cost;
    }




    FOR(i , 0 , 19) kt[i] = false;

    tim_thay = false;
    start = 0; /// diem bat dau di
    des = 12 ; /// thanh pho Bucharest




    clock_t s , t;
    double dur;

    s = clock();

     BFS();
    /// DFS(start);


    t = clock();

    dur =  (double) ( t - s )  / CLOCKS_PER_SEC;
    printf(" thoi gian chay la  %.30f" , dur );

}
