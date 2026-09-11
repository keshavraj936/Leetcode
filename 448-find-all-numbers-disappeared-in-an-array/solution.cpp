// 7 ms | 53.1 MB
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];
            int current_position = element - 1;

            if(nums[i] != nums[current_position]){
                swap(nums[i], nums[current_position]);
                i--;
            }
        }

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};