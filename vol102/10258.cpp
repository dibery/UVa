#include<cstdio>
#include<algorithm>
class score
{
	public:
		score( int n = -1 )
		{
			for( int i = 0; i < 10; ++i )
				wa[ i ] = ac[ i ] = 0;
			tried = false;
			all = all_t = 0;
			id = n;
		}
		void correct( int prob, int t )
		{
			if( !ac[ prob ] )
			{
				++ac[ prob ];
				++all;
				tried = true;
				time[ prob ] = t;
				all_t += t + wa[ prob ] * 20;
			}
		}
		void wrong( int prob )
		{
			tried = true;
			if( !ac[ prob ] )
				++wa[ prob ];
		}
		char* print() { printf( "%d %d %d\n", id, all, all_t ); }
		int wa[ 10 ], ac[ 10 ], time[ 10 ], all, all_t, id;
		bool tried;
		bool operator() ( score* a, score* b )
		{
			if( a->all != b->all )
				return a->all > b->all;
			if( a->all_t != b->all_t )
				return a->all_t < b->all_t;
			return a->id < b->id;
		}
} tmp;

int main()
{
	int t, con, pro, time;
	char in[ 20 ], stat;
	for( scanf(	"%d\n", &t ); t--; printf( t? "\n" : "" ) )
	{
		score *man[ 101 ];
		for( int i = 0; i <= 100; ++i )
			man[ i ] = new score( i );
		while( gets( in ) && *in )
		{
			sscanf( in, "%d %d %d %c", &con, &pro, &time, &stat );
			if( stat == 'C' )
				man[ con ]->correct( pro, time );
			else if( stat == 'I' )
				man[ con ]->wrong( pro );
			else
				man[ con ]->tried = true;
		}
		std::sort( man, man+101, tmp );
		for( int i = 0; i <= 100; ++i )
			if( man[ i ]->tried )
				man[ i ]->print();
		for( int i = 0; i <= 100; ++i )
			delete man[ i ];
	}

	return 0;
}
