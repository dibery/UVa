// Problem 10527
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main( String[] arg )
	{
		Scanner in = new Scanner( System.in );
		BigInteger n;

		while( in.hasNext() )
		{
			int[] t = new int[ 10 ];
			n = new BigInteger( in.next() );
			if( n.compareTo( BigInteger.ZERO ) < 0 )
				break;
			if( n.compareTo( BigInteger.valueOf( 10 ) ) < 0 )
			{
				System.out.println( 10 + n.intValue() );
				continue;
			}
			for( int i = 9; i > 1; --i )
				while( n.mod( BigInteger.valueOf( i ) ).compareTo( BigInteger.ZERO ) == 0 )
				{
					n = n.divide( BigInteger.valueOf( i ) );
					++t[ i ];
				}
			if( n.compareTo( BigInteger.ONE ) != 0 )
				System.out.println( "There is no such number." );
			else
			{
				for( int i = 2; i < 10; ++i )
					for( int j = t[ i ]; j > 0; --j )
						System.out.print( i );
				System.out.println();
			}
		}
	}
}
