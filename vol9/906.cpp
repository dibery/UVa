#include<cstdio>

int main()
{
    double up, down, diff, value, d, u, tmp;

    while( scanf( "%lf %lf %lf", &up, &down, &diff ) != EOF )
    {
        value = up / down + 1e-14;
        for( d = 1; ( tmp = ( (long long int)( d * value ) + 1 ) ) / d - value > diff || tmp * down == up * d; ++d );
        u = ( (long long int)( d * value ) + 1.0 );
        printf( "%.0f %.0f\n", u, d );
    }

	return 0;
}