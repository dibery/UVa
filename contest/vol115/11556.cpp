#include<cstdio>
#include<algorithm>

int main()
{
	for( long long int n, b; scanf( "%lld %lld", &n, &b ) == 2; )
		puts( ( 1ll << b+1 ) > n? "yes" : "no" );
}
