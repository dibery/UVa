#include<cstdio>
#include<cstdlib>
inline int unit( int n ) { return n >= 0? 1 : -1; }

int main()
{
    int x1[ 10 ], x2[ 10 ], y1[ 10 ], y2[ 10 ], item = 0, n[ 8 ], point = 0;
    char type;
//freopen("test","r",stdin);
    while( scanf( "%c", &type ) && type != '*' )
    {
        scanf( "%d.%d %d.%d %d.%d %d.%d\n", n, n+1, n+2, n+3, n+4, n+5, n+6, n+7 );
        x1[ item ] = n[ 0 ]*1000 + n[ 1 ]*unit( n[ 0 ] );
        y1[ item ] = n[ 2 ]*1000 + n[ 3 ]*unit( n[ 2 ] );
        x2[ item ] = n[ 4 ]*1000 + n[ 5 ]*unit( n[ 4 ] );
        y2[ item ] = n[ 6 ]*1000 + n[ 7 ]*unit( n[ 6 ] );
        ++item;
    }
    while( scanf( "%d.%d %d.%d", n, n+1, n+2, n+3 ) )
    {
        int x = n[ 0 ]*1000 + n[ 1 ]*unit( n[ 0 ] ), y = n[ 2 ]*1000 + n[ 3 ]*unit( n[ 2 ] );
        bool out = false;
        if( x == 9999009 && y == 9999009 )
            break;
        ++point;
        for( int i = 0; i < item; ++i )
            if( x > x1[ i ] && x < x2[ i ] && y < y1[ i ] && y > y2[ i ] )
                printf( "Point %d is contained in figure %d\n", point, i+1 ), out = true;
        if( !out )
            printf( "Point %d is not contained in any figure\n", point );
    }

	return 0;
}