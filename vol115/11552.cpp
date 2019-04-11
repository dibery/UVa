#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	int t, len;
	string str;

	for( cin >> t; t-- && cin >> len >> str; )
	{
		vector<string> seg;
		int ans[ 1000 ][ 26 ] = { { 0 } };

		for( int i = 0; i < str.size(); i += len )
			seg.push_back( str.substr( i, len ) );
		fill( ans[ 0 ], ans[ 1000 ], INT_MAX );
		for( int i = 0; i < seg.size(); ++i )
		{
			bool show[ 26 ] = { false };
			for( char c: seg[ i ] )
				show[ c - 'a' ] = true;
			int chunk = count( show, show + 26, true );
			if( i == 0 )
			{
				for( int j = 0; j < 26; ++j )
					if( show[ j ] )
						ans[ 0 ][ j ] = chunk;
			}
			else
				for( int j = 0; j < 26; ++j )
					if( ans[ i - 1 ][ j ] != INT_MAX )
						if( show[ j ] )
						{
							for( int k = 0; k < 26; ++k )
								if( show[ k ] )
									ans[ i ][ k ] = min( ans[ i ][ k ], ans[ i - 1 ][ j ] + chunk - ( k != j || chunk == 1 ) );
						}
						else
							for( int k = 0; k < 26; ++k )
								if( show[ k ] )
									ans[ i ][ k ] = min( ans[ i ][ k ], ans[ i - 1 ][ j ] + chunk );
		}
		cout << *min_element( ans[ seg.size() - 1 ], ans[ seg.size() ] ) << endl;
	}
}
