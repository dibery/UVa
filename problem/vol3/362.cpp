#include<cstdio>
#include<cmath>

int main()
{
	int size, qnt, t = 0;

	while( scanf( "%d", &size ) && size )
	{
		int ok = 0, time = 0;
		printf( "Output for data set %d, %d bytes:\n", ++t, size );
		while( ok < size )
		{
			int This = 0;
			for( int i = 0; i < 5 && ok < size; ++i, ++time )
			{
				scanf( "%d", &qnt );
				ok += qnt;
				This += qnt;
			}
			if( time % 5 == 0 )
				if( !This )
					puts( "   Time remaining: stalled" );
				else
					printf( "   Time remaining: %.0f seconds\n", ceil( 5.0 * ( size-ok ) / This ) );
		}
		printf( "Total time: %d seconds\n\n", time );
	}
}
