#include <stdio.h>
#include <math.h>

int main()
{
	int test,i,j,count;
	int num;
	char flag;

	scanf("%d",&test);

	for (j=1;j<=test;++j)
	{
		scanf("%d",&num);

		flag=count=0;
		for (i=0;i<sizeof(int)*8;++i)
		{
			if (!flag && (num & 1<<i))
			{
				flag=1;
				num=num & ~(1<<(i));
				++count;
			}
			else if (flag)
			{
				if (num & 1<<i)
				{
					num=num & ~(1<<(i));
					++count;
				}
				else
				{
				
					num=num | (1<<(i));
					break;
				}
			}
			
		}

		for (i=0;i<count-1;++i)
			num=num | (1<<i);
		
		printf("Case %d: %d\n",j,num);		
	}
	return 0;
}