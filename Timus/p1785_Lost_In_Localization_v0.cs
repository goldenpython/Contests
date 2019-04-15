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
    private class NumberDesignation : IComparable {
        public static string GetDesignation(int number) {
            int index = Array.BinarySearch<NumberDesignation>(array, new NumberDesignation(number));
            if (index < 0)
                index = ~index;

            return array[index].designation;
        }

        private NumberDesignation(int number, string designation = "") {
            this.number = number;
            this.designation = designation;
        }

        public int CompareTo(object obj) {
            NumberDesignation rhs = obj as NumberDesignation;

            if (number < rhs.number)
                return -1;
            else if (number > rhs.number)
                return 1;
            else
                return 0;
        }

        static NumberDesignation() {
            array = new NumberDesignation[] {
                new NumberDesignation(4, "few"),
                new NumberDesignation(9, "several"),
                new NumberDesignation(19, "pack"),
                new NumberDesignation(49, "lots"),
                new NumberDesignation(99, "horde"),
                new NumberDesignation(249, "throng"),
                new NumberDesignation(499, "swarm"),
                new NumberDesignation(999, "zounds"),
                new NumberDesignation(2001, "legion")
            };
        }

        private readonly int number;
        private readonly string designation;
        private readonly static NumberDesignation[] array;
    }

    private static void Main() {
        int noMonsters = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(NumberDesignation.GetDesignation(noMonsters));
    }
}