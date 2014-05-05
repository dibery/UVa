#include<cstdio>
#include<cstring>
#include<algorithm>
int calc( char *find, char dic[][ 6 ] )
{
    for( int i = 0; i < 83681; ++i )
        if( !strcmp( dic[ i ], find ) )
            return i+1;
    return 0;
}

int main()
{
    char word[ 6 ], cp[ 6 ], dic[ 83681 ][ 6 ] = { 0 }, perm[ 6 ] = { 0 };
    int i = 0;
    for( *perm = 'a'; *perm <= 'z'; ++*perm )
        strcpy( dic[ i++ ], perm );
    for( perm[ 0 ] = 'a'; perm[ 0 ] <= 'z'; ++perm[ 0 ] )
        for( perm[ 1 ] = perm[ 0 ]+1; perm[ 1 ] <= 'z'; ++perm[ 1 ] )
            strcpy( dic[ i++ ], perm );
    for( perm[ 0 ] = 'a'; perm[ 0 ] <= 'z'; ++perm[ 0 ] )
        for( perm[ 1 ] = perm[ 0 ]+1; perm[ 1 ] <= 'z'; ++perm[ 1 ] )
            for( perm[ 2 ] = perm[ 1 ]+1; perm[ 2 ] <= 'z'; ++perm[ 2 ] )
                strcpy( dic[ i++ ], perm );
    for( perm[ 0 ] = 'a'; perm[ 0 ] <= 'z'; ++perm[ 0 ] )
        for( perm[ 1 ] = perm[ 0 ]+1; perm[ 1 ] <= 'z'; ++perm[ 1 ] )
            for( perm[ 2 ] = perm[ 1 ]+1; perm[ 2 ] <= 'z'; ++perm[ 2 ] )
                for( perm[ 3 ] = perm[ 2 ]+1; perm[ 3 ] <= 'z'; ++perm[ 3 ] )
                    strcpy( dic[ i++ ], perm );
    for( perm[ 0 ] = 'a'; perm[ 0 ] <= 'z'; ++perm[ 0 ] )
        for( perm[ 1 ] = perm[ 0 ]+1; perm[ 1 ] <= 'z'; ++perm[ 1 ] )
            for( perm[ 2 ] = perm[ 1 ]+1; perm[ 2 ] <= 'z'; ++perm[ 2 ] )
                for( perm[ 3 ] = perm[ 2 ]+1; perm[ 3 ] <= 'z'; ++perm[ 3 ] )
                    for( perm[ 4 ] = perm[ 3 ]+1; perm[ 4 ] <= 'z'; ++perm[ 4 ] )
                        strcpy( dic[ i++ ], perm );

    while( scanf( "%s", word ) != EOF )
    {
        strcpy( cp, word );
        std::sort( cp, cp + strlen( cp ) );
        if( strcmp( cp, word ) )
            printf( "0\n" );
        else
            printf( "%d\n", calc( word, dic ) );
    }

    return 0;
}
