#include<bits/stdc++.h>
using namespace std;

//all values of num between 1 to n-1
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    bool visited[n] = {false};
    for(int i=0; i<n; i++) {
        if(visited[nums[i]]) return nums[i];
        visited[nums[i]] = true;
    }
    return -1;
}

int findDuplicate2(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow!=fast);

    slow= nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> arr {1,3,3,4,2};
    cout<<findDuplicate(arr)<<endl;
    cout<<findDuplicate2(arr)<<endl;
}
