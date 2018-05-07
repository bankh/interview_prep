#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

bool arePermutation(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    if(n1!=n2){
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Since we sorted shouldn't be an issue
    for(int i = 0; i<n1; ++i)
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

bool arePermutation_2(const string &sstr1, const string &str2)
{
    if(str1.length() != str2.length())
        return false;
    
    int count[256] = 0;
    for(int i=0; i<str1.length(); ++i)
    {
        int val = str1[i];
        count[val]++;
    }
    for(int i=0; i<str2.length(); ++i)
    {
        int val=str2[i];
        count[val]--;
        if(count[val]<0)
            return false;
    }
    return true;
}

int main(){

    string str1 = "testest";
    string str2 = "estxest";

    // Test method 1 - Using sort
    cout << "Method 1 - Using sort" << endl;
    if(arePermutation(str1,str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;
    
    str1 = "hello";
    str2 = "oellh";

    if(arePermutation(str1,str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;

    // Test Method 2 - Using character count
    cout << "Method 2 - Using character count" << endl;
    str1 = "testest";
    str2 = "estxest";

    if(arePermutation_2(str1, str2))
        cout << str1 << " and " << str2 << "are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << "are not permutation of each other" << endl;
    
    str1 = "hello";
    str2 = "oellh";

    if(arPermutation_2(str1, str2))
        cout << str1 << " and " << str2 << "are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << "are not permutation of each other" << endl;
}