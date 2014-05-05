#include<cstdio>
#include<cstdlib>
#include<climits>
void print( int split[ 31 ][ 200 ], int end, int layer )
{
	if( layer != 1 )
		print( split, split[ layer ][ end ], layer-1 );
	if( split[ layer ][ end ] + 1 != end )
		printf( "Depot %d at restaurant %d serves restaurants %d to %d\n", layer, ( split[ layer ][ end ] + 3 + end ) / 2, split[ layer ][ end ] + 2, end + 1 );
	else
		printf( "Depot %d at restaurant %d serves restaurant %d\n", layer, end+1, end+1 );
}

int main()
{
    int total, depot, pos[ 200 ], t = 0;

    while( scanf( "%d %d", &total, &depot ) && total )
    {
        int dist[ 200 ][ 31 ] = { { 0 } }, split[ 31 ][ 200 ] = { { 0 } };
        for( int i = 0; i < total; ++i )
            for( int j = 2; j <= depot; ++j )
                dist[ i ][ j ] = INT_MAX;
        for( int i = 0; i < total; ++i )
            scanf( "%d", pos+i );
        for( int i = 0; i < total; ++i )
            for( int j = 0; j <= i; ++j )
                dist[ i ][ 1 ] += abs( pos[ j ] - pos[ i/2 ] ), split[ 1 ][ i ] = -1;
//                for( int i = 0; i < total; ++i )
//					printf( "*%d\n", dist[ i ][ 1 ] );puts("");
        for( int supplyCenter = 2; supplyCenter <= depot; ++supplyCenter )
        {
            for( int now = /*0*/supplyCenter-1; now < total; ++now )
                for( int stop = /*0*/supplyCenter-2; stop < now; ++stop )
                {
                    int nowDist = 0;
                    for( int next = stop+1; next <= now; ++next )
                        nowDist += abs( pos[ next ] - pos[ ( now + stop + 1 ) / 2 ] );
                    if( dist[ stop ][ supplyCenter-1 ] + nowDist < dist[ now ][ supplyCenter ] )
					{
						dist[ now ][ supplyCenter ] = dist[ stop ][ supplyCenter-1 ] + nowDist;
						split[ supplyCenter ][ now ] = stop;
					}
                }
//                for( int i = /*supplyCenter-1*/0; i < total; ++i )
//					printf( "*%d\n", dist[ i ][ supplyCenter ] );puts("");
        }
        printf( "Chain %d\n", ++t );
        print( split, total-1, depot );
        printf( "Total distance sum = %d\n\n", dist[ total-1 ][ depot ] );
    }

    return 0;
}
