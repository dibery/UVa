#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#define N 300
using namespace std;

struct cmp
{
	bool operator() ( const string& lhs, const string& rhs ) const
	{ return lhs.size() != rhs.size()? lhs.size() < rhs.size() : lhs < rhs; }
};

typedef map<string,string,cmp> T;
typedef T::iterator Ti;
inline Ti next( Ti i ) { return ++i; }

int main()
{
	for( char s[ N ] = { 0 }, n[ N ] = { 0 }, p[ N ] = { 0 }; scanf( "%s", s ) == 1; )
	{
		if( !strcmp( s, "()" ) )
			puts( "not complete" );
		else
		{
			T tree;
			bool ok = true;

			do
			{
				sscanf( s, "(%[0-9],%[^)])", n, p );
				string a = n, b = p;
				if( tree.count( b ) )
					ok = false;
				else
					tree[ b ] = a;
				memset( s, 0, sizeof( s ) );
				memset( n, 0, sizeof( n ) );
				memset( p, 0, sizeof( p ) );
			}
			while( scanf( "%s", s ) && strcmp( s, "()" ) );

			for( Ti i = tree.begin(); i != tree.end() && ok; ++i )
				if( i->first != "" && !tree.count( i->first.substr( 0, i->first.size() - 1 ) ) )
					ok = false;
			if( ok )
				for( map<string,string>::iterator i = tree.begin(); i != tree.end(); ++i )
					printf( "%s%c", i->second.c_str(), next( i ) == tree.end()? '\n' : ' ' );
			else
				puts( "not complete" );
		}
	}
}
