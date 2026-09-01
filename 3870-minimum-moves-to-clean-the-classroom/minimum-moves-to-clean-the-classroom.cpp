class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // id[i][j] = bit number of litter at (i,j)
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Find starting position and assign a bit to every litter cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // No litter to collect
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;

        /*
            State:
            r, c       -> current position
            e          -> remaining energy
            mask       -> litter still NOT collected

            Initially, all litter is uncollected.
        */

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        int initialMask = totalMasks - 1;

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, initialMask});
        visited[sr][sc][energy][initialMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot make another move
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Reset area
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        nmask &= ~(1 << bit);
                    }

                    // Already visited this exact state
                    if (visited[nr][nc][ne][nmask])
                        continue;

                    visited[nr][nc][ne][nmask] = true;
                    q.push({nr, nc, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};
