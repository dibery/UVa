#include<cstdio>

int main()
{
    int bank, act, debit, credit, amount;

    while( scanf( "%d %d", &bank, &act ) && bank )
    {
        int reserve[ 21 ] = { 0 }, asset[ 21 ] = { 0 };
        register bool crisis = false;
        for( int i = 1; i <= bank; ++i )
            scanf( "%d", reserve+i );
        for( int i = 0; i < act; ++i )
        {
            scanf( "%d %d %d", &credit, &debit, &amount );
            asset[ debit ] += amount;
            asset[ credit ] -= amount;
        }
        for( int i = 1; i <= bank && !crisis; ++i )
            if( asset[ i ] + reserve[ i ] < 0 )
                crisis = true;
        puts( crisis? "N" : "S" );
    }

	return 0;
}