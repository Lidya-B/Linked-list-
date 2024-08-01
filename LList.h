//*****************************************************************************************************
//
//		File:					LList.h 
//
//		This program will impliment and test a linked list class that uses nodes to store items.
//	
//		Other files required: 
//			1.	node.h
//          2.  LDRIVER.cpp
//			
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//*****************************************************************************************************

#include"node.h"
#include <new>

//*****************************************************************************************************

template<typename TYPE>
class llist
{
private:
	node<TYPE>* front;
public:
	llist();
	~llist();
	bool insert(const TYPE& datain);
	bool remove(TYPE& dataout);
	bool retrive(TYPE& dataout)const;
	bool viewfront(TYPE& detaout)const;
	bool viewrear(TYPE& dataout)const;
	void display()const;
	int getNumVals()const;
	bool isempty()const;
	bool isfull()const;

};

//*****************************************************************************************************

template<typename TYPE>
llist<TYPE>::llist()
{
	front = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
llist<TYPE>::~llist()
{
	node<TYPE>* ptemp;
	while (front)
	{
		ptemp = front;
		front = front->next;
		delete ptemp;
	}
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::insert(const TYPE& datain)
{
	bool success = false;

	node<TYPE>* pbefore;
	pbefore= nullptr;
	node<TYPE>* pafter;
	pafter= front;
	node<TYPE>* pnew;

	while ((pafter) && (pafter->data < datain))
	{
		pbefore = pafter;
		pafter = pafter->next;
	}

	pnew = new (nothrow)node<TYPE>(datain, pafter);

	if (pnew)
	{
		if (pbefore)
		{
			pbefore->next = pnew;
		}
		else
		{
			front = pnew;
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::remove(TYPE& dataout)
{
	bool success = false;

	node<TYPE>* ptemp;
	ptemp= front;
	node<TYPE>* pbefor;
	pbefor= nullptr;

	while ((ptemp) && (ptemp->data < dataout))
	{
		pbefor = ptemp;
		ptemp = ptemp->next;
	}

	if ((ptemp) && (ptemp->data == dataout))
	{

		dataout = ptemp->data;
		if (pbefor)
		{
			pbefor->next = ptemp->next;
		}
		else
		{
			front = ptemp->next;
		}

		delete ptemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::retrive(TYPE& dataout) const
{
	bool success = false;

	node<TYPE>* ptemp;
	ptemp= front;

	while ((ptemp) && (ptemp->data < dataout))
	{
		ptemp = ptemp->next;
	}

	if ((ptemp) && (ptemp->data == dataout))
	{
		dataout = ptemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::viewfront(TYPE& detaout) const
{
	bool success = false;

	if (front)
	{
		detaout = front->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::viewrear(TYPE& dataout) const
{
	bool success = false;

	node<TYPE>* ptemp;
	ptemp= front;

	while ((ptemp) && (ptemp->next))
	{
		ptemp = ptemp->next;
	}

	if (ptemp)
	{
		dataout = ptemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
void llist<TYPE>::display() const
{
	node<TYPE>* ptemp;
	ptemp= front;

	while (ptemp != nullptr)
	{
		cout << ptemp->data << ", ";
		ptemp = ptemp->next;
	}

}

//*****************************************************************************************************

template<typename TYPE>
int llist<TYPE>::getNumVals() const
{
	int count = 0;
	node<TYPE>* ptemp;
	ptemp= front;

	while (ptemp != nullptr)
	{
		count++;
		ptemp = ptemp->next;
	}

	return count;
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::isempty() const
{
	return (front == nullptr);
}

//*****************************************************************************************************

template<typename TYPE>
bool llist<TYPE>::isfull() const
{
	bool full = true;

	node<TYPE>* ptemp;
	ptemp= new(nothrow) node<TYPE>;

	if (ptemp)
	{
		delete ptemp;
		full = false;
	}

	return full;
}


//*****************************************************************************************************

#endif

//*****************************************************************************************************
