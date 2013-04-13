/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10070 - Leap Year or Not Leap Year and ...                       */



import java.io.*;
import java.util.*;
import java.math.BigInteger;


class Main {
    static String ReadLn (int maxLg) { // utility function to read from stdin
		byte lin[] = new byte [maxLg];
		int lg = 0, car = -1;
		String line = "";

		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n')) break;
				lin [lg++] += car;
			}
		} catch (IOException e) {
			return (null);
		}

		if ((car < 0) && (lg == 0))
			return (null);  // eof
		return (new String (lin, 0, lg));
	}

	public static final int MAX_LINE_LEN = 1024 * 1024 * 1;

	public static void main(String args[]) {
		String sLine;
		boolean bFirst = true;
		
		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null || (sLine = sLine.trim()) == null)
				break;
			
			
			BigInteger oYear = new BigInteger(sLine);

			boolean bIsLeap = (oYear.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO)) && (!oYear.mod(BigInteger.valueOf(100)).equals(BigInteger.ZERO) || oYear.mod(BigInteger.valueOf(400)).equals(BigInteger.ZERO));
			boolean bIsHulu = oYear.mod(BigInteger.valueOf(15)).equals(BigInteger.ZERO);
			boolean bIsBulu = bIsLeap && oYear.mod(BigInteger.valueOf(55)).equals(BigInteger.ZERO);
			
			if (!bFirst)
				System.out.print("\n");
			
			bFirst = !true;

			if (bIsLeap)
				System.out.print("This is leap year.\n");

			if (bIsHulu)
				System.out.print("This is huluculu festival year.\n");

			if (bIsBulu)
				System.out.print("This is bulukulu festival year.\n");

			if (!bIsLeap && !bIsHulu && !bIsBulu)
				System.out.print("This is an ordinary year.\n");			
		}
	}
}