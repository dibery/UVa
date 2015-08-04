#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t, size;
	char str[ 5000 ] = { 0 };

	for( scanf( "%d", &t ); t; --t )
	{
		unsigned int n[ 1000 ] = { 0 }, m = INT_MAX;
		vector<int> v;
		
		scanf( "%d\n", &size );
		for( int i = 0; i < size; ++i )
			gets( str ), m = min( n[ i ] = count( str, str + strlen( str ), ' ' ), m );
		for( int i = 0; i < size; ++i )
			if( n[ i ] == m )
				v.push_back( i+1 );
		for( vector<int>::iterator i = v.begin(); i != v.end(); ++i )
			printf( "%d%c", *i, next( i ) == v.end()? '\n' : ' ' );
	}
}
