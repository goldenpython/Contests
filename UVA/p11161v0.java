/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11161 - Help My Brother (II)                                      */

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
		return (new String (lin, 0, lg));
	}

	public static final int MAX_LINE_LEN = 1024;
	public static final int MAX_FIB = 1510;


	public static void main(String args[]) {
		String sLine;
		int nCaseLoop = 1;

		BigInteger []arroFibs = new BigInteger[MAX_FIB];
		arroFibs[0] = BigInteger.ZERO;
		arroFibs[1] = BigInteger.ONE;
		for (int nLoop = 2; nLoop < MAX_FIB; nLoop++)
			arroFibs[nLoop] = arroFibs[nLoop - 1].add(arroFibs[nLoop - 2]);

		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			int nN = Integer.parseInt(sLine);
			if (nN == 0)
				break;

			BigInteger oFirstNum = arroFibs[nN + 1].subtract(BigInteger.ONE);
			BigInteger oSol = oFirstNum.add(arroFibs[nN].shiftRight(1));
			if (!arroFibs[nN].testBit(0) && nN > 1)
				oSol = oSol.subtract(BigInteger.ONE);

			System.out.println("Set " + nCaseLoop + ":\n" + oSol);
			nCaseLoop++;
		}
	}
}
