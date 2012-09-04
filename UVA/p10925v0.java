/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10925 - Krakovia                                                 */



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
		String sLine;
		int nCaseLoop = 0;

		while (true) {
			sLine = ReadLn(MAX_LINE_LEN).trim();
			String []sTokens = sLine.split("\\s");
			int nN = Integer.parseInt(sTokens[0]);
			int nF = Integer.parseInt(sTokens[1]);
			if (nN == 0 && nF == 0)
				break;

			BigInteger oSum = BigInteger.ZERO;
			for (int nLoop = 0; nLoop < nN; nLoop++)
				oSum = oSum.add(new BigInteger(ReadLn(MAX_LINE_LEN).trim()));

			BigInteger oSol = oSum.divide(new BigInteger(nF + ""));

			System.out.println("Bill #" + ++nCaseLoop + " costs " + oSum + ": each friend should pay " + oSol + "\n");
		}
	}
}
