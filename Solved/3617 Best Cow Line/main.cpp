#include <cstdio>
#include <queue>
#include <cassert>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        char inp[n + 2];
        for (int i = 0; i < n; i++) {
            char tmp[10];
            scanf("%s", tmp);
            inp[i] = tmp[0];
        }

        int head = 0, tail = n - 1;
        char ans[n + 2];
        for (int i = 0; i < n - 1; i++) {
	    

	    /*
	    Wrong on this case:
	    ZZCDZZ
	    ZZDCZZ

	    // WRONG!!
            if (inp[head] == inp[tail]) {
                if (inp[head + 1] <= inp[tail - 1]) {
                    ans[i] = inp[head];
                    head++;
                } else {
                    ans[i] = inp[tail];
                    tail--;
                }
            } else {
                ans[i] = inp[head] < inp[tail] ? inp[head++] : inp[tail--];
            }
	    */
        }

        ans[n - 1] = inp[head];
        ans[n] = '\0';
        for (int i = 1; i <= n; i++) {
            printf("%c", ans[i - 1]);
            if (i % 80 == 0)
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}
