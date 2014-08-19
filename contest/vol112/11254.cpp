#include<cstdio>
#include<cmath>

int main()
{
	int n, root;

	while( scanf( "%d", &n ) && n > 0 )
	{
		for( root = sqrt( n << 1 ) + 1e-12; root; --root )
			if( root % 2 == 1 && n % root == 0 || root % 2 == 0 && n % root == root / 2 )
				break;
		if( root % 2 == 1 )
			printf( "%d = %d + ... + %d\n", n, n / root - root / 2, n / root + root / 2 );
		else
			printf( "%d = %d + ... + %d\n", n, n / root + root / 2 - root + 1, n / root + root / 2 );
	}
}
