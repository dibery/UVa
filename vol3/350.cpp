#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int seed, incre, times, mod, t = 0;

    while( scanf( "%d %d %d %d", &times, &incre, &mod, &seed ) && mod )
    {
        int seq[ 10000 ] = { seed }, size = 1;
        bool has[ 10000 ] = { false };
        has[ seed ] = true;
        for( seed = ( seed * times + incre ) % mod; !has[ seed ]; seed = ( seed * times + incre ) % mod )
            seq[ size++ ] = seed, has[ seed ] = true;
        printf( "Case %d: %d\n", ++t, seq + size - find( seq, seq+size, seed ) );
    }
	return 0;
}