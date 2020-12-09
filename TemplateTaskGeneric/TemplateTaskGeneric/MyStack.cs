using System;
using System.Collections.Generic;
using System.Reflection;
using System.Text;

namespace TemplateTaskGeneric
{
    class MyStack<T>
    {
        private int size;
        private int head;
        private T[] array;

        public MyStack(int size)
        {
            if (size > 0)
            {
                this.size = size;
                this.head = 0;
                this.array = new T[size];            }
            else
                throw new Exception("not correct size");
        }

        ~MyStack() {}

        public void push(T value)
        {
            if (head < size)
                array[head++] = value;
            else
                throw new Exception("Stack is full");
        }

        public T pop()
        {
            if (head > 0)
            {
                head--;
                return array[head];
            }
            else
                throw new Exception("Stack is empty");
        }

        public void PrintStack()
        {
            for (int i = 0; i < head; i++)
                Console.Write(array[i] + "\t");
            Console.WriteLine();
        }

        public static MyStack<T> StackUnion(MyStack<T> first, MyStack<T> second)
        {
            //размер нового стека это сумма размеров объединяемых
            MyStack<T> result = new MyStack<T>(first.size + second.size);

            //переписываем элементы которые записаны в первый стек
            while (result.head < first.head)
                result.push(first.array[result.head]);

            //переписываем из второго стека
            while (result.head - first.head < second.head)
                result.push(second.array[result.head - first.head]);

            return result;
        }


    }
}
