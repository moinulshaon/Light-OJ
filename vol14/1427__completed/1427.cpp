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

struct NODE {
	int cnt;
	bool vis;
	int lev;
	NODE *next[27];
	bool donenew[27];
	vector <NODE *> out;
	NODE(int x) {
		for( int i = 0; i < 27; i++ ){
            next[i] = NULL;
            donenew[i]=false;
		}
		lev=x;
		out.clear();
		vis = false;
		cnt=0;
	}

	~NODE(){
        for( int i = 0; i < 27; i++ )
            if( donenew[i] )
                delete next[i];
	}

}*root;



void buildtrie(char dic[][5010],int n){

    root = new NODE(0);
	for( int i = 0; i < n; i++ ) {
		NODE *p = root;
		for( int j = 0; dic[i][j] ; j++ ) {
			char c = dic[i][j]- 'a' + 1  ;
			if( !p->next[c] ){
                p->next[c] = new NODE(p->lev+1);
                p->donenew[c] = true;
			}
            p = p->next[c];
		}
	}
	queue <NODE *> q;
	for( int i = 0; i < 27; i++ ) {
		if( !root->next[i] )
            root->next[i] = root;
		else {
			q.push( root->next[i] );
			root->next[i]->next[0] = root;
		}
	}
	while( !q.empty() ) {
		NODE *u = q.front(); q.pop();
		for( int i = 1; i < 27; i++ ){
            if( u->next[i] ) {
                NODE *v = u->next[i];
                NODE *w = u->next[0];
                while( !w->next[i] )
                    w = w->next[0];
                v->next[0] = w = w->next[i];
                w->out.push_back( v );
                q.push(v);
            }
		}
    }
}
NODE *save;
void aho_corasick( NODE *p, char *word ) {
	for( int i = 0; word[i]; i++ ) {
		char c = word[i]-'a'+1 ;
		save= p;
		while( !p->next[c] )
            p = p->next[0];
		p = p->next[c];
		save->next[c] = p;

		p->cnt++;
	}
}

int dfs( NODE *p ) {
	if( p->vis ) return p->cnt;
	for( int i = 0; i < p->out.size(); i++ )
        p->cnt += dfs( p->out[i] );
	p->vis = true;
	return p->cnt;
}


char query[1000100];
char dic[5010][5010];

int main(){
    FRO

    int kase;
    gets(query);
    sscanf(query,"%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        gets(query);
        sscanf(query,"%d",&n);

        gets(query);

        for (int i=0;i<n;++i){
            gets(dic[i]);
        }

        buildtrie(dic,n);

        aho_corasick( root, query );

        printf("Case %d:\n",kk);

        for( int i = 0; i < n; i++ ) {
            NODE *p = root;
            for( int j = 0; dic[i][j]; j++ ) {
                char c = dic[i][j] -'a' +1;
                p = p->next[c];
            }
            printf("%d\n", dfs( p ));
        }
        delete root;
    }


    return 0;
}
