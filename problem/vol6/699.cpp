#include<cstdio>
#include<map>
using namespace std;

void calc( int val, int pos, map<int,int>& stat )
{
	stat[ pos ] += val;
	int n;
	scanf( "%d", &n );
	if( n != -1 )
		calc( n, pos - 1, stat );
	scanf( "%d", &n );
	if( n != -1 )
		calc( n, pos + 1, stat );
}

int main()
{
	for( int t = 0, n; scanf( "%d", &n ) && n != -1; puts( "" ) )
	{
		map<int,int> stat;

		stat[ 0 ] = n;
		scanf( "%d", &n );
		if( n != -1 )
			calc( n, -1, stat );
		scanf( "%d", &n );
		if( n != -1 )
			calc( n, 1, stat );
		printf( "Case %d:\n", ++t );
		for( auto i = stat.begin(); i != stat.end(); ++i )
			printf( "%d%c", i->second, next( i ) == stat.end()? '\n' : ' ' );
	}
}
