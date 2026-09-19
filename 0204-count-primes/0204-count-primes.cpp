class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2){
            return 0;
        }

        vector<bool> isPrime(n, true);

        isPrime[0] = isPrime[1] = false;

        // 2 is the only even prime
        int count = 1;

        // Check only odd numbers
        for(int i = 3; i * i < n; i += 2){

            if(!isPrime[i]){
                continue;
            }

            // Mark only odd multiples
            for(int j = i * i; j < n; j += 2 * i){
                isPrime[j] = false;
            }
        }

        // Count odd primes
        for(int i = 3; i < n; i += 2){

            if(isPrime[i]){
                count++;
            }
        }

        return count;
    }
};