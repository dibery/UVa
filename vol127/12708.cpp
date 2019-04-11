#include<cstdio>

int main()
{
	long long int in;
	scanf( "%*d" );

	while( scanf( "%lld", &in ) == 1 )
		printf( "%lld\n", in >> 1 );

	return 0;
}
