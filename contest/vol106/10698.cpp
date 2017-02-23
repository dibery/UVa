#include<bits/stdc++.h>
using namespace std;

struct team
{
	string name;
	int played, point, score, suffer;

	team()
	{
		cin >> name;
		played = point = score = suffer = 0;
	}
	bool operator< ( const team& t )
	{
		if( point != t.point )
			return point > t.point;
		if( score - suffer != t.score - t.suffer )
			return score - suffer > t.score - t.suffer;
		if( score != t.score )
			return score > t.score;
		return lexicographical_compare( name.begin(), name.end(), t.name.begin(), t.name.end(), [] ( char a, char b ) { return tolower( a ) < tolower( b ); } );
	}
	bool operator== ( const team& t ) { return point == t.point && score - suffer == t.score - t.suffer && score == t.score; }
	bool operator!= ( const team& t ) { return !( *this == t ); }
};

int main()
{
	for( int T, G, first = 1, sa, sb; cin >> T >> G && T; first = 0 )
	{
		team *stat = new team[ T ];
		if( !first )
			puts( "" );

		for( string ta, tb, dash; G-- && cin >> ta >> sa >> dash >> sb >> tb; )
		{
			int ida = find_if( stat, stat + T, [ ta ] ( const team& t ) { return t.name == ta; } ) - stat,
					idb = find_if( stat, stat + T, [ tb ] ( const team& t ) { return t.name == tb; } ) - stat;

			++stat[ ida ].played;
			++stat[ idb ].played;
			stat[ ida ].score += sa;
			stat[ idb ].score += sb;
			stat[ ida ].suffer += sb;
			stat[ idb ].suffer += sa;
			if( sa == sb )
				++stat[ ida ].point, ++stat[ idb ].point;
			else if( sa > sb )
				stat[ ida ].point += 3;
			else
				stat[ idb ].point += 3;
		}
		sort( stat, stat + T );
		for( int i = 0; i < T; ++i )
			if( !i || stat[ i ] != stat[ i - 1 ] )
				if( stat[ i ].played )
					printf( "%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", i + 1, stat[ i ].name.c_str(), stat[ i ].point, stat[ i ].played, stat[ i ].score, stat[ i ].suffer, stat[ i ].score - stat[ i ].suffer, stat[ i ].point * 100. / 3 / stat[ i ].played );
				else
					printf( "%2d.%16s%4d%4d%4d%4d%4d%7s\n", i + 1, stat[ i ].name.c_str(), stat[ i ].point, stat[ i ].played, stat[ i ].score, stat[ i ].suffer, stat[ i ].score - stat[ i ].suffer, "N/A" );
			else
				if( stat[ i ].played )
					printf( "%19s%4d%4d%4d%4d%4d%7.2f\n", stat[ i ].name.c_str(), stat[ i ].point, stat[ i ].played, stat[ i ].score, stat[ i ].suffer, stat[ i ].score - stat[ i ].suffer, stat[ i ].point * 100. / 3 / stat[ i ].played );
				else
					printf( "%19s%4d%4d%4d%4d%4d%7s\n", stat[ i ].name.c_str(), stat[ i ].point, stat[ i ].played, stat[ i ].score, stat[ i ].suffer, stat[ i ].score - stat[ i ].suffer, "N/A" );
	}
}
