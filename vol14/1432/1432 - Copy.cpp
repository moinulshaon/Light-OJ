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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 100100

struct tt{
    LL x1,y1,x2,y2;
}tmp;

vector<tt> ans[SIZE];

map< pair< pair<LL,LL>,LL > , int > mp;

bool cmpy( const tt&a,const tt&b ){
    return a.y1<b.y1;
}
bool cmpx( const tt&a,const tt&b ){
    return a.x1<b.x1;
}
int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int cnt = 0;
        mp.clear();

        int n;
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%lld %lld %lld %lld",&tmp.x1,&tmp.y1,&tmp.x2,&tmp.y2);

            if ( tmp.x1 == tmp.x2 && tmp.y1 == tmp.y2 )continue;

            if ( tmp.y2<tmp.y1 ){
                swap( tmp.x1,tmp.x2 );
                swap( tmp.y1,tmp.y2 );
            }else if ( tmp.y2== tmp.y1 && tmp.x2<tmp.x1 ){
                swap( tmp.x1,tmp.x2 );
                swap( tmp.y1,tmp.y2 );
            }

            LL num = (tmp.y2-tmp.y1);
            LL den = (tmp.x2-tmp.x1);

            LL xx= den* tmp.y1 - num*tmp.x1;
            LL yy =  num*num+den*den ;

            LL moinul=double ( xx/sqrt(yy) )*100000;
            //cout<<xx<<" "<<yy<<endl;




            if ( den<0 ){
                num = -num;
                den = -den;
            }
            LL dd= __gcd( num,den );
            num/=dd;
            den/=dd;

            if ( mp.find( make_pair( make_pair( num,den ), moinul ) ) == mp.end() ){
                mp[ make_pair( make_pair( num,den ), moinul ) ] = cnt++;
            }

            ans[  mp[ make_pair( make_pair( num,den ), moinul ) ] ] .PB( tmp );
        }

        LL shaon=0;

        for (int i=0;i<cnt;++i){

            if ( ans[i][0].y1!= ans[i][0].y2 ){
                sort( ans[i].begin(),ans[i].end(),cmpy );

                for (int j=0;j<ans[i].size();++j){

                    int low = j+1,high = ans[i].size()-1;
                    while ( low<=high ){
                        int mid = (low+high)/2;
                        if ( ans[i][mid].y1 < ans[i][j].y2 ){
                            low = mid+1;
                        }else{
                            high= mid-1;
                        }
                    }
                    //cout<<low<<" "<<j<<endl;
                    shaon+= low-j-1;
                }

            }else{
                sort( ans[i].begin(),ans[i].end(),cmpx );

                for (int j=0;j<ans[i].size();++j){

                    int low = j+1,high = ans[i].size()-1;
                    while ( low<=high ){
                        int mid = (low+high)/2;
                        if ( ans[i][mid].x1 < ans[i][j].x2 ){
                            low = mid+1;
                        }else{
                            high= mid-1;
                        }
                    }
                    //cout<<low<<" "<<j<<endl;
                    shaon+= low-j-1;
                }
            }

        }
        //cout<<cnt<<endl;
        printf("Case %d: %lld\n",kk,shaon);
        for (int i=0;i<cnt;++i){
            ans[i].clear();
        }
    }


    return 0;
}
