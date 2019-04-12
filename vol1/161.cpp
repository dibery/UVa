#include<cstdio>
#include<algorithm>

int main()
{
	int time[ 100 ], in, size = 0, M = 100, ans = 0;

	while( scanf( "%d", &in ) == 1 )
		if( in )
			time[ size++ ] = in, M = std::min( M, in );
		else if( size )
		{
			for( ans = M; ans <= 18000; ++ans )
			{
				bool ok = true;
				for( int i = 0; i < size && ok; ++i )
					ok &= ans % ( time[ i ] * 2 ) < time[ i ] - 5;
				if( ok )
					break;
			}
			if( ans <= 18000 )
				printf( "%02d:%02d:%02d\n", ans / 3600, ans / 60 % 60, ans % 60 );
			else
				puts( "Signals fail to synchronise in 5 hours" );
			size = 0;
			M = 100;
		}
}
