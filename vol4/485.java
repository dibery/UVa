import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		BigInteger[] fact = new BigInteger[ 205 ];
		
		fact[ 0 ] = BigInteger.ONE;
		for( int i = 1; i < 205; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );

		for( int i = 0; i < 205; ++i )
			for( int j = 0; j <= i; ++j )
				System.out.print( fact[ i ].divide( fact[ j ] ).divide( fact[ i-j ] ) + ( j == i? "\n" : " " ) );
	}
}
