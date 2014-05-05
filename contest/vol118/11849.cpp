#include<cstdio>

int main()
{
    int a, b, tmp;

    while( scanf( "%d %d", &a, &b ) && ( a+b ) )
    {
        int both = 0;
        bool *has = new bool[ 1000000001 ];
        for( int i = a+b; i; --i )
        {
            scanf( "%d", &tmp );
            if( has[ tmp ] )
                ++both;
            else
                has[ tmp ] = true;
        }
        printf( "%d\n", both );
        delete[] has;
    }

	return 0;
}