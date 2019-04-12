#include<cstdio>
#include<cctype>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;

void path( int prev[], int index, int end )
{
	if( prev[ index ] != index )
		path( prev, prev[ index ], end );
	printf( "%d%c", index, index == end? '\n' : ' ' );
}

int main()
{
    for( int vertex, query, id, begin, end; scanf( "%d", &vertex ) == 1; )
    {
        int adj[ 301 ][ 301 ] = { { 0 } }, size[ 301 ] = { 0 };
        for( int i = 0; i < vertex; ++i )
        {
            scanf( "%d-", &id );
            char str[ 1000 ];
            gets( str );
            for( int i = 0; str[ i ]; ++i )
				if( !isdigit( str[ i ] ) )
					str[ i ] = ' ';
            stringstream ss( str );
            for( int n; ss >> n; adj[ id ][ size[ id ]++ ] = n );
        }
        puts( "-----" );
        for( scanf( "%d", &query ); query--; )
        {
            queue<int> bfs;
            int prev[ 301 ] = { 0 };

            scanf( "%d %d", &begin, &end );
            prev[ begin ] = begin;
            for( bfs.push( begin ); !bfs.empty(); bfs.pop() )
                for( int i = 0; i < size[ bfs.front() ]; ++i )
                    if( !prev[ adj[ bfs.front() ][ i ] ] )
                    {
                        bfs.push( adj[ bfs.front() ][ i ] );
                        prev[ adj[ bfs.front() ][ i ] ] = bfs.front();
                    }
            if( prev[ end ] )
                path( prev, end, end );
            else
                puts( "connection impossible" );
        }
    }
}
