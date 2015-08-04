#include<cstdio>
#include<algorithm>

int main()
{
	int t, size, len[ 20 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &size );
		int *sum = new int[ 1 << size ], total = 0;
		for( int i = 0; i < size; ++i )
			scanf( "%d", len+i ), total += sum[ 1 << i ] = len[ i ];
		for( int i = 1; i < ( 1 << size ); ++i )
			if( i & i-1 )
				sum[ i ] = sum[ i & -i ] + sum[ i & ~( i & -i ) ];
		if( total % 4 )
			puts( "no" );
		else
		{
			int one[ 20000 ] = { 0 }, s = 0, side = total / 4;
			bool *two = new bool[ 1 << size ], ok = false;
			std::fill( two, two + ( 1 << size ), false );
			for( int i = 1; i < ( 1 << size ); ++i )
				if( sum[ i ] == side )
					one[ s++ ] = i;
			for( int i = 0; i < s; ++i )
				for( int j = i+1; j < s; ++j )
					if( ( one[ i ] & one[ j ] ) == 0 )
						two[ one[ i ] | one[ j ] ] = true;
			for( int i = 1; i < ( 1 << size ) && !ok; ++i )
				if( two[ i ] && two[ ( 1 << size ) - 1 ^ i ] )
					ok = true;
			puts( ok? "yes" : "no" );
			delete[] two;
		}
		delete[] sum;
	}
}
