#include <stdio.h>


double Power(double a, int n)
{
    double temp;

    if (n == 0)
        return 1;

    temp = Power(a, n / 2);

    if (n % 2 == 0)
        return temp * temp;
    else
        return a * temp * temp;
}

int main()
{
    double a;
    int n;

    printf("Enter base (a): ");
    scanf("%lf", &a);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    printf("Result = %.2lf\n", Power(a, n));

    return 0;
}

