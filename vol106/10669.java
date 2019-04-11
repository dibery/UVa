import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] arg )
    {
        BigInteger[] ans = new BigInteger[ 64 ];
        ans[ 0 ] = BigInteger.ONE;
        for( int i = 1; i < 64; ++i )
            ans[ i ] = ans[ i-1 ].multiply( BigInteger.valueOf( 3 ) );
        long num;
        Scanner in = new Scanner( System.in );

        while( in.hasNext() )
        {
            int[] out = new int[ 64 ];
            int now = 0, put = 0;
            for( int i = 0; i < 64; ++i )
                out[ i ] = 0;
            num = in.nextLong();
            if( num == 0 )
                break;
            --num;
            if( num == 0 )
            {
                System.out.println( "{  }" );
                continue;
            }
            while( num != 0 )
            {
                if( num % 2 == 1 )
                {
                    out[ put ] = now;
                    ++put;
                }
                ++now;
                    num = num / 2;
            }
            System.out.print( "{ " );
            for( int i = 0; i < put; ++i )
                if( i == put-1 )
                    System.out.println( ans[ out[ i ] ] + " }" );
                else
                    System.out.print( ans[ out[ i ] ] + ", " );
        }
    }
}
