#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( string s; getline( cin, s ) && s != "****END_OF_INPUT****"; )
	{
		map<string,double> stat;
		double ent = 0;
		int all = 0;

		do
		{
			for( char& c: s )
				c = strchr( ",.:;!?\"() \t\n", c )? ' ' : tolower( c );

			stringstream ss( s );

			while( ss >> s )
				++stat[ s ], ++all;
		}
		while( getline( cin, s ) && s != "****END_OF_TEXT****" );

		for( auto& i: stat )
			ent += i.second * log10( all / i.second ) / all;
		printf( "%d %.1f %.0f\n", all, ent, ent / log10( all ) * 100 );
	}
}
