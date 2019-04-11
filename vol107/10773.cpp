#include<cstdio>
#include<cmath>

int main()
{
    int t;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        double dist, river, boat;
        scanf( "%lf %lf %lf", &dist, &river, &boat );
        if( !river || boat <= river || !boat )
        {
            printf( "Case %d: can't determine\n", i );
            continue;
        }
        printf( "Case %d: %.3lf\n", i, dist / sqrt( boat*boat - river*river ) - dist / boat );
    }

	return 0;
}