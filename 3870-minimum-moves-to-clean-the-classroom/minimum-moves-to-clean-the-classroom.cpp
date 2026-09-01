class Solution {
public:
    struct State {
        int x, y, energy, steps, mask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        unordered_map<int, int> id; // key = x * n + y
        int idCounter = 0;
        int sx, sy;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = classroom[i][j];
                if (c == 'L') {
                    id[i * n + j] = idCounter++;
                } else if (c == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        int fullMask = (1 << idCounter) - 1;

        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(fullMask + 1, -1)));
        queue<State> q;
        q.push({sx, sy, energy, 0, 0});
        bestEnergy[sx][sy][0] = energy;

        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.mask == fullMask) return s.steps;
            if (s.energy <= 0) continue;

            for (int d = 0; d < 4; ++d) {
                int nx = s.x + dx[d], ny = s.y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                char cell = classroom[nx][ny];
                if (cell == 'X') continue;

                int newEnergy = (cell == 'R') ? energy : (s.energy - 1);
                int newMask = s.mask;

                if (cell == 'L') {
                    newMask |= (1 << id[nx * n + ny]);
                }

                if (newEnergy <= bestEnergy[nx][ny][newMask]) continue;
                bestEnergy[nx][ny][newMask] = newEnergy;
                q.push({nx, ny, newEnergy, s.steps + 1, newMask});
            }
        }

        return -1;
    }
};