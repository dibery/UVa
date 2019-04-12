#include<bits/stdc++.h>

int main()
{
	int t, seg, qnt, num[ 100 ], tmp[ 100 ], bit[ 1 << 15 ] = { 0 };
	char n[ 50 ] = { 0 };

	for( int i = 1; i < 1 << 15; ++i )
		bit[ i ] = 1 + bit[ i ^ i & -i ];

	for( scanf( "%d", &t ); t--; )
	{
		int ans = 99;
		scanf( "%d %d\n", &seg, &qnt );
		for( int i = 0; i < qnt; ++i )
		{
			gets( n );
			*std::remove( n, n + strlen( n ), ' ' ) = 0;
			num[ i ] = strtol( n, NULL, 2 );
		}
		for( int i = 0; i < 1 << seg; ++i )
			if( bit[ i ] < ans )
			{
				for( int j = 0; j < qnt; ++j )
					tmp[ j ] = i & num[ j ];
				bool uniq = true;
				for( int j = 0; j < qnt; ++j )
					for( int k = j + 1; k < qnt; ++k )
						uniq &= tmp[ j ] != tmp[ k ];
				if( uniq )
					ans = bit[ i ];
			}
		printf( "%d\n", ans );
	}
}
