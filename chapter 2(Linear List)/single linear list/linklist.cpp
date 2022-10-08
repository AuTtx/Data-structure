#include<iostream>
using namespace std;

template<typename T>
struct LinkNode
{
	T data;
	LinkNode* next;
	LinkNode() :next(NULL) {}
	LinkNode(T d) :data(d), next(NULL) {}
};

template<typename T>
class LinkList {
public:
	LinkNode<T>* head;
	LinkList();
	~LinkList();
	void CreatListF(T a[], int n);
	void CreatListR(T a[], int n);
	LinkNode<T>* geti(int i);
	void Add(T e);
	int GetLength();
	bool GetElem(int i, T& e);
	bool SetElem(int i, T e);
	int GetNo(T e);
	bool Insert(int i, T e);
	bool Delete(int i);
	void DisplayList();

	T middle(LinkList<T>& L);// ����ָ�뷨��Ѱ������м�Ԫ��
	int maxcount(LinkList<T>& L);// ͳ��������Ԫ��data���Ľ�����
	void DeleteMaxNode(LinkList<T>& L);// ɾ�������
	void reverse(LinkList<T>& L);// ͷ�巨����˼��,������ת�� week3 question4
	void split(LinkList<T>& A, LinkList<T>& B);//week3 quesion1
	void NegativeFront(LinkList<T>& L);//week 3 quesion2
	int MaxElementNo(LinkList<T>& L);//week 3 question3
	void Combine(LinkList<T>& L1, LinkList<T>& L2, LinkList<T>& L);//week3 question6
	void DeleteSame(LinkList<T>& L);// week3 question7
	int MaxElemetLogicNo(LinkList<T>& L);//week3 question8

};

template<typename T>
LinkList<T>::LinkList()
{
	head = new LinkNode<T>();
}

template<typename T>
LinkList<T>::~LinkList()
{
	LinkNode<T>* p, * pre;
	pre = head, p = head->next;
	while (p != NULL)
	{
		delete pre;
		pre = p, p = p->next;
	}
	delete pre;//���һ������޺�̽ڵ㣬����Ҫ��ɾ��
}

template<typename T>
void LinkList<T>::CreatListF(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		LinkNode<T>* s = new LinkNode<T>(a[i]);//�������ݽ��s
		s->next = head->next;// �����s����head���֮��
		head->next = s;//ͷ�巨�������˳���ܻ����������������������෴
	}
}

template<typename T>
void LinkList<T>::CreatListR(T a[], int n)
{
	LinkNode<T>* s, * r;// sΪ���ݽ�㣬rΪβ���
	r = head;
	for (int i = 0; i < n; i++)
	{
		s = new LinkNode<T>(a[i]);
		r->next = s;//�����ݽ��嵽β���֮��
		r = s;
	}
	r->next = NULL;
}

template<typename T>
LinkNode<T>* LinkList<T>::geti(int i)
{
	if (i < -1) return NULL;
	LinkNode<T>* p = head;
	j = -1;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	return p;// j=i,�˳�ѭ��������p������p�Լ�ָ��β��㣬�򷵻�null��i=-1����δ����ѭ��������head���
}

template<typename T>
void LinkList<T>::Add(T e)
{
	LinkNode<T>* s = LinkNode<T>(e);
	LinkNode<T>* p = head;
	while (p->next != NULL)//���ҵ�β��㣬β�����ص�Ϊnextָ��ָ��null����������Ϊp->next��Ϊnull
	{
		p = p->next;
	}
	p->next = s;
}

template<typename T>
int LinkList<T>::GetLength()
{
	int cnt = 0;
	LinkNode<T>* p = head;
	while (p->next != NULL)
	{
		p = p->next;
		cnt++;
	}
	return cnt;
}

