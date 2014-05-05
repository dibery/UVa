#include<cstdio>
int* find( int up, int down )
{
    static int process[ 32 ] = { 0 };
	if( up == 0 || up == 1 || down == 0 || down == 1 )
		return NULL;
    *process = up;
	int i;

    for( i = 1; process[ i-1 ] != 0; ++i )
    {
        if( process[ i-1 ] % down != 0 && process[ i-1 ] != 1 )
        {
            process[ 0 ] = 0;
            return NULL;
        }
        else
            process[ i ] = process[ i-1 ] / down;
    }
    return process;
}

int main()
{
    int m, n;

    while( scanf( "%d %d", &m, &n ) != EOF )
    {
        int *divide = find( m, n );
        if( divide == NULL )
            printf( "Boring!" );
        else
            for( int i = 0; divide[ i ]; ++i )
                printf( "%s%d", i? " " : "", divide[ i ] );
        puts( "" );
    }

    return 0;
}
