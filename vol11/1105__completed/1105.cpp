#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

#define SIZE 50

LL lev[SIZE][2];

int get_lev(LL n){

    int cnt  = 0;
    while ( n>0 ){
        n -= lev[cnt][0] + lev[cnt][1];
        cnt++;
    }
    return cnt-1;
}

LL get(int x){
    return lev[x][0]+ lev[x][1];
}

char str[SIZE];
LL sum[SIZE];

vector<int> board[SIZE];
vector<int> parent[SIZE];



int main(){

    lev[0][0] = 0;
    lev[0][1] = 1;

    for (int i=1;i<SIZE;++i){
        lev[i][0] = lev[i-1][0] + lev[i-1][1];
        lev[i][1] = lev[i-1][0];
    }

    sum[0] = 1;
    for (int i=0;i<SIZE;++i){
        sum[i] = sum[i-1]+lev[i][0] + lev[i][1];
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL n;
        scanf("%lld",&n);

        int tar = get_lev(n);

        int cnt = 0;

        if ( tar-1>=0 )
            n-= sum[tar-1];

        //show(  n );

        str[cnt++]='1';
        int now = 1;
        while ( cnt<= tar ){
            if ( now == 1 ){
                str[cnt++] ='0';
                now = 0;
            }else{
                LL up = get(tar-cnt+1);
                //show( cnt,up,n );
                if ( n > up ){
                    str[cnt++] ='1';
                    now = 1;
                    n-= up;
                }else{
                    str[cnt++] ='0';
                    now = 0;
                }
            }
        }

        str[cnt++] ='\0';
        printf("Case %d: %s\n",kk,str);

    }


    return 0;
}
