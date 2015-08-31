/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10198 - Counting                                                 */



import java.io.*;
import java.util.*;
import java.math.BigInteger;
import sun.security.util.BigInt;


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
		return (new String (lin, 0, lg).trim());
	}

	public static final int MAX_LINE_LEN = 16;
	
	private static final int MAX = 1001;

	public static void main(String args[]) {
		String sLine;
		
		
		BigInteger oSol[] = new BigInteger[MAX];
		oSol[0] = BigInteger.ONE;
		oSol[1] = BigInteger.valueOf(2);
		oSol[2] = BigInteger.valueOf(5);
		for (int nLoop = 3; nLoop < MAX; nLoop++) {
			oSol[nLoop] = oSol[nLoop - 1].multiply(BigInteger.valueOf(2)).add(oSol[nLoop - 2]).add(oSol[nLoop - 3]);
		}
		

		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null)
				break;

			int nN = Integer.parseInt(sLine);
			System.out.println(oSol[nN]);
		}
	}
}