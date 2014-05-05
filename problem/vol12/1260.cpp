#include<cstdio>

int main()
{
    int test, sale[ 1000 ], size, ans;
    scanf( "%d", &test );

    while( test-- )
    {
        ans = 0;
        scanf( "%d", &size );
        for( int i = 0; i < size; ++i )
            scanf( "%d", sale+i );
        for( int i = 1; i < size; ++i )
            for( int j = i-1; j >= 0; --j )
                if( sale[ j ] <= sale[ i ] )
                    ++ans;
        printf( "%d\n", ans );
    }

	return 0;
}