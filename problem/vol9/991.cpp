#include<cstdio>

int main()
{
	int catalan[] = { 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796 }, n;
	bool begin = true;

	while( scanf( "%d", &n ) == 1 )
	{
		printf( "%s%d\n", begin? "" : "\n", catalan[ n ] );
		begin = false;
	}
}
