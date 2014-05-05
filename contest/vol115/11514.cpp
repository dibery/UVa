#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#define INT_MAX 1000000000
using namespace std;
char str[ 110000 ], *tmp, name[ 1000 ];
bool beat[ 1001 ][ 1001 ];
int dp[ 1001 ][ 1001 ];

int main()
{
	int qPower, qMan, energy, atk[ 1001 ], def[ 1001 ], cost[ 1001 ];

	while( scanf( "%d %d %d", &qPower, &qMan, &energy ) && qPower+qMan+energy )
	{
		map<string,int> id;
		memset( beat, false, sizeof( beat ) );
		memset( dp, 0, sizeof( dp ) );
		for( int i = 1; i <= qMan; ++i )
			dp[ i ][ 0 ] = INT_MAX;

		for( int i = 1; i <= qPower; ++i )
		{
			scanf( "%s %d %d", str, atk+i, cost+i );
			id[ str ] = i;
		}
		for( int i = 1; i <= qMan; ++i )
		{
			scanf( "%s %d %s", name, def+i, str );
			tmp = strtok( str, "," );
			while( tmp )
			{
				beat[ i ][ id[ string( tmp ) ] ] = true;
				tmp = strtok( NULL, "," );
			}
		}

		for( int villain = 1; villain <= qMan; ++villain )
			for( int ability = 1; ability <= qPower; ++ability )
			{
				dp[ villain ][ ability ] = dp[ villain ][ ability-1 ];
				if( beat[ villain ][ ability ] && atk[ ability ] >= def[ villain ] )
					dp[ villain ][ ability ] = min( dp[ villain ][ ability ], dp[ villain-1 ][ ability-1 ] + cost[ ability ] );
			}
		puts( dp[ qMan ][ qPower ] <= energy? "Yes" : "No" );
	}
}
