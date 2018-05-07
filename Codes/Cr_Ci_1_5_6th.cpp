#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool isOneAway(string s1, string s2)
{
    string a,b;
    a = s1.length() >= s2.length() ? s1:s2;
    b = s1.length() < s2.length() ? s1:s2;
    int len1, len2;

    len1 = a.length();
    len2 = b.length();
    
    if(abs(len1-len2)>1)
        return false;
    
    bool flag = false;
    for(int i=0, j=0; i<len1 && j<len2;){
        if(a[i]!=b[j])
        {
            if(flag)
                return false;
            flag = true;
            if(len1 == len2)
                i++, j++;
            else
                i++;
        }else
            i++, j++;
    }
    return true;
}

bool OneEditAway(const std::string &str1, const std::string &str2)
{
    if(std::abs(int(str1.length()) - int(str2.length())) > 1 )
    {
        return false;
    }
    int len1 = str1.length();
    int len2 = str2.length();

    std::string smaller = len1 < len2 ? str1 : str2;
    std::string bigger = len1 < len2 ? str2 : str1;

    unsigned int i=0, j=0;
    bool mismatchDone = false;
    while(i < smaller.length() && j < bigger.length())
    {
        if(smaller[i] != bigger[j])
        {
            if(mismatchDone)
            {
                return false;
            }
            mismatchDone = true;
            if(len1 == len2)
            {
                ++i;
            }
        }else{
                ++i;
        }
        ++j;
    }
    return true;
}

void translate(bool result, const std::string str1, const std::string str2)
{
    if(result==true)
    {
        std::cout << str1 << " and " << str2 << " are one edit away\n";
    }else {
        std::cout << str1 << " and " << str2 << "are not one edit away\n";
    }
}

int main(void)
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if(isOneAway(s1,s2))
        cout << "One edit away." << endl;
    else
        cout << "Not one edit away." << endl;

    translate( oneEditAway("pale","ple"), "pale", "ple");
    translate( oneEditAway("pales", "pale"), "pales", "pale");
    translate( oneEditAway("pale", "pales"), "pale", "pales");
    translate( oneEditAway("pale", "bale"), "pale", "bale");
    translate( oneEditAway("pale", "bake"), "pale", "bake");

    return 0;
}