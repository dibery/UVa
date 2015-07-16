#include<cstdio>

int main()
{
	long long key, door;

	for( scanf( "%*s" ); scanf( "%lld %lld", &key, &door ) == 2; )
		printf( "%lld\n", ( door-1 + door-key ) * key / 2 );
}
