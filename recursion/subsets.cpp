#include<bits/stdc++.h>
using namespace std;

void generate(const vector<int> &nums, vector<vector<int>> &ans, vector<int> v = {}, int i=0) {
    if(i==nums.size()) {
        ans.push_back(v);
        return;
    }
    generate(nums, ans, v, i+1);
    v.push_back(nums[i]);
    generate(nums, ans, v, i+1);
}

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> ans;
    generate(nums, ans);
    return ans;
}

int main() {
    vector<vector<int>> s = subsets({1,2,3});
    for(auto v: s) {
        for(auto c: v)
            cout<<c<<' ';
        cout<<endl;
    }
}
