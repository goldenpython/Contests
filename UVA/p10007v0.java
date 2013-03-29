/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10007 - Count the Trees                                          */

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

	public static final int MAX_LINE_LEN = 1024;

	public static void main(String args[]) {
		final int MAX = 301;
		
		BigInteger catalans[] = new BigInteger[MAX];
		BigInteger factorials[] = new BigInteger[MAX];
		
		catalans[1] = BigInteger.ONE;
		factorials[1] = BigInteger.ONE;
		
		for (int loop = 1; loop < MAX - 1; loop++) {
			catalans[loop + 1] = catalans[loop].multiply(BigInteger.valueOf(2 * (2 * loop + 1))).divide(BigInteger.valueOf(loop + 2));
			factorials[loop + 1] = factorials[loop].multiply(BigInteger.valueOf(loop + 1));
		}
		
		
		
		String sLine;

		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null)
				break;
			
			int n = Integer.parseInt(sLine);
			if (n == 0)
				break;

			System.out.println(catalans[n].multiply(factorials[n]));
		}
	}
}
