
/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1293. Eniya                                                      */
/*   http://acm.timus.ru/problem.aspx?num=1293                                */


import java.io.*;
import java.util.*;

public class Main {
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

	static int currentInteger;

	static boolean isDigit(int character) {
		return character >= '0' && character <= '9';
	} 
	static int ReadNextUInt() {
		int character;

		try {
			currentInteger = 0;

			do {
				character = System.in.read();
				if (character < 0)
					return -1;
			} while (!isDigit(character));

			do {
				currentInteger = currentInteger * 10 + character - '0';				
				character = System.in.read();
			} while (isDigit(character));

		} catch (IOException e) {
			return -1;
		}

		return currentInteger;
	}



	public static void main(String args[]) {
		int N = ReadNextUInt(), A = ReadNextUInt(), B = ReadNextUInt();		

		System.out.println(2 * N * A * B);
	}
}
