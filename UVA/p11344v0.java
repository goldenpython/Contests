/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11344 - The Huge One                                             */



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
		for (int nNoTestCasesLeft = Integer.parseInt(ReadLn(MAX_LINE_LEN).trim()); nNoTestCasesLeft-- > 0; ) {
			BigInteger oM = new BigInteger(ReadLn(MAX_LINE_LEN).trim());
			String []arrLineStrings = ReadLn(MAX_LINE_LEN).trim().split("\\s");
			boolean bIsWonderful = true;
			for (int nLoop = Integer.valueOf(arrLineStrings[0]); nLoop > 0; nLoop--) 
				if (oM.mod(new BigInteger(arrLineStrings[nLoop])).intValue() != 0) {
					bIsWonderful = false;
					break;
				}

			System.out.println(oM + " - " + (bIsWonderful ? "Wonderful." : "Simple."));
		}
	}
}