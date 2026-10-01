class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int ans;
        int highest = 0;

        for(auto p : mp) {
            if(p.second > highest) {
                highest = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};