#include<cstdio>
#include<cmath>

int main()
{
    int t, sum, pro, sq;
    scanf( "%d", &t );

    for( int i = 0; i < t; ++i )
    {
        scanf( "%d %d %d", &sum, &pro, &sq );
        int lim = sqrt( sq );
        bool found = false;
        for( int a = -lim; a <= lim && !found; ++a )
            for( int b = -lim; b <= lim && !found; ++b )
                for( int c = -lim; c <= lim && !found; ++c )
                    if( a != b && b != c && a != c && a+b+c == sum && a*b*c == pro && a*a + b*b + c*c == sq )
                        printf( "%d %d %d\n", a, b, c ), found = true;
        if( !found )
            puts( "No solution." );
    }

	return 0;
}