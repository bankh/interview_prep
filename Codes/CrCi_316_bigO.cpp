
#include <stdio.h>

int fib(int n, int memo[])
{
    if(n<=0) return 0;
    else if(n==1) return 1;
    else if (memo[n] > 0) 
        {   
            printf(" here %d \n",n);
            return memo[n];
        }

    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

void allFib(int n)
{
    int memo[n+1];
    for(int i = 0; i < n; ++i)
    {
        int fibb = fib(i, memo);
        printf("%d : %d\n",i, fibb);
    }
}

int main()
{
    int test = 4;
    allFib(test);
}