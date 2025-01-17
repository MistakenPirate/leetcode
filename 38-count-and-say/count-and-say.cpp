class Solution
{
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        // Recursive call to get the previous sequence
        string prev = countAndSay(n - 1);
        int len = prev.length();

        // To store the answer
        string ans = "";

        // Initialize count to 1 for the first character
        int count = 1;

        // Traverse the string
        for (int i = 1; i < len; i++) {
            if (prev[i] == prev[i - 1]) {
                // If identical characters are found, increase the counter
                count++;
            } else {
                // Add frequency and digit to the result
                ans.push_back('0' + count); // Add frequency
                ans.push_back(prev[i - 1]); // Add the digit
                count = 1; // Reset counter to 1
            }
        }

        // Add the frequency and the last digit
        ans.push_back('0' + count);
        ans.push_back(prev[len - 1]);

        return ans;
    }
};
