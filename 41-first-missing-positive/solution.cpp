// 0 ms | 54.9 MB
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];

            if(element >= 1 && element <= nums.size()){
                int current_element = element - 1;

                if(element != nums[current_element]){
                    swap(nums[i], nums[current_element]);
                    i--;
                }
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};