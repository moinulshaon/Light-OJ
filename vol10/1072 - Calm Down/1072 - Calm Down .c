#include <stdio.h>
#include <math.h>
#define pi 3.141592654

int main()
{
	int test,j;
	int n;
	double R,r,temp;

	scanf("%d",&test);

	for (j=1;j<=test;++j)
	{		
		scanf("%lf %d",&R,&n);
		
		temp=sin(pi/n);
		r=(R*temp)/(1+temp);

		printf("Case %d: %.10lf\n",j,r);
		
	}
	return 0;
}