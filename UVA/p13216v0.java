/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13216 - Problem with a ridiculously long name but                */
/*                   with a ridiculously short description                    */



import java.io.*;
import java.util.*;
import java.math.BigInteger;


class Main {
	public static final int MAX_LINE_LEN = 1010;
	static byte lin[] = new byte [MAX_LINE_LEN];

    static String ReadLn (int maxLg) { // utility function to read from stdin
		int lg = 0, car = -1;

		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n')) break;
				lin [lg++] = (byte)car;
			}
		} catch (IOException e) {
			return (null);
		}

		if ((car < 0) && (lg == 0))
			return (null);  // eof
		
		return new String (lin, 0, lg).trim();
	}
	
	public static void main(String args[]) {
		int []arrSol = new int[] {56, 96, 36, 76, 16};
		
		for (int nNoTestCases = Integer.parseInt(ReadLn(MAX_LINE_LEN)); nNoTestCases-- > 0; ) {
			BigInteger oNumber = new BigInteger(ReadLn(MAX_LINE_LEN));
			// System.out.println(BigInteger.valueOf(66).modPow(oNumber, BigInteger.valueOf(100)));
			
			if (oNumber.equals(BigInteger.ZERO))
				System.out.println(1);
			else if (oNumber.equals(BigInteger.ONE))
				System.out.println(66);
			else
				System.out.println(arrSol[oNumber.subtract(BigInteger.valueOf(2)).mod(BigInteger.valueOf(5)).intValue()]);
		}
	}
}