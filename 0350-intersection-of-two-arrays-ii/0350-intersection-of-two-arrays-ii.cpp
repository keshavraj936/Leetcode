class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        vector<int> ans;

        // Store frequency of nums1
        for(int x : nums1) {
            mp[x]++;
        }

        // Check nums2
        for(int x : nums2) {
            if(mp[x] > 0) {
                ans.push_back(x);
                mp[x]--;
            }
        }

        return ans;
    }
};