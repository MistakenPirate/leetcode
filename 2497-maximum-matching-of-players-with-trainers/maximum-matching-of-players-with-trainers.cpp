class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // same as assign cookie problem -> greedy paradigm
        int n = players.size(), m = trainers.size(), l = 0, r = 0;
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        while(l < n && r < m){
            if(trainers[r] >= players[l]){
                l++;
            }
            r++;
        }
        return l;
    }
};