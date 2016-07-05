#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

int ff(char c){
    if ( islower(c) ){
        return c-'a';
    }else{
        return c-'A'+26;
    }
}

struct NODE{
    int words;
    vector<NODE*> edge;
    map<int,int> mp;
    NODE(){
        words=0;
    }
    ~NODE(){
        for (int i=0;i<edge.size();++i){
            delete edge[i];
        }
    }
}*root;

void add(NODE *v,char* word){
    //printf("%s\n",word);
    if ( word[0]=='\0' ){
        v->words++;
    }else{
        //v->prefix++;
        if ( v->mp.find(ff(word[0])) == v->mp.end() ){
            v->edge.push_back( new NODE() );
            v->mp[ ff(word[0]) ]=v->edge.size()-1;
        }

        add(v->edge[ v->mp[ ff(word[0]) ] ],word+1);
    }
}

int dfs(NODE *v,char *w){
    //printf("%s\n",w);
    if ( w[0]=='\0' )return v->words;
    else if ( v->mp.find( ff(w[0]) )==v->mp.end() ){
        return 0;
    }
    dfs(v->edge[ v->mp[ ff(w[0]) ] ],w+1);
}



int main(){
    freopen("in.txt","r",stdin);

    int n,kase,q,tmp;
    char dic[110],line[100100];
    char *pch;
    scanf("%d",&kase);
    gets(dic);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        gets(dic);
        root=new NODE();
        while (n--){
            scanf("%s",dic);
            tmp=strlen(dic);
            if ( tmp>3 ){
                sort(dic+1,dic+tmp-1);
            }

            //printf("%s\n",dic);
            add(root,dic);
        }
        scanf("%d",&q);
        gets(dic);
        printf("Case %d:\n",kk);
        while (q--){
            gets(line);
            pch = strtok (line," ");
            int ans=1;

            while (pch != NULL){
                //printf ("%s1\n",pch);

                tmp=strlen(pch);
                if ( tmp>3 ){
                    sort(pch+1,pch+tmp-1);
                }
                //printf("%s\n",pch);

                ans*=dfs(root,pch);
                pch = strtok (NULL, " ");

            }

            printf("%d\n",ans);
        }
        delete root;
    }
    return 0;
}
