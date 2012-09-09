/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12027 - Very Big Perfect Squares                                 */



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
		while (true) {
			String sLine = ReadLn(MAX_LINE_LEN).trim();
			if (sLine.compareTo("0") == 0)
				break;

			if (sLine.length() % 2 == 1) {
				System.out.print((int)Math.sqrt(sLine.charAt(0) - '0'));
			} else {
				System.out.print((int)Math.sqrt((sLine.charAt(0) - '0') * 10 + sLine.charAt(1) - '0'));
			}

			for (int nLoop = 0; nLoop < (sLine.length() - 1) / 2; nLoop++)
				System.out.print("0");
			System.out.println("");
		}
	}
}
