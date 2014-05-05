#include<cstdio>
#include<cmath>
int sq[ 224 ] = { 0 }, can[ 50001 ] = { 0 };

int main()
{
    int t, in;
    scanf( "%d", &t );
    for( int i = 1; i <= 223; ++i )
        sq[ i ] = i * i;
    for( int i = 0; i <= 223; ++i )
        for( int j = 0; j <= 223 && sq[ i ] + sq[ j ] <= 50000; ++j )
            for( int k = 0; k <= 223 && sq[ i ] + sq[ j ] + sq[ k ] <= 50000; ++k )
                if( !can[ sq[ i ] + sq[ j ] + sq[ k ] ] )
                    can[ sq[ i ] + sq[ j ] + sq[ k ] ] = k + 1000 * j + 1000000 * i;

    while( t-- )
    {
        scanf( "%d", &in );
        if( can[ in ] )
            printf( "%d %d %d\n", can[ in ] / 1000000, can[ in ] / 1000 % 1000, can[ in ] % 1000 );
        else
            puts( "-1" );
    }

	return 0;
}