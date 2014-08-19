#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const string ABO[] = { "A", "B", "AB", "O" }, RH[] = { "+", "-" };
inline string real( string& n ) { return n == "?"? "IMPOSSIBLE" : n; }
string real( string& s, vector<string>& a )
{
	if( s != "?" )
		return s;
	bool add = a.size() > 1;
	string ret;
	while( !a.empty() )
	{
		ret += a.back();
		a.pop_back();
		ret += a.empty()? "" : ", ";
	}
	return add? "{"+ret+"}" : ret;
}

int main()
{
	string dad, mom, child;
	bool ans[ 4 ][ 2 ][ 4 ][ 2 ][ 4 ][ 2 ] = { false };
	int t = 0;

	for( int i = 0; i < 4; ++i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 4; ++k )
				for( int l = 0; l < 2; ++l )
				{
					bool blood[ 4 ] = { false }, rh[ 2 ] = { false };
					string all = ABO[ i ] + ABO[ k ];

					if( j == 0 || l == 0 )
						rh[ 0 ] = rh[ 1 ] = true;
					else
						rh[ 1 ] = true;

					if( find( all.begin(), all.end(), 'A' ) != all.end() )
						blood[ 0 ] = true;
					if( find( all.begin(), all.end(), 'B' ) != all.end() )
						blood[ 1 ] = true;
					blood[ 2 ] = blood[ 0 ] & blood[ 1 ];
					if( i == 3 || k == 3 )
						blood[ 2 ] = false;
					if( i != 2 && k != 2 )
						blood[ 3 ] = true;

					for( int m = 0; m < 4; ++m )
						for( int n = 0; n < 2; ++n )
							if( blood[ m ] && rh[ n ] )
								ans[ i ][ j ][ k ][ l ][ m ][ n ] = true;
				}

	while( cin >> dad >> mom >> child && dad != "E" )
	{
		vector<string> all;
		bool s = false;

		if( dad == "?" )
			swap( dad, mom ), s = true;
		if( child == "?" )
		{
			string db = dad.substr( 0, dad.length()-1 ), dr = dad.substr( dad.length()-1, 1 );
			string mb = mom.substr( 0, mom.length()-1 ), mr = mom.substr( mom.length()-1, 1 );
			int dbp = find( ABO, ABO+4, db ) - ABO, drp = find( RH, RH+2, dr ) - RH;
			int mbp = find( ABO, ABO+4, mb ) - ABO, mrp = find( RH, RH+2, mr ) - RH;

			for( int i = 0; i < 4; ++i )
				for( int j = 0; j < 2; ++j )
					if( ans[ dbp ][ drp ][ mbp ][ mrp ][ i ][ j ] )
						all.push_back( ABO[ i ] + RH[ j ] );
		}
		else
		{
			string db = dad.substr( 0, dad.length()-1 ), dr = dad.substr( dad.length()-1, 1 );
			string cb = child.substr( 0, child.length()-1 ), cr = child.substr( child.length()-1, 1 );
			int dbp = find( ABO, ABO+4, db ) - ABO, drp = find( RH, RH+2, dr ) - RH;
			int cbp = find( ABO, ABO+4, cb ) - ABO, crp = find( RH, RH+2, cr ) - RH;

			for( int i = 0; i < 4; ++i )
				for( int j = 0; j < 2; ++j )
					if( ans[ dbp ][ drp ][ i ][ j ][ cbp ][ crp ] )
						all.push_back( ABO[ i ] + RH[ j ] );
		}	
		if( s )
			swap( dad, mom );

		if( all.empty() )
			cout << "Case " << ++t << ": " << real( dad ) << ' ' << real( mom ) << ' ' << real( child ) << endl;
		else
			cout << "Case " << ++t << ": " << real( dad, all ) << ' ' << real( mom, all ) << ' ' << real( child, all ) << endl;
	}
}
