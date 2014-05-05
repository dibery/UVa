#include<cstdio>
#include<cstring>
#include<cctype>
inline bool correct( bool *guessed, bool *exist )
{
    for( int i = 0; i < 26; ++i )
        if( exist[ i ] && !guessed[ i ] )
            return false;
    return true;
}

int main()
{
    char answer[ 30000 ], guess[ 30000 ];
    int test;

    while( scanf( "%d", &test ) && test != -1 )
    {
        int wrong = 0;
        bool exist[ 26 ] = { false }, guessed[ 26 ] = { false };
        scanf( "%s", answer );
        scanf( "%s", guess );

        for( int i = strlen( answer )-1; i >= 0; --i )
            exist[ toupper( answer[ i ] )-'A' ] = true;
        for( int i = 0; i < strlen( guess ); ++i )
            if( !guessed[ toupper( guess[ i ] )-'A' ] )
            {
                guessed[ toupper( guess[ i ] )-'A' ] = true;
                if( !exist[ toupper( guess[ i ] )-'A' ] )
                    ++wrong;
                if( wrong >= 7 )
                {
                    printf( "Round %d\nYou lose.\n", test );
                    goto end;
                }
                else if( correct( guessed, exist ) )
                {
                    printf( "Round %d\nYou win.\n", test );
                    goto end;
                }
            }
        printf( "Round %d\nYou chickened out.\n", test );
end:
        ++wrong;
    }

    return 0;
}
