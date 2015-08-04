#include<cstdio>
#include<algorithm>
using namespace std;

bool ok( int c, int y, int m, int d )
{
	int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if( y % 4 == 0 && ( y % 100 || c % 4 == 0 ) )
		++day[ 2 ];
	if( m > 12 || m < 1 || d < 1 )
		return false;
	return d <= day[ m ];
}

int main()
{
	int t, cen, date[ 3 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d %d %d", &cen, date, date+1, date+2 );
		sort( date, date+3 );
		do
			if( ok( cen, date[ 0 ], date[ 1 ], date[ 2 ] ) )
				break;
		while( next_permutation( date, date+3 ) );
		if( !ok( cen, date[ 0 ], date[ 1 ], date[ 2 ] ) )
			puts( "-1" );
		else
			printf( "%02d %02d %02d\n", date[ 0 ], date[ 1 ], date[ 2 ] );
	}
}
