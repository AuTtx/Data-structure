#include<iostream>
using namespace std;

const int initcap = 5;
template <typename T>
class SqList {
public:
    T* data;
    int capacity;
    int lenth;
    SqList();
    SqList(const SqList <T>& s);
    ~SqList();
    void recap(int newcap);
    void Createlist(T a[], int n);
    void add(T e);
    int getlenth();
    bool GetElem(int i, T& e);
    bool setElem(int i, T e);
    int GetNo(T e);
    bool insert(int i, T e);
    bool Delete(int i);
    void display();
    void delete_x(SqList<T>& s,int x);
};

//������˳���
template<typename T>
SqList<T>::SqList()
{
    capacity = initcap;
    data = new T[initcap];
    lenth = 0;
}

//�������Ҹ���˳���
template<typename T>
SqList<T>::SqList(const SqList<T>& s)
{
    capacity = s.capacity;
    lenth = s.lenth;
    data = new T[capacity];
    for (int i = 0; i < lenth; i++)
    {
        data[i] = s.data[i];
    }
}


template<typename T>
SqList<T>::~SqList()
{
    delete[] data;
}

template<typename T>
void SqList<T>::recap(int newcap)
{
    if (newcap <= 0) return;
    T* olddata = data;
    data = new T[newcap];
    capacity = newcap;
    for (int i = 0; i < lenth; i++)
    {
        data[i] = olddata[i];
    }
    delete[] olddata;
}

// ��һ����֪�������鴴��˳���,ǰ���Ǹ�˳����Ѿ�ʹ��Ĭ�Ϲ��췽������
template<typename T>
void SqList<T>::Createlist(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (capacity == lenth)
            recap(2 * lenth);
        data[lenth] = a[i];
        lenth++;
    }
}

template<typename T>
void SqList<T>::add(T e)
{
    if (lenth == capacity)
        recap(2 * lenth);
    data[lenth] = e;
    lenth++;//���ܳ���add��lenth = capacity,capacityδ���ݵ����
}

template<typename T>
int SqList<T>::getlenth()
{
    return lenth;
}

template<typename T>
bool SqList<T>::GetElem(int i, T& e)
{
    if (i < 0 || i >= lenth) {
        return false;
    }
    e = data[i];
    return true;
}

template<typename T>
bool SqList<T>::setElem(int i, T e)
{
    if (i < 0 || i >= lenth)
        return false;
    data[i] = e;
    return true;
}

template<typename T>
int SqList<T>::GetNo(T e)
{
    int i=0;
    while (i < lenth && data[i] != e)
        i++;
    if (i >= lenth)
        return -1;
    else
        return i;
}

template<typename T>
bool SqList<T>::insert(int i, T e)
{
    if (i< 0 || i>lenth)
        return false;
    if (lenth == capacity)
        recap(2 * lenth);
    for (int k = lenth; k > i; k--) {
        data[k] = data[k - 1];
    }
    data[i] = e;
    lenth++;
    return true;
}

template<typename T>
bool SqList<T>::Delete(int i)
{
    if (i < 0 || i >= lenth)
        return false;
    for (int j = i; j < lenth - 1; j++)
    {
        data[j] = data[j + 1];
    }
    lenth--;
    if (capacity > initcap && lenth <= capacity / 4)
        recap(capacity / 2);
    return true;
}

template<typename T>
void SqList<T>::display()
{
    for (int i = 0; i < lenth; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void SqList<T>::delete_x(SqList<T>& s, int x)// ɾ��˳����е�Ԫ��x,ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
{
    int k = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (s.data[i] != x) {
            s.data[k] = s.data[i];
            k++;
        }
    }
    s.lenth = k;
}




int main()
{
    int i, e;
    SqList<int> L;  //��������Ϊint��˳������L
    cout << "��������˳���L" << endl;
    L.insert(0, 2);	//����Ԫ��2
    L.insert(1, 3);	//����Ԫ��3
    L.insert(2, 1);	//����Ԫ��1
    L.insert(3, 5);	//����Ԫ��5
    L.insert(4, 4);	//����Ԫ��4
    L.insert(5, 1);	//����Ԫ��1
    L.add(8);		//�������8 
    cout << "˳���L:"; L.display();
    cout << "����:" << L.lenth << "  ����:"
        << L.capacity << endl;
    i = 3; L.GetElem(i, e);
    cout << "���Ϊ" << i << "��Ԫ��:" << e << endl;

}
