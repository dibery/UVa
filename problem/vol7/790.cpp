#include<bits/stdc++.h>
using namespace std;

struct sub
{
	int id, time, prob;
	char result;

	sub( const char* s )
	{
		int h, m;
		char p;
		sscanf( s, "%d %c %d:%d %c", &id, &p, &h, &m, &result );
		time = h * 60 + m;
		prob = p - 'A';
	}

	bool operator< ( const sub& rhs ) const
	{
		if( time == rhs.time && result != rhs.result )
			return result == 'N';
		return time < rhs.time;
	}
};

class score
{
	public:
		score()
		{
			for( int i = 0; i < 10; ++i )
				wa[ i ] = ac[ i ] = 0;
			tried = false;
			all = all_t = 0;
			id = serial++;
		}
		void correct( int prob, int t )
		{
			if( !ac[ prob ] )
			{
				++ac[ prob ];
				++all;
				tried = true;
				time[ prob ] = t;
				all_t += t + wa[ prob ] * 20;
			}
		}
		void wrong( int prob )
		{
			tried = true;
			if( !ac[ prob ] )
				++wa[ prob ];
		}
		void print()
		{
			if( all )
				printf( "%5d%5d%11d\n", id, all, all_t );
			else
				printf( "%5d\n", id );
		}
		int wa[ 10 ], ac[ 10 ], time[ 10 ], all, all_t, id;
		static int serial;
		bool tried;
		bool operator< ( const score& s ) const
		{
			if( tried != s.tried )
				return tried > s.tried;
			if( !tried )
				return id < s.id;
			if( all != s.all )
				return all > s.all;
			if( all_t != s.all_t )
				return all_t < s.all_t;
			return id < s.id;
		}
		bool operator!= ( const score& s ) { return all_t != s.all_t || all != s.all; }
};

int score::serial = 0;

int main()
{
	int t;
	for( scanf( "%d\n", &t ); t--; score::serial = 0 )
	{
		vector<sub> record;
		score team[ 26 ];
		int rank = 1, total_team = -1, last = -1, out = 0;

		for( char s[ 1000 ]; gets( s ) && *s; record.emplace_back( s ) );
		sort( record.begin(), record.end() );

		for( auto& s: record )
			if( s.result == 'Y' )
				team[ s.id ].correct( s.prob, s.time ), total_team = max( total_team, s.id );
			else
				team[ s.id ].wrong( s.prob ), total_team = max( total_team, s.id );
		for( int i = 1; i <= total_team; ++i )
			team[ i ].tried = true;
		sort( team, team + 26 );

		puts( "RANK TEAM PRO/SOLVED TIME" );
		for( int i = 0; i < 26; ++i )
			if( team[ i ].tried )
			{
				if( out && team[ i ] != team[ last ] )
					rank = out + 1;
				printf( "%4d", rank );
				team[ i ].print();
				++out;
				last = i;
			}
		printf( t? "\n" : "" );
	}
}
