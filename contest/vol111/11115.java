import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] arg )
    {
        Scanner in = new Scanner( System.in );
        BigInteger base;
        int exp;

        while( true )
        {
            base = new BigInteger( in.next() );
            if( base.equals( BigInteger.ZERO ) )
                break;
            exp = in.nextInt();
            System.out.println( base.pow( exp ) );
        }
    }
}