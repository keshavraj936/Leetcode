// 135 ms | 79.9 MB
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>set;
        for(int x : nums){
            if(x > 0){
            set.insert(x);
            }
        }

        for(int i = 1; i <= nums.size(); i++){
            if(!set.contains(i)){
                return i; 
            }
        }
        return nums.size() + 1;
    }
};