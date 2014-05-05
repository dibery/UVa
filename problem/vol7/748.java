import java.util.Scanner;
import java.math.*;

public class Main
{
	public static void main( String[] aa )
	{
		BigDecimal base, ans;
		int exp, i;
		Scanner in = new Scanner( System.in );
		String tmp;

		while( in.hasNext() )
		{
			base = new BigDecimal( in.next() );
			exp = in.nextInt();
			ans = base.pow( exp );
			tmp = ans.toPlainString();
			for( i = tmp.length()-1; tmp.charAt( i ) == '0'; --i );
			for( int k = 0; k <= i; ++k )
				if( k != 0 || tmp.charAt( 0 ) != '0' )
					System.out.printf( "%c", tmp.charAt( k ) );
			System.out.println();
		}
	}
}
