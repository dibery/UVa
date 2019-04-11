#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int book, p[ 10000 ], *now, money;

    while( scanf( "%d", &book ) != EOF )
    {
        for( int i = 0; i < book; ++i )
            scanf( "%d", p+i );
        scanf( "%d", &money );
        sort( p, p+book );
        for( now = upper_bound( p, p+book, money >> 1 ) - 1; now >= p; --now )
        {
            if( now != p && *now == *(now-1) || !binary_search( p, p+book, money-*now ) )
                continue;
            if( ( upper_bound( p, p+book, money-*now )-1 ) != now )
                break;
        }
        printf( "Peter should buy books whose prices are %d and %d.\n\n", *now, *lower_bound( p, p+book, money-*now ) );
    }

	return 0;
}