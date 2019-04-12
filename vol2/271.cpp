#include<iostream>
#include<cstring>
using namespace std;
inline int right( char *letter, int i ){ return ( letter[ i ] >= 'n' && letter[ i ] <= 'z' ? 1 : 0 ); }

int main()
{
	char word[ 256 ] = { 0 };
	int len, judge, WA = 0, i;

	while( cin >> word )
	{
		len = strlen( word );
		i = len-1;
		while( len > 1 && WA == 0 && i >= 0 )
			for( i = len-1; i >= 0; i-- )
				if( !right( word, i ) )
					if( word[ i ] == 'N' )
					{
						if( right( word, i+1 ) )
						{
							word[ i ] = 'p';
							word[ --len ] = '\0';
						}
						else
						{
							WA++;
							break;
						}
					}
					else if( word[ i ] == 'C' || word[ i ] == 'D' || word[ i ] == 'E' || word[ i ] == 'I' )
					{
						if( right( word, i+1 ) && right( word, i+2 ) )
							word[ i ] = 'p';
						else
						{
							WA++;
							break;
						}
						word[ --len ] = word[ --len ] = '\0';
					}
		cout << ( len == 1 && right( word, 0 ) && WA == 0 ? "YES\n" : "NO\n" );
		WA = 0;
		memset( word, 0, sizeof( word ) );
	}
}
