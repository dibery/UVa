#include<iostream>
#define white -1
#define black 1
#define none 0
using namespace std;
bool Color( int index, bool vertex[ 200 ][ 200 ], int *record, int size, int color )
{
    if( record[ index ] == none )
        record[ index ] = color;
    else if( record[ index ] == color )
        return true;
    else
        return false;
    for( int i = 0; i < size; ++i )
        if( vertex[ index ][ i ] )
            if( !Color( i, vertex, record, size, -color ) )
                return false;
    return true;
}

int main()
{
    int n, v;

    while( cin >> n && n )
    {
        bool vertex[ 200 ][ 200 ];
        int node[ 200 ];
        cin >> v;
        int begin, end;
        for( int i = 0; i < 200; ++i )
            for( int j = 0; j < 200; ++j )
                node[ i ] = vertex[ i ][ j ] = none;
        for( int i = 0; i < v; ++i )
        {
            cin >> begin >> end;
            vertex[ begin ][ end ] = vertex[ end ][ begin ] = true;
        }
        cout << ( Color( 0, vertex, node, n, black )? "BICOLORABLE." : "NOT BICOLORABLE." ) << endl;
    }

	return 0;
}