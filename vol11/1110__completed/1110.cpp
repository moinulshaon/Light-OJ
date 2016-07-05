#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int mat[110][110];
string a,b;

int main()
{
    freopen("in.txt","r",stdin);
    int kase;
    cin>>kase;
    for (int kk=1;kase-- ;++kk)
    {
        cin>>a>>b;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int length_a=a.length();
        int length_b=b.length();

        for (int i=0;i<=length_a;++i)
            mat[i][0]=0;
        for (int i=0;i<=length_b;++i)
            mat[0][i]=0;

        for (int i=1;i<=length_b;++i){
            for (int j=1;j<=length_a;++j){
                if (b[i-1]==a[j-1]){
                    mat[i][j]=1+mat[i-1][j-1];
                }
                else
                    mat[i][j]=max( mat[i-1][j],mat[i][j-1] );
            }
        }
        int ans=mat[length_b][length_a];

        printf("Case %d: ",kk);
        if ( ans==0 ){
            printf(":(\n");
            continue;
        }

        int row=length_b,col=length_a;
        string rr;
        for (int i=ans;i>0;--i){
            char mn=125;
            int limr=0,limc=0;

            for (int r=row;r>0;--r){
                for (int c=col;c>0;--c){
                    if ( mat[r][c]== i && b[r-1]==a[c-1] && b[r-1]<mn ){
                        mn=b[r-1];
                        limr=r;
                        limc=c;
                    }
                }
            }
            rr+=mn;
            row=limr-1;
            col=limc-1;
            //printf("%d %d %c\n",row,col,mn);
        }
        cout<<rr<<endl;

    }
    return 0;
}
