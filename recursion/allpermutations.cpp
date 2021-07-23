#include<bits/stdc++.h>
using namespace std;

//recursion inside loop
void generate(vector<int> nums, vector<vector<int>> &ans, int i=0) {
    if(i == nums.size() - 1) {
        ans.push_back(nums);
        return;
    }
    
    for(int j=i; j<nums.size(); j++) {
        swap(nums[i], nums[j]);
        generate(nums, ans, i+1);
        swap(nums[j], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    generate(nums, ans);
    return ans;
}

int main() {
    vector<int> inp{1,2,3};
    vector<vector<int>> s = permute(inp);
    for(auto v: s) {
        for(auto c: v)
            cout<<c<<' ';
        cout<<endl;
    }
}
