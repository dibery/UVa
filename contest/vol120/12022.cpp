#include<cstdio>

int main()
{
    int ans[] = { 1, 1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563, 1622632573 }, t, n;
    scanf( "%d", &t );
    while( t-- )
        scanf( "%d", &n ), printf( "%d\n", ans[ n ] );
    return 0;
}