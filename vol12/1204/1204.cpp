#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int n,k;
struct ttt{
    int x,y1,y2,flag;
}segment[70000];
int segCnt;
int y[70000];
int yCnt;


struct nnn{
    int left,right,cover,slen[12];
}vertex[400000];

void build( int node,int left,int right ){

    vertex[node].left=left;
    vertex[node].right=right;
    vertex[node].cover=0;
    memset(vertex[node].slen,0,sizeof(vertex[node].slen));
    vertex[node].slen[0]=y[ right ]-y[left];

    if ( left==right )return ;
    build(2*node,left,(left+right)>>1);
    build(2*node+1,(left+right)>>1+1,right);

}


bool cmp(const ttt&a,const ttt&b){
    if( a.x == b.x )
		return a.flag > b.flag;
	return a.x < b.x;
}

int ul,ur;
void update(int node,int v){

    if (vertex[node].right<ul || vertex[node].left>ur)return ;
    else if (vertex[node].left>=ul && vertex[node].right<=ur){
        vertex[node].cover+=v;
    }else{
        update(2*node,l,(l+r)/2);
        update(2*node+1,(l+r)/2+1,r);

        while (node){
            tree[node]=tree[2*node]+tree[2*node+1];
            node/=2;
        }

    }
}

int main(){
    int kase,a,b,c,d;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&k);
        segCnt=0;

        for (int i=0;i<n;++i){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            a++;
            c++;

            segment[ segCnt ].x=a;
            segment[ segCnt ].y1=b;
            segment[ segCnt ].y2=d;
            segment[ segCnt ].flag= -1;

            y[segCnt++]=b;

            segment[ segCnt ].x=c;
            segment[ segCnt ].y1=b;
            segment[ segCnt ].y2=d;
            segment[ segCnt ].flag= -1;

            y[segCnt++]=d;
        }

        sort(y,y+segCnt);
        yCnt=unique(y,y+n)-y;

        sort(segment,segment+segCnt,cmp);

        build(1,0,yCnt-1);
        update(1,segment[0]);

        LL ans=0;
        for (int i=1;i<segCnt;++i){
            ans+= vertex[1].slen[k]*(segment[i].x-segment[i-1].x);
            ul=segment[i].y1;
            ur=segment[i].y2;
            update(1,segment[i].flag);
        }

    }
}
