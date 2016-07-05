#include <stdio.h>

int main()
{
	int test,i,a,b,temp,m;

	scanf("%d",&test);

	for (i=1;i<=test;++i)
	{
		scanf("%d %d",&a,&b);
		temp=a*b;
		if ((a<3 && b<3) || a==1 || b==1)
			printf("Case %d: %d\n",i,temp);
		else if (a==2)
		{
			m=b%4;
			if (m>2)
				m=2;
			b/=4;
			
			printf("Case %d: %d\n",i,(m+b*2)*2);
		}
		else if (b==2)
		{
			m=a%4;
			if (m>2)
				m=2;
			a/=4;
			
			printf("Case %d: %d\n",i,(m+a*2)*2);
		}
		else
		{

			
			if (temp & 1)
				printf("Case %d: %d\n",i,(temp>>1)+1);
			else
				printf("Case %d: %d\n",i,temp>>1);
		}
	}
	return 0;
}