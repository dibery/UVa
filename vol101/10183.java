import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] arg )
	{
		BigInteger a, b;
		Scanner in = new Scanner( System.in );
		BigInteger[] fib = new BigInteger[ 5000 ];
		fib[ 0 ] = fib[ 1 ] = BigInteger.ONE;
		for( int i = 2; i < 5000; ++i )
			fib[ i ] = fib[ i-1 ].add( fib[ i-2 ] );

		while( in.hasNext() )
		{
		    int ans = 0;
		    a = new BigInteger( in.next() );
		    b = new BigInteger( in.next() );
		    if( a.equals( BigInteger.ZERO ) && b.equals( BigInteger.ZERO ) )
                break;
		    for( int i = 1; i < 5000; ++i )
                if( a.compareTo( fib[ i ] ) <= 0 && b.compareTo( fib[ i ] ) >= 0 )
                    ++ans;
            System.out.println( ans );
		}
	}
}
