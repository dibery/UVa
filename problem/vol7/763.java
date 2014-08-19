import java.util.Scanner;
import java.math.BigInteger;
//problem 763

public class Main
{
	public static void main( String[] arg )
	{
		Scanner in = new Scanner( System.in );
		BigInteger[] fib = new BigInteger[ 105 ];
		fib[ 0 ] = fib[ 1 ] = BigInteger.ONE;
		String a, b;
		int index;
		boolean first = true;

		for( int i = 2; i <= 104; ++i )
			fib[ i ] = fib[ i-1 ].add( fib[ i-2 ] );

		while( in.hasNext() )
		{
			BigInteger sum = BigInteger.ZERO;
			a = in.next();
			b = in.next();
			a = new StringBuilder( a ).reverse().toString();
			b = new StringBuilder( b ).reverse().toString();
			for( int i = 0; i < a.length(); ++i )
				if( a.charAt(i) == '1' )
					sum = sum.add( fib[ i+1 ] );
			for( int i = 0; i < b.length(); ++i )
				if( b.charAt(i) == '1' )
					sum = sum.add( fib[ i+1 ] );

			if( !first )
				System.out.println();
			first = false;
			if( sum.compareTo( BigInteger.ZERO ) == 0 )
				System.out.print( "0" );

			for( index = 104; sum.compareTo( fib[ index ] ) < 0 && index > 0; --index );
			for( ; index > 0; --index )
				if( sum.compareTo( fib[ index ] ) >= 0 )
				{
					System.out.print( "1" );
					sum = sum.subtract( fib[ index ] );
				}
				else
					System.out.print( "0" );
			System.out.println();
		}
	}
}
