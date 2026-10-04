class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        vector<int> ans;

        for(int x : nums1) {
            set1.insert(x);
        }

        for(int x : nums2) {
            set2.insert(x);
        }

        for(int x : set1) {
            if(set2.count(x)) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};