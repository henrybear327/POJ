#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int R, n;
    while (scanf("%d %d", &R, &n) == 2 && !(R == -1 && n == -1)) {
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            int curr;
            scanf("%d", &curr);

            pos.push_back(curr);
        }

        sort(pos.begin(), pos.end());

        int cnt = 0, i = 0;
        while (i < n) {
            cnt++;
            // find right-most point from left
            int j = i;
            while (j < n && pos[j + 1] - pos[i] <= R) // pos[j + 1]!! Good job!
                j++;
            i = j;
            // find right-most point from center
            while (j < n && pos[j + 1] - pos[i] <= R)
                j++;
            i = j + 1;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
