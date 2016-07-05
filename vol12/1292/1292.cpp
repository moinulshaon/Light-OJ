#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int T,N,x[2200],y[2200];
    pair<int, int> P[2200];

    scanf("%d",&T);

    for(int kkk=1;T--;++kkk){
        scanf("%d",&N);

        for(int i = 0;i < N;++i)
            scanf("%d %d",&x[i],&y[i]);

        int ans = 0;

        if(N > 1){
            ans = 1;

            for(int i = 0;i < N;++i){
                for(int j = 0,k = 0;j < N;++j){
                    if(j != i){
                        int dx = x[j] - x[i];
                        int dy = y[j] - y[i];

                        if(dy < 0 || (dy == 0 && dx < 0)) dx = -dx;
                        if(dy < 0) dy = -dy;

                        int g = __gcd(dx,dy);

                        if(g != 0){
                            dx /= g;
                            dy /= g;
                        }

                        P[k].first = dx;
                        P[k].second = dy;
                        ++k;
                    }
                }

                sort(P,P + (N - 1));

                int aux = 1;

                for(int i = 1;i < N - 1;++i){
                    if(P[i] != P[i - 1]) aux = 1;
                    else ++aux;

                    ans = max(ans,aux);
                }
            }
        }

        printf("Case %d: %d\n",kkk,ans+1);
    }

    return 0;
}
