#include<cstdio>
#include<cstdlib>

int main()
{
	int t, size, div;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &size, &div );
		int *num = new int[ size ];
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d", num+i );
			num[ i ] = ( num[ i ] % div + div ) % div;
		}
		bool has[ 100 ] = { false };
		has[ *num ] = has[ div - *num ] = true;
		for( int i = 1; i < size; ++i )
		{
			bool tmp[ 100 ] = { false };
			for( int j = 0; j < div; ++j )
			{
				tmp[ ( j + num[ i ] ) % div ] |= has[ j ];
				tmp[ ( j - num[ i ] + div ) % div ] |= has[ j ];
			}
			for( int j = 0; j < div; ++j )
				has[ j ] = tmp[ j ];
		}
		puts( *has? "Divisible" : "Not divisible" );
		delete[] num;
	}

	return 0;
}
