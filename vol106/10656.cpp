#include<cstdio>

int main()
{
    int size, num;

    while( scanf( "%d", &size ) && size )
    {
        int i = 0;
        for( ; i < size; ++i )
        {
            scanf( "%d", &num );
            if( num )
            {
                printf( "%d", num );
                ++i;
                break;
            }
        }
        if( i == size )
            printf( "0" );
        for( ; i < size; ++i )
        {
            scanf( "%d", &num );
            if( num )
                printf( " %d", num );
        }
        puts( "" );
    }

	return 0;
}