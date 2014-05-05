import java.util.Scanner;
import java.math.BigInteger;
import java.lang.String;

public class Main
{
	public static void main( String[] argv )
	{
		BigInteger base, base2, Mod, ori;
		int exp1, exp2, num;
		Scanner in = new Scanner( System.in );
		String tmp;

		while( in.hasNext() )
		{
			num = in.nextInt();
			exp1 = in.nextInt();
			exp2 = in.nextInt();
			System.out.print( "("+num+"^"+exp1+"-1)/("+num+'^'+exp2+"-1) " );
			if( Math.log10( num ) * ( exp1 - exp2 ) >= 100 || num == 1 || exp1 % exp2 != 0 || num == 1 )
			{
				System.out.println( "is not an integer with less than 100 digits." );
				continue;
			}
			if( exp1 == exp2 )
			{
				System.out.println( "1" );
				continue;
			}
			ori = BigInteger.valueOf( num );
			base = ori.pow( exp1 ).subtract( BigInteger.ONE );
			base2 = ori.pow( exp2 ).subtract( BigInteger.ONE );
			Mod = base.mod( base2 );
			tmp = base.divide( base2 ).toString();

			if( Mod == BigInteger.ZERO && tmp.length() <= 100 )
				System.out.println( tmp );
			else
				System.out.println( "is not an integer with less than 100 digits." );
		}
	}
}
