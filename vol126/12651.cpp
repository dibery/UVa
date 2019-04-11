#include<cstdio>
#include<set>
using namespace std;

int main()
{
	for( int pnt; scanf( "%d", &pnt ) == 1; )
	{
		int len = 0, tri = 0;
		set<int> pos;

		for( int seg, i = 0; i < pnt && scanf( "%d", &seg ); ++i )
			pos.insert( len ), len += seg;

		if( len % 3 == 0 )
			for( int i: pos )
				tri += pos.count( ( i + len / 3 ) % len ) & pos.count( ( i + 2 * len / 3 ) % len );
		printf( "%d\n", tri / 3 );
	}
}
