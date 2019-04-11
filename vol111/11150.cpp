#include<cstdio>
using namespace std;

int main()
{
    int bottle;

    while( scanf( "%d", &bottle ) != EOF )
        printf( "%d\n", bottle & 1? bottle / 2 * 3 + 1 : bottle / 2 * 3 );

	return 0;
}