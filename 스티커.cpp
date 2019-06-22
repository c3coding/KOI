/*예제 입력 1
2
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80

예제 출력 1
260
290
*/
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))
long long a[100001][2];
long long d[100001][3];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[i][0]);
        }
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[i][1]);
        }
        d[0][0] = d[0][1] = d[0][2] = 0;
        for (int i=1; i<=n; i++) {
            d[i][0] = max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
            d[i][1] = max(d[i-1][0],d[i-1][2])+a[i][0];
            d[i][2] = max(d[i-1][0],d[i-1][1])+a[i][1];
        }
        long long ans = 0;
        for (int i=1; i<=n; i++) {
            ans = max(max(ans,d[i][0]),max(d[i][1],d[i][2]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
