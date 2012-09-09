/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 787 - Maximum Sub-sequence Product                               */


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
	public static final int MAX_NUMBERS	= 128;
	
	public static String sLine = null;
	public static String []arrsStrings = null;
	public static int nIndex = 0;

	public static String NextInt() {
		if (sLine == null) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null)
				return null;
			arrsStrings = sLine.trim().split("[ ]+");
		}

		if (nIndex < arrsStrings.length) {
			return arrsStrings[nIndex++];
		}  else {
			sLine = null;
			arrsStrings = null;
			nIndex = 0;
			return NextInt();
		}
	}

	public static void main(String args[]) {
		String sLine;
		String []arrsNumbers = new String[MAX_NUMBERS];

		while (true) {
			int nNumbers = 0;
			while (true) {
				String sNumber = NextInt();
				if (sNumber == null)
					return;
				if (sNumber.compareTo("-999999") == 0)
					break;
				else
					arrsNumbers[nNumbers++] = sNumber;
			}


			BigInteger oMax = new BigInteger(arrsNumbers[0]);
			for (int nLoop1 = 0; nLoop1 < nNumbers; nLoop1++) {
				int nLoop2 = nLoop1;
				BigInteger oNumber = BigInteger.ONE;
				do {
					oNumber = oNumber.multiply(new BigInteger(arrsNumbers[nLoop2]));
					if (oMax.compareTo(oNumber) < 0)
						oMax = oNumber;
					if (arrsNumbers[nLoop2].compareTo("0") == 0)
						break;
					nLoop2++;
				} while (nLoop2 < nNumbers);
			}

			System.out.println(oMax);
		}
	}
}
