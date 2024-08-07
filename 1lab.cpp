//Restore Ip Addresses
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) {
            return{};
        }
        vector<string> res;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                for (int n = j + 1; n <= s.length(); n++) {
                    string part1 = s.substr(0, i);
                    if (part1.length() > 1 && part1[0] == '0' || part1.length() == 0 || part1.length() > 3) {
                        continue;
                    }
                    string part2 = s.substr(i, j - i);
                    if (part2.length() > 1 && part2[0] == '0' || part2.length() == 0 || part2.length() > 3) {
                        continue;
                    }
                    string part3 = s.substr(j, n - j);
                    if (part3.length() > 1 && part3[0] == '0' || part3.length() == 0 || part3.length() > 3) {
                        continue;
                    }
                    string part4 = s.substr(n, s.length() - n);
                    if (part4.length() > 1 && part4[0] == '0' || part4.length() == 0 || part4.length() > 3) {
                        continue;
                    }
                    if (stoi(part1) >= 0 && stoi(part1) <= 255 && stoi(part2) >= 0 && stoi(part2) <= 255 && stoi(part3) >= 0 && stoi(part3) <= 255 && stoi(part4) >= 0 && stoi(part4) <= 255) {
                        res.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                    }
                }
            }
        }
        return res;
    }
};
