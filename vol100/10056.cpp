#include<cstdio>
#include<cmath>

int main()
{
    int t, people, index;
    double prob;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %lf %d", &people, &prob, &index );
        double ans = 0, tmp = prob * pow( 1-prob, index-1 );
        for( int i = 0; i < 200; ++i )
        {
            ans += tmp + 1e-12;
            tmp *= pow( 1-prob, people );
        }
        printf( "%.4f\n", ans );
    }

	return 0;
}