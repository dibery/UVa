import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger a, b, c, ten = BigInteger.TEN, digit;

		while( true )
		{
			a = in.nextBigInteger();
			if( !in.hasNext() )
				break;
			b = in.nextBigInteger();
			c = a.multiply( b );
			int stop = Math.max( a.toString().length(), b.toString().length() ),
					indent = Math.max( c.toString().length(), stop );

			System.out.printf( "%" + indent + "d\n", a );
			System.out.printf( "%" + indent + "d\n", b );

			if( ok( a, b ) )
			{
				for( int i = 0; i <= indent; ++i )
					System.out.print( i == indent? '\n' : i < indent - stop? ' ' : '-' );
				for( int i = 0; ten.pow( i ).compareTo( b ) <= 0; ++i )
				{
					digit = a.multiply( b.divide( ten.pow( i ) ).mod( ten ) );
					if( digit.compareTo( BigInteger.ZERO ) > 0 )
						System.out.printf( "%" + ( indent - i ) + "d\n", digit );
				}
				for( int i = 0; i < indent; ++i )
					System.out.print( '-' );
			}
			else
				for( int i = 0; i < Math.max( indent, stop ); ++i )
					System.out.print( i < indent - stop? ' ' : '-' );
			System.out.printf( "\n%" + indent + "d\n\n", c );
		}
	}

	public static boolean ok( BigInteger a, BigInteger b )
	{
		if( a.compareTo( BigInteger.ZERO ) == 0 || b.compareTo( BigInteger.TEN ) < 0 )
			return false;
		while( b.mod( BigInteger.TEN ).compareTo( BigInteger.ZERO ) == 0 )
			b = b.divide( BigInteger.TEN );
		return b.compareTo( BigInteger.TEN ) >= 0;
	}
}
