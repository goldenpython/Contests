/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13161 - Candle Box                                               */


import java.io.*;
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

	static int ReadNextInt() {
		return Integer.parseInt(ReadLn(MAX_LINE_LEN).trim());
	}

	static int QuadraticEquationPositiveRoot(int a, int b, int c) {
		int delta = b * b - 4 * a * c;
		return (-b + (int)Math.sqrt(delta)) / 2 / a;
	}

	public static void main(String args[]) {
		while (true) {
			try {
				int D = ReadNextInt(), R = ReadNextInt(), T = ReadNextInt();
				int AgeRita = QuadraticEquationPositiveRoot(2, 2 - 2 * D, D * D - D - 18 - 2 * (T + R));
				int CandlesRita = (AgeRita + 4) * (AgeRita - 3) / 2;
				System.out.println(R - CandlesRita);
			} catch (Exception e) {
				break;
			}
		}
							

	}
}