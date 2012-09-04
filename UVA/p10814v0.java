/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10814 - Simplifying Fractions                                    */



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
		String sLine = ReadLn(MAX_LINE_LEN).trim();
		int nNoCases = Integer.parseInt(sLine);

		for (int nCaseLoop = 0; nCaseLoop < nNoCases; nCaseLoop++) {
			sLine = ReadLn(MAX_LINE_LEN).trim();
			String []arrsTokens = sLine.split("\\s/ ");

			BigInteger oP = new BigInteger(arrsTokens[0]);
			BigInteger oQ = new BigInteger(arrsTokens[1]);
			BigInteger oGCD = oP.gcd(oQ);
			System.out.println(oP.divide(oGCD) + " / " + oQ.divide(oGCD));
		}
	}
}
