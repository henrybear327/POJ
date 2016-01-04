/*
The main idea is to use dfs to explore all of the connected Ws.

Also, change W to . whenever your dfs traverse over W!
*/
#include <cstdio>

int n, m;
char input[100][110];

inline bool in_bound(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void dfs(int x, int y)
{
    input[x][y] = '.';
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == j && i == 0)
                continue;
            if (in_bound(x + i, y + j) == true && input[x + i][y + j] == 'W') {
                dfs(x + i, y + j);
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%s", input[i]);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (input[i][j] == 'W') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
