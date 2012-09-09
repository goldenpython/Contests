/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 343 - What Base Is This?                                         */



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

			String []arrsStrings = sLine.trim().split("[ ]+");

			boolean bFoundSol = false;
			for (int nBase1 = 2; nBase1 <= 36; nBase1++) {
				BigInteger oNumber1;

				try {
					oNumber1 = new BigInteger(arrsStrings[0], nBase1);
				} catch (NumberFormatException oException) {
					continue;
				}

				for (int nBase2 = 2; nBase2 <= 36; nBase2++) {
					try {
						BigInteger oNumber2 = new BigInteger(arrsStrings[1], nBase2);

						String sNumber1 = oNumber1.toString();
						String sNumber2 = oNumber2.toString();

						if (sNumber1.compareTo(sNumber2) == 0) {
							System.out.println(arrsStrings[0] + " (base " + nBase1 + ") = " + arrsStrings[1] + " (base " + nBase2 + ")");
							nBase1 = nBase2 = 37;
							bFoundSol = true;
							break;
						}
					} catch (NumberFormatException oException) {
					}
				}
			}

			if (!bFoundSol) {
				System.out.println(arrsStrings[0] + " is not equal to " + arrsStrings[1] + " in any base 2..36");
			}
		}
	}
}
