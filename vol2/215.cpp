#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<string>
#include<list>
using namespace std;
class cell
{
public:
	bool ok;
	list<string> ref;
	int val;
	cell() { ok = false; val = 0; }
};
bool noAlpha( char* str )
{
	for( int i = 0; str[ i ]; ++i )
		if( isalpha( str[ i ] ) )
			return false;
	return true;
}
char origin[ 20 ][ 10 ][ 80 ], alpha[] = { "ABCDEFGHIJKLMNOPQRST" };

int main()
{
	int row, col, num;
	char expr[ 80 ], buf[ 15 ];

	while( scanf( "%d %d", &row, &col ) && row+col )
	{
		int ok = 0;
		cell board[ row ][ col ];
		for( int i = 0; i < row; ++i )
			for( int j = 0; j < col; ++j )
			{
                scanf( "%s", expr );
                strcpy( origin[ i ][ j ], expr );
                if( strchr( expr, '+' ) == NULL && strchr( expr+1, '-' ) == NULL && noAlpha( expr ) )
				{
					board[ i ][ j ].val = atoi( expr );
					board[ i ][ j ].ok = true;
					++ok;
				}
				else
					for( char* tmp = expr; *tmp; )
						if( isalpha( *tmp ) || *tmp == '-' && isalpha( tmp[ 1 ] ) && ( tmp == expr || *(tmp-1) == '+' ) )
						{
							board[ i ][ j ].ref.push_back( string( tmp, *tmp == '-'? 3 : 2 ) );
							tmp += *tmp == '-'? 3 : 2;
						}
						else if( isdigit( *tmp ) || *tmp == '-' && isdigit( tmp[ 1 ] ) && ( tmp == expr || *(tmp-1) == '+' ) )
						{
							sscanf( tmp, "%d", &num );
							sprintf( buf, "%d", num );
							tmp += strlen( buf );
							board[ i ][ j ].ref.push_back( string( buf ) );
						}
						else
						{
							board[ i ][ j ].ref.push_back( string( 1, *tmp ) );
							++tmp;
						}
			}
		for( int modify = -1; ok != row * col && modify; )
		{
			modify = 0;
			for( int i = 0; i < row; ++i )
				for( int j = 0; j < col; ++j )
					if( !board[ i ][ j ].ok )
					{
						bool add, digit = false;
						list<string>::iterator it;
						for( it = board[ i ][ j ].ref.begin(); it != board[ i ][ j ].ref.end(); ++it )
							if( (*it)[ 0 ] != '-' )
								if( isalpha( (*it)[ 0 ] ) && board[ (*it)[ 0 ] - 'A' ][ (*it)[ 1 ] - '0' ].ok )
								{
									sprintf( buf, "%d", board[ (*it)[ 0 ] - 'A' ][ (*it)[ 1 ] - '0' ].val );
//									printf( "replaced: [%d][%d] %s to %s\n", i, j, it->c_str(), buf );
									*it = string( buf );
									++modify;
								}
								else;
							else if( isalpha( (*it)[ 1 ] ) && board[ (*it)[ 1 ] - 'A' ][ (*it)[ 2 ] - '0' ].ok )
							{
								sprintf( buf, "%d", -board[ (*it)[ 1 ] - 'A' ][ (*it)[ 2 ] - '0' ].val );
//								printf( "replaced: [%d][%d] %s to %s\n", i, j, it->c_str(), buf );
								*it = string( buf );
								++modify;
							}
//						for( it = board[ i ][ j ].ref.begin(); it != board[ i ][ j ].ref.end(); ++it )
//							printf( "*%s\n", it->c_str() );
						for( it = board[ i ][ j ].ref.begin(); it != board[ i ][ j ].ref.end(); ++it )
							if( isalpha( (*it)[ 0 ] ) )
								break;
						if( it != board[ i ][ j ].ref.end() )
							continue;
						it = board[ i ][ j ].ref.begin();
						board[ i ][ j ].val = atoi( it->c_str() );
						for( ++it; it != board[ i ][ j ].ref.end(); ++it )
							if( digit )
								if( add )
									board[ i ][ j ].val += atoi( it->c_str() ), digit = false;
								else
									board[ i ][ j ].val -= atoi( it->c_str() ), digit = false;
							else
								add = *it == "+", digit = true;
						board[ i ][ j ].ok = true;
						++ok;
					}
		}
		if( ok != row * col )
		{
			for( int i = 0; i < row; ++i )
				for( int j = 0; j < col; ++j )
					if( !board[ i ][ j ].ok )
						printf( "%c%d: %s\n", i+'A', j, origin[ i ][ j ] );
		}
		else
		{
			printf( "  " );
			for( int i = 0; i < col; ++i )
				printf( "%5d%s", i, i == col-1? "\n" : " " );
			for( int i = 0; i < row; ++i )
			{
				putchar( i+'A' );
				for( int j = 0; j < col; ++j )
					printf( " %5d", board[ i ][ j ].val );
				puts( "" );
			}
		}
		puts("");
	}

	return 0;
}