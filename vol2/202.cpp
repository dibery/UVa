#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int up, down; scanf( "%d %d", &up, &down ) == 2; puts( "" ) )
	{
		int q = up / down, d, last = up % down;
		vector<int> ans( 1, last * 10 / down ), res( 1, last );

		while( find( res.begin(), res.end(), last * 10 % down ) == res.end() )
		{
			res.push_back( last = last * 10 % down );
			ans.push_back( last * 10 / down );
		}

		d = distance( find( res.begin(), res.end(), res.back() * 10 % down ), res.end() );
		printf( "%d/%d = %d.", up, down, q );
		for( int i = 0; i < ans.size(); ++i )
		{
			if( i == 50 )
			{
				printf( "..." );
				break;
			}
			if( i + d == ans.size() )
				putchar( '(' );
			printf( "%d", ans[ i ] );
		}
		puts( ")" );
		printf( "   %d = number of digits in repeating cycle\n", d );
	}
}
