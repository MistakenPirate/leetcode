class Solution {

public:
    vector<int> nextGreaterElements(vector<int> arr) {

        int n = arr.size();

        // To store the next greater elements
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            // Get the current element
            int currEle = arr[i];

            /* Nested loop to get the
            next greater element */
            for (int j = 1; j < n; j++) {

                // Getting the hypothetical index
                int ind = (j + i) % n;

                // If the next greater element is found
                if (arr[ind] > currEle) {

                    // Store the next greater element
                    ans[i] = arr[ind];

                    // Break from the loop
                    break;
                }
            }
        }

        // Return the answer
        return ans;
    }
};