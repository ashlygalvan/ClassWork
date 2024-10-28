/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350 - 02
PA3: Do You See What I See?
*/
#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <iostream>
#include <cstdlib>
using namespace std;


template <typename T>
class MonoStack
{
    public:
        MonoStack();
        MonoStack(int size, char o);
        virtual ~MonoStack();
        void push(T data);
        T pop();
        T top();
        int size();
        bool isEmpty();

    private:
        T* stackArr; //an array
        char decreaseOincrease; //this will take in the char that determines if the stack is eaither an increasing or decreasing onotonic stack
        int count; //current size that the arr is at
        int topIndex; //top of the index
        int max;
    
};

template <typename T>
MonoStack<T>::MonoStack()//constructor
{
    count = 0;
    max = 0;
    stackArr = NULL;
    topIndex =-1;
}

template <typename T>
MonoStack<T>::MonoStack(int size, char o)//defeault constructor
{
    count = 0;
    max = size;
    decreaseOincrease = o;
    topIndex = -1;
    stackArr = new T[max];
    
}

template <typename T>
MonoStack<T>:: ~MonoStack()//deconstructor
{
    if (stackArr != NULL)
    {
        delete[] stackArr;
    }
}

template <typename T>
T MonoStack<T>:: pop()//this will return the value of the top index in the array and then remove it
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        //BEGIN CODE FROM SOURCE: CHATGPT
        return T();//return the default value of T 
        //END CODE FROM CHATGPT 
    }
    T res = stackArr[topIndex--];
    --count; //decrease count first
    return res;
}

template <typename T>
T MonoStack<T> :: top()//returns what is on top of the stack
{
    if (topIndex >= 0)
    {
        return stackArr[topIndex];
    }else
    {
        cout << "Stack is empty" << endl;
        return T();
    }
} 

template <typename T>
void MonoStack<T>:: push(T data)//this first intakes what type of stack we are doing based off the constructor either decreading == d or increasing == i
{
    if(decreaseOincrease == 'd')
    {
        while(!isEmpty() && stackArr[topIndex] < data)
        {
            pop();
        }
    }else if (decreaseOincrease == 'i')
    {
        while(!isEmpty() && stackArr[topIndex] > data)
        {
            pop();
        }
    }else
    {
        return;//not a valid char for the stack
    }
    if (topIndex < max -1)
    {
        ++topIndex;
        stackArr[topIndex] = data;
        count++;
    }else
    {
        cout << "Full stack. " << endl;
    }
}

template <typename T>
int MonoStack<T>:: size()
{
    return count; //return current size
}

template <typename T>
bool MonoStack<T>:: isEmpty()
{
    return (topIndex == -1); //checks if the stack is empty
}

#endif