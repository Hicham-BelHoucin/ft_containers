/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:31:30 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/08/22 16:49:45 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CPP code for inorder successor
// and predecessor of tree
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	Node* left,*right;
};

// Function to return data
Node* getnode(int info)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = info;
	p->right = NULL;
	p->left = NULL;
	return p;
}

/*
since inorder traversal results in
ascending order visit to node , we
can store the values of the largest
no which is smaller than a (predecessor)
and smallest no which is large than
a (successor) using inorder traversal
*/
void find_p_s(Node* root,int a,
			Node** p, Node** q)
{
	// If root is null return
	if(!root)
		return ;
		
	// traverse the left subtree
	find_p_s(root->left, a, p, q);
	
	// root data is greater than a
	if(root && root->data > a)
	{
		
		// q stores the node whose data is greater
		// than a and is smaller than the previously
		// stored data in *q which is successor
		if((!*q) || (*q) && (*q)->data > root->data)
				*q = root;
	}
	
	// if the root data is smaller than
	// store it in p which is predecessor
	else if(root && root->data < a)
	{
		*p = root;
	}
	
	// traverse the right subtree
	find_p_s(root->right, a, p, q);
}

// Driver code
int main()
{
	Node* root1 = getnode(14);
	root1->left = getnode(17);
	root1->right = getnode(11);
	root1->left->left = getnode(7);
	root1->left->right = getnode(53);
	root1->right->left = getnode(4);
	root1->right->right = getnode(13);
	root1->right->right = getnode(12);
	root1->right->right = getnode(8);
	Node* p = NULL, *q = NULL;

	find_p_s(root1, 53, &p, &q);
	
	if(p)
        std::cout << "Predecessor is : " << p->data << std::endl;
	if(q)
	    std::cout << "Successor is : " << q->data << std::endl;
	return 0;
}
