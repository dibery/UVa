#include<cstdio>

int main()
{
    int test, size, ans;
    scanf( "%d", &test );

    for( int i = 1; i <= test; ++i )
    {
        scanf( "%d", &size );
        for( int k = size >> 1; k; --k )
            scanf( "%*d" );
        scanf( "%d", &ans );
        for( int k = size >> 1; k; --k )
            scanf( "%*d" );
        printf( "Case %d: %d\n", i, ans );
    }

    return 0;
}
