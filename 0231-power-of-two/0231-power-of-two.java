class Solution {
    public boolean isPowerOfTwo(int n) {
        // Trick: Power of 2 has only one 1 in binary
        // n & (n-1) removes that 1
        // If result = 0, it is a power of 2
        if(n <= 0){
            return false;
        }
        return(n & (n - 1)) == 0;
    }
}