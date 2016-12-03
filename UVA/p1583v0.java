/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1583 - Digit Generator                                           */


import java.io.*;
import java.util.*;

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

	static int ReadNextInt() {
		return Integer.parseInt(ReadLn(MAX_LINE_LEN).trim());
	}

	public static void main(String args[]) {
		int []vecParent = new int[100000 + 1]; 
		for (int d1 = 0; d1 <= 1; d1++)
			for (int d2 = 0; d2 <= 9; d2++)		
				for (int d3 = 0; d3 <= 9; d3++)
					for (int d4 = 0; d4 <= 9; d4++)							
						for (int d5 = 0; d5 <= 9; d5++)					
							for (int d6 = 0; d6 <= 9; d6++) {
								int father = d1 * 100000 + d2 * 10000 + d3 * 1000 + d4 * 100 + d5 * 10 + d6;
								int number = father + d1 + d2 + d3 + d4 + d5 + d6;
								if (number > 100000)
									break;
								if (vecParent[number] == 0 || vecParent[number] > father)
									vecParent[number] = father;
							}
							
		for (int noTestCases = ReadNextInt(); noTestCases > 0; noTestCases--) {
			int n = ReadNextInt();
			System.out.println(vecParent[n]);
		}
	}
}