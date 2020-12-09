using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace TemplateTaskGeneric
{
    class MyBinaryTree<T> where T:IComparable<T>
    {
        private T data;
        private MyBinaryTree<T> parent;
        private MyBinaryTree<T> left;
        private MyBinaryTree<T> right;

        public MyBinaryTree(T data, MyBinaryTree<T> parent = null)
        {
            this.data = data;
            this.parent = parent;
        }

        public void add(T value)
        {
            if (value.CompareTo(this.data) < 0)
                if (left == null)
                    this.left = new MyBinaryTree<T>(value, this);
                else
                    this.left.add(value);
            else if (value.CompareTo(this.data) > 0)
                if (right == null)
                    this.right = new MyBinaryTree<T>(value, this);
                else
                    this.right.add(value);
            else if (value.CompareTo(this.data) == 0)
                throw new Exception("already here");
            else 
                throw new Exception("exception");
        }

        public void deleting(T value)
        {
            //если удаляемый элемент слева или справа то идём туда

            if (value.CompareTo(this.data) < 0)
                this.left.deleting(value);
            else if (value.CompareTo(this.data) > 0)
                this.right.deleting(value);
            else if (value.CompareTo(this.data) == 0)
            {
                MyBinaryTree<T> tempForDeleting = this;

                //если удаляемый узел не имеет потомков то просто очищаем
                if (this.left == null && this.right == null)
                {
                    if (this.parent.left == this)
                        this.parent.left = null;
                    else
                        this.parent.right = null;
                }
                //если потомок у него один то связываем его с родителем и очищаем удаляемый узел
                else if (this.left != null && this.right == null)
                {
                    this.left.parent = this.parent;
                    if (this == this.parent.left)
                    {
                        this.parent.left = this.left;
                    }
                    else if (this == this.parent.right)
                    {
                        this.parent.right = this.left;
                    }

                    tempForDeleting = null;
                }
                else if (this.left == null && this.right != null)
                {
                    this.right.parent = this.parent;
                    if (this == this.parent.left)
                    {
                        this.parent.left = this.right;
                    }
                    else if (this == this.parent.right)
                    {
                        this.parent.right = this.right;
                    }

                    tempForDeleting = null;
                }
                else if (this.left != null && this.right != null)
                {
                    //если потомка два

                    //идём влево
                    tempForDeleting = this.left;

                    //ищем самый правый узел
                    while (tempForDeleting.right != null)
                        tempForDeleting = tempForDeleting.right;

                    //переписываем оттуда значение
                    this.data = tempForDeleting.data;

                    //если слева у крайнего правового есть потомок
                    if (tempForDeleting.left != null)
                    {
                        //связываем родителя и потомка и очищаем узел
                        tempForDeleting.left.parent = tempForDeleting.parent;
                        tempForDeleting.parent.right = tempForDeleting.left;
                        tempForDeleting = null;
                    }
                    else
                        tempForDeleting.parent.right = null;
                }
            }
            else
                throw new Exception("exception");
        }

        public void getList(ref List<T> list)
        {
            if (this.left != null)
                this.left.getList(ref list);
            list.Add(this.data);
            if (this.right != null)
                this.right.getList(ref list);
        }

        public void print()
        {
            if (this.left != null)
                this.left.print();
            Console.Write(this.data + "\t");
            if (this.right != null)
                this.right.print();
        }

        public bool contains(T value)
        {
            if (value.CompareTo(this.data) == 0)
                return true;
            else if (value.CompareTo(this.data) < 0 && this.left != null)
                return this.left.contains(value);
            else if (value.CompareTo(this.data) > 0 && this.right != null)
                return this.right.contains(value);
            else return false;
        }

        public MyBinaryTree<T> getLeaf(T value)
        {
            if (value.CompareTo(this.data) == 0)
                return this;
            else if (value.CompareTo(this.data) < 0 && this.left != null)
                return this.left.getLeaf(value);
            else if (value.CompareTo(this.data) > 0 && this.right != null)
                return this.right.getLeaf(value);
            else return null;
        }

    }
}
