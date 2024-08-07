//Best player in chess
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findBestChessPlayer(int n, vector<vector<int>>& edges)
    {
        unordered_set<int> powerfulPlayers;
        unordered_set<int> poorPlayers;
        for (vector<int> edge : edges)
        {
            powerfulPlayers.insert(edge[0]);
            poorPlayers.insert(edge[1]);
        }
        vector<int> liders;
        for (int i = 0; i < n; ++i)
        {
            if (poorPlayers.find(i) == poorPlayers.end() && powerfulPlayers.find(i) != powerfulPlayers.end())
            {
                liders.push_back(i);
            }
        }
        if (liders.size() > 1)
        {
            return -1;
        }
        if (liders.empty()) {
            return -1;
        }
        else {
            return liders[0];
        }
    }
};
int main() {
    Solution solution;

    int n = 6;
    vector<vector<int>> edges = { {0, 2}, {1, 4}, {3, 5}, {1, 0}, {4,3} };

    int bestPlayer = solution.findBestChessPlayer(n, edges);

    if (bestPlayer == -1) {
        cout << "0 best players" << endl;
    }
    else {
        cout << "Best player: " << bestPlayer << endl;
    }

    return 0;
}
