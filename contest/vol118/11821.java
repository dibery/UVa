import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{
    public static void main( String[] arg )
    {
        BigDecimal num, sum;
        String out;
        Scanner in = new Scanner( System.in );
        int t = in.nextInt(), tmp;

        for( int a = 1; a <= t; ++a )
        {
            sum = BigDecimal.ZERO;
            while( true )
            {
                num = new BigDecimal( in.next() );
                if( num.equals( BigDecimal.ZERO ) )
                    break;
                sum = sum.add( num );
            }
            out = sum.toString();
            for( tmp = out.length()-1; out.charAt( tmp ) == '0'; --tmp );
            if( out.charAt( tmp ) == '.' )
                --tmp;
            for( int i = 0; i <= tmp; ++i )
                System.out.print( out.charAt( i ) );
            System.out.println();
        }
    }
}
