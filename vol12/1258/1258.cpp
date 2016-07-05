#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int failure[1001000];

int Morris_Pratt(string& t, string& p){


    for (int i=1, j=failure[0]= -1; i<p.size() ; ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }


    for (int i=0, j=-1; i<t.size(); ++i)
    {
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];

        if (p[j+1] == t[i]) j++;


        if (i == t.size()-1)
        {
            //cout << i - p.size() + 2<<endl;
            return t.size() -j-1;
            j = failure[j];
        }
    }
    return 0;
}


int main(){
    int kase;
    scanf("%d",&kase);
    getchar();

    string a,b;

    for (int kk=1;kase--;++kk){
        getline(cin,a);

        b=a;
        reverse(b.begin(),b.end());

        printf("Case %d: %d\n",kk,a.length()+Morris_Pratt(a,b));


    }
    return 0;
}
