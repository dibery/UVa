#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char a[ 10 ]= { 0 }, b[ 10 ] = { 0 }, carry = 0;

    while( scanf( "%s %s", a, b ) && ( strcmp( a, "0" ) || strcmp( b, "0" ) ) )
    {
        reverse( a, a+strlen( a ) );
        reverse( b, b+strlen( b ) );
        for( int i = 0; i < 10; ++i )
            if( a[ i ] + b[ i ] > 105 || a[ i ] + b[ i ] < 96 && a[ i ] + b[ i ] > 57 )
            {
                ++carry;
                ++a[ i+1 ];
            }
        if( !carry )
            puts( "No carry operation." );
        else if( carry == 1 )
            puts( "1 carry operation." );
        else
            printf( "%d carry operations.\n", carry );
        for( int i = 0; i < 10; ++i )
            carry = a[ i ] = b[ i ] = 0;
    }

	return 0;
}