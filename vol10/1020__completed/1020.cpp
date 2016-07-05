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

int main(){
    FRO

    int kase,n;
    scanf("%d",&kase);

    char tt[10];
    for (int kk=1;kase--;++kk){
        scanf("%d %s",&n,tt);

        printf("Case %d: ",kk);
        if ( tt[0]=='A' ){
            if ( n%3==1 )printf("Bob\n");
            else printf("Alice\n");
        }else{
            if ( n%3==0 )printf("Alice\n");
            else printf("Bob\n");
        }
    }


    return 0;
}
