#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	string tmp, file[ 144 ];

	for( scanf( "%d\n", &t ); t--; printf( t? "\n" : "" ) )
	{
		int size = 0, all_len = 0;
		set<string> dict;

		while( getline( cin, tmp ) && tmp.size() )
			all_len += ( file[ size++ ] = tmp ).size();

		size_t dest = all_len * 2 / size;
		
		for( int i = 0; i < size; ++i )
			for( int j = i + 1; j < size; ++j )
				if( file[ i ].size() + file[ j ].size() == dest )
				{
					dict.insert( file[ i ] + file[ j ] );
					dict.insert( file[ j ] + file[ i ] );
				}
		for( size_t i = 1; i * 2 <= dest; ++i )
		{
			set<string> pass, join;
			for( int m = 0; m < size; ++m )
				if( file[ m ].size() == i || file[ m ].size() == dest - i )
					pass.insert( file[ m ] );
			if( pass.empty() )
				continue;
			else if( pass.size() == 1u )
				pass.insert( *pass.begin() + *pass.begin() );
			else
				for( auto& a: pass )
					for( auto& b: pass )
						if( a != b && a.size() + b.size() == dest )
							pass.insert( a + b );
			for( auto& s: pass )
				if( dict.find( s ) != dict.end() )
					join.insert( s );
			dict = join;
		}
		if( !dict.empty() )
			cout << *dict.begin() << endl;
		else
			cout << "oops" << endl;
	}
}
