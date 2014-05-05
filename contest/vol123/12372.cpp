#include<cstdio>

int main()
{
    int test, a[ 3 ];
    scanf( "%d", &test );

    for( int i = 1; i <= test; ++i )
    {
        scanf( "%d %d %d", a, a+1, a+2 );
        printf( "Case %d: %s\n", i, a[ 0 ] > 20 || a[ 1 ] > 20 || a[ 2 ] > 20? "bad" : "good" );
    }

    return 0;
}
