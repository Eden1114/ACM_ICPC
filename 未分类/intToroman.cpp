#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int m = INT_MAX;
        for(auto& s:strs)
        {
            m = (s.length() < m)?s.length():m;
        }
        string res = "";
        for(int i = 0;i < m;i++) {
            bool flag = true;
            char t = strs[0][i];
            for(auto& s:strs) if(s[i] != t) flag = false;
            if(flag == false) break;
            else res += t;
        }
        return res;
    }
};