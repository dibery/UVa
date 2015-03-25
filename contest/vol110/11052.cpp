#include<bits/stdc++.h>
using namespace std;

struct call
{
	int year, month, day, hour, minute;
	bool want;
	call( int M = 0, int D = 0, int h = 0, int m = 0, bool w = true ) { month = M; day = D; hour = h; minute = m; want = w; }
	bool operator< ( const call& c )
	{
		if( month != c.month )
			return month < c.month;
		if( day != c.day )
			return day < c.day;
		if( hour != c.hour )
			return hour < c.hour;
		return minute < c.minute;
	}
	bool operator<= ( const call& c ) { return *this < c || *this == c; }
	bool operator== ( const call& c ) { return month == c.month && day == c.day && hour == c.hour && minute == c.minute; }
};

int main()
{
	int size, month, day, hour, minute, now;
	char status;

	while( scanf( "%d", &size ) && size )
	{
		call log[ 1000 ];
		int yes[ 1000 ] = { 0 }, no[ 1000 ] = { 0 }, ans = 0, stop = 1000, S = 0;

		for( int i = 0; i < size; ++i )
		{
			scanf( "%d:%d:%d:%d %*s %c\n", &month, &day, &hour, &minute, &status );
			log[ S++ ] = call( month, day, hour, minute, status == '+' );
			if( !i )
				log[ i ].year = 0;
			else
				now = log[ i ].year = log[ i-1 ] < log[ i ]? log[ i-1 ].year : log[ i-1 ].year+1;
		}

		for( int i = 0; i < size; ++i )
			if( log[ i ].want )
				++yes[ log[ i ].year ], stop = stop < i? stop : i;
			else
				++no[ log[ i ].year ];

		call last = call( 0, 0, 0, 0, true );
		for( int i = size-1; i >= stop; --i )
		{
			int range;
			for( range = i; range >= 0; --range )
				if( log[ range ].year != log[ range-1 ].year )
					break;
			if( !yes[ log[ i ].year ] )
			{
				int j;
				for( j = range; j <= i; ++j )
					if( last <= log[ j ] )
						break;
				if( j <= i )
					last = log[ j ], ++ans;
				else
				{
					ans += 2;
					int first;
					for( first = range; first <= i; ++first )
						if( log[ i+1 ] <= log[ first ] )
							break;
					last = log[ first ];
				}
			}
			else
			{
				int final, first = 1000;
				for( int j = range; j <= i; ++j )
					if( log[ j ].want )
					{
						++ans;
						final = j;
						first = min( first, j );
					}
				if( log[ final ] < last )
					if( log[ final ] < log[ i+1 ] )
						ans += log[ i+1 ].want? 1 : last < log[ i ]? 1 : 2;
					else
						++ans;
				last = log[ first ];
			}
			//printf( "At year %d, ans = %d\n", last.year, ans );
			i = range;
		}

		printf( "%d\n", ans );
	}
}
