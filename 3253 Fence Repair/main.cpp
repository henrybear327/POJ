#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    // use long long int, stupid!
    while (scanf("%d", &n) == 1) {
        priority_queue<long long int, vector<long long int>, greater<long long int> >
                pq;

        for (int i = 0; i < n; i++) {
            long long int tmp;
            scanf("%lld", &tmp);

            pq.push(tmp);
        }

        long long int cost = 0;
        while (pq.size() > 1) {
            long long int one = pq.top();
            pq.pop();
            long long int two = pq.top();
            pq.pop();
            cost += one + two;
            pq.push(one + two);
        }
        printf("%lld\n", cost);
    }

    return 0;
}
