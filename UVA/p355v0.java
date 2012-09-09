/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 355 - The Bases Are Loaded                                       */



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

		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null)
				break;

			String []arrsStrings = sLine.split("\\s");
			int nBase1 = Integer.parseInt(arrsStrings[0]);
			BigInteger oNumber1 = null;
			
			try {
				oNumber1 = new BigInteger(arrsStrings[2], nBase1);
			} catch (NumberFormatException oException) {
				System.out.println(arrsStrings[2] + " is an illegal base " + nBase1 + " number");
				continue;
			}

			int nBase2 = Integer.parseInt(arrsStrings[1]);

			System.out.println(arrsStrings[2] + " base " + nBase1 + " = " + oNumber1.toString(nBase2).toUpperCase() + " base " + nBase2);
		}
	}
}
