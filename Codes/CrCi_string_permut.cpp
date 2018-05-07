#include <iostream>       // std::cout
#include <string>          // std::stack
#include <stdio.h>

int count = 0;
void permutation(std::string str);
void permutation(std::string str1, std::string str2);

void permutation(std::string str)
{
    permutation(str, "");
}

void permutation(std::string str, std::string prefix)
{
    if(str.length()==0)
    {
        //System.out.println(prefix);
        printf(" Prefix %s", prefix.c_str());
        printf(" String %s\n",str.c_str());
    }else
    {
        for(int i=0; i<str.length(); i++)
        {
            count++;
            std::string rem = str.substr(0,i) + str.substr(i+1);
            printf("Str: %s\n", str.c_str());
            printf("Subtr: %s\n", str.substr(i+1).c_str());
            printf("Count: %d\n", count);
            printf("Rem: %s\n", rem.c_str());
            printf("i: %d\n",i);
            permutation(rem, prefix + str.at(i));
        }
    }
    
}

int main ()
{
    std::string str = "Loremip";
    permutation(str);
}