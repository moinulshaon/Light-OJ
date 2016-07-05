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


struct NODE{

    NODE* edge[2];
    NODE(){
        for (int i=0;i<2;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<2;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

void add(NODE *v,int word,int height){
    if ( height <0 )return ;
    if ( v->edge[ ( word & (1<<height) ) != 0 ]== NULL ){
        v->edge[ ( word & (1<<height) ) != 0  ]=new NODE();
    }
    add(v->edge[ ( word & (1<<height) ) != 0 ],word,height-1);
}

int calc_max(NODE *v,int word,int height){
    if ( height <0 )return 0;

    int val = ( ( word & (1<<height) ) != 0 ) ;

    if ( v->edge[ !val ] != NULL ){
        return ( 1<<height ) | calc_max( v->edge[ !val ],word,height-1 );
    }else{
        return calc_max( v->edge[ val ],word,height-1 );
    }
}

int calc_min(NODE *v,int word,int height){
    if ( height <0 )return 0;

    int val = ( word & (1<<height) ) != 0;

    //cout<<val<<" "<<v->edge[val]<<" "<<v->edge[!val]<<endl;

    if ( v->edge[ val ] != NULL ){
        return calc_min( v->edge[ val ],word,height-1 );
    }else if ( v->edge[ !val ] != NULL ){
        return (1<<height) | calc_min( v->edge[ !val ],word,height-1 );
    }else{
        return INT_MAX;
    }
}


#define SIZE 50010

int pre[SIZE];
int arr[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }

        pre[0] = 0;
        for (int i=1;i<=n;++i){
            pre[i] = pre[i-1] ^ arr[i];
        }

        root = new NODE();

        add(root,0,31);

        int max_val = INT_MIN;
        int min_val = INT_MAX;

        for (int i=1;i<=n;++i){

            min_val = min( min_val , arr[i] );
            min_val = min( min_val,  calc_min( root ,pre[i] ,31 ) );
            add( root, pre[i], 31 );
            max_val = max( max_val , calc_max( root ,pre[i] ,31 ) );

        }

        printf("Case %d: %d %d\n",kk,max_val,min_val);

        delete root;

    }


    return 0;
}
