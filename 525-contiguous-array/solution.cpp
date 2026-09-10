// 52 ms | 88.6 MB
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 0){
                sum--;
            }else{
                sum++;
            }

            if(mp.count(sum)){
                int length = i - mp[sum];
                ans = max(ans, length);
            }else{
                mp[sum] = i;
            }
        }

        return ans;
    }
};