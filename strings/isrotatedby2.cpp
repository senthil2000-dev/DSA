#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();
        if(m!=n) return false;
        auto pos = (str1+str1).find(str2);
        if(pos == string::npos) return false; 
        //now able to find and length equal so it is a rotation but by 2?
        if(m==1) return true;
        return (pos == 2 || pos == m-2);
    }

};
