class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
          vector<pair<int,int>> dir = {
            {-2,-1}, {-2,1}, {-1,-2}, {-1,2},
            {1,-2}, {1,2}, {2,-1}, {2,1}
        };

        queue<vector<int>> q;
        bool vis[8][8][2] = {};

        q.push({start[0], start[1], 0}); // x, y, moves
        vis[start[0]][start[1]][0] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int moves = cur[2];

            if (x == target[0] && y == target[1]) {
                if (moves % 2 == 0)
                    return true;
            }

            for (auto &d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    int np = (moves + 1) % 2;

                    if (!vis[nx][ny][np]) {
                        vis[nx][ny][np] = true;
                        q.push({nx, ny, moves + 1});
                    }
                }
            }
        }

        return false;
    }
};