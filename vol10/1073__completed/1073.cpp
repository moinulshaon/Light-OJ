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

char str[16][16*100];
char save[16*100];
int n;
int cost[16][16];

int zz[16*100];

int calc( char *str ,int beg ){
    int left=0,right = 0;
    int len=strlen(str);
    zz[0]=len;
    for (int i=1;i<len;++i){
        if ( i>right ){
            left=right = i;
            while ( right<len && str[right] == str[right-left] ){
                right ++;
            }
            right --;
            zz[i] = right -left+1;
        }else{
            int tmp = i-left;
            if ( zz[tmp] < right-i+1 ){
                zz[i]= zz[tmp];
            }
            else{
                left = i;
                while ( right<len && str[right] == str[right-left] ){
                    right ++;
                }
                right --;
                zz[i] = right -left+1;
            }
        }
    }


    for (int i=beg;i<len;++i){
        if ( i+zz[i] == len ){
            return zz[i];
        }
    }
    return 0;
}

bool match( char *str ,int xxx ){

    int left=0,right = 0;
    int len=strlen(str);
    zz[0]=len;
    for (int i=1;i<len;++i){
        if ( i>right ){
            left=right = i;
            while ( right<len && str[right] == str[right-left] ){
                right ++;
            }
            right --;
            zz[i] = right -left+1;
        }else{
            int tmp = i-left;
            if ( zz[tmp] < right-i+1 ){
                zz[i]= zz[tmp];
            }
            else{
                left = i;
                while ( right<len && str[right] == str[right-left] ){
                    right ++;
                }
                right --;
                zz[i] = right -left+1;
            }
        }
    }


    for (int i=xxx+1;i<len;++i){
        if ( zz[i] == xxx ){
            return true;
        }
    }
    return false;
}

int dp[16][1<<16];

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int func(int now ,int state){
    if ( state == (1<<n)-1 )return 0;
    int &ret = dp[now][state];

    if ( ret != -1 )return ret;

    ret = INT_MAX;

    for (int i=0;i<n;++i){
        if ( Check(state,i)==0 ){
            int val = cost[now][i] + func( i,Set(state,i) );
            if ( val <ret ){
                ret = val;
            }
        }
    }
    return ret;
}

int lensave[16];

void prnt(int now ,int state){


    if ( state==(1<<n)-1 )return ;

    int d = -1;
    int ret = INT_MAX;

    for (int i=0;i<n;++i){
        if ( Check(state,i)==0 ){
            int val = cost[now][i] + func( i,Set(state,i) );
            if ( val <ret ){
                ret = val;
                d=i;
            }else if ( val==ret ){
                if ( strcmp(&str[i][ lensave[i]-cost[now][i] ] ,
                             &str[d][ lensave[d]-cost[now][d] ] ) <0  ){
                    d= i;
                }
            }
        }
    }
    printf("%s",&str[d][ lensave[d]-cost[now][d] ]);
    //strcat( save,&str[d][ lensave[d]-cost[now][d] ] );

    prnt( d,Set(state,d) );

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%s",str[i]);
        }

        bool ok[20];
        for (int i=0;i<n;++i){
            ok[i]=true;
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( i==j || !ok[j] || !ok[i]  )continue;

                strcpy( save,str[j] );
                int ss=strlen(save);

                strcat( save,"#" );
                strcat( save,str[i] );

                if ( match( save,ss ) ){
                    ok[j]=false;
                    //cout<<i<<" "<<j<<" "<<vec[i].c_str()<<" "<<vec[j].c_str()<<endl;
                }

            }
        }

        int shaon = n;
        n=0;

        for (int i=0;i<shaon;++i){
            //cout<<vec[i].c_str()<<endl;
            if ( ok[i] ){
                if ( n !=i ){
                    strcpy( str[n], str[i] );
                }
                n++;
            }
        }


        for (int i=0;i<n;++i){
            //cout<<str[i]<<endl;
            lensave[i]=strlen(str[i]);
        }


        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( i==j )continue;

                strcpy( save,str[j] );
                strcat( save,"#" );
                int ss=strlen(save);
                strcat( save,str[i] );

                cost[i][j] = lensave[j] -calc( save,ss );

                //cout<<i<<" "<<j<<" "<<save<<" "<<cost[i][j]<<endl;
            }
        }
/*
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                printf("%3d",cost[i][j]);
            }
            printf("\n");
        }
*/

        for (int i=0;i<n;++i){
            for (int j=0;j<(1<<n);++j){
                dp[i][j] = -1;
            }
        }



        int ans = INT_MAX;
        int start= -1;
        for (int i=0;i<n;++i){
            int val = lensave[i] + func( i,Set(0,i) );
            if ( val<ans ){
                ans = val;
                start = i;
            }else if ( val == ans ){
                if ( strcmp( str[i] ,
                             str[start] ) <0  ){
                    start= i;
                }
            }
        }

        //cout<<ans<<endl;

        printf("Case %d: ",kk);
        printf("%s",str[start]);
        prnt(start,Set(0,start));
        printf("\n");


        //cout<<ans<<endl;

    }



    return 0;
}
