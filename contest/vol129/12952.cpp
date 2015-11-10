#include<cstdio>
#include<algorithm>

int main()
{
	for( int a, b; scanf( "%d %d", &a, &b ) == 2; printf( "%d\n", std::max( a, b ) ) );
}
