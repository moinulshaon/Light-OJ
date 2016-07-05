#include <stdio.h>

int main()
{
	long input,n,m,temp;
	int test,k;
	char flag;

	scanf("%d",&test);

	for (k=1;k<=test;++k)
	{
		scanf("%ld",&input);
		
		flag=0;
		m=2;
		temp=input/3;
		while (m<=temp)
		{
			if (input%m==0)
			{
				n=input/m;
				if (n&1)
				{
					flag=1;
					break;
				}
			}
			m*=2;
		}
		if (flag)
			printf("Case %d: %ld %ld\n",k,n,m);
		else
			printf("Case %d: Impossible\n",k);
	}
	return 0;
}