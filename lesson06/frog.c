#include <stdio.h>

// 方法1：递归实现（简单但效率低）
long long jumpWays_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return jumpWays_recursive(n - 1) + jumpWays_recursive(n - 2);
}

// 方法2：动态规划实现（推荐）
long long jumpWays_dp(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 方法3：动态规划优化（节省空间）
long long jumpWays_optimized(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long a = 1, b = 2, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    printf("请输入台阶数n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("台阶数不能为负数！\n");
        return 1;
    }

    printf("递归方法: 跳上%d级台阶有%lld种跳法\n", n, jumpWays_recursive(n));
    printf("动态规划: 跳上%d级台阶有%lld种跳法\n", n, jumpWays_dp(n));
    printf("优化方法: 跳上%d级台阶有%lld种跳法\n", n, jumpWays_optimized(n));

    return 0;
}