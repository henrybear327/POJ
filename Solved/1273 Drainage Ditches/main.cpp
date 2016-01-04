#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;

#define MAX_VERTICES 210

struct edge {
    int to, capacity, backward_edge;
};

vector<edge> G[MAX_VERTICES]; // graph recorded using adj. list
int level[MAX_VERTICES];      // Distance to s
int iteration[MAX_VERTICES];  // Store the currently traversed node from each
// node in the graph (avoid repeat searching from
// first)

void add_edge(int from, int to, int capacity)
{
    G[from].push_back((edge) {
        to, capacity, (int)G[to].size()
    }); // forward edge
    G[to].push_back((edge) {
        from, 0, (int)G[from].size() - 1
    });  // backward graph
    // the third .size() parameter is the postion of the backward edge. (The
    // property of the adj. list!)
}

void bfs(int s) // distance to s
{
    memset(level, -1, sizeof(level));
    level[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < (int)G[curr].size(); i++) {
            edge &next = G[curr][i];
            if (next.capacity > 0 && level[next.to] < 0) {
                // not visited and capacity is positive
                level[next.to] = level[curr] + 1;
                q.push(next.to);
            }
        }
    }
}

int dfs(int curr, int t, int max_flow_this_time)
{
    if (curr == t)
        return max_flow_this_time;

    for (int &i = iteration[curr]; i < (int)G[curr].size(); i++) {
        edge &next = G[curr][i];
        if (next.capacity > 0 && level[curr] < level[next.to]) {
            int bottleneck = dfs(next.to, t, min(max_flow_this_time, next.capacity));

            if (bottleneck > 0) {
                next.capacity -= bottleneck; // forward edge -= bottleneck
                G[next.to][next.backward_edge].capacity +=
                    bottleneck; // backward edge += bottleneck
                return bottleneck;
            }
        }
    }

    return 0; // base case
}

int max_flow(int s, int t)
{
    int ans = 0;
    while (1) {
        bfs(s);
        if (level[t] < 0)
            return ans;
        memset(iteration, 0, sizeof(iteration));

        int max_flow_this_round;
        while ((max_flow_this_round = dfs(s, t, INT_MAX)) > 0) {
            ans += max_flow_this_round;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        // init
        for (int i = 0; i < MAX_VERTICES; i++)
            G[i].clear();

        for (int i = 0; i < n; i++) {
            int from, to, cap;
            scanf("%d %d %d", &from, &to, &cap);
            add_edge(from - 1, to - 1, cap);
        }
        printf("%d\n", max_flow(0, m - 1));
    }

    return 0;
}
