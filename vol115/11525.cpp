#include<cstdio>
#include<vector>
using namespace std;
int tem[ 100000 ];

int main()
{
	int t, size, del;
	for( int i = 0; i < 100000; ++i )
		tem[ i ] = i+1;

	for( scanf( "%d", &t ); t; --t )
	{
		scanf( "%d", &size );
		vector<int> proc( tem, tem+size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d", &del );
			printf( "%d%c", proc[ del ], proc.size() == 1? '\n' : ' ' );
			proc.erase( proc.begin() + del );
		}
	}
}
