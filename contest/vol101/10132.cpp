#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

int main()
{
	int t;
	char tmp[ 256 ], *file[ 144 ] = { NULL };
	for( scanf( "%d\n", &t ); t--; printf( t? "\n" : "" ) )
	{
		int size = 0, all_len = 0;
		map<string,int>dict;
		map<string,int>::iterator it;
		while( gets( tmp ) && *tmp )
		{
			file[ size++ ] = strdup( tmp );
			all_len += strlen( tmp );
		}
		int dest = all_len * 2 / size;
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				if( i != j && strlen( file[ i ] ) + strlen( file[ j ] ) == dest )
				{
					string n = string( file[ i ] ) + string( file[ j ] );
					dict.insert( pair<string,int>( n, 0 ) );
					++dict[ n ];
				}
		for( it = dict.begin(); it != dict.end(); ++it )
			if( it->second >= size/2 )
				break;
		printf( "%s\n", it->first.c_str() );
	}
	return 0;
}
