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

typedef pair<LL,LL> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


#define SIZE 20100

pint arr[SIZE];
int n,d;

double tar;

bool cmp(pint a,pint b){
    return a.X-tar*a.Y > b.X-tar*b.Y;
}

bool pos(double mid){
    tar = mid;
    sort( arr,arr+n,cmp );

    pint ret = MP(0,0);
    for (int i=0;i<d;++i){
        //show( arr[i].X,arr[i].Y );
        ret.X += arr[i].X;
        ret.Y += arr[i].Y;
    }

    return ( double(ret.X)/ret.Y >= mid );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&d);
        d = n-d;

        for (int i=0;i<n;++i){
            scanf("%lld %lld",&arr[i].X,&arr[i].Y);
            //show( arr[i].X,arr[i].Y );
        }

        double low = 0,high=100;
        for ( int it = 0;it<100 && low<high;++it ){

            double mid = (low+high)/2;

            if ( pos(mid) ){
                low = mid+1e-9;
            }else{
                high = mid-1e-9;
            }
        }


        printf("Case %d: %.8f\n",kk,low*100);

    }

    return 0;
}
