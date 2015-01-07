#include<cstdio>
#include<cctype>
#include<list>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char s[ 30000 ], *pos;
	bool first = true;
	
	while( gets( pos = s ) )
	{
		if( !first )
			puts( "" );
		first = false;
		int n;
		char op, *after = strchr( s, '=' ) + 1;
		list<string> parse;
		while( *pos == ' ' ) ++pos;
		while( *after == ' ' ) ++after;
		
		while( sscanf( pos, "%d %c", &n, &op ) )
		{
//		printf( "ins: %d %c\n", n, op );
			char tmp[ 30 ];
			sprintf( tmp, "%d", n );
			string a = tmp;
			parse.push_back( a );
			if( op == '=' )
				break;
			tmp[ 0 ] = op;
			tmp[ 1 ] = 0;
			string b = tmp;
			parse.push_back( b );
			if( *pos == '+' || *pos == '-' ) ++pos;
			while( *pos != '+' && *pos != '-' && *pos != '*' && *pos != '/' ) ++pos;
			++pos;
			while( *pos == ' ' ) ++pos;
		}
//		for( list<string>::iterator a = parse.begin(); a != parse.end(); ++a )
//				printf( "%s ", a->c_str() );
//		printf( "= %s\n", after );

		while( find( parse.begin(), parse.end(), "*" ) != parse.end() || find( parse.begin(), parse.end(), "/" ) != parse.end() )
		{
			for( list<string>::iterator a = parse.begin(); a != parse.end(); ++a )
				printf( "%s ", a->c_str() );
			printf( "= %s\n", after );
		
		//	list<string>::iterator a = find( parse.begin(), parse.end(), "*" ); b = find( parse.begin(), parse.end(), "/" )
			list<string>::iterator ok;
			
			for( ok = parse.begin(); *ok != "*" && *ok != "/"; ++ok );
			int A = stoi( *prev( ok ) ), B = stoi( *next( ok ) ), r = *ok == "*"? A*B : A/B;
			//printf( "a=%d b=%d\n", A, B );
			char tmp[ 30 ];
			sprintf( tmp, "%d", r );
			string s = tmp;
			list<string>::iterator e = parse.erase( prev( ok ), next( next( ok ) ) );
			parse.insert( e, s );
		}
		while( find( parse.begin(), parse.end(), "+" ) != parse.end() || find( parse.begin(), parse.end(), "-" ) != parse.end() )
		{
			for( list<string>::iterator a = parse.begin(); a != parse.end(); ++a )
				printf( "%s ", a->c_str() );
			printf( "= %s\n", after );
		
			//list<string>::iterator a = find( parse.begin(), parse.end(), "+" );
			list<string>::iterator ok;
			
			for( ok = parse.begin(); *ok != "+" && *ok != "-"; ++ok );
			int A = stoi( *prev( ok ) ), B = stoi( *next( ok ) ), r = *ok == "+"? A+B : A-B;
			//printf( "a=%d b=%d\n", A, B );
			char tmp[ 30 ];
			sprintf( tmp, "%d", r );
			string s = tmp;
			list<string>::iterator e = parse.erase( prev( ok ), next( next( ok ) ) );
			parse.insert( e, s );
		}
		for( list<string>::iterator a = parse.begin(); a != parse.end(); ++a )
			printf( "%s ", a->c_str() );
		printf( "= %s\n", after );
	}
}
