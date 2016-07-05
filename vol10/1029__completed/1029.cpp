#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>

#define SIZE 100000

using namespace std;

int parent[SIZE];
int size[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

void makeUnion(int p,int q){
    if (size[p]>size[q])swap(p,q);
    size[q]+=size[p];
    parent [p] = q;
}

struct lists {
    int start;
    int end;
    int weight;
} edge[SIZE];


bool cmp (lists p, lists q){
    if ( p.weight < q.weight ) return true;
    return false;
}

void clearunion(int vv){
    for (int i=0;i<=vv;++i){
        parent[i]=i;
        size[i]=1;
    }
}

int main(){
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int vv,ee=0;
        scanf("%d",&vv);

        int a,b,w;

        while(true){
            scanf("%d %d %d",&a,&b,&w);
            if ( !a && !b && !w )break;

            edge[ee].start=a;
            edge[ee].end=b;
            edge[ee].weight=w;
            ee++;
        }
        sort(edge,edge+ee,cmp);

        int selectededge=vv+1;

        int mn=0;
        clearunion(vv);
        for (int i=0;i<ee && selectededge;++i){
            int p=parentOf(edge[i].start);
            int q=parentOf(edge[i].end);

            if ( p!=q ){
                makeUnion(p,q);
                mn+=edge[i].weight;
            }
        }
        int mx=0;
        clearunion(vv);
        selectededge=vv+1;
        for (int i=ee-1;i>=0 && selectededge;--i){
            int p=parentOf(edge[i].start);
            int q=parentOf(edge[i].end);

            if ( p!=q ){
                makeUnion(p,q);
                mx+=edge[i].weight;
            }
        }
        printf("Case %d: ",kk);
        if ( (mx+mn)%2==0 ){
            printf("%d\n",(mx+mn)/2);
        }else{
            printf("%d/2\n",(mx+mn));
        }
    }
    return 0;
}
