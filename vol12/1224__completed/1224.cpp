#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

struct NODE{
    int height;
    int prefix;
    NODE* edge[4];
    NODE(){
        prefix=0;
        height= -1;
        for (int i=0;i<4;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<4;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

int ff(char c){
    if ( c=='A' )return 0;
    else if ( c=='C' )return 1;
    else if ( c=='G' )return 2;
    else return 3;
}

void add(NODE *v,char* word,int h){
    //printf("%s\n",word);
    v->height=h;
    v->prefix++;
    if ( word[0]=='\0' )return ;
    if ( v->edge[ ff(word[0]) ]== NULL ){
        v->edge[ ff(word[0]) ]=new NODE();
    }

    add(v->edge[ ff(word[0]) ],word+1,h+1);
}
int ans;
void dfs(NODE *v){
    //printf("%d\n",v->height);
    ans=(ans < (v->height*v->prefix) )?(v->height*v->prefix):ans;
    for (int i=0;i<4;++i){
        if ( v->edge[i]!=NULL ){
            dfs( v->edge[i] );
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int n,kase;
    char line[55];
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        root=new NODE();
        while (n--){
            scanf("%s",line);
            add(root,line,0);
        }
        ans=0;
        dfs(root);

        printf("Case %d: %d\n",kk,ans);
        delete root;
    }
    return 0;
}
