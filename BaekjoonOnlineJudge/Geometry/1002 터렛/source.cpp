// BOJ #1002
// User ID: krta2
// Algorithm: geometry

#include <stdio.h>
#include <math.h>

int main()
{
    int T, x1, x2, r1, y1, y2, r2;

    scanf("%d", &T);

    for (int t=0; t<T; t++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        double d = sqrt(pow((double)(x1-x2), 2.0) + pow((double)(y1-y2), 2.0));
        double rSum = (double)(r1+r2);
        double rDiff = (double)abs(r1-r2);
        
        if (d == 0.0 && rDiff == 0.0)
            printf("-1\n");
        else if (rDiff < d && d < rSum)
            printf("2\n");
        else if(rSum == d || rDiff == d)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
