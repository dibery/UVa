#include<cstdio>
#include<cstring>
#include<cstdlib>
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }
int pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

int main()
{
    int rep, fra, up, down, len, factor, t = 0;
    char tmp[ 10 ];

    while( scanf( "%d", &rep ) && rep != -1 )
    {
        scanf( " 0.%s", tmp );
        len = strlen( tmp );
        fra = atoi( tmp );
        if( !rep )
        {
            factor = gcd( fra, pow10[ len ] );
            printf( "Case %d: %d/%d\n", ++t, fra / factor, pow10[ len ] / factor );
        }
        else
        {
            up = fra - fra / pow10[ rep ];
            down = pow10[ len ] - pow10[ len - rep ];
            factor = gcd( up, down );
            printf( "Case %d: %d/%d\n", ++t, up / factor, down / factor );
        }
    }
    return 0;
}
