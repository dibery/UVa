#include<cstdio>
#include<cmath>
long long int sq( long long int a ) { return a*a; }

int main()
{
    long long int out = 0, root;
    for( long long int i = 6; out < 10; ++i )
        if( sq( root = (long long int)sqrt( 8*i*i + 1 ) ) == i*i*8 + 1 && root % 2 )
            printf( "%10lld%10lld\n", i, ( root-1 ) / 2 ), out++;

	return 0;
}