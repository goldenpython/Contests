/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10992 - The Ghost of Programmers                                 */



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

	public static void main(String args[]) {
		String sLine;
		boolean bFirst = true;
		
		while (true) {
			sLine = ReadLn(MAX_LINE_LEN);
			if (sLine == null || (sLine = sLine.trim()) == null)
				break;
			
			BigInteger oYear = new BigInteger(sLine);
			if (oYear.equals(BigInteger.ZERO))
				break;

			boolean bIsLeap = (oYear.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO)) && (!oYear.mod(BigInteger.valueOf(100)).equals(BigInteger.ZERO) || oYear.mod(BigInteger.valueOf(400)).equals(BigInteger.ZERO));
			
			BigInteger oYear2148 = BigInteger.valueOf(2148);
			
			System.out.println(oYear);
			oYear = oYear.subtract(oYear2148);
			
			boolean bAtLeastOneGhost = false;
			if (oYear.compareTo(BigInteger.ZERO) >= 0) {
				if (oYear.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Tanveer Ahsan!!!");
					bAtLeastOneGhost = true;
				}
				
				if (oYear.mod(BigInteger.valueOf(5)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Shahriar Manzoor!!!");
					bAtLeastOneGhost = true;
				}
				
				if (oYear.mod(BigInteger.valueOf(7)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Adrian Kugel!!!");
					bAtLeastOneGhost = true;
				}						
				
				if (oYear.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Anton Maydell!!!");
					bAtLeastOneGhost = true;
				}									

				if (oYear.mod(BigInteger.valueOf(15)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Derek Kisman!!!");
					bAtLeastOneGhost = true;
				}
				
				if (oYear.mod(BigInteger.valueOf(20)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Rezaul Alam Chowdhury!!!");
					bAtLeastOneGhost = true;
				}

				if (oYear.mod(BigInteger.valueOf(28)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Jimmy Mardell!!!");
					bAtLeastOneGhost = true;
				}

				if (oYear.mod(BigInteger.valueOf(36)).equals(BigInteger.ZERO)) {
					System.out.println("Ghost of Monirul Hasan!!!");
					bAtLeastOneGhost = true;
				}

				if (bIsLeap){
					System.out.println("Ghost of K. M. Iftekhar!!!");
					bAtLeastOneGhost = true;
				}
			}
			
			if (!bAtLeastOneGhost)
				System.out.println("No ghost will come in this year");							
			
		}
	}
}