class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        //sort by end time in ascending order
        sort(intervals.begin(), intervals.end()
            ,[](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
            }
        );

        int prev = 0, count = 1;

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }

        // we have to remove n - count meetings
        return n - count;
    }
};