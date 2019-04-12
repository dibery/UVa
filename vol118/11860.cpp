#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;

	cin >> t;
	for( int n = 1, begin, end; n <= t; ++n )
	{
		vector<string> text;
		set<string> all;
		map<string,int> show;
		pair<int,int> ans;

		for( string s; getline( cin, s ) && s != "END"; )
		{
			for( char& c: s )
				c = isalpha( c )? c : ' ';
			stringstream ss( s );

			while( ss >> s )
			{
				text.push_back( s );
				all.insert( s );
			}
		}

		for( end = 0; show.size() < all.size(); ++end )
			++show[ text[ end ] ];
		for( begin = 0; show[ text[ begin ] ] > 1; ++begin )
			--show[ text[ begin ] ];
		ans = make_pair( begin, end );

		while( end < text.size() )
		{
			while( end < text.size() && text[ end ] != text[ begin ] )
				++show[ text[ end++ ] ];
			if( end == text.size() )
				break;
			++show[ text[ end++ ] ];
			while( show[ text[ begin ] ] > 1 )
				--show[ text[ begin++ ] ];
			if( end - begin < ans.second - ans.first )
				ans = make_pair( begin, end );
		}
		printf( "Document %d: %d %d\n", n, ++ans.first, ans.second );
	}
}
