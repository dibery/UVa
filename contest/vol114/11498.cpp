#include<cstdio>

int main()
{
    register int test, ox, oy, x, y;

    while( scanf( "%d", &test ) && test )
    {
        scanf( "%d %d", &ox, &oy );
        while( test-- )
        {
            scanf( "%d %d", &x, &y );
            if( x > ox )
                if( y > oy )
                    puts( "NE" );
                else if( y == oy )
                    puts( "divisa" );
                else
                    puts( "SE" );
            else if( x == ox )
                    puts( "divisa" );
            else if( x < ox )
                if( y > oy )
                    puts( "NO" );
                else if( y == oy )
                    puts( "divisa" );
                else
                    puts( "SO" );
        }
    }
    return 0;
}
