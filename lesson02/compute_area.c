/*compute area*/
#include<stdio.h>
 
int main() {
	/*define vars and constants*/ 
	double radius, area,volume;
	const double PI = 3.14;
	
	/*input radius*/
	printf("input radius:");
	scanf("%lf",&radius);
	
	/*compute area*/
	area = radius * radius * PI;


	/*compute volume*/
	volume = (4.0/3.0) * PI * radius * radius * radius;
	
	/*output results*/
	printf("the area for the circle of radius %lf is %lf\n", 
		radius, area);
	printf("the volume for the sphere of radius %lf is %lf\n", 
		radius, volume);
}