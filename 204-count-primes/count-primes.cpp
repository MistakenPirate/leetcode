class Solution {
public:
    //optimal
    int countPrimes(int n) {
        if (n <= 2) return 0; // No primes less than 2

        // Create a vector to mark whether numbers are prime
        vector<int> isPrime(n, 1); // Only up to n-1 needed
        isPrime[0] = 0; // 0 is not prime
        isPrime[1] = 0; // 1 is not prime

        int count = 0;

        // Traverse numbers from 2 to n-1
        for (long long i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
                // Mark all multiples of i as not prime
                for (long long val = i * i; val < n; val += i) {
                    isPrime[val] = 0;
                }
            }
        }

        return count;
    }

    //brute force
    // int countPrimes(int n) {
    //     int count = 0;
    //     for(int i = 2; i < n; i++){
    //         if(isPrime(i))
    //             count++;
    //     }
    //     return count;
    // }

    // bool isPrime(int n){
    //     for(int i = 2; i <= sqrt(n); i++){
    //         if(n % i == 0)
    //             return false;
    //     }
    //     return true;
    // }
};