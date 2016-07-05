#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

char input[10100];

int compF(int a,int b)
{
    int lena=strlen(&input[a]);
    int lenb=strlen(&input[b]);
    int len=( lena<lenb )?lena:lenb;
    int same;
    for (same=0;same<len;++same)
        if (input[a+same]!=input[b+same])
            return same;
    return same;
}

int pos(int n){
    return (n<0)?0:n;
}
int lcp[10100];


bool cmp( const int &p,const int&q ){
    return strcmp(&input[p],&input[q])<=0;
}

int main()
{
    int test;

    scanf("%d",&test);
    for (int kk=1;test--;++kk)
    {
        scanf("%s",input);
        vector <int> suffixArray;
        int tmp=strlen(input);
        for (int i=0;i<tmp;++i)
            suffixArray.push_back(i);
        sort(suffixArray.begin(),suffixArray.end(),cmp);




        lcp[0]=0;
        tmp=suffixArray.size();
        int maxi=0;
        for (int i=1;i<tmp;++i){
            lcp[i]=compF(suffixArray[i],suffixArray[i-1]);
        }

        int result=0;

        int a,b;
        cin>>a>>b;

        result = min( int(strlen( &input[ suffixArray[0] ] ) ), b ) - a + 1;
        if(result < 0) result = 0;

        for (int i=1;i<tmp;++i){
            int tt=strlen( &input[suffixArray[i] ] );

            result+=pos( min(b,tt) -max(a,1+lcp[i]) + 1 );

                //cout<<suffixArray[i]<<' '<<result<<endl;
        }

        printf("Case %d: %d\n",kk,result);

    }
    return 0;
}

