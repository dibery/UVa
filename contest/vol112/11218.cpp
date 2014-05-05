#include<cstdio>
#include<algorithm>
struct node
{
    int a, b, c, score;
} data[ 80 ];
bool ok( node a, node b, node c )
{
    bool status[ 10 ] = { false };
    status[ a.a ] = status[ a.b ] = status[ a.c ] = status[ b.a ] = status[ b.b ] = status[ b.c ] = status[ c.a ] = status[ c.b ] = status[ c.c ] = true;
    for( int i = 1; i < 10; ++i )
        if( !status[ i ] )
            return false;
    return true;
}

int main()
{
    int size, t = 0;

    while( scanf( "%d", &size ) && size )
    {
        int ans = -1;

        for( int i = 0; i < size; ++i )
            scanf( "%d %d %d %d", &data[ i ].a, &data[ i ].b, &data[ i ].c, &data[ i ].score );
        for( int i = 0; i < size; ++i )
            for( int j = i+1; j < size; ++j )
                for( int k = j+1; k < size; ++k )
                    if( ok( data[ i ], data[ j ], data[ k ] ) )
                        ans = std::max( ans, data[ i ].score+data[ j ].score+data[ k ].score );
        printf( "Case %d: %d\n", ++t, ans );
    }

	return 0;
}