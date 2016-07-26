#include<cstdio>
#include<vector>
using namespace std;

int stick, step, t;
vector<int> peg[ 3 ];

void print( int n )
{
	printf( "%c=>", 'A' + n );
	if( !peg[ n ].empty() )
		for( auto i = peg[ n ].begin(); i != peg[ n ].end(); ++i )
			printf( "%s%d", i == peg[ n ].begin()? "   " : " ", *i );
	puts( "" );
}

void tower( int n, int a, int b, int c )
{
	if( n == 0 )
		return;
	tower( n - 1, a, c, b );
	if( !step )
		return;
	peg[ c ].push_back( peg[ a ].back() );
	peg[ a ].pop_back();
	for( int i = 0; i < 3; ++i )
		print( i );
	puts( "" );
	if( !--step )
		return;
	tower( n - 1, b, a, c );
}

int main()
{
	while( scanf( "%d %d", &stick, &step ) && stick )
	{
		printf( "Problem #%d\n\n", ++t );
		for( int i = stick; i; --i )
			peg->push_back( i );
		for( int i = 0; i < 3; ++i )
			print( i );
		puts( "" );
		tower( stick, 0, 1, 2 );
		for( auto& p: peg )
			p.clear();
	}
}
