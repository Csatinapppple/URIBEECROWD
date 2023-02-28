#include <stdio.h>
#include <math.h>
#define PI 3.14159
double sphere(double r){
    return (4.0/3) * PI * pow(r,3); 
}
int main() {
    double r;
    scanf("%lf",&r);
    printf("VOLUME = %.3lf\n",sphere(r));
    return 0;
}