template<typename T>
bool LinkList<T>::GetElem(int i, T& e)
{
	if (i < 0)
	{
		return false;
	}
	LinkNode<T>* p = geti(i);
	if (p != NULL) {
		e = p->data;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool LinkList<T>::SetElem(int i, T e)
{
	if (i < 0)return false;
	LinkNode<T>* p = geti(i);
	if (p != NULL) {
		p->data = e;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
int LinkList<T>::GetNo(T e)
{
	int j = 0;
	LinkNode<T>* p = head->next;
	while (p->data != e && p != NULL )
	{
		j++;
		p = p->next;
	}
	if (p == NULL) {
		return -1;
	}
	else
	{
		return j;
	}
}

template<typename T>
bool LinkList<T>::Insert(int i, T e)
{
	if (i < 0)return false;
	LinkNode<T>* p = geti(i - 1);
	if (p != NULL) {
		LinkNode<T>* t = LinkNode<T>(e);
		t->next = p->next;
		p->next = t;
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool LinkList<T>::Delete(int i)
{
	if (i < 0)return false;
	LinkNode<T>* p = geti(i - 1);
	if (p != NULL)
	{
		LinkNode<T>* q = p->next;
		if (q != NULL) {
			p->next = q->next;
			delete q;
			turn true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<typename T>
void LinkList<T>::DisplayList()
{
	LinkNode<T>* p;
	p = head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<typename T>
T LinkList<T>::middle(LinkList<T> &L)
{
	LinkNode<T>* fast = L.head->next;
	LinkNode<t>* slow = L.head->next;
	while (fast != NULL && slow != NULL)
	{
		if (fast->next == NULL || fast->next->next == NULL)//���������Ϊ������fast->nextΪnull����֮fast->next->nextΪnull
		{
			return slow->data;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

template<typename T>
int LinkList<T>::maxcount(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next;
	T maxe = p->data;
	int cnt = 1;
	while (p->next != NULL)
	{
		if (p->next->data > maxe) {
			maxe = p->next->data;
			cnt = 1;
		}
		else if (p->next->data == maxe) {
			cnt++;
		}
		p = p->next;
	}
	return cnt;
}

template<typename T>
void LinkList<T>::DeleteMaxNode(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next;
	T maxe = p->data;
	while (p->next != NULL)// ȷ�������dataֵ
	{
		if (p->next->data > maxe)
			maxe = p->next->data;
		p = p->next;
	}
	LinkNode<T>* pre = L.head;
	p = pre->next;
	while (p != NULL)//�����P->next != NULL,���޷�������β��㣬��β�����ܱ�ɾ��
	{
		if (p->data == maxe) {
			pre->next = p->next;
			delete p;
			p = pre->next;
		}
		else {
			pre = pre->next;
			p = pre->next;
		}
	}

}

template<typename T>
void LinkList<T>::reverse(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next,*q;
	L.head->next = NULL;
	while (p!=NULL)
	{
		q = p->next;// q������ʱ����p�ĺ�̽��
		p->next = L.head->next;
		L.head->next = p;
		p = q;
	}
}

template<typename T>
void LinkList<T>::split(LinkList<T>& A, LinkList<T>& B)
{
	LinkNode<T>* p = A.head->next, * ra, * rb;
	ra = A.head;
	rb = B.head;
	while (p != NULL)
	{
		// pָ��ż�����
		if (p->data % 2 == 0) {
			ra->next = p;
			p = p->next;
		}
		else
		{
			rb->next = p;
			p = p->next;
		}
	}
	ra->next = NULL;
	rb->next = NULL;
}

template<typename T>
void LinkList<T>::NegativeFront(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next, * pre = p;
	while (p != NULL)
	{
		if (p->data < 0) {
			pre->next = p->next;
			p->next = L.head->next;
			L.head->next = p;
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

template<typename T>
int LinkList<T>::MaxElementNo(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next, * maxe = p;
	int i = 0;
	int maxi = 0;
	while (p != NULL)
	{
		if (maxe->data < p->data) {
			maxe = p;
			maxi = i;
		}
		p = p->next;
		i++;
	}
	return maxi;
}

template<typename T>
void LinkList<T>::Combine(LinkList<T>& L1, LinkList<T>& L2, LinkList<T>& L)
{
	LinkNode<T>* a = L1.head->next, * p;
	LinkNode<T>* b = L2.head->next, * q;
	while (a != NULL && b != NULL)
	{
		if (a->data < b->data) {
			p = a->next;
			a->next = L.head->next;
			L.head->next = a;
			a = p;
		}
		else
		{
			q = b->next;
			b->next = L.head->next;
			L.head->next = b;
			b = q;
		}
	}
	if (a != NULL)
	{
		while (a != NULL)
		{
			p = a->next;
			a->next = L.head->next;
			L.head->next = a;
			a = p;
		}
	}
	else
	{
		while(b != NULL)
		{
			q = b->next;
			b->next = L.head->next;
			L.head->next = b;
			b = q;
		}
	}
}

template<typename T>
void LinkList<T>::DeleteSame(LinkList<T>& L)
{
	LinkNode<T>* pre = L.head->next, * p = pre->next;
	while (p != L.head)
	{
		if (pre->data == p->data) {
			pre->next = p->next;
			delete p;
			p = pre->next;
		}
		pre = p;
		p = p->next;
	}

}

template<typename T>
int LinkList<T>::MaxElemetLogicNo(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next, * maxe = p;
	int i = 0;
	int maxi = 0;
	while (p != head)
	{
		if (maxe->data < p->data) {
			maxe = p;
			maxi = i;
		}
		p = p->next;
		i++;
	}
	return maxi;
}




