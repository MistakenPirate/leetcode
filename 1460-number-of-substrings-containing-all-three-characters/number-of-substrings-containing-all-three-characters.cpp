class Solution {
public:
    int numberOfSubstrings(string s) {
        //optimal
        int n = s.size();
        //array to store the 
        //last seen index of chars
        //a, b, c
        int lastSeen[3] = {-1, -1, -1};

        int count = 0;

        for(int i = 0; i < n; i++){

            //update lastSeem index for
            lastSeen[s[i] - 'a'] = i;

            //check if all chars have been seen
            if(lastSeen[0] != -1 &&
               lastSeen[1] != -1 &&
               lastSeen[2] != -1){

                //count valid substrings
                //ending at current index

                count += 1 + min({lastSeen[0],
                                 lastSeen[1],
                                 lastSeen[2]});
            }
        }

        return count;
        
        //brute
        // int count = 0;
        // int n = s.size();

        // for(int i = 0; i < n; i++){
        //     vector<int> hash(3,0);
        //     for(int j = i; j < n; j++){
        //         //mask current char in hash
        //         hash[s[j] - 'a'] = 1;
        //         if(hash[0] + hash[1] + hash[2] == 3)
        //             count++;
        //     }
        // }    

        // return count;
    }
};