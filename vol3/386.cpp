#include<cstdio>
#include<cmath>
inline int cube( int i ) { return i*i*i; }
bool Cub[ 8000000 ] = { false };

int main()
{
    for( int i = 0; i < 200; ++i )
        Cub[ cube( i ) ] = true;
    for( int i = 6; i <= 200; ++i )
        for( int j = 2; j < i; ++j )
            for( int k = j; k < i; ++k )
            {
                int tmp = cube( i ) - cube( j ) - cube( k );
                if( tmp > 0 && Cub[ tmp ] && cbrt( tmp ) >= k )
                    printf( "Cube = %d, Triple = (%d,%d,%.0f)\n", i, j, k, cbrt( tmp ) );
            }
    return 0;
}
