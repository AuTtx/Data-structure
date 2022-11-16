//
// Created by �쿡�� on 2022/10/12.
//

#include <cstddef>
#include "iostream"

using namespace std;

template<typename T>
struct LinkNode                //��ջ�������
{
    T data;                    //������
    LinkNode *next;                //ָ����
    LinkNode() : next(NULL) {}            //���캯��
    LinkNode(T d) : data(d), next(NULL) {}    //���ع��캯��
};

template<typename T>
class STACK                    //��ջ��ģ��
{
public:
    LinkNode<T> *rear;                //��ջβ���ָ��
    STACK() : rear(NULL) {}            //���캯��
    ~STACK()                    //��������
    {
        if (rear == NULL) return;            //������ֱ�ӷ���
        LinkNode<T> *pre = rear, *p = pre->next;
        while (p != rear) {
            delete pre;
            pre = p;
            p = p->next;            //pre��pͬ������
        }
        delete pre;
    }

    bool empty()                //��ջ���㷨
    {
        return rear == NULL;
    }

    bool push(T e)                  //��ջ�㷨
    {
        LinkNode<T> *p = new LinkNode<T>(e); //�½����p
        if (empty())              //ջΪ�յ����
        {
            rear = p;
            rear->next = rear;
        } else                      //ջ���յ����
        {
            p->next = rear->next;          //�����p���뵽���rear֮��
            rear->next = p;
        }
        return true;
    }

    bool pop(T &e)                //��ջ�㷨
    {
        LinkNode<T> *p;
        if (empty()) return false;    //ջ�յ����
        if (rear->next == rear)        //ջ��ֻ��һ���������
        {
            p = rear;
            rear = NULL;
        } else                    //ջ����2�������Ͻ������
        {
            p = rear->next;
            rear->next = p->next;
        }
        e = p->data;
        delete p;                //�ͷŽ��p
        return true;
    }

    bool gettop(T &e)            //ȡջ��Ԫ��
    {
        if (empty()) return false;    //ջ�յ����
        e = rear->next->data;
        return true;
    }

    T Getbottom()            //ȡջ��Ԫ��
    {
        return rear->data;
    }
};


int main() {
    int e;
    STACK<int> st;
    cout << "1��5��ջ" << endl;
    for (int i = 1; i <= 5; i++)
        st.push(i);
    cout << "ջ��Ԫ��: " << st.Getbottom() << endl;
    st.pop(e);
    cout << "��ջԪ��" << e << endl;
    st.pop(e);
    cout << "��ջԪ��" << e << endl;
    cout << "ջ��Ԫ��: " << st.Getbottom() << endl;
    return 0;
}

