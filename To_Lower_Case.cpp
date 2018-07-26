/*
 * Problem Description
 *
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 * 
 * Example 1:
 * Input: "Hello"  Output: "hello"
 * 
 * Example 2:
 * Input: "here"  Output: "here"
 */


#include <algorithm>
class Solution 
{
public:
    string toLowerCase(string str) 
    {
        transform(str.begin(),str.end(),str.begin(),::tolower);
        return str;
    }
};
