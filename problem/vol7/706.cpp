#include<cstdio>
#define Z(x) (digit[ t ] == x)

void first(), second(), third(), fourth(), fifth();
int digit[ 8 ] = { 0 }, input, size, n, t, hold;

int main()
{

    while( scanf( "%d %d", &size, &input ) && size )
    {
        n = 7;
        hold = input;
        while( input != 0 )
        {
            digit[ n-- ] = input % 10;
            input /= 10;
        }
        for( n = 0; n < 8 && digit[ n ] == 0; n++ ) {}
        if( hold == 0 )
            n = 7;
        first();
        for( int i = 0; i < size; i++ )
            second();
        third();
        for( int i = 0; i < size; i++ )
            fourth();
        fifth();
        for( int i = 0; i < 8; i++ )
            digit[ i ] = 0;
    }
}

void first()
{
    t = n;
    while( t < 8 )
    {
        if( !Z(1) && !Z(4) )
        {
            putchar( ' ' );
            for( int i = 0; i < size; i++ )
                putchar( '-' );
            putchar( ' ' );
        }
        else
        {
            for( int i = 0; i <= size+1; i++ )
                putchar( ' ' );
        }
        if( t != 7 )
            putchar( ' ' );
        t++;
    }
    puts( "" );
}

void second()
{
    t = n;
    while( t <= 7 )
    {
        if( Z(4) || Z(8) || Z(9) || Z(0) )
        {
            putchar( '|' );
            for( int i = 0; i < size; i++ )
                putchar( ' ' );
            putchar( '|' );
        }
        else if( Z(5) || Z(6) )
        {
            putchar( '|' );
            for( int i = 0; i <= size; i++ )
                putchar( ' ' );
        }
        else if( Z(1) || Z(2) || Z(3) || Z(7) )
        {
            for( int i = 0; i <= size; i++ )
                putchar( ' ' );
            putchar( '|' );
        }
        else
        {
            for( int i = 0; i <= size+1; i++ )
                putchar( ' ' );
        }
        if( t != 7 )
            putchar( ' ' );
        t++;
    }
    puts( "" );
}

void third()
{
    t = n;
    while( t <= 7 )
    {
        if( !Z(1) && !Z(7) && !Z(0) )
        {
            putchar( ' ' );
            for( int i = 0; i < size; i++ )
                putchar( '-' );
            putchar( ' ' );
        }
        else
        {
            for( int i = 0; i <= size+1; i++ )
                putchar( ' ' );
        }
        if( t != 7 )
            putchar( ' ' );
        t++;
    }
    puts( "" );
}

void fourth()
{
    t = n;
    while( t <= 7 )
    {
        if( Z(6) || Z(8) || Z(0) )
        {
            putchar( '|' );
            for( int i = 0; i < size; i++ )
                putchar( ' ' );
            putchar( '|' );
        }
        else if( Z(2) )
        {
            putchar( '|' );
            for( int i = 0; i <= size; i++ )
                putchar( ' ' );
        }
        else if( Z(1) || Z(3) || Z(4) || Z(5) || Z(7) || Z(9) )
        {
            for( int i = 0; i <= size; i++ )
                putchar( ' ' );
            putchar( '|' );
        }
        if( t != 7 )
            putchar( ' ' );
        t++;
    }
    puts( "" );
}

void fifth()
{
    t = n;
    while( t <= 7 )
    {
        if( !Z(1) && !Z(7) && !Z(4) )
        {
            putchar( ' ' );
            for( int i = 0; i < size; i++ )
                putchar( '-' );
            putchar( ' ' );
        }
        else
        {
            for( int i = 0; i <= size+1; i++ )
                putchar( ' ' );
        }
        if( t != 7 )
            putchar( ' ' );
        t++;
    }
    puts( "\n" );
}
