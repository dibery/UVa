#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
using namespace std;

int main()
{
	int t;
	char before[ 101 ], after[ 101 ], *pb, *pa, key[ 101 ], val[ 101 ];

	for( scanf( "%d\n", &t ); t; --t, puts( "" ) )
	{
		map<string,string> b, a;
		set<string> add, sub, mod;
		gets( pb = before );
		gets( pa = after );

		if( strcmp( before, "{}" ) )
			while( pb )
			{
				sscanf( pb, "%*c%[a-z]:%[0-9]", key, val );
				b[ string( key ) ] = string( val );
				pb = strchr( pb+1, ',' );
			}
		if( strcmp( after, "{}" ) )
			while( pa )
			{
				sscanf( pa, "%*c%[a-z]:%[0-9]", key, val );
				a[ string( key ) ] = string( val );
				pa = strchr( pa+1, ',' );
			}

		for( map<string,string>::iterator i = a.begin(); !a.empty() && i != a.end(); ++i )
			if( b.find( i->first ) == b.end() )
				add.insert( i->first );
		for( map<string,string>::iterator i = b.begin(); !b.empty() && i != b.end(); ++i )
			if( a.find( i->first ) == a.end() )
				sub.insert( i->first );
		for( map<string,string>::iterator i = a.begin(); i != a.end(); ++i )
			if( add.find( i->first ) == add.end() && sub.find( i->first ) == sub.end() && b[ i->first ] != a[ i->first ] )
				mod.insert( i->first );

		if( add.empty() && sub.empty() && mod.empty() )
			puts( "No changes" );
		else
		{
			if( !add.empty() )
				for( set<string>::iterator i = add.begin(); i != add.end(); ++i )
					printf( "%c%s%s", i == add.begin()? '+' : ',', i->c_str(), next( i ) == add.end()? "\n" : "" );
			if( !sub.empty() )
				for( set<string>::iterator i = sub.begin(); i != sub.end(); ++i )
					printf( "%c%s%s", i == sub.begin()? '-' : ',', i->c_str(), next( i ) == sub.end()? "\n" : "" );
			if( !mod.empty() )
				for( set<string>::iterator i = mod.begin(); i != mod.end(); ++i )
					printf( "%c%s%s", i == mod.begin()? '*' : ',', i->c_str(), next( i ) == mod.end()? "\n" : "" );
		}
	}
}
