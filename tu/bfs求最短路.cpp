#include <queue>
#include <iostream>
#include <algorithm>
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 1010;

int g[N][N];
PII memory[N][N];

int st[N][N];
int n;

void bfs()
{
    queue<PII> q;
    q.push({n - 1, n - 1});
    st[n - 1][n - 1] = true;
    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + t.x, y = dy[i] + t.y;
            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            if (st[x][y])
                continue;
            if (g[x][y] == 1)
                continue;
            q.push({x, y});
            st[x][y] = true;
            memory[x][y] = t;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    bfs();
    PII end = {0, 0};
    cout << 0 << ' ' << 0 << endl;

    while (end.x != n - 1 || end.y != n - 1)
    {
        printf("%d %d\n", memory[end.x][end.y].x, memory[end.x][end.y].y);
        int x = end.x, y = end.y;
        end.x = memory[x][y].x, end.y = memory[x][y].y;
    }

    return 0;
}
