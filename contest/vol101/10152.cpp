#include<cstdio>
#include<cstring>

int main()
{
	int t, qnt, g, o;
	char name[ 81 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d%*c", &qnt );
		char *origin[ qnt ], *goal[ qnt ];
		for( int i = 0; i < qnt; ++i )
			gets( name ), origin[ qnt - i - 1 ] = strdup( name );
		for( int i = 0; i < qnt; ++i )
			gets( name ), goal[ qnt - i - 1 ] = strdup( name );
		for( g = o = 0; o < qnt; g = g + ( o != qnt ), ++o )
			for( ; strcmp( origin[ o ], goal[ g ] ) && o < qnt; ++o );
		for( ; g != qnt; ++g )
			puts( goal[ g ] );
		puts( "" );
	}
}
