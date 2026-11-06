/*rational*/
#include <assert.h>
#include <stdio.h>

typedef struct RATIONAL {
    int x, y;
} Rational;

int gcd(int x, int y);
// 注：本案例合适用传值和返回值
Rational* ADD1(Rational* r1, const Rational* r2);
Rational ADD2(Rational r1, Rational r2);
// 请完成乘法，并测试函数正确性
Rational* MULTI1(Rational* r1, const Rational* r2);
Rational MULTI2(Rational r1, Rational r2);

int main(void) {
    assert(gcd(63, 14) == 7);

    // C99,可对成员乱序初始化，C++风格
    Rational r1 = {.x = 1, .y = 2};
    printf("%d,%d\n", r1.x, r1.y);

    // input, 请输入 1 5
    Rational r2;
    scanf("%d%d", &r2.x, &r2.y);

    Rational r3 = ADD2(r1, r2);
    printf("%d,%d\n", r3.x, r3.y);
    assert(ADD1(&r1, &r2)->x == 7);
    printf("%d,%d\n", r1.x, r1.y);

    return 0;
}

Rational* ADD1(Rational* r1, const Rational* r2) {
    int g = gcd(r1->y, r2->y);
    int y = r1->y * r2->y / g;
    int x = (r1->x * r2->y + r1->y * r2->x) / g;
    //    printf("%d,%d,%d\n",g,x,y);
    r1->x = x;
    r1->y = y;
    return r1;
}

Rational ADD2(Rational r1, Rational r2) {
    int g = gcd(r1.y, r2.y);
    int y = r1.y * r2.y / g;
    int x = (r1.x * r2.y + r1.y * r2.x) / g;
    Rational r = {x, y};
    return r;
}

int gcd(int x, int y) {
    if (y % x)
        return gcd(y % x, x);
    else
        return x;
}