    #include <stdio.h>


    long long fact[20]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,
    6227020800LL,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};
    int main()
    {
        int test,i,count,j;
        char arr[20];

        long number;


        scanf("%d",&test);

        for (i=1;i<=test;++i)
        {
            scanf("%ld",&number);

            count=0;
            for (j=0;j<20;++j)
                arr[j]=0;
            for (j=19;j>=0;--j)
                if (number>=fact[j])
                {
                    number-=fact[j];
                    arr[j]=1;
                }
            if (number)
                printf("Case %d: impossible\n",i);
            else
            {
                printf("Case %d: ",i);
                for (j=0;j<20;++j)
                {
                    if (arr[j])
                    {
                        if (count++)
                            printf("+%d!",j);
                        else
                            printf("%d!",j);
                    }
                }
                printf("\n");
            }

        }
        return 0;
    }
