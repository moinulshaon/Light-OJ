#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))


#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)

#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n)  while(scanf("%d",&n)!=-1)
using namespace std;


void RD(int &x){scanf("%d",&x);}
void RD(i64 &x){scanf("%I64d",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(i64 &x,i64 &y){scanf("%I64d%I64d",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(i64 &x,i64 &y,i64 &z){scanf("%I64d%I64d%I64d",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(i64 x) {printf("%I64d\n",x);}
void PR(u32 x) {printf("%u\n",x);}
void PR(double x) {printf("%.10lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

const int mod=1000000007;
const double inf=1e50;
const int INF=1000000000;
const int N=105;


int f[N][N][N*3],p[N][N][N*3];
int n,m,K;
string a,b,c;
int next[N*3][26];

void init()
{
    int i,j;
    clr(next,-1);
    FORL0(i,K-1)
    {
        FOR0(j,26) next[i][j]=next[i+1][j];
        next[i][c[i]-'a']=i;
    }
}

void up(int &x,int y)
{
    x+=y;
    if(x>=mod) x-=mod;
}

int check(string a,int i,int n,int k)
{
    int x,t;
    for(x=i;x<n;x++)
    {
        t=a[x]-'a';
        if(next[k][t]==-1) return 0;
        k=next[k][t]+1;
    }
    return 1;
}

int DFS(int i,int j,int k)
{
    if(i==n)
    {
        if(check(b,j,m,k)) return m-j;
        return INF;
    }
    if(j==m)
    {
        if(check(a,i,n,k)) return n-i;
        return INF;
    }
    if(f[i][j][k]!=-1) return f[i][j][k];
    int ans=INF;
    if(a[i]==b[j])
    {
        if(next[k][a[i]-'a']>=0)
        {
            ans=min(ans,DFS(i+1,j+1,next[k][a[i]-'a']+1)+1);
        }
    }
    else
    {
        if(next[k][a[i]-'a']>=0)
        {
            ans=min(ans,DFS(i+1,j,next[k][a[i]-'a']+1)+1);
        }
        if(next[k][b[j]-'a']>=0)
        {
            ans=min(ans,DFS(i,j+1,next[k][b[j]-'a']+1)+1);
        }
    }
    return f[i][j][k]=ans;
}


int DFS1(int i,int j,int k)
{
    if(i==n||j==m) return 1;
    if(p[i][j][k]!=-1) return p[i][j][k];
    int ans=0,x;
    if(a[i]==b[j])
    {
        x=next[k][a[i]-'a'];
        if(x!=-1&&DFS(i+1,j+1,x+1)+1==f[i][j][k]) up(ans,DFS1(i+1,j+1,x+1));
    }
    else
    {
        x=next[k][a[i]-'a'];
        if(x!=-1&&DFS(i+1,j,x+1)+1==f[i][j][k]) up(ans,DFS1(i+1,j,x+1));
        x=next[k][b[j]-'a'];
        if(x!=-1&&DFS(i,j+1,x+1)+1==f[i][j][k]) up(ans,DFS1(i,j+1,x+1));
    }
    return p[i][j][k]=ans;
}


string ans;


void DFS2(int i,int j,int k)
{
    if(i==n)
    {
        ans+=b.substr(j,m-j);
        return;
    }
    if(j==m)
    {
        ans+=a.substr(i,n-i);
        return;
    }
    int L=f[i][j][k],x,y;
    if(a[i]==b[j])
    {
        ans+=a[i];
        x=next[k][a[i]-'a'];
        DFS2(i+1,j+1,x+1);
    }
    else
    {
        x=next[k][a[i]-'a'];
        y=next[k][b[j]-'a'];
        if(x!=-1&&y!=-1&&L==DFS(i+1,j,x+1)+1&&L==DFS(i,j+1,y+1)+1)
        {
            if(a[i]<b[j])
            {
                ans+=a[i];
                DFS2(i+1,j,x+1);
            }
            else
            {
                ans+=b[j];
                DFS2(i,j+1,y+1);
            }
        }
        else if(x!=-1&&L==DFS(i+1,j,x+1)+1)
        {
            ans+=a[i];
            DFS2(i+1,j,x+1);
        }
        else
        {
            ans+=b[j];
            DFS2(i,j+1,y+1);
        }
    }
}


void deal()
{
    clr(f,-1); clr(p,-1);
    int minLen=DFS(0,0,0);
    if(minLen>=INF)
    {
        puts("0");
        puts("NOT FOUND");
        return;
    }
    int cnt=DFS1(0,0,0);
    PR(cnt);
    ans="";
    DFS2(0,0,0);
    PR(ans);
}


int main()
{
    freopen("in.txt","r",stdin);
    int num=0;
    rush()
    {
        RD(a); n=SZ(a);
        RD(b); m=SZ(b);
        RD(c); K=SZ(c);
        init();
        printf("Case %d: ",++num);
        deal();
    }
}
