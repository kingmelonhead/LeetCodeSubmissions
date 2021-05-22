class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> used_chars;
        int counter = 1;
        int highest = 0;
        used_chars.push_back(s[0]);
        if (s.length() == 0) return 0;
        for (int i = 1; i < s.length(); i++){
            auto it = find(used_chars.begin(), used_chars.end(), s[i]);
            if(it != used_chars.end()){
                if (counter > highest) highest = counter;
                used_chars.erase(used_chars.begin(), ++it);
                used_chars.push_back(s[i]);
                counter = used_chars.size();
            }
            else {
                used_chars.insert(used_chars.end(), s[i]);
                counter++;
            }
        }
        if (counter > highest) return counter;
        else return highest;
    }
};
