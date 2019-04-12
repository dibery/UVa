#include<cstdio>
#include<cstring>
#include<cstdlib>
const char *ans[] = { "0", "1", "2486", "3971", "46", "5", "6", "7931", "8426", "91" };

int main()
{
    int base, exp;
    char a[ 102 ], b[ 102 ];

    while( scanf( "%s %s", a, b ) && ( strcmp( a, "0" ) || strcmp( b, "0" ) ) )
    {
        base = a[ strlen( a ) - 1 ] - '0';
        exp = strlen( b ) > 8 ? atoi( b + strlen( b ) - 6 ) : atoi( b );

        if( exp )
            printf( "%c\n", ans[ base ][ ( exp - 1 ) % strlen( ans[ base ] ) ] );
        else
            puts( base? "1" : "0" );
    }

    return 0;
}
