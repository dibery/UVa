import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int t = in.nextInt();

		for( int q = 1; q <= t; ++q )
		{
			String str = in.next();
			int strlen = str.length(), len = (strlen+1) / 2;
			BigInteger a = BigInteger.ZERO;
			BigInteger[] sqrt = new BigInteger[ len ], remainder = new BigInteger[ 1 ];

			if( strlen % 2 == 1 )
				sqrt[ 0 ] = new BigInteger( str.substring( 0, 1 ) );
			for( int i = strlen % 2; i < strlen; i += 2 )
				sqrt[ ( i+1 ) / 2 ] = new BigInteger( str.substring( i, i+2 ) );
			remainder[0] = BigInteger.ZERO;

			for( int i = 0; i < len; ++i )
				a = a.multiply( BigInteger.valueOf( 10 ) ).add( nextDigit( a, remainder, sqrt[ i ] ) );
			System.out.println( a );
			if( q != t )
				System.out.println();
		}
	}

	public static BigInteger nextDigit( BigInteger a, BigInteger[] r, BigInteger next )
	{
		a = a.multiply( BigInteger.valueOf( 20 ) );
		BigInteger digit = BigInteger.ONE;
		for( ; digit.compareTo( BigInteger.valueOf( 9 ) ) <= 0; digit = digit.add( BigInteger.ONE ) )
			if( r[0].multiply( BigInteger.valueOf( 100 ) ).add( next ).compareTo( a.add( digit ).multiply( digit ) ) == -1 )
				break;
		digit = digit.subtract( BigInteger.ONE );
		r[0] = r[0].multiply( BigInteger.valueOf( 100 ) ).add( next ).subtract( a.add( digit ).multiply( digit ) );
		return digit;
	}
}
