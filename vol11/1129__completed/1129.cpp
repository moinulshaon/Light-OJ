#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

struct NODE{
    //int words;
    //int prefix;
    NODE* edge[10];
    NODE(){
        //words=prefix=0;
        for (int i=0;i<10;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<10;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

void add(NODE *v,char* word){
    //printf("%s\n",word);
    if ( word[0]=='\0' ){
        //v->words++;
    }else{
        //v->prefix++;
        if ( v->edge[ word[0]-'0' ]== NULL ){
            v->edge[ word[0]-'0' ]=new NODE();
        }
        add(v->edge[ word[0]-'0' ],word+1);
    }
}

int cnt;

void dfs(NODE *v){

    bool leaf=true;
    for (int i=0;i<10;++i){
        if ( v->edge[i] !=NULL ){
            leaf=false;
            dfs(v->edge[i]);
        }
    }
    if ( leaf )cnt++;

}

int main(){
    freopen("in.txt","r",stdin);

    int n,kase;
    char line[15];
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        root=new NODE();

        for (int i=0;i<n;++i){
            scanf("%s",line);
            add(root,line);
        }
        cnt=0;
        dfs(root);


        if ( cnt==n ){
            printf("Case %d: YES\n",kk);
        }else{
            printf("Case %d: NO\n",kk);
        }

        delete root;
    }
    return 0;
}
