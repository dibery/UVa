#include<cstdio>

int joseph( int size, int step )
{
	if( size == 1 )
		return 0;
	int next = joseph( size - 1, step );
	return ( step - next - ( next + size - 1 ) / size + size ) % size;
}

int main()
{
	for( int pos, ans; scanf( "%d", &pos ) && pos; printf( "%d\n", ans ) )
		for( ans = 1; joseph( 100, ans ) != pos - 1; ++ans );
}
