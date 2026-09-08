// 0 ms | 22 MB
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];
            int element_position = nums[i];    //the position where i should be there

            if(nums[i] < nums.size()  && nums[element_position] != element  ){
                swap(nums[i], nums[element_position]);
                i--;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                return i;
            }
        }

        return nums.size();
    }
};