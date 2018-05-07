#include <stdio.h>

int powersof2(int n)
{
    if(n<1)
    {
        return 0;
    }
    else if(n==1)
    {
        printf("1\n");
        return 1;
    }
    else
    {
        int prev = powersof2(n/2);
        int curr = prev * 2;
        printf("n: %d curr: %d\n",n,curr);
        return curr;
    }
}

int main()
{
    printf("Main power %d", powersof2(5));
}