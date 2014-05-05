import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static void main( String[] arg )
	{
		Scanner in = new Scanner( System.in );
		BigInteger ans, n;
		int t = in.nextInt();

		while( t-- > 0 )
		{
			n = in.nextBigInteger();
			System.out.println( edge( n ).subtract( vertex( n ) ).add( BigInteger.ONE ) );
		}
	}
	public static BigInteger edge( BigInteger n )
	{
		BigInteger ans = BigInteger.ZERO, nSub1 = n.subtract( BigInteger.ONE ), two = BigInteger.valueOf( 2 ), three = BigInteger.valueOf( 3 ), nSub2 = n.subtract( two ), six = BigInteger.valueOf( 6 );
		ans = nSub1;
		ans = ans.add( nSub2.multiply( nSub2 ).multiply( nSub1 ).divide( two ) );
		ans = ans.subtract( nSub2.multiply( nSub1 ).multiply( n.multiply( two ).subtract( three ) ).divide( six ) );
		return ans.multiply( n ).divide( two ).add( n );
	}
	public static BigInteger vertex( BigInteger n )
	{
		BigInteger ans = BigInteger.ZERO, nSub1 = n.subtract( BigInteger.ONE ), two = BigInteger.valueOf( 2 ), three = BigInteger.valueOf( 3 ), nSub2 = n.subtract( two ), six = BigInteger.valueOf( 6 );
		ans = ans.add( nSub2.multiply( nSub2 ).multiply( nSub1 ).divide( two ) );
		ans = ans.subtract( nSub2.multiply( nSub1 ).multiply( n.multiply( two ).subtract( three ) ).divide( six ) );
		return ans.multiply( n ).divide( BigInteger.valueOf( 4 ) ).add( n );
	}
}
