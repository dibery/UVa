#include<cstdio>
#include<cmath>

int main()
{
    int t, num;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d", &num );
        printf( "Case %d:", i );
        for( int i = sqrt( double( num ) ); i; --i )
            if( ( num - i * i ) % i == 0 && num != i * i )
                printf( " %d", num - i * i );
        puts( "" );
    }

	return 0;
}