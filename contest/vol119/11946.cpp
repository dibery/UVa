#include<cstdio>
#include<cctype>

int main()
{
	char c, map[] = "OIZEASGTBP";
	for( scanf( "%*d\n" ); ( c = getchar() ) != EOF; )
		putchar( isdigit( c )? map[ c-'0' ] : c );
}
