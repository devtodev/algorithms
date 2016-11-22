#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	long double t = 0, t1 = 1, n = 10;
	long double result = 0;

	scanf("%Lf %Lf %Lf", &t, &t1, &n);

    for (int i = 2; i < n; i++)
    {
    	result = t + t1 * t1;
    	t = t1;
    	t1 = result;
    }
    printf("%0.LF", result);
    return 0;
}
