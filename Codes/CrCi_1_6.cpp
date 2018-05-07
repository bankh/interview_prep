#include <iostream>
#include <string>

std::string compress(std::string str)
{   
    // It is a type able to represent the size of any object in bytes: 
    // size_t is the type returned by the sizeof operator and is widely 
    // used in the standard library to represent sizes and counts.
    size_t original_length = str.length();

    if(original_length <2)
    {
        return str;
    }

    std::string out{""};
    int count = 1;
    for(size_t i=1; i<original_length; ++i)
    {
        if(str[i-1] == str[i])
        {
            ++count;
        }else{
            out += str[i-1];
            out += std::to_string(count);
            count = 1;
        }
        if(out.length() >= original_length)
        {
            printf("Compression doesn't make sense. Keep the original.\n");
            return str;
        }
    }
    out += str[original_length-1];
    out += std::to_string(count);
    if(out.length() >= original_length)
    {
        return str;
    }
    return out;
}

int main()
{
    // We can change the algorithm to keep the original string in case there is no 
    // repetition of the character.
    std::string str={"abcdef"}, out;
    printf("Original String: %s\n", str.c_str());

    out = compress(str);
    if(str.compare(out))
    {
        std::cout << str << " can be compressed to " << out << std::endl;
    }else{
        std::cout << str << " can not be compressed\n";
    }
    return 0;
}