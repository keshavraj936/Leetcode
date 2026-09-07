// 253 ms | 251.2 MB
class Solution {
    public int firstMissingPositive(int[] nums) {
        int[]freq=new int[10000002];
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0 && nums[i]<=nums.length){
                freq[nums[i]]++;
            }
        }
        for(int i=1;i<=nums.length;i++){
            if(freq[i]==0)return i;
        }
        return nums.length +1;
    }
}