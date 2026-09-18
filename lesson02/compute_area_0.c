/*compute area primary*/
#include <stdio.h>

int main() {
    /*define vars and constants*/
    double radius = 5;
    double area;
    const double PI = 3.14;
    /*compute area*/
    area = radius * radius * PI;

    /*output results*/
    printf("the area for the circle of radius %lf is %lf\n", radius, area);
}