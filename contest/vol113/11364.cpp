#include<cstdio>

int main()
{
    register int test, i, min, max, in;
    scanf( "%*s" );

    while( scanf( "%d", &test ) != EOF )
    {
        min = 99999;
        max = -1;
        for( i = 0; i < test; ++i )
        {
            scanf( "%d", &in );
            if( in > max )
                max = in;
            if( in < min )
                min = in;
        }
        printf( "%d\n", (max-min) << 1 );
    }

	return 0;
}