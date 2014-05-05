#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cctype>
int check( char *n )
{
    char ans = 0;
    for( int i = 0; n[ i ]; ++i )
        ans = std::max( ans, n[ i ] );
    if( isdigit( ans ) )
        return std::max( ans-'0'+1, 2 );
    else
        return ans-'A'+11;
}

int main()
{
    char a[ 1000 ], b[ 1000 ];
    int baseA, baseB;

    while( scanf( "%s %s", a, b ) != EOF )
    {
        bool found = false;
        if( !strcmp( a, "0" ) || !strcmp( b, "0" ) )
            found = true;
        for( baseA = check( a ); baseA <= 36 && !found; ++baseA )
            for( baseB = check( b ); baseB <= 36 && !found; ++baseB )
                if( strtoll( a, NULL, baseA ) == strtoll( b, NULL, baseB ) )
                    goto next;
next:
        if( !strcmp( a, "0" ) && !strcmp( b, "0" ) )
            baseA = baseB = 2;
        if( baseA == 37 || ( !strcmp( a, "0" ) || !strcmp( b, "0" ) ) && strcmp( a, b ) )
            printf( "%s is not equal to %s in any base 2..36\n", a, b );
        else
            printf( "%s (base %d) = %s (base %d)\n", a, baseA, b, baseB );
    }

    return 0;
}
