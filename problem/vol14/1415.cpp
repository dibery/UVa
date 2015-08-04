#include<cstdio>
#include<cmath>
bool gauss_prime( int R, int I )
{
	int len = R*R + 2*I*I;
	if( len > 2 && len % 2 == 0 )
		return false;
	for( int i = 3; i*i <= len; i += 2 )
		if( len % i == 0 )
			return false;
	return true;
}
int main()
{
	int t, r, i;
	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &r, &i );
		puts( r && i && gauss_prime( r, i )? "Yes" : "No" );
	}
}
