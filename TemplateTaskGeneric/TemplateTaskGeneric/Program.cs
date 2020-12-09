using System;
using System.Collections.Generic;

namespace TemplateTaskGeneric
{
    class Program
    {
        static void Main(string[] args)
        {
            MyBinaryTree<int> a = new MyBinaryTree<int>(10);

            a.add(8);
            a.add(9);
            a.add(3);
            a.add(-10);
            a.add(4);
            a.add(-11);
            a.add(-9);
            a.add(-5);
            a.add(-6);
            a.add(-7);

            a.deleting(3);
            Console.WriteLine();

            a.print();

            List<int> b = new List<int>();

            a.getList(ref b);
            Console.WriteLine();
            foreach (var el in b)
                Console.Write(el + "\t");

            for (int i = -15; i < 15; i++)
                Console.WriteLine(a.contains(i).ToString() + '\t' + i);

        }
    }
}
