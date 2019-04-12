import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] aa )
    {
        int toss, consequent;
        Scanner in = new Scanner( System.in );
        BigInteger[] pow2 = new BigInteger[ 101 ];
        BigInteger[][] ans = new BigInteger[ 101 ][ 101 ];
        pow2[ 0 ] = BigInteger.ONE;
        pow2[ 1 ] = BigInteger.valueOf( 2 );
        for( int i = 2; i <= 100; ++i )
            pow2[ i ] = pow2[ i-1 ].multiply( pow2[ 1 ] );
        for( int i = 0; i <= 100; ++i )
            for( int j = 0; j <= 100; ++j )
                ans[ i ][ j ] = BigInteger.ZERO;
        for( int i = 1; i <= 100; ++i ) //consequent
            for( int j = 1; j <= 100; ++j ) //toss
                if( j >= i )
                {
                    for( int k = 1; k <= i; ++k )
                        ans[ j ][ i ] = ans[ j ][ i ].add( ans[ j-k ][ i ] );
                    ans[ j ][ i ] = ans[ j ][ i ].add( pow2[ j-i ] );
                }

        while( in.hasNext() )
        {
            toss = in.nextInt();
            consequent = in.nextInt();
            System.out.println( ans[ toss ][ consequent ] );
        }
    }
}