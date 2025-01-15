class Solution {
public:
    string reverseWords(string s) {
    int n = s.length();
        vector<string> words;
        //pointers to mark the start and end of a word
        int start, end;

        int i = 0;
        while(i < n){
            //finding the first char of a word
            while(i < n && s[i] == ' ') i++;

            //if no word found, break
            if(i >= n) break;

            //store the infex of first char of word
            start = i;

            //finding the last char of the word
            while(i < n && s[i] != ' ') i++;

            //storing the index of last char of word
            end = i - 1;

            //add the found word to the list of words
            string wordFound = s.substr(start, end - start + 1);
            words.push_back(wordFound);
        }

        string ans = "";

        //addming all the words to result in the rev order
        for(int i = words.size() - 1; i >= 0; i--){
            ans += words[i];

            if(i != 0) ans.push_back(' ');
        }

        return ans;    
    }
};