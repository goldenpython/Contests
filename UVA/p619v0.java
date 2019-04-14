/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 619 - Numerically Speaking                                       */



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

	public static final int MAX_LINE_LEN = 128;

	final static BigInteger oBase26 = BigInteger.valueOf(26);

	public static String NumberToWord(String sNumber) {
		BigInteger oNumber = new BigInteger(sNumber);
		String oRetValue = "";
		while (oNumber.compareTo(BigInteger.ZERO) > 0) {
			oRetValue = (char)('a' + oNumber.mod(oBase26).intValue() - 1) + oRetValue;
			oNumber = oNumber.divide(oBase26);
		}
		
		return oRetValue;
	}

	public static String WordToNumber(String sWord) {
		BigInteger oNumber = BigInteger.ZERO;

		for (int nLoop = 0, nStringLen = sWord.length(); nLoop < nStringLen; nLoop++)
			oNumber = oNumber.multiply(oBase26).add(BigInteger.valueOf((sWord.charAt(nLoop) - 'a' + 1)));

		return oNumber.toString();
	}

	public static String AddSeparatingCommans(String sNumber) {
		String sRet = new String();
		sRet = sRet + sNumber.charAt(0);
		for (int nLoop = 1, nStringLen = sNumber.length(), nMod = (sNumber.length() % 3); nLoop < nStringLen; nLoop++) {
			if (nLoop % 3 == nMod)
				sRet += ',';
			sRet += sNumber.charAt(nLoop);
		}

		return sRet;
	}

	public static void main(String args[]) {
		String sLine;
		boolean bFirstLine = true;
		
		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null || (sLine = sLine.trim()) == null || sLine.charAt(0) == '*')
				break;

			String sNumber, sWord;
			if (Character.isDigit(sLine.charAt(0))) {
				sNumber = sLine;
				sWord = NumberToWord(sNumber);
			} else {
				sWord = sLine;
				sNumber = WordToNumber(sWord);
			}

			System.out.print(sWord);
			for (int nLoop = 22 - sWord.length(); nLoop > 0; nLoop--)
				System.out.print(' ');
			System.out.println(AddSeparatingCommans(sNumber));
							
		}
	}
}