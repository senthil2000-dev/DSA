#include <bits/stdc++.h>
using namespace std;

string smallestWindow (string &s, string &p) {
    if(s.length()<p.length()) return "-1";
    int hashs[256] = {0}, hashp[256] = {0}, count=0; //count represents no of chars matched so far in s as in p
    int ans = INT_MAX;
    int start = 0, startInd = 0;
    for(char c: p) hashp[c]++;
    for(int j=0; j<s.length(); j++) {
        hashs[s[j]]++;
        if(hashs[s[j]] <= hashp[s[j]]) count++;
        if(count == p.length()) { //once it reaches count, we remove from start only when you find the start char at the other end
            while(hashs[s[start]]>hashp[s[start]]) { //more than required chars in pattern, so remove
                hashs[s[start]]--;
                start++;
            }
            if(ans>j-start+1) { //update answer and start if better
                ans = j-start+1;
                startInd = start;
            }
            //3 lines below to just optimise by deleting one char at start and searching on other side till it is found
            hashs[s[start]]--;
            start++;
            count--;
        }
    }
    return ans == INT_MAX? "-1": s.substr(startInd, ans);
}

string slideWindow (string &s, string &p) {
    if(s.length()<p.length()) return "-1";
    int hp[256] = {0}, count=0;
    //result
    int start = 0;
    int len = INT_MAX;
    //hash pattern and count distinct chars
    for(char c: p) {
        if(!hp[c]) count++;
        hp[c]++;
    }
    int i=0, j=0;
    // traverse string as windows - pattern - window
    for(; j<s.length(); j++) {
        hp[s[j]]--;
        if(!hp[s[j]]) count--;
        // match found
        while(count==0) {
            //result updation
            if(len>j-i+1) {
                len = j-i+1;
                start = i; 
            }
            //slide window to shift i
            hp[s[i]]++;
            if(hp[s[i]]>0) count++; //pattern has more of this char than window
            i++;
        }
    }
    return len==INT_MAX? "-1": s.substr(start, len);
}

int main()
{
    string s = "zotomlazapzo";
    string p = "oza";
    cout<<"Smallest window that contain all character : "<<smallestWindow(s, p)<<endl;
    cout<<"Smallest window that contain all character : "<<slideWindow(s, p)<<endl;
}
