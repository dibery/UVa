#include<bits/stdc++.h>
using namespace std;

struct team
{
	string name;
	int played, point, score, suffer, win, lose, tie;

	team()
	{
		getline( cin, name );
		played = point = score = suffer = win = lose = tie = 0;
	}
	bool operator< ( const team& t )
	{
		if( point != t.point )
			return point > t.point;
		if( win != t.win )
			return win > t.win;
		if( score - suffer != t.score - t.suffer )
			return score - suffer > t.score - t.suffer;
		if( score != t.score )
			return score > t.score;
		if( played != t.played )
			return played < t.played;
		return lexicographical_compare( name.begin(), name.end(), t.name.begin(), t.name.end(), [] ( char a, char b ) { return tolower( a ) < tolower( b ); } );
	}
	bool operator== ( const team& t ) { return point == t.point && score - suffer == t.score - t.suffer && score == t.score; }
	bool operator!= ( const team& t ) { return !( *this == t ); }
};

int main()
{
	int tournament, T, G, sa, sb;
	string title;
	char ta[ 100 ] = { 0 }, tb[ 100 ] = { 0 };

	for( cin >> tournament, cin.get(); tournament--; )
	{
		getline( cin, title );
		cin >> T;
		cin.get();
		team *stat = new team[ T ];

		for( cin >> G, cin.get(); G-- && scanf( "%[^#]#%d@%d#%[^#\n]\n", ta, &sa, &sb, tb ); )
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
				++stat[ ida ].point, ++stat[ idb ].point, ++stat[ ida ].tie, ++stat[ idb ].tie;
			else if( sa > sb )
				stat[ ida ].point += 3, ++stat[ ida ].win, ++stat[ idb ].lose;
			else
				stat[ idb ].point += 3, ++stat[ idb ].win, ++stat[ ida ].lose;
		}
		sort( stat, stat + T );
		cout << title << endl;
		for( int i = 0; i < T; ++i )
		{
			auto& T = stat[ i ];
			printf( "%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
								 i + 1, T.name.c_str(), T.point, T.played, T.win, T.tie, T.lose, T.score - T.suffer, T.score, T.suffer );
		}
		if( tournament )
			puts( "" );
	}
}
