#include<cstdio>
#include<algorithm>

int main()
{
    int a[ 3 ], t = 0;
    scanf( "%*s" );

    while( scanf( "%d %d %d", a, a+1, a+2 ) != EOF )
    {
        std::sort( a, a+3 );
        printf( "Case %d: %d\n", ++t, a[ 1 ] );
    }
    return 0;
}
