#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( string s; getline( cin, s ); puts( "" ) )
	{
		stringstream ss( s );
		vector<int> coef;
		bool first = true;

		for( int x; ss >> x; )
			coef.push_back( x );
		getline( cin, s );
		ss.clear();
		ss.str( s );
		for( int x, ans = 0; ss >> x; ans = 0 )
		{
			if( first )
				first = false;
			else
				putchar( ' ' );

			for( int i = 0; i < coef.size(); ++i )
				ans += coef[ i ] * pow( x, coef.size() - i - 1 );
			cout << ans;
		}
	}
}
