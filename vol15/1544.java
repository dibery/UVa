import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger a, b, c, ten = BigInteger.TEN, digit;

		for( int t = in.nextInt(), indent; t-- > 0; System.out.println( "" ) )
		{
			String s = in.next();
			Scanner num = new Scanner( s );

			if( s.indexOf( '+' ) > 0 )
			{
				num.useDelimiter( "\\+" );
				a = num.nextBigInteger();
				b = num.nextBigInteger();
				c = a.add( b );
				indent = Math.max( c.toString().length(), b.toString().length() + 1 );
				int stop = Math.max( b.toString().length() + 1, c.toString().length() );
				System.out.printf( "%" + indent + "d\n", a );
				System.out.printf( "%" + indent + "s\n", "+" + b );
				for( int i = 0; i <= indent; ++i )
					System.out.print( i < indent - stop? ' ' : i < indent? '-' : '\n' );
				System.out.printf( "%" + indent + "d\n", c );
			}
			else if( s.indexOf( '-' ) > 0 )
			{
				num.useDelimiter( "\\-" );
				a = num.nextBigInteger();
				b = num.nextBigInteger();
				c = a.subtract( b );
				int stop = Math.max( b.toString().length() + 1, c.toString().length() );
				indent = Math.max( a.toString().length(), stop );
				System.out.printf( "%" + indent + "d\n", a );
				System.out.printf( "%" + indent + "s\n", "-" + b );
				for( int i = 0; i <= indent; ++i )
					System.out.print( i < indent - stop? ' ' : i < indent? '-' : '\n' );
				System.out.printf( "%" + indent + "d\n", c );
			}
			else
			{
				num.useDelimiter( "\\*" );
				a = num.nextBigInteger();
				b = num.nextBigInteger();
				c = a.multiply( b );
				indent = Math.max( c.toString().length(), b.toString().length() + 1 );
				System.out.printf( "%" + indent + "d\n", a );
				System.out.printf( "%" + indent + "s\n", "*" + b );
				if( b.compareTo( ten ) >= 0 )
				{
					int stop = Math.max( a.multiply( b.mod( ten ) ).toString().length(), b.toString().length() + 1 );
					for( int i = 0; i <= indent; ++i )
						System.out.print( i == indent? '\n' : i < indent - stop? ' ' : '-' );
					for( int i = 0; ten.pow( i ).compareTo( b ) <= 0; ++i )
					{
						digit = a.multiply( b.divide( ten.pow( i ) ).mod( ten ) );
						System.out.printf( "%" + ( indent - i ) + "d\n", digit );
					}
				}
				for( int i = 0; i <= indent; ++i )
					System.out.print( i < indent - c.toString().length()? ' ' : i < indent? '-' : '\n' );
				System.out.printf( "%" + indent + "d\n", c );
			}
		}
	}
}
