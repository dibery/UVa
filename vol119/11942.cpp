#include<cstdio>

int main()
{
    int t, len[ 10 ];
    scanf( "%d", &t );
    puts( "Lumberjacks:" );

    while( t-- )
    {
        bool down = false, up = false;
        for( int i = 0; i < 10; ++i )
            scanf( "%d", len+i );
        for( int i = 1; i < 10; ++i )
            if( len[ i ] > len[ i-1 ] )
                up = true;
            else if( len[ i ] < len[ i-1 ] )
                down = true;
        puts( up ^ down? "Ordered" : "Unordered" );
    }

	return 0;
}