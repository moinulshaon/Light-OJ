#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 110;
int vis[maxn*maxn];
int y[maxn*maxn];
vector <int> G[maxn*maxn];
int n, m;
char a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
struct node
{
    int x, y;
    node() {} node(int x, int y): x(x), y(y) {}
};
vector <node> X[10010];
bool dfs(int u)
{
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(y[v] == -1 || dfs(y[v]))
        {
            y[v] = u;
            return true;
        }
    }
    return false;
}
int match()
{
    int ans = 0;
    memset(y, -1, sizeof(y));
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}
int main()
{
    int cas = 1;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int r, C;
        scanf("%d %d", &r, &C);
        for(int i = 0; i < r; i++) scanf("%s", a[i]);
        n = 0, m = 0;
        memset(b, 0, sizeof(b));
        for(int i = 0; i < r; i++)
        {
            int j = 0, flag = 1, flag2 = 0;
            while(j < C)
            {
                while(a[i][j] == 'W' && j < C)
                {
                    flag2 = 1;
                    flag++;
                    j++;
                }
                if(j < C && a[i][j] == '.')
                {
                    if(!flag2)
                    {
                        flag2 = 1;
                        flag = 1;
                    }
                    if(flag)
                    {
                        ++n;
                        flag = 0;
                    }
                    b[i][j] = n;
                }
                j++;
            }
        }
        memset(c, 0, sizeof(c));
        for(int i = 0; i < C; i++)
        {
            int j = 0, flag = 1, flag2 = 0;
            while(j < r)
            {
                while(a[j][i] == 'W' && j < r)
                {
                    flag++;
                    j++;
                }
                if(j < r && a[j][i] == '.')
                {
                    if(!flag2)
                    {
                        flag2 = 1;
                        flag = 1;
                    }
                    if(flag)
                    {
                        ++m;
                        flag = 0;
                    }
                    c[j][i] = m;
                }
                j++;
            }
        }
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
            X[i].clear();
        }
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < C; j++)
            {
                //printf("%d...", b[i][j]);
                if(a[i][j] == '.')
                {
                    G[b[i][j]].push_back(c[i][j]);
                    X[b[i][j]].push_back(node(i, j));
                }
            }
            //puts("");
        }
        printf("Case %d: %d\n", cas++, match());
        for(int i = 1; i <= m; i++)
        {
            if(y[i] == -1) continue;
            int u = y[i];
            for(int j = 0; j < X[u].size(); j++)
            {
                node no = X[u][j];
                if(c[no.x][no.y] == i)
                {
                    a[no.x][no.y] = 'T';
                    break;
                }
            }
        }
        for(int i = 0; i < r; i++) puts(a[i]);
    }
    return 0;
}
