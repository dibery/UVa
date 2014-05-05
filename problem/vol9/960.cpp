#include<cstdio>
#include<cmath>
bool gauss_prime( int R, int I )
{
    int len = R*R + I*I;
    double lim = sqrt( len ) + 1e-14;

    for( int a = 1; a <= lim; ++a )
        for( int b = -lim; b <= lim; ++b )
            if( a*a + b*b > 1 && a*a + b*b < len && ( a*R + b*I ) % ( a*a + b*b ) == 0 && ( a*I - b*R ) % ( a*a + b*b ) == 0 )
                return false;
    return true;
}

int main()
{
    int t, r, i;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %d", &r, &i );
        if( r < 0 && i < 0 )
            r = -r, i = -i;
        printf( gauss_prime( r, i )? "P\n" : "C\n" );
    }

    return 0;
}
