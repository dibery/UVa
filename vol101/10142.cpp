#include<bits/stdc++.h>
using namespace std;

void vote( int get[ 20 ], deque<int> order[], int elect )
{
	fill( get, get + 20, 0 );
	for( int i = 0; i < elect; ++i )
		++get[ order[ i ].front() ];
}

bool ok( int get[ 20 ], bool lose[ 20 ], int man, int elect )
{
	for( int i = 0; i < man; ++i )
		if( get[ i ] > elect / 2 )
			return true;
	int min = 0;
	for( int i = 0; min == 0; ++i )
		min = get[ i ];
	for( int i = 1; i < man; ++i )
		if( !lose[ i ] && get[ i ] != min )
			return false;
	return true;
}

int main()
{
	int t, man, id, elect;

	for( cin >> t; t--; printf( t? "\n" : "" ) )
	{
		string name[ 20 ], line;
		deque<int> order[ 1000 ];

		scanf( "%d\n", &man );
		for( int i = 0; i < man; ++i )
			getline( cin, name[ i ] );

		for( elect = 0; getline( cin, line ) && line.size(); ++elect )
			for( stringstream ss( line ); ss >> id; )
				order[ elect ].push_back( id - 1 );

		int get[ 20 ];
		bool lose[ 20 ] = { false };
		while( true )
		{
			vote( get, order, elect );
			if( ok( get, lose, man, elect ) )
				break;
			else
			{
				int m = INT_MAX;
				for( int i = 0; i < man; ++i )
					if( !lose[ i ] )
						m = min( m, get[ i ] );
				for( int i = 0; i < man; ++i )
					if( get[ i ] == m )
						lose[ i ] = true;
				for( int i = 0; i < elect; ++i )
					while( lose[ order[ i ].front() ] )
						order[ i ].pop_front();
			}
		}

		int M = *max_element( get, get + man );
		for( int i = 0; i < man; ++i )
			if( get[ i ] == M )
				cout << name[ i ] << endl;
	}
}
