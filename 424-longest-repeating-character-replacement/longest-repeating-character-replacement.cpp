class Solution {
public:
    int characterReplacement(string s, int k) {
        //optimal
        
        int n = s.size();
        /* Variable to store the maximum
        length of substring found*/
        int maxLen = 0;
        int maxFreq = 0;
        int l = 0, r = 0; 
        
        // Hash array to count frequencies of characters
        vector<int> hash(26, 0);

        // Iterate through each starting point of substring
        while (r < n) {

            /* Update frequency of current 
            character in the hash array*/
            hash[s[r] - 'A']++;
            
            // Update max frequency encountered
            maxFreq = max(maxFreq, hash[s[r] - 'A']); 
            
            // Check if current window is invalid 
            if((r - l + 1) - maxFreq > k) {
                
                /* Slide the left pointer to
                make the window valid again*/
                hash[s[l] - 'A']--;                  
                // Move left pointer forward
                l++; 
                
                
            }
            
            /* Update maxLen with the length 
            of the current valid substring*/
            maxLen = max(maxLen, r - l + 1);
            
            // Move right pointer forward to expand the window
            r++;
        }

        /* Return the maximum length of substring
        with at most k characters replaced*/
        return maxLen;

        //better
        // int n = s.size();
        // /* Variable to store the maximum
        // length of substring found*/
        // int maxLen = 0;
        // int maxFreq = 0;
        // int l = 0, r = 0; 
        
        // // Hash array to count frequencies of characters
        // vector<int> hash(26, 0);

        // // Iterate through each starting point of substring
        // while (r < n) {

        //     /* Update frequency of current 
        //     character in the hash array*/
        //     hash[s[r] - 'A']++;
            
        //     // Update max frequency encountered
        //     maxFreq = max(maxFreq, hash[s[r] - 'A']); 
            
        //     // Check if current window is invalid 
        //     while ((r - l + 1) - maxFreq > k) {
                
        //         /* Slide the left pointer to
        //         make the window valid again*/
        //         hash[s[l] - 'A']--;  
                
        //         // Recalculate maxFreq for current window
        //         maxFreq = 0;
        //         for (int i = 0; i < 26; ++i) {
        //             maxFreq = max(maxFreq, hash[i]);
        //         }
                
        //         // Move left pointer forward
        //         l++; 
                
                
        //     }
            
        //     /* Update maxLen with the length 
        //     of the current valid substring*/
        //     maxLen = max(maxLen, r - l + 1);
            
        //     // Move right pointer forward to expand the window
        //     r++;
        // }

        // /* Return the maximum length of substring
        // with at most k characters replaced*/
        // return maxLen;
        
        //brute
        // int n = s.size();    
        // int maxLen  = 0;

        // //variable to track the max freq
        // //of any single char in the current
        // //window
        // int maxFreq = 0;
        
        // for(int i = 0; i < n; i++){
        //     vector<int> hash(26,0);

        //     for(int j = i; j < n; j++){
        //         //update freq of current
        //         //char in hash array
        //         hash[s[j] - 'A']++;

        //         //update max freq encountered
        //         maxFreq = max(maxFreq, hash[s[j] - 'A']);

        //         //calculate changes
        //         int changes = j - i + 1 - maxFreq;

        //         if(changes > k) break;

        //         maxLen = max(maxLen, j - i + 1);
        //     }
        // }

        // return maxLen;
    }
};