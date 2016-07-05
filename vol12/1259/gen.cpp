    //lightoj 1259- getting TLE
    #include <cstdio>
    #include <cstring>
    #include <vector>

    using namespace std;

    #define SIZE 10000001

    vector<int> v;

    int high,low;
    bool find( int x ){
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if ( v[mid]==x )return true;
            else if ( x> v[mid] )low=mid+1;
            else high=mid-1;
        }
        return false;
    }

    int func(int x){

        high=v.size()-1;
        low=0;

        if ( x%2 ){
            return  find(x-2) ;
        }

        int cnt=0;
        for (int i=0;i<=high && 2 * v[i] <=x; ++i){
            low=i;
            if ( find( x- v[i] ) ){
                cnt++;
            }
        }
        return cnt;
    }

    int status[(SIZE/32)+2];

    bool Check(int N,int pos){
        return (bool)(N & (1<<pos));
    }
    int Set(int N,int pos){
        return N=N | (1<<pos);
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
