#include <stdio.h>

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


int main()
{
	int number,i,temp1,temp2;
	int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int count[25];

    int kase=fastIn<int>();


	for (int kk=1;kase--;++kk){
		scanf("%d",&number);

		for (i=0;i<25;++i)
			count[i]=0;

		temp1=temp2=number+1;
		while (temp1>1){
			--temp1;
			number=temp1;
			for (i=0;i<25;++i)
			{
				while (number%primes[i]==0)
				{
					number/=primes[i];
					++count[i];
				}

			}
		}



		printf("Case %d: %d =",kk,temp2-1);
		bool on=false;
		for (i=0;i<25;++i){
			if ( count[i]!=0 ){
			    if ( on )printf(" *");
				printf(" %d (%d)",primes[i],count[i]);
				on=true;
			}
		}
		printf("\n");

	}
	return 0;
}
