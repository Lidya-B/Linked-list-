//*****************************************************************************************************
//
//		File:					node.h
//
//		This program will impliment and test a linked list class that uses nodes to store items.
//	
//		Other files required: 
//			1.	LDRIVER.cpp
//          2.  LList.h
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct node
{
	TYPE data;
	node<TYPE>* next;

	node();
	node(const TYPE& d, node<TYPE>* n = nullptr);
};

//*****************************************************************************************************

template<typename TYPE>
inline node<TYPE>::node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
inline node<TYPE>::node(const TYPE& d, node<TYPE>* n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif