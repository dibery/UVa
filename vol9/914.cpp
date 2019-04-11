#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int prime[ 78500 ] = { 2 }, size = 1;

bool check( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	int t, begin, end;

	for( int i = 3; i < 1000040; i += 2 )
		if( check( i ) )
			prime[ size++ ] = i;

	for( scanf( "%d", &t ); t; --t )
	{
		bool champ = false;
		int ans = 0, times = 0;
		map<int,int> stat;

		scanf( "%d %d", &begin, &end );
		for( int* i = lower_bound( prime, prime+size, begin ) + 1; *i <= end; ++i )
			++stat[ *i - *(i-1) ];
		for( map<int,int>::iterator it = stat.begin(); it != stat.end(); ++it )
			if( it->second > times )
				ans = it->first, times = it->second, champ = true;
			else if( it->second == times )
				champ = false;
		if( champ )
			printf( "The jumping champion is %d\n", ans );
		else
			puts( "No jumping champion" );
	}
}
