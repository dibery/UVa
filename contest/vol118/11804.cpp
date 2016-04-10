#include<iostream>
#include<algorithm>
using namespace std;

struct player
{
	string name;
	int atk, def;
	bool operator< ( const player& p ) const { return name < p.name; }
} team[ 10 ];

int main()
{
	int t, list[ 252 ], s = 0;
	char pattern[] = "0000011111";

	do
		list[ s++ ] = strtol( pattern, NULL, 2 );
	while( next_permutation( pattern, pattern + 10 ) );

	cin >> t;
	for( int n = 1; n <= t; ++n )
	{
		int sol, atk = 0, def = 0, out = 0;

		for( int i = 0; i < 10; ++i )
			cin >> team[ i ].name >> team[ i ].atk >> team[ i ].def;
		sort( team, team + 10 );

		for( s = 0; s < 252; ++s )
		{
			int t_atk = 0, t_def = 0;

			for( int i = 0; i < 10; ++i )
				if( list[ s ] & 1 << i )
					t_atk += team[ i ].atk;
				else
					t_def += team[ i ].def;

			if( t_atk > atk || t_atk == atk && t_def > def )
			{
				sol = list[ s ];
				atk = t_atk;
				def = t_def;
			}
		}

		cout << "Case " << n << ":\n(";
		for( int i = 0; i < 10; ++i )
			if( sol & 1 << i )
				cout << team[ i ].name << ( ++out == 5? ")\n(" : ", " );
		for( int i = 0; i < 10; ++i )
			if( ~sol & 1 << i )
				cout << team[ i ].name << ( ++out == 10? ")\n" : ", " );
	}
}
