#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int times, first = 0; cin >> times; )
	{
		map<string,int> stat;

		if( first )
			puts( "" );
		else
			first = 1;

		for( string line, w; getline( cin, line ) && line != "EndOfText"; )
		{
			for( auto& c: line )
				c = isalpha( c )? tolower( c ) : ' ';
			for( stringstream ss( line ); ss >> w; )
				++stat[ w ];
		}

		bool out = false;
		for( auto& w: stat )
			if( w.second == times )
				puts( w.first.c_str() ), out = true;
		if( !out )
			puts( "There is no such word." );
	}
}
