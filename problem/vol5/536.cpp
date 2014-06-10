#include<cstdio>
#include<cstring>
void recover( char* pre, char* pend, char* in, char* iend )
{
	if( pre == pend || in == iend )
		return;
	int len = strchr( in, *pre ) - in;
	recover( pre+1, pre+len+1, in, in+len );
	recover( pre+len+1, pend, in+len+1, iend );
	putchar( *pre );
}

int main()
{
	char pre[ 30 ], in[ 30 ];

	while( scanf( "%s %s", pre, in ) == 2 )
		recover( pre, pre + strlen( pre ), in, in + strlen( in ) ), putchar( '\n' );
}
