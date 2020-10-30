#include "Stack.h"

template <class T>
class TMultiStack
{
protected:

    int stackCount;
    TStack<T>** stacks;

public:
    TMultiStack(int sizeStack = 1, int _stackCount = 1);
    TMultiStack(TMultiStack<T>& _v);
    ~TMultiStack();

    TMultiStack<T>& operator =(TMultiStack<T>& _v);

    void Push(T d, int i);
    T Get(int i);

    bool IsEmpty(int i) const;
    bool IsFull(int i) const;

    void Resize(int sizeStack = 1, int stackCount = 1);
};

template <class T>
TMultiStack<T> :: TMultiStack(int _sizeStack, int _stackCount)
{
    if (_stackCount < 1 || _sizeStack < 1)
    {
        throw "-1";
    }
    this->stackCount = _stackCount;
    stacks = new TStack <T> * [stackCount];
    for (int i = 0; i < stackCount; i++)
    {
        stacks[i] = new TStack<T>(_sizeStack);
    }
}

template <class T>
TMultiStack<T>::TMultiStack(TMultiStack<T>& _v)
{
    stackCount = _v.stackCount;
    stacks = new TStack <T> * [stackCount];
    for (int i = 0; i < stackCount; i++)
    {
        stacks[i] = new TStack<T>(1, fasle);
        *(stacks[i]) = *(_v.stacks[i]);
    }
}
template <class T>
TMultiStack<T> :: ~TMultiStack()
{
    if (stacks != 0)
    {
        for (int i = 0; i < stackCount; i++)
            delete[]stacks[i];

        delete[]stacks;
        stacks = 0;
    }
}

template<class T>
inline TMultiStack<T>& TMultiStack<T>::operator=(TMultiStack<T>& _v)
{
    if (this == _v)
    {
        return this;
    }
    if (stackCount != _v.stackCount)
    {
        for (int i = 0; i < stackCount; i++)
        {
            delete[]stacks[i];
        }
        delete[]stacks;
        stacks = new TStack<T> * [stackCount];
        for (int i = 0; i < stackCount; i++)
        {
            stacks[i] = new TStack<T>(1, true);
        }
    }
    stackCount = _v.stackCount;
    for (int i = 0; i < stackCount; i++)
    {
        *(stacks[i]) = *(_v.stacks[i]);
    }
}

template<class T>
inline void TMultiStack<T>::Push(T d, int i)
{
    if (i > stackCount || IsFull(i) || i<0)
    {
        throw - 1;
    }
    stacks[i]->Push(d);
}

template<class T>
inline T TMultiStack<T>::Get(int i)
{
    if (i < 0 || i > stackCount || IsEmpty(i))
    {
        throw - 1;
    }
    T d = stacks[i]->Get();
    return d;
}


template<class T>
inline bool TMultiStack<T>::IsEmpty(int i) const
{
    return stacks[i]->IsEmpty();
}

template<class T>
inline bool TMultiStack<T>::IsFull(int i) const
{
    return stacks[i]->IsFull();
}

template<class T>
inline void TMultiStack<T>::Resize(int sizeStack, int stackCount)
{
    if (stackCount < 1 || sizeStack < 1)
    {
        throw "-1";
    }
    for (int i = 0; i < this->stackCount; i++)
    {
        delete[]stacks[i];
    }
    delete[]stacks;
    stacks = 0
    this->stackCount = _stackCount;
    stacks = new TStack <T> * [stackCount];
    for (int i = 0; i < stackCount; i++)
    {
        stacks[i] = new TStack<T>(_sizeStack);
    }
}
