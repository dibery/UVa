#include<cstdio>

int main()
{
    int t, a, b;
    char op;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%X %c %X", &a, &op, &b );
        int result = op == '-'? a-b : a+b;
        for( int i = 12; i >= 0; --i )
            printf( "%d", ( a & 1 << i ) / ( 1 << i ) );
        printf( " %c ", op );
        for( int i = 12; i >= 0; --i )
            printf( "%d", ( b & 1 << i ) / ( 1 << i ) );
        printf( " = %d\n", result );
    }

	return 0;
}