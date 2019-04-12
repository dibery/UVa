#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char A[ 1001 ], B[ 1001 ], *a = A, *b = B;

	while( gets( a ) && gets( b ) )
	{
		sort( a, a + strlen( a ) );
		sort( b, b + strlen( b ) );
		while( *a && *b )
			if( *a == *b )
			{
				putchar( *a );
				++a;
				++b;
			}
			else if( *a < *b )
				++a;
			else
				++b;
		putchar( '\n' );
		a = A;
		b = B;
	}
	return 0;
}
