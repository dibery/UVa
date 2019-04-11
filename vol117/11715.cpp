#include<cstdio>
#include<cmath>

int main()
{
    int T = 0, Case;
    double u, v, t, a, s;

    while( scanf( "%d", &Case ) && Case )
    {
        if( Case == 1 )
        {
            scanf( "%lf %lf %lf", &u, &v, &t );
            printf( "Case %d: %.3f %.3f\n", ++T, ( u+v ) * t / 2,( v-u ) / t );
        }
        else if( Case == 2 )
        {
            scanf( "%lf %lf %lf", &u, &v, &a );
            printf( "Case %d: %.3f %.3f\n", ++T, ( u+v ) * ( v-u ) / a / 2, ( v-u ) / a );
        }
        else if( Case == 3 )
        {
            scanf( "%lf %lf %lf", &u, &a, &s );
            printf( "Case %d: %.3f %.3f\n", ++T, sqrt( u*u + 2*a*s ), ( sqrt( u*u + 2*a*s )-u ) / a );
        }
        else
        {
            scanf( "%lf %lf %lf", &v, &a, &s );
            printf( "Case %d: %.3f %.3f\n", ++T, sqrt( v*v - 2*a*s ), ( v-sqrt( v*v - 2*a*s ) ) / a );
        }
    }

    return 0;
}