#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str)
    {   unordered_map<int, int> mp;
        for(char c: str) {
            mp[c] = 1;
        }
        for(int i=65; i<91; i++) {
            if(mp.find(i) == mp.end() && mp.find(i+32) == mp.end()) return false;
        }
        return true;
    }

};
