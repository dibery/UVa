import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger n, four = BigInteger.valueOf( 4 ), twenty = BigInteger.valueOf( 20 );
		String sum = new String( "01528392877847384154" );

		while( true )
		{
			n = in.nextBigInteger();
			if( n.compareTo( BigInteger.ZERO ) == 0 )
				break;
			System.out.println( n.divide( twenty ).multiply( four ).add( BigInteger.valueOf( sum.charAt( n.mod( twenty ).intValue() ) - '0' ) ).mod( BigInteger.valueOf( 10 ) ) );
		}
	}
}
