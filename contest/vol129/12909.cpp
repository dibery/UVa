#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long sol[] = { 8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161, 384199200, 2239277041u, 13051463048ll, 76069501249ll, 443365544448ll, 2584123765441ll, 15061377048200ll, 87784138523761ll, 511643454094368ll }, n;

	while( scanf( "%lld", &n ) && n )
		printf( "%d\n", upper_bound( sol, sol+19, n ) - sol );
}
