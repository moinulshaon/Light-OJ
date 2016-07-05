#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 33333;
int x[MAXN<<1],t,n,sum[MAXN<<3],cnt[MAXN<<3],x_num,line_num;
unsigned __int64 ans;
struct Line{
    int l,r,h,s;
    Line(){}
    Line(int ll,int rr,int hh,int ss):l(ll),r(rr),h(hh),s(ss){}
    bool operator < (const Line &l) const{
        return h<l.h;
    }
}L[MAXN<<1];
#define lson l,m,rt<<1
#define rson m,r,rt<<1|1
void build(){
    memset(sum,0,sizeof(sum));
    memset(cnt,0,sizeof(cnt));
    x_num = line_num = 0;
    ans = 0;
}
void pushUP(int rt,int l,int r){
    if(cnt[rt]){
        //cout<<rt<<" "<<l<<" "<<r<<" "<<x[r]<<" "<<x[l]<<endl;
        sum[rt] = x[r]-x[l];
    }else{
        sum[rt] = sum[rt*2]+sum[rt*2+1];
    }
}
void update(int L,int R,int s,int l,int r,int rt){
    if(L<=l&&R>=r){
        cnt[rt]+=s;
        pushUP(rt,l,r);
        return;
    }
    cout<<rt<<endl;
    //if(l==r-1)return;
    int m = (l+r)>>1;
    if(m>L)update(L,R,s,lson);
    if(m<R)update(L,R,s,rson);
    pushUP(rt,l,r);
}
int search(int k){
    int l=0,r=x_num-1,m;
    while(l<=r){
        m = (l+r)>>1;
        if(x[m]==k)return m;
        else if(k<x[m])r = m-1;
        else l = m+1;
    }
    return -1;
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d",&n);
        build();
        for(int i=0;i<n;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            x[x_num++] = a;
            x[x_num++] = c;
            L[line_num++] = Line(a,c,b,1);
            L[line_num++] = Line(a,c,d,-1);
        }
        sort(x,x+x_num);sort(L,L+line_num);
        int temp = 1;
        for(int i=1;i<x_num;i++)if(x[i]!=x[i-1])x[temp++]=x[i];
        //for( int i=0;i<temp;++i)cout<<x[i]<<endl;
        x_num = temp;
        for(int i=0;i<line_num;i++){
            int l = search(L[i].l);
            int r = search(L[i].r);
            if(!i){
                //cout<<l<<" "<<r<<endl;
                update(l,r,L[i].s,0,x_num-1,1);
            }else{
                ans += (__int64)sum[1]*(L[i].h-L[i-1].h);
                update(l,r,L[i].s,0,x_num-1,1);
            }
        }
        printf("Case %d: %llu\n",cas,ans);
    }
    return 0;
}
