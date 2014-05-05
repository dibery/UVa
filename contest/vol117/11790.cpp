#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int test;
    cin >> test;

    for( int i = 1; i <= test; ++i )
    {
        int building, tmp, *all, total = 0, *lis, *lds, down = -1, up = -1, *h, *l;
        cin >> building;
        h = new int[ building ];
        l = new int[ building ];
        lis = new int[ building ];
        lds = new int[ building ];
        for( int i = 0; i < building; ++i )
            cin >> h[ i ];
        for( int i = 0; i < building; ++i )
            cin >> l[ i ];
        for( int i = 0; i < building; ++i )
            lis[ i ] = lds[ i ] = l[ i ];

        for( int i = building-1; i >= 0; --i )
            for( int j = i+1; j < building; ++j )
                if( h[ j ] > h[ i ] )
                    lis[ i ] = max( lis[ i ], lis[ j ]+l[ i ] );
        for( int i = building-1; i >= 0; --i )
            for( int j = i+1; j < building; ++j )
                if( h[ j ] < h[ i ] )
                    lds[ i ] = max( lds[ i ], lds[ j ]+l[ i ] );
        for( int i = 0; i < building; ++i )
            down = max( down, lds[ i ] );
        for( int i = 0; i < building; ++i )
            up = max( up, lis[ i ] );
        if( down > up )
            cout << "Case " << i << ". Decreasing (" << down << "). Increasing (" << up << ").\n";
        else
            cout << "Case " << i << ". Increasing (" << up << "). Decreasing (" << down << ").\n";
        delete[] h;
        delete[] l;
        delete[] lis;
        delete[] lds;
    }

	return 0;
}