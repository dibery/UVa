#include<cstdio>

int main()
{
    int n;
    char res[ 5 ];
    bool candi[ 11 ] = { true, true, true, true, true, true, true, true, true, true, true };

    while( scanf( "%d", &n ) && n )
    {
        scanf( "%*s %s", res );
        if( *res == 'h' )
            for( int i = n; i <= 10; ++i )
                candi[ i ] = false;
        else if( *res == 'l' )
            for( int i = n; i; --i )
                candi[ i ] = false;
        else
        {
            puts( candi[ n ]? "Stan may be honest" : "Stan is dishonest" );
            for( int i = 0; i <= 10; ++i )
                candi[ i ] = true;
        }
    }

    return 0;
}
