#include<iostream>
#include<vector>
#include<stack>
using namespace std;

inline bool match( string& a, string& b ) { return a[ 0 ] == b[ 0 ] || a[ 1 ] == b[ 1 ]; }

int main()
{
	for( string card; cin >> card && card != "#"; puts( "" ) )
	{
		vector<string> deck;
		vector<stack<string>> pile;

		deck.push_back( card );
		for( int i = 1; i < 52 && cin >> card ; ++i )
			deck.push_back( card );

		for( auto& c: deck )
		{
			if( pile.size() >= 3 && match( c, pile[ pile.size() - 3 ].top() ) )
				pile[ pile.size() - 3 ].push( c );
			else if( pile.size() >= 3 && match( c, pile.back().top() ) )
				pile.back().push( c );
			else
				pile.push_back( stack<string>() ), pile.back().push( c );

			for( bool mod = true; mod; )
			{
				mod = false;
				for( auto p = pile.begin(); p != pile.end(); ++p )
					if( p - pile.begin() >= 3 && match( p->top(), ( p - 3 )->top() ) )
					{
						( p - 3 )->push( p->top() );
						p->pop();
						mod = true;
						if( p->empty() )
							pile.erase( p );
						break;
					}
					else if( p > pile.begin() && match( p->top(), ( p - 1 )->top() ) )
					{
						( p - 1 )->push( p->top() );
						p->pop();
						mod = true;
						if( p->empty() )
							pile.erase( p );
						break;
					}
			}
		}

		printf( "%lu pile%s remaining:", pile.size(), pile.size() > 1? "s" : "" );
		for( auto& p: pile )
			cout << ' ' << p.size();
	}
}
