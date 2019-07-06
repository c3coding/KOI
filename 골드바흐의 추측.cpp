#include <cstdio>
const int MAX = 1000000;
int prime[MAX];
int pn;
bool check[MAX+1];
int main() {
    for (int i = 2; i <= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i + i; j <= MAX; j += i) {
                check[j] = true;
            }
        }
    }
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 1; i < pn; i++) {
            if (check[n - prime[i]] == false) {
                printf("%d = %d + %d \n", n, prime[i], n - prime[i]);
                break;
            }
        }
    }
    return 0;
}
