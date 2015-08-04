#include<cstdio>
#include<cstring>
#include<set>
#include<string>
using namespace std;

int main()
{
	char a[ 301 ], b[ 301 ], tmp[ 301 ];
	bool first = true;

	while( scanf( "%s %s", a, b ) == 2 )
	{
		bool found = false;
		int la = strlen( a ), lb = strlen( b );
		set<string> out;

		if( !first )
			puts( "" );
		first = false;

		for( int span = la; span && !found; --span )
			for( int begin = 0; begin+span <= la; ++begin )
				for( int cmp = 0; cmp+span <= lb; ++cmp )
					if( strncmp( a+begin, b+cmp, span ) == 0 )
					{
						found = true;
						out.insert( string( a+begin, span ) );
					}
		if( !found )
			puts( "No common sequence." );
		else
			for( set<string>::iterator i = out.begin(); i != out.end(); ++i )
				puts( i->c_str() );
	}
}
