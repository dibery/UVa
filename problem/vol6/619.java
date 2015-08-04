import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger RADIX = BigInteger.valueOf( 26 );
		BigInteger[] pow = new BigInteger[ 21 ];
		pow[ 0 ] = BigInteger.ONE;
		for( int i = 1; i <= 20; ++i )
			pow[ i ] = pow[ i-1 ].multiply( RADIX );

		while( in.hasNext() )
		{
			String s = in.next(), text = "", number = "";
			BigInteger n = BigInteger.ZERO;
			if( s.compareTo( "*" ) == 0 )
				break;
			if( Character.isDigit( s.charAt(0) ) )
			{
				n = new BigInteger( number = s );
				int index = 0;
				while( n.compareTo( BigInteger.ZERO ) != 0 )
				{
					n = n.subtract( BigInteger.ONE );
					text = (char) ( 'a' + n.mod( RADIX ).intValue() ) + text;
					n = n.divide( RADIX );
				}
				n = new BigInteger( s );
			}
			else
			{
				text = s;
				for( int i = 0; i < s.length(); ++i )
					n = n.add( pow[ s.length()-i-1 ].multiply( BigInteger.valueOf( s.charAt(i) - 'a' + 1 ) ) );
			}
			System.out.printf( "%-22s", text );
			comma( n.toString() );
		}
	}

	static void comma( String n )
	{
		for( int i = 0; i < n.length(); ++i )
		{
			System.out.print( n.charAt(i) );
			if( ( n.length() - i ) % 3 == 1 && i != n.length() - 1 )
				System.out.print( ',' );
		}
		System.out.println();
	}
}
