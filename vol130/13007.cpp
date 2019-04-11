#include<cstdio>
#include<algorithm>
using namespace std;
const int ten[] = { 1, 10, 100, 1000, 10000 };

int main()
{
	for( int P, R; scanf( "%d %d", &P, &R ) == 2; )
	{
		int bonus = 0, bid[ 20 ] = { 0 }, budget;

		for( int i = 0, sum = 0, index; i < R; ++i, sum = 0 )
		{
			scanf( "%d %d", &budget, bid );
			for( int j = 1; j < P; ++j )
				scanf( "%d", bid + j ), sum += bid[ j ];

			if( sum + *bid < budget )
			{
				budget -= sum;
				for( index = 4; index >= 0; --index )
					if( budget >= ten[ index ] )
						break;
				bonus += ten[ index ] - *bid;
			}
			else if( sum + *bid > budget && sum < budget )
			{
				budget -= sum;
				for( index = 4; index >= 0; --index )
					if( budget >= ten[ index ] )
						break;
				bonus += ten[ index ];
			}
		}
		printf( "%d\n", bonus );
	}
}
