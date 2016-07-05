#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

bool vis[16][16][16][16][5][5];
double dp[16][16][16][16][5][5];

int a,b,c,d;

double func( int p,int q,int r,int s ,int jone,int jtwo){

    int have[5]={0};

    have[1]=p;
    have[2]=q;
    have[3]=r;
    have[4]=s;

    have[jone]++;
    have[jtwo]++;


    if ( have[1] >= a && have[2] >= b &&  have[3] >= c && have[4] >= d  )return 0;

    double &ret = dp[p][q][r][s][jone][jtwo];

    if ( vis[p][q][r][s][jone][jtwo]  )return ret;
    vis[p][q][r][s][jone][jtwo] = true;
    ret = 0;

    have[1] = 13 - p;
    have[2] = 13 - q;
    have[3] = 13 - r;
    have[4] = 13 - s;

    int sum = 0;
    for (int i=1;i<=4;++i){
        sum += have[i];
    }
    if ( jone == 0 )sum++;
    if ( jtwo == 0 )sum++;

    if ( sum == 0 )return ret = (1<<29);

    if ( have[1] >0 )
    ret += double(have[1])/sum * ( 1+ func( p+1,q,r,s,jone,jtwo ) );
    if ( have[2] >0 )
    ret += double(have[2])/sum * ( 1+ func( p,q+1,r,s,jone,jtwo ) );
    if ( have[3] >0 )
    ret += double(have[3])/sum * ( 1+ func( p,q,r+1,s,jone,jtwo ) );
    if ( have[4] >0 )
    ret += double(have[4])/sum * ( 1+ func( p,q,r,s+1,jone,jtwo ) );

    if ( jone == 0 ){
        ret += 1.0/sum * ( 1+min( func(p,q,r,s,1,jtwo) , min( func(p,q,r,s,2,jtwo) ,
                                                            min( func(p,q,r,s,3,jtwo) , func(p,q,r,s,4,jtwo) ) )  ) );
    }
    if ( jtwo == 0 ){
        ret += 1.0/sum * ( 1+ min( func(p,q,r,s,jone,1) , min( func(p,q,r,s,jone,2) ,
                                                            min( func(p,q,r,s,jone,3) , func(p,q,r,s,jone,4) ) )  ) );
    }
    return ret;
}


int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d %d %d",&a,&b,&c,&d);

        printf("Case %d: ",kk);

        if ( max(0,a-13) + max(0,b-13) + max(0,c-13)+ max(0,d-13) >2 ){
            printf("-1\n");
            continue;
        }

        CLR(vis);

        printf("%.7lf\n",func(0,0,0,0,0,0));

    }


    return 0;
}
