#include<cstdio>
#include<cmath>
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }

int main()
{
    int size, num[ 50 ];

    while( scanf( "%d", &size ) && size )
    {
        double coprime = 0;
        for( int i = 0; i < size; ++i )
            scanf( "%d", num+i );
        for( int i = 0; i < size; ++i )
            for( int j = i+1; j < size; ++j )
                if( gcd( num[ i ], num[ j ] ) == 1 )
                    ++coprime;
        if( !coprime )
            puts( "No estimate for this data set." );
        else
            printf( "%.6f\n", sqrt( 3.0 * size * ( size-1 ) / coprime ) );
    }
    return 0;
}
