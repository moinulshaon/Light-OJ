#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main()
{

    freopen("in.txt","r",stdin);

    int test;
    scanf("%d",&test);

    for (int i=1;i<=test;++i)
    {

        printf("Case %d:\n",i);

        stack <string> forward;
        stack <string> backward;

        string com,url,cur="http://www.lightoj.com/";

        while (true)
        {
            cin>>com;

            if (com[0]=='B')
            {
                if (backward.empty())
                {
                    printf("Ignored\n");
                    continue;
                }
                else
                {
                    forward.push(cur);
                    cur=backward.top();
                    backward.pop();
                }
            }
            else if (com[0]=='F')
            {
                if (forward.empty())
                {
                    printf("Ignored\n");
                    continue;
                }
                else
                {
                    backward.push(cur);
                    cur=forward.top();
                    forward.pop();
                }
            }
            else if (com[0]=='V')
            {
                backward.push(cur);
                cin>>cur;
                while (!forward.empty())
                    forward.pop();
            }
            else if (com[0]=='Q')
                break;

            cout<<cur<<endl;
        }
    }
    return 0;

}
