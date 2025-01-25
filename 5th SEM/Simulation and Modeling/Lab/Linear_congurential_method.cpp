#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, c, a;
    int x[100], m;
    float r[100];
    printf("enter the value of multiplier: ");
    scanf("%d", &a);
    printf("enter the value of increment: ");
    scanf("%d", &c);
    printf("enter the value of m: ");
    scanf("%d", &m);
    printf("enter value of seed: ");
    scanf("%d", &x[0]);
    printf("\n x[i] \t\t r[i]");
    printf("\n***********************");
    for (i = 0; i < 100; i++)
    {
        x[i + 1] = (a + x[i] + c) % m;
        printf("\n nx[%2d]=%2d", i, x[i]);
        r[i] = float(x[i]) / float(m);
        printf("\t%.3f", r[i]);
    }
}