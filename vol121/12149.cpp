#include<cstdio>
using namespace std;

int main()
{
    int a;

    while( scanf( "%d", &a ) && a )
        printf( "%d\n", a * ( a+1 ) * ( 2*a+1 ) / 6 );

	return 0;
}