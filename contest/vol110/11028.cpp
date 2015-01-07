#include<cstdio>

int main()
{
	int a[] = { 0, 1, 1, 1, 3, 8, 21, 43, 69, 102, 145, 197, 261, 336, 425, 527, 645, 778, 929, 1097, 1285 };
	for( int n, t = 0; scanf( "%d", &n ) && n; printf( "Case #%d: %d\n", ++t, a[ n ] ) );
}
