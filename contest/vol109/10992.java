import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main( String[] aa )
    {
        Scanner in = new Scanner( System.in );
        BigInteger year, offset;
        BigInteger[] ghost;
        ghost = new BigInteger[ 11 ];
        boolean first = true, out;
        String[] name = { "Tanveer Ahsan", "Shahriar Manzoor", "Adrian Kugel", "Anton Maydell", "Derek Kisman", "Rezaul Alam Chowdhury", "Jimmy Mardell", "Monirul Hasan" };
        int[] come = { 2, 5, 7, 11, 15, 20, 28, 36, 4, 100, 400 };
        offset = BigInteger.valueOf( 2148 );
        for( int i = 0; i < 11; ++i )
            ghost[ i ] = BigInteger.valueOf( come[ i ] );

        while( in.hasNext() )
        {
            out = false;
            year = new BigInteger( in.next() );
            if( year.equals( BigInteger.ZERO ) )
                break;
            if( !first )
                System.out.println();
            first = false;
            System.out.println( year );
            if( year.compareTo( offset ) < 0 )
            {
                System.out.println( "No ghost will come in this year" );
                continue;
            }
            for( int i = 0; i < 8; ++i )
                if( year.subtract( offset ).mod( ghost[ i ] ).equals( BigInteger.ZERO ) )
                {
                    System.out.println( "Ghost of " + name[ i ] + "!!!" );
                    out = true;
                }
            if( year.mod( ghost[ 8 ] ).equals( BigInteger.ZERO ) && ( !year.mod( ghost[ 9 ] ).equals( BigInteger.ZERO ) || year.mod( ghost[ 10 ] ).equals( BigInteger.ZERO ) ) )
            {
                System.out.println( "Ghost of K. M. Iftekhar!!!" );
                out = true;
            }
            if( !out )
                System.out.println( "No ghost will come in this year" );
        }
    }
}
