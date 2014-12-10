#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int len, take;
	char n[ 100001 ];

	while( scanf( "%d %d\n", &len, &take ) && len )
	{
		queue<int> pos[ 10 ];
		int taken = 0;
		take = len - take;
		gets( n );
		for( int i = 0; n[ i ]; ++i )
			pos[ n[ i ] - '0' ].push( i );
		while( taken != take )
			for( int i = 9; i >= 0; --i )
				if( !pos[ i ].empty() && len - pos[ i ].front() >= take - taken )
				{
					putchar( i + '0' );
					++taken;
					for( int j = 0; j < 10; ++j )
						while( !pos[ j ].empty() && pos[ j ].front() < pos[ i ].front() )
							pos[ j ].pop();
					pos[ i ].pop();
					break;
				}
		puts( "" );
	}
}
