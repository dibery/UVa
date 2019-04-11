#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int test, size, train[ 2000 ], lis[ 2000 ], lds[ 2000 ];
    cin >> test;

    while( test-- )
    {
        int ans = 0;
        cin >> size;
        for( int i = 0; i < size; ++i )
            lis[ i ] = lds[ i ] = 1;
        for( int i = 0; i < size; ++i )
            cin >> train[ i ];
        for( int i = size-1; i >= 0; --i )
            for( int j = i+1; j < size; ++j )
                if( train[ j ] > train[ i ] )
                    lis[ i ] = max( lis[ i ], lis[ j ]+1 );
        for( int i = size-1; i >= 0; --i )
            for( int j = i+1; j < size; ++j )
                if( train[ j ] < train[ i ] )
                    lds[ i ] = max( lds[ i ], lds[ j ]+1 );
        for( int i = 0; i < size; ++i )
            ans = max( ans, lis[ i ]+lds[ i ]-1 );
        cout << ans << endl;
    }
    return 0;
}