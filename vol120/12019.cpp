#include<cstdio>

int main()
{
	int t, m, d, offset[] = { 0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3 };
	char day[][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &m, &d );
		puts( day[ ( offset[ m ] + d ) % 7 ] );
	}
}
