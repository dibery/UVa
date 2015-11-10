#include<cstdio>
#include<cmath>

int main()
{
    double v, v0, tmp;

    while( scanf( "%lf %lf", &v, &v0 ) && v )
    {
        double max = 0;
        int i, ans;
        bool can = v > v0;

        for( i = 1; can && v / i > v0; ++i )
        {
            tmp = i * 0.3 * sqrt( v / i - v0 );
            if( fabs( tmp - max ) < 1e-9 )
                can = false;
            else if( tmp > max )
            {
                max = tmp;
                ans = i;
            }
        }
        printf( "%d\n", can? ans : 0 );
    }
}
