#include<cstdio>
#include<cmath>

int main()
{
    int hole;
    double gopherx, gophery, dogx, dogy, x, y, a;

    while( scanf( "%d %lf %lf %lf %lf", &hole, &gopherx, &gophery, &dogx, &dogy ) != EOF )
    {
        bool escape = false;
        for( int i = 0; i < hole; ++i )
            if( escape )
                scanf( "%*lf %*lf" );
            else
            {
                scanf( "%lf %lf", &x, &y );
                if( 2*sqrt( ( gopherx-x )*( gopherx-x )+( gophery-y )*( gophery-y ) ) <= sqrt( ( dogx-x )*( dogx-x )+( dogy-y )*( dogy-y ) ) )
                    escape = true;
            }
        if( !escape )
            puts( "The gopher cannot escape." );
        else
            printf( "The gopher can escape through the hole at (%.3f,%.3f).\n", x, y );
    }

	return 0;
}