## Linked list

![[structure-of-a-singly-linked-list.png]]

Example class :

```c++
class list_int{

public:
	list_int(); //default constructor
	list_int(const list_int& s); // copy contructor
	~list_int(); // distruttore
	void append(int e);
	void prepend(int e);

private:
	struct cell{
		int info;
		cell* next;
	};
	typedef cell* Pcell;
	Pcell h;

	void append_ric

}




```



## Double linked list

## Vector

