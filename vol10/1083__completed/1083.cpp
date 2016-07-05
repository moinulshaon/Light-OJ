#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


#define SIZE 30005

int height[SIZE];
int left[SIZE],right[SIZE];
int area[SIZE];
int n;

void calcleft(){
    stack<int> stk;
    stk.push(0);
    for (int i=1;i<=n;++i){
        while(height[i]<=height[ stk.top() ] ){
            stk.pop();
        }
        area[i]=( i-stk.top() )*height[i];
        stk.push(i);
    }
}
void calcright(){
    stack<int> stk;
    stk.push(n+1);
    height[n+1]=0;
    for (int i=n;i>0;--i){
        while(height[i]<=height[ stk.top() ] ){
            stk.pop();
        }
        area[i]+=( stk.top()-i-1 )*height[i];
        stk.push(i);
    }
}

int main(){
    int kase=fastIn<int>();
    for (int kk=1;kase--;++kk){
        n=fastIn<int>();
        for (int i=1;i<=n;++i){
            height[i]=fastIn<int>();
        }
        calcleft();
        calcright();
        int ans=0;
        for (int i=1;i<=n;++i){
            ans=max(ans,area[i]);
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}
