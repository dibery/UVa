#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
long long int rotate( long long int, int ), arrtoll( int*, int );

int main()
{
	int t, round = 0, in[ 24 ];
	long long int dest = strtoll( "022203330111044405550", NULL, 6 ), delim = -1, next[ 4 ];
	queue<long long int> Q;
	map<long long int,long long int> backward, forward;

	Q.push( dest ), Q.push( delim );
	backward.insert( pair<long long int,long long int>( dest, 0 ) );
	while( round <= 8 )
	{
		if( Q.front() == delim )
		{
			++round;
			if( round <= 8 )
				Q.push( delim );
		}
		else
			for( int i = 0; i < 4; ++i )
			{
				next[ i ] = rotate( Q.front(), i+1 );
				if( backward.find( next[ i ] ) == backward.end() )
				{
					backward.insert( pair<long long int,long long int> ( next[ i ], backward.find( Q.front() )->second * 10 + ( i+2 ) % 4 + 1 ) );
					if( round < 8 )
						Q.push( next[ i ] );
				}
			}
		Q.pop();
	}

	for( scanf( "%d", &t ); t; --t )
	{
		char ans[ 20 ] = { 0 };
		for( int i = 0; i < 24; ++i )
			scanf( "%d", in+i );
		long long int start = arrtoll( in, 6 );
		if( start == dest )
		{
			puts( "PUZZLE ALREADY SOLVED" );
			continue;
		}
		if( backward.find( start ) != backward.end() )
			sprintf( ans, " %lld", backward.find( start )->second );
		if( !*ans )
		{
			Q.push( start );
			Q.push( delim );
			forward.insert( pair<long long int,long long int>( start, 0 ) );
		}
		round = 0;
		while( round < 8 && !*ans )
		{
			if( Q.front() == delim )
			{
				++round;
				if( round < 8 )
					Q.push( delim );
			}
			else
				for( int i = 0; i < 4 && !*ans; ++i )
				{
					next[ i ] = rotate( Q.front(), i+1 );
					if( forward.find( next[ i ] ) == forward.end() )
						if( backward.find( next[ i ] ) == backward.end() )
						{
							forward.insert( pair<long long int,long long int> ( next[ i ], forward.find( Q.front() )->second * 10 + i + 1 ) );
							if( round < 7 )
								Q.push( next[ i ] );
						}
						else
							sprintf( ans, "%lld%d %lld", forward.find( Q.front() )->second, i+1, backward.find( next[ i ] )->second );//,printf("path: %lld\n",backward.find(next[i])->second);
				}
			Q.pop();
		}
		while( !Q.empty() )
			Q.pop();
		if( round == 8 )
		{
			puts( "NO SOLUTION WAS FOUND IN 16 STEPS" );
			continue;
		}
		reverse( strchr( ans, ' ' ) + 1, ans + strlen( ans ) );
		*strchr( ans, ' ' ) = 0;
		printf( "%s%s\n", *ans == '0'? ans+1 : ans, ans+strlen( ans )+1 );
	}

	return 0;
}

long long int arrtoll( int* arr, int base )
{
	char str[ 25 ] = { 0 };
	for( int i = 0; i < 21; ++i )
		str[ i ] = ( arr[ i ] + i % 2 ) / 2 + '0';
	return strtoll( str, NULL, base );
}

long long int rotate( long long int src, int type )
{
	char R[ 25 ] = { 0 }, tmp[ 25 ] = { 0 };
	for( int i = 0; i < 21; ++i )
	{
		R[ i ] = src % 6 + '0';
		src /= 6;
	}
	reverse( R, R+21 );
	if( type == 1 )
	{
		for( int i = 0; i < 12; ++i )
			tmp[ i ] = R[ ( i + 10 ) % 12 ];
		strncpy( R, tmp, 12 );
	}
	else if( type == 2 )
	{
		for( int i = 9; i < 21; ++i )
			tmp[ i ] = R[ ( i - 7 ) % 12 + 9 ];
		strncpy( R+9, tmp+9, 12 );
	}
	else if( type == 3 )
	{
		for( int i = 0; i < 12; ++i )
			tmp[ i ] = R[ ( i + 2 ) % 12 ];
		strncpy( R, tmp, 12 );
	}
	else
	{
		for( int i = 9; i < 21; ++i )
			tmp[ i ] = R[ ( i + 1 ) % 12 + 9 ];
		strncpy( R+9, tmp+9, 12 );
	}
	return strtoll( R, NULL, 6 );
}
