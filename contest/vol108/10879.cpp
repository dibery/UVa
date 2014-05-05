#include<cstdio>

int main()
{
    int t, in;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d", &in );
        for( int x = 2; x < in >> 1; ++x )
            if( in % x == 0 )
                for( int y = 2; y < in >> 1; ++y )
                    if( in / x % y == 0 )
                    {
                        printf( "Case #%d: %d = %d * %d = %d * %d", i, in, x, in / x, x * y, in / x / y );
                        goto end;
                    }
end:
        puts( "" );
    }

    return 0;
}
