/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1785. Lost in Localization                                       */
/*   http://acm.timus.ru/problem.aspx?num=1785                                */



using System;

public class Lost_In_Localization {
    private class A : IComparable {
        public static string GetDesignation(int number) {
            int index = Array.BinarySearch<A>(array, new A(number));
            if (index < 0)
                index = ~index;

            return array[index].designation;
        }

        private A(int number, string designation = "") {
            this.number = number;
            this.designation = designation;
        }

        public int CompareTo(object obj) {
            A rhs = obj as A;

            if (number < rhs.number)
                return -1;
            else if (number > rhs.number)
                return 1;
            else
                return 0;
        }

        static A() {
            array = new A[] {
                new A(4, "few"),
                new A(9, "several"),
                new A(19, "pack"),
                new A(49, "lots"),
                new A(99, "horde"),
                new A(249, "throng"),
                new A(499, "swarm"),
                new A(999, "zounds"),
                new A(2001, "legion")
            };
        }

        private readonly int number;
        private readonly string designation;
        private readonly static A[] array;
    }

    private static void Main() {
        int noMonsters = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(A.GetDesignation(noMonsters));
    }
}