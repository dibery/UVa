#include<cstdio>

int main()
{
	int fast, slow;

	while( scanf( "%d %d", &slow, &fast ) == 2 )
		printf( "%d\n", ( fast + fast - slow - 1 ) / ( fast - slow ) );
}
