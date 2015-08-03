#include<cstdio>
#include<vector>
using namespace std;
long long fact[ 21 ] = { 1 };

long long calc( vector<int> v )
{
	if( v.empty() )
		return 1;
	vector<int> lt, gt;
	long long base = fact[ v.size() - 1 ];

	for( int i = 1; i < v.size(); ++i )
		( v[ i ] > v[ 0 ]? gt : lt ).push_back( v[ i ] );

	return base / fact[ lt.size() ] / fact[ gt.size() ] * calc( lt ) * calc( gt );
}

int main()
{
	int t, size, n[ 20 ];

	for( int i = 1; i <= 20; ++i )
		fact[ i ] = i * fact[ i-1 ];
	for( scanf( "%d", &t ); scanf( "%d", &size ) == 1; )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d", n + i );
		printf( "%lld\n", calc( vector<int>( n, n + size ) ) % 9999991 );
	}
}
