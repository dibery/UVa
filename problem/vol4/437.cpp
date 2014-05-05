#include<iostream>
#include<algorithm>
using namespace std;
struct type
{
    int x, y, z;
} cube[ 90 ];
bool cmp( type a, type b )
{
    if( a.x > b.x && a.y > b.y )
        return true;
    if( a.x < b.x && a.y < b.y )
        return false;
    if( a.x != b.x )
        return a.x > b.x;
    return a.y > b.y;
}

int main()
{
    int in, a, b, c, t = 0;

    while( cin >> in && in )
    {
        int lis[ in*3 ], M = -1;
        for( int i = in*3-1; i >= 0; --i )
            cube[ i ].x = cube[ i ].y = cube[ i ].z = 0;
        for( int i = in*3; i; i -= 3 )
        {
            cin >> a >> b >> c;
            cube[ i-1 ].z = a;
            cube[ i-1 ].x = max( b, c );
            cube[ i-1 ].y = min( b, c );
            cube[ i-2 ].z = b;
            cube[ i-2 ].x = max( a, c );
            cube[ i-2 ].y = min( a,c );
            cube[ i-3 ].z = c;
            cube[ i-3 ].x = max( a, b );
            cube[ i-3 ].y = min( a, b );
        }
        sort( cube, cube+3*in, cmp );
        for( int i = in*3-1; i >= 0; --i )
            lis[ i ] = cube[ i ].z;
        for( int i = in*3-1; i >= 0; --i )
            for( int j = i+1; j < in*3; ++j )
                if( cube[ i ].x > cube[ j ].x && cube[ i ].y > cube[ j ].y )
                    lis[ i ] = max( lis[ i ], lis[ j ]+cube[ i ].z );
        for( int i = in*3-1; i >= 0; --i )
            M = max( M, lis[ i ] );
        cout << "Case " << ++t << ": maximum height = " << M << endl;
    }

	return 0;
}