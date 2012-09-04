/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



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

		BigInteger oNum17 = new BigInteger("17");

		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null)
				break;

			BigInteger oN = new BigInteger(sLine);
			if (sLine.compareTo("0") == 0) {
				break;
			} else {
				if (oN.mod(oNum17).compareTo(BigInteger.ZERO) == 0)
					System.out.println("1");
				else
					System.out.println("0");
			}
		}
	}
}
