#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, a, b;

	while( scanf( "%d %d %d", &N, &a, &b ) == 3 )
	{
		map<int,int> die;
		int index = 0;
		long long int now;
		for( now = 0; die.find( now ) == die.end(); now = ( now * now % N * a + b ) % N )
			die[ now ] = index++;
		printf( "%u\n", N - die.size() + die[ now ] );
	}
}
