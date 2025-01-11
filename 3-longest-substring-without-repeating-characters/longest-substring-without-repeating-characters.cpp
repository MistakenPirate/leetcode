class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){

            //hash for 256 characters ascii
            vector<int> hash(256,0);

            for(int j = i; j < n; j++){
                //if it is in hash break
                if(hash[s[j]] == 1) break;
                
                //if not put it in hash
                hash[s[j]]++;
                
                //current length
                int len = j - i + 1;
                
                maxLen = max(maxLen, len);
            }
        }     

        return maxLen;
    }
};
