/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 763 - Fibinary Numbers                                           */


import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {
   static String ReadLn (int maxLg) { // utility function to read from stdin
		int lg = 0, car = -1;

		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n')) break;
				lin [lg++] = (byte)car;
			}
		} catch (IOException e) {
			return (null);
		}

		if ((car < 0) && (lg == 0))
			return (null);  // eof
		return (new String (lin, 0, lg));
	}

	public static final int MAX_LINE_LEN = 1024;
	static byte lin[] = new byte [MAX_LINE_LEN];

	static BigInteger[] GenFibs(int nMaxDigits) {
		ArrayList<BigInteger> oFibs = new ArrayList<BigInteger>();
		oFibs.add(BigInteger.ONE);
		oFibs.add(BigInteger.ONE.add(BigInteger.ONE));
		BigInteger oLimit = BigInteger.TEN.pow(nMaxDigits);
		for (int nLoop = 2; true; nLoop++) {
			BigInteger oCurrentFib = oFibs.get(nLoop - 1).add(oFibs.get(nLoop - 2));
			if (oCurrentFib.compareTo(oLimit) >= 0)
				break;
			oFibs.add(oCurrentFib);
		}

		BigInteger []oFibArray = new BigInteger[oFibs.size()];
		oFibArray = oFibs.toArray(oFibArray);
		return oFibArray;
	}

	public static BigInteger FibinaryString2BigInt(String oFibinaryString, BigInteger oFibs[]) {
		oFibinaryString = (new StringBuilder(oFibinaryString)).reverse().toString();

		BigInteger oResult = BigInteger.ZERO;
		for (int nLoop = 0; nLoop < oFibinaryString.length(); nLoop++)
			if (oFibinaryString.charAt(nLoop) == '1')
				oResult = oResult.add(oFibs[nLoop]);

		return oResult;
	}

	public static String BigInt2FibinaryString(BigInteger oNumber, BigInteger oFibs[]) {
		String oResult = "";
		boolean bFirst = true;
		for (int nLoop = oFibs.length - 1; nLoop >= 0; nLoop--)
			if (oFibs[nLoop].compareTo(oNumber) <= 0) {
				bFirst = false;
				oResult += '1';
				oNumber = oNumber.subtract(oFibs[nLoop]);
			} else {
				if (!bFirst)
					oResult += '0';
			}

		return oResult.length() == 0 ? "0" : oResult;
	}

	public static void main(String args[]) {
		final int MAX_FIB = 101;
		BigInteger oFibs[] = GenFibs(MAX_FIB);
		
		boolean bFirstCase = true;
		while (true) {
			String oNum1 = ReadLn(MAX_LINE_LEN).trim();
			String oNum2 = ReadLn(MAX_LINE_LEN).trim();

			BigInteger oSum = FibinaryString2BigInt(oNum1, oFibs).add(FibinaryString2BigInt(oNum2, oFibs));
			
			if (!bFirstCase)
				System.out.println();
			bFirstCase = false;
			System.out.println(BigInt2FibinaryString(oSum, oFibs));

			oNum1 = ReadLn(MAX_LINE_LEN);
			if (oNum1 == null)
				break;
		}
	}
}