#include<cstdio>

int main()
{
	int n;
	char *T[] = { "", "M", "MM", "MMM" };  
	char *H[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };  
	char *t[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };  
	char *o[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }; 
	char match[] = { "00230000100240000000020200" };

	while( scanf( "%d", &n ) == 1 )
	{
		char tmp[ 300 ] = { 0 };
		int ans = 0;
		sprintf( tmp, "%s%s%s%s", T[n/1000], H[(n/100)%10], t[(n/10)%10], o[n%10] );
		for( int i = 0; tmp[ i ]; ++i )
			ans += match[ tmp[ i ] - 'A' ] - '0';
		printf( "%d\n", ans );
	}
}
