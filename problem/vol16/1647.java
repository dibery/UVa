import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		BigInteger[][] way = new BigInteger[ 1001 ][ 4 ];

		way[ 1 ][ 1 ] = BigInteger.ONE;
		way[ 1 ][ 0 ] = way[ 1 ][ 2 ] = way[ 1 ][ 3 ] = BigInteger.ZERO;
		for( int i = 2; i <= 1000; ++i )
		{
			way[ i ][ 0 ] = way[ i-1 ][ 1 ];
			way[ i ][ 1 ] = way[ i-1 ][ 0 ].add( way[ i-1 ][ 1 ] ).add( way[ i-1 ][ 3 ] ).add( BigInteger.valueOf( i % 2 ) );
			way[ i ][ 2 ] = way[ i-1 ][ 0 ].add( way[ i-1 ][ 2 ] ).add( way[ i-1 ][ 3 ] ).add( BigInteger.valueOf( ( i + 1 ) % 2 ) );
			way[ i ][ 3 ] = way[ i-1 ][ 2 ];
		}

		while( in.hasNext() )
			System.out.println( way[ in.nextInt() ][ 0 ] );
	}
}
