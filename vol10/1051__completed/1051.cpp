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



set<char> ss;

char dp[55][10][10];
vector<int> v;

bool isbad(int now,int cntv,int cntc){

    if ( cntv== 3 || cntc==5)return true;
    if ( now==v.size() )return false;

    if ( dp[now][cntv][cntc] !=-1 )return dp[now][cntv][cntc];


    if ( v[now]==0 ){
        return dp[now][cntv][cntc]=isbad(now+1,cntv+1,0);
    }else if ( v[now]==1 ){
        return dp[now][cntv][cntc]=isbad(now+1,0,cntc+1);
    }else{
        return dp[now][cntv][cntc]= ( isbad(now+1,cntv+1,0) || isbad(now+1,0,cntc+1) );
    }

}


bool isgood(int now,int cntv,int cntc){
    //printf("%d %d %d\n",now,cntv,cntc);
    if ( cntv== 3 || cntc==5)return false;

    if ( now==v.size() )return true;

    if ( dp[now][cntv][cntc] !=-1 )return dp[now][cntv][cntc];



    if ( v[now]==0 ){
        return dp[now][cntv][cntc]=isgood(now+1,cntv+1,0);
    }else if ( v[now]==1 ){
        return dp[now][cntv][cntc]=isgood(now+1,0,cntc+1);
    }else{
        return dp[now][cntv][cntc]= ( isgood(now+1,cntv+1,0) || isgood(now+1,0,cntc+1) );
    }
}
int main(){
    FRO

    ss.insert('A');
    ss.insert('E');
    ss.insert('I');
    ss.insert('O');
    ss.insert('U');

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        string str;
        cin>>str;

        v.clear();

        for (int i=0;i<str.length();++i){
            if ( str[i]=='?' ){
                v.PB(2);
            }else if ( ss.find(str[i])!=ss.end() ){
                v.PB(0);
            }else{
                v.PB(1);
            }
        }
        /*
        for (int i=0;i<v.size();++i){
            printf("%d",v[i]);
        }printf("\n");
        */


        memset(dp,-1,sizeof(dp));
        bool good=isgood(0,0,0);
        memset(dp,-1,sizeof(dp));
        bool bad=isbad(0,0,0);

        //printf("%d %d\n",good,bad);

        printf("Case %d: ",kk);
        if ( good && !bad ){
            printf("GOOD\n");
        }else if ( bad && !good ){
            printf("BAD\n");
        }else{
            printf("MIXED\n");
        }
    }


    return 0;
}
