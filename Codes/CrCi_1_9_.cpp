#include <iostream>
#include <string>

bool isRotation(std::string s1, std::string s2)
{
    size_t len1 = s1.length();
    size_t len2 = s2.length();

    printf ("Str1: %u and Str2: %u\n", s1.length(), s2.length());

    if(len1 == 0 || len2 == 0)
    {
        return false;
    }
    printf("%s",s1.c_str());
    std::string concatS1 = s1 + s1;
    printf("Concatenated string: %s\n", concatS1.c_str());
    // The position of the first character of the first match.
    // If no matches were found, the function returns string::npos.
    if(concatS1.find(s2) != std::string::npos)
    {
        return true;
    }else{
        return false;
    }
}

int main()
{
    std::string str1 ("stitchesbru");
    std::string str2 ("st");

    if(isRotation(str1, str2))
    {
        std::cout << "Yes! " << str2 << " is a rotation of " << str1 << std::endl;
    }else{
        std::cout << "No! " << str2 << " is not a rotation of " << str1 << std::endl;
    }
    return 0;
}