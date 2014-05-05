#include<cstdio>
#include<cmath>
int p, q, r, s, t, u;
inline double equ( double x ) { return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u; }

int main()
{

    while( scanf( "%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u ) != EOF )
    {
        if( equ( 0 ) * equ( 1 ) > 0 )
        {
            puts( "No solution" );
            continue;
        }
        double h = 1, l = 0, m = 0.5;
        for( int i = 0; i < 22; ++i, m = ( l+h ) / 2 )
            if( equ( m ) > 0 )
                l = m;
            else
                h = m;
        printf( "%.4f\n", m );
    }

	return 0;
}