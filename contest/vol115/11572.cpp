#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int num[ 1000001 ], t, size;

int main()
{
    scanf( "%d", &t );

    while( t-- )
    {
        int ans = 0, start = 0;
        set<int>pack;

        scanf( "%d", &size );
        for( int i = 0; i < size; ++i )
            scanf( "%d", num+i );
        for( int i = 0; i < size; ++i )
			if( pack.find( num[ i ] ) == pack.end() )
				pack.insert( num[ i ] ), ans = max( ans, (int)pack.size() );
			else
			{
				while( pack.find( num[ i ] ) != pack.end() )
					pack.erase( num[ start++ ] );
				pack.insert( num[ i ] );
			}
        printf( "%d\n", ans );
    }

	return 0;
}
