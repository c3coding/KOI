/*
입력
6
6
10
13
9
8
1

출력
33
*/
#include <cstdio>
int a[10001];
int d[10001];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    d[1] = a[1];
    d[2] = a[1]+a[2];
    for (int i=3; i<=n; i++) {
        d[i] = d[i-1];
        if (d[i] < d[i-2] + a[i]) {
            d[i] = d[i-2] + a[i];
        }
        if (d[i] < d[i-3] + a[i] + a[i-1]) {
            d[i] = d[i-3] + a[i] + a[i-1];
        }
    }
    printf("%d\n",d[n]);
    return 0;
}
