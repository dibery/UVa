#include<cstdio>
#include<cstring>
#include<numeric>

int main()
{
	char diet[ 300 ], tu, *pos;
	double tq, per[ 5 ] = { 9, 4, 4, 4, 7 };
	
	while( gets( pos = diet ) && *diet != '-' )
	{
		double cal[ 5 ] = { 0 }, sum = 0;

		do
		{
			double rate[ 5 ] = { 0 }, cent = 0, total = 0;

			for( int i = 0; i < 5; ++i )
			{
				sscanf( pos, "%lf%c", &tq, &tu );
				if( tu == 'g' )
					cal[ i ] += tq * per[ i ], total += tq * per[ i ];
				else if( tu == '%' )
					rate[ i ] += tq, cent += tq;
				else
					cal[ i ] += tq, total += tq;
				pos = strchr( pos, ' ' ) + 1;
			}

			total /= ( 100 - cent ) / 100;
			for( int i = 0; i < 5; ++i )
				cal[ i ] += rate[ i ] * total / 100;
		}
		while( gets( pos = diet ) && *diet != '-' );
		
		printf( "%.0f%%\n", 100.0 * *cal / std::accumulate( cal, cal+5, 0.0 ) );
	}
}
