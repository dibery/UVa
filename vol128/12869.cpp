#include<cstdio>

int main()
{
	for( long long L, H; scanf( "%lld %lld", &L, &H ) && L; )
		printf( "%lld\n", ( H - ( L -= L % 5 ) ) / 5 + 1 );
}