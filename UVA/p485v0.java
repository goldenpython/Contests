/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 485 - Pascal's Triangle of Death                                 */



import java.math.BigInteger;
import java.util.ArrayList;

class Main {
	public static void main(String args[]) {
		BigInteger oMax = BigInteger.TEN.pow(60);
		
		System.out.println("1");
		System.out.println("1 1");		
		
		ArrayList<BigInteger> oPrevRow = new ArrayList<BigInteger>();
		oPrevRow.add(BigInteger.ONE);
		oPrevRow.add(BigInteger.ONE);		
	
		boolean bStop = false;
		while (!bStop) {
			ArrayList<BigInteger> oCurrentRow = new ArrayList<BigInteger>();
			oCurrentRow.add(BigInteger.ONE);
			
			for (int nLoop = 1; nLoop < oPrevRow.size(); nLoop++)
				oCurrentRow.add(oPrevRow.get(nLoop - 1).add(oPrevRow.get(nLoop)));
			
			oCurrentRow.add(BigInteger.ONE);
			
			System.out.print("1");
			for (int nLoop = 1; nLoop < oCurrentRow.size(); nLoop++) {
				BigInteger oNumber = oCurrentRow.get(nLoop);
				if (oNumber.compareTo(oMax) >= 0)
					bStop = true;
				System.out.print(" " + oNumber);
			}
			System.out.println();
			
			oPrevRow = oCurrentRow;
		}

	}
}