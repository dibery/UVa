import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main( String[] arg )
    {
        BigInteger[] ans = new BigInteger[ 801 ];
        Scanner in = new Scanner( System.in );
        int t;
        ans[ 1 ] = BigInteger.ZERO;
        ans[ 2 ] = BigInteger.ONE;
        for( int i = 3; i <= 800; ++i )
            ans[ i ] = ans[ i-1 ].add( ans[ i-2 ] ).multiply( BigInteger.valueOf( i-1 ) );

        while( in.hasNext() )
        {
            t = in.nextInt();
            if( t == -1 )
                break;
            System.out.println( ans[ t ] );
        }
    }
}
