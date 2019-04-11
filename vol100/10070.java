import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger num;
		boolean first = true;

		while( in.hasNext() )
		{
			if( !first )
                System.out.println();
            first = false;
			num = in.nextBigInteger();

			boolean leap = num.mod( BigInteger.valueOf( 4 ) ) == BigInteger.ZERO && num.mod( BigInteger.valueOf( 100 ) ) != BigInteger.ZERO || num.mod( BigInteger.valueOf( 400 ) ) == BigInteger.ZERO;
			boolean hulu = num.mod( BigInteger.valueOf( 15 ) ) == BigInteger.ZERO;
			boolean bulu = num.mod( BigInteger.valueOf( 55 ) ) == BigInteger.ZERO && leap;
			boolean ok = leap || hulu || bulu;

			if( leap )
				System.out.println( "This is leap year." );
			if( hulu )
				System.out.println( "This is huluculu festival year." );
			if( bulu )
				System.out.println( "This is bulukulu festival year." );
			if( !ok )
				System.out.println( "This is an ordinary year." );
		}
	}
}
