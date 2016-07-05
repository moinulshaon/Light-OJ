#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int fact(int n,int f){
    if ( n==0 )return 0;
    else return n/f+fact(n/f,f);
}

int fact2(int n,int f){

    int cnt=0;
    while ( n%f ==0 ){
        n/=f;
        ++cnt;
    }
    return cnt;
}


int main(){
    int n,r,p,q,kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d %d %d",&n,&r,&p,&q);

        int two=0,five=0;
        two+=fact(n,2);
        two+=fact2(p,2)*q;

        five+=fact(n,5);
        five+=fact2(p,5)*q;

        five-= fact( n-r , 5 );
        five-= fact( r , 5 );

        two-= fact( n-r , 2 );
        two-= fact( r , 2 );

        printf("Case %d: %d\n",kk,min(two,five));
    }
    return 0;
}
