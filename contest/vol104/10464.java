import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{
    public static void main( String[] arg )
    {
        Scanner in = new Scanner( System.in ), get;
        BigDecimal sum;
        int t = in.nextInt(), k;
        String line = in.nextLine(), out, tmp;

        for( int i = 0; i < t; ++i )
        {
            line = in.nextLine();
            get = new Scanner( line );
            sum = BigDecimal.ZERO;
            while( get.hasNext() )
            {
                tmp = get.next();
                if( tmp.compareTo( "." ) == 0 )
                    tmp = "0.0";
                sum = sum.add( new BigDecimal( tmp ) );
            }
            out = sum.toPlainString();
            for( k = out.length()-1; k >= 0 && out.charAt( k ) == '0'; --k );
            if( k == -1 )
                System.out.println( out + ".0" );
            else if( out.charAt( k ) == '.' )
                System.out.println( out.substring( 0, k+2 ) );
            else
                System.out.println( out.substring( 0, k+1 ) );
            get.close();
        }
    }
}