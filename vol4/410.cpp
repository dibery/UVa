#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	for( int room, item, n[ 10 ], t = 0; scanf( "%d %d", &room, &item ) == 2; )
	{
		vector<int> machine[ room ];
		double ave = 0, diff = 0;

		for( int i = 0; i < item; ++i )
			scanf( "%d", n + i ), ave += double( n[ i ] ) / room;
		sort( n, n + item, greater<int>() );
		for( int i = 0; i < item; ++i )
			machine[ i < room? i : room - i % room - 1 ].push_back( n[ i ] );

		printf( "Set #%d\n", ++t );
		for( int i = 0; i < room; ++i )
		{
			int sum = 0;
			printf( " %d:", i );
			for( int j: machine[ i ] )
				printf( " %d", j ), sum += j;
			puts( "" );
			diff += abs( sum - ave );
		}
		printf( "IMBALANCE = %.5f\n\n", diff );
	}
}
