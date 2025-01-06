class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // l and r are pointers to first index of g and s array
        int n = g.size(), m = s.size(), l = 0, r = 0;
        int count = 0;
        // sorting the arrays g and s
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        //while the pointers are still in bound
        //check if cookie can satisfy greed (>= greed)
        //if yes, add count, and move to the next greed index
        //either way go to the next cookie index
        while(l < n && r < m){
            if(s[r] >= g[l]){
                count++;
                l++;
            }
            r++;
        }
        return count;
    }
};