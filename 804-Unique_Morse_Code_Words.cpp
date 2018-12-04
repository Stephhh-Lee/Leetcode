class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string dict[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---", ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, int> m;
        for(auto x:words){
            string s = "";
            for(char c:x){
                s += dict[c-'a'];
            }
            m[s]++;
        }
        return m.size();
    }
};
