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

#define SIZE 70000
struct L{
    int x1,x2;
    int y;
    int val;
    L(int a,int b,int c,int d){
        x1=a;
        x2=b;
        y=c;
        val=d;
    }
    L(){}
}line[SIZE];

bool cmp(const L &a,const L &b ){
    return a.y<b.y;
}

vector<int> rev;
LL sum[5*SIZE];
int carry[5*SIZE];

void validate(int num,int left,int right){
    if ( carry[num] >0 ){
        sum[num] = rev[right]-rev[left];
    }else{
        sum[num] = sum[ 2*num ]+sum[ 2*num+1 ];
    }
}

void update(int num,int left,int right,int ul,int ur,int val){

    if ( left>ur || right<ul )return ;

    if ( left>=ul && right<=ur ){
        carry[num]+= val;
        validate(num,left,right);
        return ;
    }
    if ( right-left >=2 ){
        update( 2*num,left,(left+right)/2,ul,ur,val );
        update( 2*num+1,(left+right)/2,right,ul,ur,val );
    }

    validate(num,left,right);
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1; kase-- ;++kk ){
        int n;
        scanf("%d",&n);

        int a,b,c,d;
        mint mp;
        int cnt = 0;
        for (int i=0;i<n;++i){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            line[cnt++] = L( a,c,b,1 );
            line[cnt++] = L( a,c,d,-1 );
            mp[a];
            mp[c];
        }


        rev.clear();
        int sz = 0;
        rev.PB( -1 );
        snuke( mp,itr ){
            itr->second = ++sz;
            rev.PB( itr->first );
        }
        //cout<<sz<<endl;
        for (int i=0;i<cnt;++i){
            line[i].x1 = mp[ line[i].x1 ];
            line[i].x2 = mp[ line[i].x2 ];
        }

        for (int i=0;i<5*sz;++i){
            sum[i] = 0;
            carry[i] = 0;
        }

        sort( line,line+cnt,cmp );

        LL ans = 0;
        for (int i=0;i<cnt;++i){
            if ( i ){
                ans += sum[1]*( line[i].y-line[i-1].y );
            }
            update( 1,1,sz,line[i].x1,line[i].x2,line[i].val );
        }
        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
