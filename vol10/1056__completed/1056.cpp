#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int i,kase;
	double x,y,theta,a,b,temp;
    scanf("%d",&kase);
	for (i=1;kase--;++i)
	{
	    scanf("%lf : %lf",&a,&b);

		theta=atan(b/a);
		x=200/(1+theta*sqrt(1+(b*b)/(a*a)));
		y=b/a*x;
		printf("Case %d: %.8lf %.8lf\n",i,x,y);
	}

	return (0);
}
