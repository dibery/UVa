#include<cstdio>

int main()
{
    int t, in;
    scanf( "%d", &t );

    for( int k = 1; k <= t; ++k )
    {
        int size, max = -1;
        scanf( "%d", &size );

        for( int i = 0; i < size; ++i )
        {
            scanf( "%d", &in );
            if( in > max )
                max = in;
        }
        printf( "Case %d: %d\n", k, max );
    }

	return 0;
}