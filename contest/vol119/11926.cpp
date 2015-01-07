#include<cstdio>

int main()
{
	int one, mult;

	while( scanf( "%d %d", &one, &mult ) && one+mult )
	{
		bool stamp[ 1000001 ] = { false }, lap = false;

		for( int i = 0; i < one; ++i )
		{
			int begin, end;
			scanf( "%d %d", &begin, &end );
			for( int t = begin; t < end && !lap; ++t )
				if( !stamp[ t ] )
					stamp[ t ] = true;
				else
					lap = true;
		}
		for( int i = 0; i < mult; ++i )
		{
			int begin, end, inter;
			for( scanf( "%d %d %d", &begin, &end, &inter ); begin <= 1000000 && !lap; begin += inter, end += inter )
				for( int t = begin; t < end && t <= 1000000 && !lap; ++t )
					if( !stamp[ t ] )
						stamp[ t ] = true;
					else
						lap = true;
		}

		puts( lap? "CONFLICT" : "NO CONFLICT" );
	}
}
