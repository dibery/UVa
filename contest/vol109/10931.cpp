#include<cstdio>
#include<cstring>

int main()
{
    int n;

    while( scanf( "%d", &n ) && n )
    {
        char bin[ 32 ] = { 0 };
        int par = 0;
        memset( bin, '0', sizeof( char ) * 31 );
        for( int i = 0; i < 31; ++i, n /= 2 )
            if( n % 2 == 1 )
                ++bin[ 30 - i ], ++par;
        printf( "The parity of %s is %d (mod 2).\n", strchr( bin, '1' ), par );
    }

	return 0;
}