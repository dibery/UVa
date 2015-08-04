#include<cstdio>
#include<algorithm>

int fn[ 673400 ] = { 0, 1, 2, 2 }, sum[ 673400 ] = { 0, 1, 3, 5 }, fs = 3, ss = 3;

int main()
{
	for( int i = 3; sum[ ss ] < 2000000000; sum[ ss+1 ] = sum[ ss ] + fn[ ++i ], ++ss )
		for( int j = 0; fs < 673400 && j < fn[ i ]; ++j )
			fn[ ++fs ] = i;
	for( int i; scanf( "%d", &i ) && i; printf( "%ld\n", std::lower_bound( sum, sum+ss, i ) - sum ) );
}
