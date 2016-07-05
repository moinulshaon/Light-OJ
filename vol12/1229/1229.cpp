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


#define SIZE 300
char str[SIZE];
int len;

int dp[SIZE][2][2];

int calc( int x,int low,int high ){
    if ( x == 0 )return 0;

    int &ret = dp[x][low][high];
    if ( ret != -1 )return ret;

    set<int> vis;
    for (int i=0;i<len;++i){
        vis.insert( calc( i,low,1 ) ^ calc( len-i ) )
    }

}

int pos(){
    for (int i=2;i<=len;++i){
        if ( str[i] == 'X' && str[i-1] == 'X' ){
            return true;
        }
    }

    int grundy = 0;
    int start = 1;
    for (int i=1;i<=len;++i){
        if ( str[i] == 'X' ){
            int len = i-start+1;
            bool le=false,ri=false;
            if ( str[start-1] == 'X' ){
                le = true;
            }
            if ( str[i+1] == 'X' ){
                ri = true;
            }
            grundy ^= calc( len,le,ri );
            start = i+1;
        }
    }
    return grundy;
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",&str[1]);
        str[0] = '.';
        len = strlen(str)-1;
        str[len+1] = '.';

        vector<int> ans;

        for (int i=1;i<=len;++i){
            if ( str[i] == '.' ){
                str[i] = 'X'
                if ( pos() == 0 ){
                    ans.PB( i );
                }
                str[i] = '.';
            }
        }

    }


    return 0;
}
