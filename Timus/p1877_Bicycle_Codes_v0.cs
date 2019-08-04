/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1877. Bicycle Codes                                              */
/*   http://acm.timus.ru/problem.aspx?num=1877                                */



using System;

public class About_Grisha_N {

    private static void Main() {
        int nCode1 = Convert.ToInt32(Console.ReadLine());
        int nCode2 = Convert.ToInt32(Console.ReadLine());
        bool bYes = (nCode1 % 2 == 0) || (nCode2 % 2 == 1);
        Console.WriteLine(bYes ? "yes" : "no");
    }
}