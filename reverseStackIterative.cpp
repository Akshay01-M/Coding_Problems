#include<bits/stdc++.h>
using namespace std;

class StackNode {
	public:
	int data;
	StackNode *next;
	
	StackNode(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Stack {
	
	StackNode *top;
	
	public:
	
	void push(int data)
	{
		if (top == NULL) {
			top = new StackNode(data);
			return;
		}
		StackNode *s = new StackNode(data);
		s->next = top;
		top = s;
	}
	
	StackNode* pop()
	{
		StackNode *s = top;
		top = top->next;
		return s;
	}

	void display()
	{
		StackNode *s = top;
		while (s != NULL) {
			cout << s->data << " ";
			s = s->next;
		}
		cout << endl;
	}

	void reverse()
	{
		StackNode *prev, *cur, *succ;
		cur = prev = top;
		cur = cur->next;
		prev->next = NULL;
		while (cur != NULL) {

			succ = cur->next;
			cur->next = prev;
			prev = cur;
			cur = succ;
		}
		top = prev;
	}
};

int main()
{
	Stack *s = new Stack();
    int n, val;
    cout<<"Enter the number of elements : ";
    cin>>n;

    cout<<"Enter the elements : ";
    while(n--){
        cin>>val;
        s->push(val);
    }

	cout << "Original Stack" << endl;;
	s->display();
	cout << endl;
	
	s->reverse();

	cout << "Reversed Stack" << endl;
	s->display();
	
	return 0;
}

