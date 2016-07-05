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

char s1[110],s2[110],s3[310];
int len1,len2,len3;

int mod=1000000007;

int tbl[110][110];

int lcs(){
    for (int i=0;i<=len1;++i){
        tbl[i][0]=0;
    }
    for (int i=0;i<=len2;++i){
        tbl[0][i]=0;
    }

    for (int i=0;i<=len1;++i){
        for (int j=0;j<=len2;++j){
            if ( s1[i-1]==s2[j-1] ){
                tbl[i][j]=1+tbl[i-1][j-1];
            }else{
                tbl[i][j]=max( tbl[i-1][j],tbl[i][j-1] );
            }
        }
    }
}

int dp[101][101][301];

bool used[301][26];

int func( int x,int y,int left,string sss ){

    //cout<<x<<' '<<y<<' '<<left<<' '<<sss<<endl;
    if ( x==0 && y==0 ){
        cout<<"shaon "<<sss<<endl;
        return 1;
    }
    if ( left==0 )return 0;

    //if ( dp[x][y][left] != -1 )return dp[x][y][left];

    if ( x==0  ){
        if ( s2[y-1]==s3[left-1]  ){
            if ( ! used[left][ s3[left-1] -'a'] ){
                used[left][ s3[left-1] -'a']=true;
                return dp[x][y][left]=func( x,y-1,left-1,sss+s2[y-1] );
            }else{
                return 0;
            }
        }
        else
            return dp[x][y][left]=func( x,y,left-1,sss );
    }
    if ( y==0  ){
        if ( s1[x-1]==s3[left-1] ){
            if ( ! used[left][ s3[left-1] -'a'] ){
                used[left][ s3[left-1] -'a']=true;
                return dp[x][y][left]=func( x-1,y,left-1,sss+s1[x-1] );
            }else{
                return 0;
            }
        }
        else
            return dp[x][y][left]=func( x,y,left-1 ,sss);
    }




    if ( s1[x-1]==s2[y-1] ){
        if  ( s3[left-1]==s1[x-1] ){
            if ( ! used[left][ s3[left-1] -'a'] ){
                used[left][ s3[left-1] -'a']=true;
                return dp[x][y][left]=func( x-1,y-1,left-1,sss+s3[left-1]);
            }else{
                return 0;
            }
        }
        else
            return dp[x][y][left]=func( x,y,left-1 ,sss );
    }else{
        int tmp=0;
        if ( tbl[x-1][y]>=tbl[x][y-1]  ){
            if  ( s3[left-1]==s1[x-1] ){
                if ( ! used[left][ s3[left-1] -'a'] ){
                    used[left][ s3[left-1] -'a']=true;
                    tmp+= func( x-1,y,left-1 ,sss+s3[left-1] );
                }
            }
            else
                tmp+=func( x,y,left-1,sss );
        }
        if ( tbl[x][y-1]>=tbl[x-1][y] ){
            if  ( s3[left-1]==s2[y-1] ){
                if ( ! used[left][ s3[left-1] -'a'] ){
                    used[left][ s3[left-1] -'a']=true;
                    tmp+= func( x,y-1,left-1,sss+s3[left-1] );
                }
            }
            else
                tmp+=func( x,y,left-1,sss );
        }
        return  dp[x][y][left]=tmp;
    }

}


int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",s1);
        len1=strlen(s1);
        scanf("%s",s2);
        len2=strlen(s2);
        scanf("%s",s3);
        len3=strlen(s3);

        for (int i=0;i<len1/2;++i){
            swap( s1[i],s1[ len1-i-1 ] );
        }
        for (int i=0;i<len2/2;++i){
            swap( s2[i],s2[ len2-i-1 ] );
        }
        for (int i=0;i<len3/2;++i){
            swap( s3[i],s3[ len3-i-1 ] );
        }

        lcs();
        NEG(dp);
        CLR(used);
        int ans=func(len1,len2,len3,"");
        printf("Case %d: %d\n",kk,ans);
        if ( ans ){
            //cnt=0;
            //show(len1,len2,len3);
        }else{
            printf("NOT FOUND\n");
        }



    }




    return 0;
}
