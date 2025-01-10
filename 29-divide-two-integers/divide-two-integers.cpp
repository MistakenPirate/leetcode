class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == divisor) return 1;
        
        int sign = 1;

        if ((dividend < 0 && divisor > 0)||(dividend > 0 && divisor < 0)){
            sign = -1;
        }

        //convert divisor and divident to positive ints
        long long n = abs((long long)dividend), d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            long long temp = d, count = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            n -= temp;
            ans += count;
        }

        long long result = sign * ans;

        //overflow case
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int) result;
    }
};