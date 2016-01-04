#include <cstdio>
#include <algorithm>

using namespace std;

int par[50100];

int root(int a)
{
    return par[a] < 0 ? a : par[a] = root(par[a]);
}

void merge(int a, int b)
{
    if (par[a] == par[b])
        return;

    if (par[a] > par[b]) { //-3 -5
        swap(par[a], par[b]);
    }

    par[a] += par[b];
    par[b] = a;

    return;
}

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        fill(par, par + 50100, -1);
	
	int ans = 0;
        for (int i = 0; i < k; i++) {
            int d, a, b;
	    scanf("%d %d %d", &d, &a, &b);

        }
    }

    return 0;
}
