class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //optimal
        int n = fruits.size();
        int maxLen = 0;
        unordered_map<int,int> mpp;

        int l = 0, r = 0;

        while(r < n){
            mpp[fruits[r]]++;

            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++; 
            }

            if(mpp.size() <= 2){
                maxLen = max(maxLen,  r - l + 1);
            }
            r++;
        }

        return maxLen;

        //better
        // int n = fruits.size();
        // int maxLen = 0;
        // unordered_map<int,int> mpp;

        // int l = 0, r = 0;

        // while(r < n){
        //     mpp[fruits[r]]++;

        //     while(mpp.size() > 2){
        //         mpp[fruits[l]]--;
        //         if(mpp[fruits[l]] == 0)
        //             mpp.erase(fruits[l]);
        //         l++; 
        //     }

        //     if(mpp.size() <= 2){
        //         maxLen = max(maxLen,  r - l + 1);
        //     }
        //     r++;
        // }

        // return maxLen;
        
        //brute

        // int n = fruits.size();
        // int maxLen  = 0;
        
        // for(int i = 0; i < n; i++){
        //     //set to store fruits
        //     unordered_set<int> set;

        //     for(int j = i; j < n; j++){
        //         set.insert(fruits[j]);
        //         if(set.size() > 2) break;

        //         int len = j - i + 1;
        //         maxLen = max(maxLen, len);
        //     }
        // }

        // return maxLen;
    }
};