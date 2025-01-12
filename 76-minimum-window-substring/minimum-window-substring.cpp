class Solution {
public:
    string minWindow(string s, string t) {
        //optimal
        int minLen = INT_MAX;
        int sIndex = -1;
        vector<int> hash(256, 0);

        for(char c : t){
            hash[c]++;
        }

        int count = 0; 
        int l = 0, r = 0;

        while(r < s.size()){
            if(hash[s[r]] > 0)
                count++;
            hash[s[r]]--;

            //if all chars from t are found in 
            //the current window
            while(count == t.size()){
                //update minLen and sIndex
                //if current window is smaller
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;
                }

                // Remove leftmost character from window
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }

        return (sIndex == -1) ? "": s.substr(sIndex, minLen);

        //brute
//      int minLen = INT_MAX;
//      //variable to store the starting
//      //index of the min length substring
//      int sIndex = -1;
//      for(int i = 0; i < s.size(); i++){
//          vector<int> hash(256, 0);
//          //count the freq of chars in t
//          for(char c : t){
//              hash[c]++;
//          }
//          int count = 0;
//          //iterate through the current window
//          for(int j = i; j < s.size(); j++){
//              if(hash[s[j]] > 0){
//                  count++;
//              }
//              hash[s[j]]--;
//              //if all chars from t are
//              //found in current window
//              if(count == t.size()){
//                  //update minLen 
//                  //and sIndex
//                  //if current window
//                  //is smaller
//                  if(j - i + 1 < minLen){
//                      minLen = j - i + 1;
//                      sIndex = i;
//                  }
//                  break;
//              }
//          }
//      }
//      return (sIndex == -1) ? "": s.substr(sIndex, minLen);
    }
};    
    