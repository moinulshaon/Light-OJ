#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<ll> T;
void dfs(int d,ll dig) {
    if(d>12)return;
    T.pb(dig);
    dfs(d+1,dig*10+4);
    dfs(d+1,dig*10+7);
}
int tmp;
void dfs2(ll dig,int t) {
    if(dig!=1)T.pb(dig);
    for(int i=t; i<tmp; i++) {
        if(T[i]<=1000000000000LL/dig)dfs2(dig*T[i],i);
        else break;
    }
}
int lower(ll x) {
    if(x<T[0])return 0;
    if(x>=T[T.size()-1])return T.size();
    int l=0,r=T.size()-1;
    int mid;
    while(l<=r) {
        mid=(l+r)>>1;
        if(T[mid]==x)return mid+1;
        if(x>T[mid])l=mid+1;
        else r=mid-1;
    }
    return min(r,mid)+1;
}
int main() {
    T.clear();
    dfs(1,4);
    dfs(1,7);
    tmp=T.size();


    sort(T.begin(),T.end());
    dfs2(1,0);
    sort(T.begin(),T.end());
    T.erase(unique(T.begin(),T.end()),T.end());



    return 0;

    int TT;
    scanf("%d",&TT);
    for(int tt=1; tt<=TT; tt++) {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %d\n",tt,lower(b)-lower(a-1));
    }

    return 0;
}
