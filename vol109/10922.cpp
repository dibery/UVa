#include<cstdio>
#include<cstring>
void find( int num, int &depth )
{
    int sum = 0;
    ++depth;
    while( num )
    {
        sum += num % 10;
        num /= 10;
    }
    if( sum > 9 )
        find( sum, depth );
}

int main()
{
    char num[ 1001 ];

    while( gets( num ) && strcmp( num, "0" ) )
    {
        int sum = 0, depth = 0;
        for( int i = 0; num[ i ]; ++i )
            sum += num[ i ] - '0';
        if( sum > 9 )
            ++depth;
        if( sum % 9 == 0 )
            find( sum, depth );
        if( sum % 9 )
            printf( "%s is not a multiple of 9.\n", num );
        else
            printf( "%s is a multiple of 9 and has 9-degree %d.\n", num, depth );
    }

	return 0;
}