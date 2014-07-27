#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
const int NONE = -1;
using namespace std;

bool lnk( const string& a, const string& b )
{
	if( a.size() != b.size() )
		return false;
	int d = 0;
	for( size_t i = 0; i < a.size(); ++i )
		d += a[ i ] != b[ i ];
	return d == 1;
}

int main()
{
	int t, from, to;
	char str[ 50 ];
	string in, b, e;

	for( scanf( "%d\n", &t ); t--; )
	{
		map<string,int> dic;
		int index = 0, dist[ 200 ];
		bool adj[ 200 ][ 200 ] = { { false } };

		while( getline( cin, in ) && in != "*" )
			dic[ in ] = index++;
		for( map<string,int>::iterator i = dic.begin(); i != dic.end(); ++i )
			for( map<string,int>::iterator j = next( i ); j != dic.end(); ++j )
				if( lnk( i->first, j->first ) )
					adj[ i->second ][ j->second ] = adj[ j->second ][ i->second ] = true;
		
		while( gets( str ) && *str )
		{
			queue<int> q;
			*strchr( str, ' ' ) = 0;
			fill( dist, dist+index, NONE );
			b = str;
			e = str + strlen( str ) + 1;
			dist[ from = dic[ b ] ] = 0;
			to = dic[ e ];

			for( q.push( from ); !q.empty() && dist[ to ] == NONE; q.pop() )
				for( int i = 0; i < index; ++i )
					if( adj[ q.front() ][ i ] && dist[ i ] == NONE )
						dist[ i ] = dist[ q.front() ] + 1, q.push( i );
			cout << b << ' ' << e << ' ' << dist[ to ] << endl;
		}
		if( t )
			puts( "" );
	}
}
