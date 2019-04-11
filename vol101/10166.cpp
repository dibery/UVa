#include<bits/stdc++.h>
using namespace std;
const int N = 144099;

struct Time
{
	int hour, min;
	Time( int h = 25, int m = 0 ) { hour = h; min = m; }
	int toint() const { return hour * 100 + min; }
	Time& operator= ( const int& t ) { hour = t / 60; min = t % 60; return *this; }
	bool operator< ( const Time& c ) const { return toint() < c.toint(); }
	bool operator<= ( const Time& c ) const { return toint() <= c.toint(); }
	bool operator== ( const Time& c ) { return toint() == c.toint(); }
	bool operator!= ( const Time& c ) { return toint() != c.toint(); }
} NPOS;

Time dfs( int stop, int now, int goal, list<int> lnk[], Time memory[], set<int> out[] )
{
	int enc = now*100 + stop;
	if( stop == goal )
		return memory[ enc ] = now;
	if( memory[ enc ] != NPOS )
		return memory[ enc ];
	for( set<int>::iterator t = out[ stop ].find( now ); t != out[ stop ].end(); ++t )
		for( list<int>::iterator i = lnk[ *t * 100 + stop ].begin(); i != lnk[ *t * 100 + stop ].end(); ++i )
			memory[ enc ] = min( memory[ enc ], dfs( *i % 100, *i / 100, goal, lnk, memory, out ) );
	return memory[ enc ];
}

int main()
{
	int city, train, stop, timelast, timenext, start, begin, end;
	string last, next, from, to;

	while( scanf( "%d", &city ) && city )
	{
		string name[ 100 ];
		map<string,int> id;
		list<int> lnk[ N ];
		set<int> out[ 100 ];
		Time memory[ N ], arrive, dep;

		for( int i = 0; i < city; ++i )
			cin >> name[ i ], id[ name[ i ] ] = i;

		for( scanf( "%d", &train ); train--; )
		{
			scanf( "%d", &stop );
			cin >> timelast >> last;
			timelast = timelast / 100 * 60 + timelast % 100;
			out[ id[ last ] ].insert( timelast );
			for( int i = 1; i < stop; ++i )
			{
				cin >> timenext >> next;
				timenext = timenext / 100 * 60 + timenext % 100;
				lnk[ timelast * 100 + id[ last ] ].push_back( timenext * 100 + id[ next ] );
				timelast = timenext;
				last = next;
				out[ id[ last ] ].insert( timelast );
			}
		}

		scanf( "%d", &start );
		cin >> from >> to;
		begin = id[ from ];
		end = id[ to ];

		
		for( int i = start / 100 * 60 + start % 100; i < 1440; ++i )
			if( !lnk[ i*100 + begin ].empty() )
				dfs( begin, i, end, lnk, memory, out );

		for( int i = start / 100 * 60 + start % 100; i < 1440; ++i )
			if( memory[ i*100 + begin ] <= arrive )
				arrive = memory[ i*100 + begin ], dep = i;

		if( arrive != NPOS )
			printf( "%04d %04d\n", dep.toint(), arrive.toint() );
		else
			puts( "No connection" );
	}
}
