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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

char board[36][36];
int row;
int col;



int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

struct NODE{
    bool ok;
    int prv;
    //int words;
    //int prefix;
    NODE* edge[26];
    NODE(){
        //words=prefix=0;
        ok=false;
        prv= -1;

        for (int i=0;i<26;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<26;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

void add(NODE *v,char* word){

    if ( word[0]=='\0' ){
        //v->words++;
    }else{
        //v->prefix++;
        if ( v->edge[ word[0]-'a' ]== NULL ){
            v->edge[ word[0]-'a' ]=new NODE();
        }
        add(v->edge[ word[0]-'a' ],word+1);
    }
}


bool another(NODE *v,char* word){
    //printf("%s\n",word);
    if ( word[0]=='\0' )return v->ok;
    else if ( ! v->ok )return false;
    return another(v->edge[ word[0]-'a' ],word+1);
}

int shaon(int x,int y,NODE* v){

    v->ok=true;

    int rr,cc;

    for (int k=0;k<4;++k){
        rr=x+dr[k];
        cc=y+dc[k];
        if ( rr>=0 && rr<row && cc>=0 && cc<col  ){
            if ( v->edge[ board[rr][cc] -'a'] != NULL ){
                shaon(rr,cc,v->edge[ board[rr][cc] -'a']);
                v->edge[ board[rr][cc] -'a']
            }
        }
    }

}

char save[20][20];
int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }

        root=new NODE();

        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%s",save[i]);
            add(root,save[i]);
        }

        root->ok=true;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( root->edge[ board[i][j]-'a' ] != NULL ){
                    shaon( i,j,root->edge[ board[i][j]-'a' ] );
                    //printf("new\n");
                }
            }
        }

        for (int i=0;i<n;++i){
            printf("%s: %s\n", save[i], another( root,save[i] ) ? "YES" : "NO");
        }
    }




    return 0;
}
