import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] arg )
    {
        Scanner in = new Scanner( System.in );
        BigInteger sq;
        String tmp;

        while( in.hasNext() )
        {
            tmp = in.next();
            sq = new BigInteger( tmp );
            sq = sq.multiply( sq );
            if( sq.toString().endsWith( tmp ) && sq.compareTo( BigInteger.ONE ) != 0 && sq.compareTo( BigInteger.ZERO ) != 0 )
                System.out.println( "Automorphic number of " + tmp.length() + "-digit." );
            else
                System.out.println( "Not an Automorphic number." );
        }
    }
}