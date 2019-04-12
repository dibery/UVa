#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
char data[ 4000 ][ 16 ];

int main()
{
	int num;
	char input[ 16 ];
	char *T[] = { "", "M", "MM", "MMM" };  
	char *H[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };  
	char *t[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };  
	char *o[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }; 

	for( int n = 0; n < 4000; ++n )
		sprintf( data[ n ], "%s%s%s%s", T[n/1000], H[(n/100)%10], t[(n/10)%10], o[n%10] );

	while( gets( input ) )
		if( isalpha( *input ) )
		{
			for( num = 0; strcmp( data[ num ], input ); ++num );
			printf( "%d\n", num );
		}
		else
			puts( data[ atoi( input ) ] );
}
