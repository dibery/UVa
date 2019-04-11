#include<cstdio>

int main()
{
    long long int test, in, i;
    scanf( "%lld", &test );

    for( i = 1; i <= test; ++i )
    {
        scanf( "%lld", &in );
        if( in % 4 > 1 )
            printf( "Case %d: %lld/2\n", i, in*(in-1)>>1 );
        else
            printf( "Case %d: %lld\n", i, in*(in-1)>>2 );
    }

	return 0;
}