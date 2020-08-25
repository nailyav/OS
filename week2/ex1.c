#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("size of a: %lu\nsize of b: %lu\nsize of c: %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("value of a: %d\nvalue of b: %.2f\nvalue of c: %lf\n", a, b, c);
    return 0;
}
