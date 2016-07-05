#include <stdio.h>
#include <math.h>

int main()
{
	int test,j;
	int base,number;
	double final;

	scanf("%d",&test);


	for (j=1;j<=test;++j)
	{		
		scanf("%d %d",&number,&base);
		
		if (number<=1)
		{
			printf("Case %d: 1\n",j);	
			continue;
		}
	
		final=ceil((log(2*3.1416*number)/2 + number*(log(number) - 1) + 1/(12*number))/log(base)) ;

		printf("Case %d: %.0lf\n",j,final);		
	}
	return 0;
}