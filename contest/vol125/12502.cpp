#include<cstdio>

int main()
{
    int t, a, b, ado, bdo, pay;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %d %d", &a, &b, &pay );
        ado = a * 60 - ( a + b ) * 20;
        bdo = b * 60 - ( a + b ) * 20;
        if( ado < 0 )
            ado = 0;
        printf( "%d\n", pay * ado / ( ado + bdo ) );
    }

	return 0;
}