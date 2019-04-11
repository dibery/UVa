#include<cstdio>

int main()
{
    int t, C, F;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d %d", &C, &F );
        printf( "Case %d: %.2lf\n", i, C + F / 1.8 + 1e-12 );
    }

	return 0;
}