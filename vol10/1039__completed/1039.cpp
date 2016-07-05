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

string tmp,start,fin,str;
set<string> ss;

int bfs(){

    queue<string> q;
    queue<int> ans;

    if ( ss.find( start )==ss.end() ){
        q.push( start );
        ans.push(0);

        ss.insert( start );
    }


    while( !q.empty() ){
        tmp=q.front();q.pop();
        int cnt=ans.front();ans.pop();

        if ( tmp==fin )return cnt;

        for (int i=0;i<3;++i){
            str=tmp;
            str[i]++;
            if ( str[i]>'z' )str[i]='a';

            if ( ss.find( str )==ss.end() ){
                q.push( str );
                ans.push(cnt+1);
                ss.insert( str );
            }
        }

        for (int i=0;i<3;++i){
            str=tmp;
            str[i]--;
            if ( str[i]<'a' )str[i]='z';

            if ( ss.find( str )==ss.end() ){
                q.push( str );
                ans.push(cnt+1);
                ss.insert( str );
            }
        }

    }
    return -1;
}


struct NODE{
    //int words;
    //int prefix;
    NODE* edge[26];
    NODE(){
        //words=prefix=0;
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
    //printf("%s\n",word);
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

bool find( NODE *v,char* word ){
    if ( word[0]=='\0' ){
        return true;
    }else{
        if ( v->edge[ word[0]-'a' ]== NULL ){
            return false;;
        }
    }
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        cin>>start>>fin;

        ss.clear();
        root=new NODE();

        int n;
        string ccc;
        cin>>n;

        string xx,yy,zz;
        char word[10];
        while( n-- ){
            cin>>xx>>yy>>zz;
            //cout<<xx<<yy<<zz<<endl;

            for (int i=0;i<xx.length();++i){
                for (int j=0;j<yy.length();++j){
                    for (int k=0;k<zz.length();++k){
                        word[0]=xx[i];
                        word[1]=yy[j];
                        word[2]=zz[k];
                        word[3]='\0';

                        if ( !find( root,word ) ){
                            str=word;
                            ss.insert( str );
                            //cout<<str<<endl;
                            add( root,word );
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",kk,bfs() );

        delete root;
    }


    return 0;
}

