import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );

		for( int t = in.nextInt(); t-- > 0; )
		{
			BigInteger[][] freq = new BigInteger[ 100 ][ 10000 ];
			String a = in.next(), b = in.next();

			for( int i = 0; i < b.length(); ++i )
				for( int j = 0; j < a.length(); ++j )
					freq[ i ][ j ] = BigInteger.ZERO;
			freq[ 0 ][ 0 ] = a.charAt( 0 ) == b.charAt( 0 )? BigInteger.ONE : BigInteger.ZERO;
			for( int i = 1; i < a.length(); ++i )
				freq[ 0 ][ i ] = freq[ 0 ][ i-1 ].add( a.charAt( i ) == b.charAt( 0 )? BigInteger.ONE : BigInteger.ZERO );
			for( int i = 1; i < b.length(); ++i )
				for( int j = i; j < a.length(); ++j )
					if( b.charAt( i ) == a.charAt( j ) )
						freq[ i ][ j ] = freq[ i-1 ][ j-1 ].add( freq[ i ][ j-1 ] );
					else
						freq[ i ][ j ] = freq[ i ][ j-1 ];
			System.out.println( freq[ b.length() - 1 ][ a.length() - 1 ] );
		}
	}
}
