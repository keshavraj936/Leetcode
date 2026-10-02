class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;

        // Count characters in magazine
        for(char c : magazine) {
            mp[c]++;
        }

        // Use characters for ransomNote
        for(char c : ransomNote) {
            if(mp[c] == 0)
                return false;

            mp[c]--;
        }

        return true;
    }
};