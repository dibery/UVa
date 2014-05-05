#include<cstdio>
#include<algorithm>

int main()
{
	unsigned int catalan[] = { 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190 }, n;
	while( scanf( "%u", & n ) == 1 )
		printf( "%d\n", std::lower_bound( catalan, catalan+19, n ) - catalan + 1 );
}
