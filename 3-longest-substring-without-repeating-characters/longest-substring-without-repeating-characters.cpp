class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //optimal
        int n = s.size();

        //hash table to store last
        //occurence of each char
        vector<int> hash(256, -1);
        
        int l = 0, r = 0, maxLen = 0;

        while(r < n){
            //if current char s[r]
            //is already in the substring
            if(hash[s[r]] != -1){
                //move left ptr to the
                //right of the last 
                //occurrence of s[r]
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            
            hash[s[r]] = r;
            r++;
        }

        return maxLen;

        //brute
        // int n = s.size();
        // int maxLen = 0;

        // for(int i = 0; i < n; i++){

        //     //hash for 256 characters ascii
        //     vector<int> hash(256,0);

        //     for(int j = i; j < n; j++){
        //         //if it is in hash break
        //         if(hash[s[j]] == 1) break;
                
        //         //if not put it in hash
        //         hash[s[j]]++;
                
        //         //current length
        //         int len = j - i + 1;
                
        //         maxLen = max(maxLen, len);
        //     }
        // }     

        // return maxLen;
    }
};
