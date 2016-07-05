    //lightoj 1259- getting TLE
    #include <cstdio>
    #include <cstring>
    #include <vector>

    using namespace std;

    #define SIZE 10000001

    vector<int> v;

    int status[(SIZE/32)+2];

    bool Check(int N,int pos){
        return (bool)(N & (1<<pos));
    }
    int Set(int N,int pos){
        return N=N | (1<<pos);
    }

    int func(int x){

        if ( x%2 ){
            return  Check( status[(x-2)>>5],(x-2)&31 )==0 ;
        }

        int cnt=0,tmp;
        for (int i=0; 2 * v[i] <=x; ++i){
            tmp=(x-v[i]);
            if ( ( tmp==2 || tmp%2!=0 ) &&  Check(status[ tmp>>5 ],tmp&31 )==0 ){
                cnt++;
            }
        }
        return cnt;
    }

    void sieve(){
         int i, j, sqrtN;
         sqrtN = 3163;
         for( i = 3; i <= sqrtN; i += 2 ){
             if( Check(status[i>>5],i&31)==0){
                 for( j = i*i; j < SIZE; j += (i<<1) ){
                     status[j>>5]=Set(status[j>>5],j & 31)   ;
                 }
             }
         }

         v.push_back(2);

         for(i=3;i<SIZE;i+=2)
             if( Check(status[i>>5],i&31)==0)
                v.push_back(i);
        //printf("%d\n",v.size());
    }


    int main(){
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        sieve();
        int n,kase;
        scanf("%d",&kase);

        for (int kk=1;kase--;++kk){
            scanf("%d",&n);
            printf("Case %d: %d\n",kk,func(n));
        }
        return 0;
    }
