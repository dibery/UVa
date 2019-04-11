#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t, c, r;

	scanf( "%d", &t );
	for( int n = 1; n <= t && scanf( "%d %d", &c, &r ); ++n, puts( "" ) )
	{
		c -= r;
		vector<int> ans;
		for( int i = 1; i * i <= c; ++i )
			if( c % i == 0 )
			{
				if( i > r )
					ans.push_back( i );
				if( c / i > r && i * i != c )
					ans.push_back( c / i );
			}
		if( !c )
			ans.push_back( 0 );
		sort( ans.begin(), ans.end() );
		printf( "Case #%d:", n );
		for( int i: ans )
			printf( " %d", i );
	}
}
