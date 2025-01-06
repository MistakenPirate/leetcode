class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; //, twenty = 0;
        int n = bills.size();

        //iterate through every lemonade order bill
        //there will be 3 cases
        //1. they give 5 (five++)
        //2. they give 10 
        //   a. if you have 5 , five-- && ten++
        //   b. if you dont have 5, return false
        //3. they give a 20
        //   a. if you have 10 & 5, ten--, five--, twenty++
        //   b. if you have 3 * 5, five -= 3, twenty++
        //   c. if you dont have either , return false
        //note: no need to store 20 because it can't be returned
        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                if(five && ten){
                    five--;
                    ten--;
                    //twenty++;
                }
                else if (five >= 3){
                    five -= 3;
                    //twenty++;
                }
                else return false;
            }
        }
        return true;
    }
};