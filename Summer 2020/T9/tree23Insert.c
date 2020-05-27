#include "tree23.h"

struct node23 *toRoot = NULL;

/* Calls to insert2() and remove2() will use
	   these variables to tell their parents if
	   the parent node needs to accommodate a new
	   key after the call */

struct node23 *newRight = NULL; 
int newKey = 0;

static void insert2(node23p node, int data);
static void splitLeaf(node23p node, int data);
static insertInternal(node23p node, int data);

static node23p mkNode(int val) 
{
	node23p tmp = malloc(sizeof(struct node23)); assert(tmp != NULL);
	tmp->data[0] = val;
	tmp->data[1] = 0;
	tmp->countKeys = 1;
	tmp->subT[0] = tmp->subT[1] = tmp->subT[2] = NULL; 
	return tmp;
}

void insert(int data) 
{
	node23p oldRoot = toRoot;
	
	if (toRoot == NULL) 
	{
		toRoot = mkNode(data);
		return; 
	}

	newRight = NULL;
	insert2(toRoot, data);

	/* check if tree height needs increase */ 
	if (newRight != NULL) 
	{
		toRoot = mkNode(newKey); 
		toRoot->subT[0] = oldRoot; 
		toRoot->subT[1] = newRight;
	} 
}

static void insert2(node23p node, int data) 
{ 
	assert(node != NULL);
	int kys, temp;
	// Primarily to insert in a LEAF
	
	if (node->subT[0] == NULL) 
	{	// This is a leaf
		if (node->data[0] == data) 
			return; 	// Duplicate data
		
		if (node->countKeys == 2) 
		{ // Full leaf node 
			if (node->data[1] == data)
				return; // Duplication of data
		
		// Tell parent to care for new right sibling. 
			splitLeaf(node, data);
			return;
		}

		// Add data in this leaf node 
		node->data[node->countKeys] = data; 
		node->countKeys += 1;
		kys = node->countKeys-1;
		
		while (kys>0) 
		{
			if (node->data[kys-1] <= node->data[kys]) 
				return; // Node set up
			
			// Swap

			temp = node->data[kys-1]; 
			node->data[kys-1] = node->data[kys]; 
			node->data[kys] = temp;
			return; 
		}
		
		// Insertion into an internal node
		
		assert(node->subT[0] != NULL && node->subT[1] != NULL); 
		assert(node->countKeys == 1 || node->subT[2] != NULL); 
	
	/* When inserting data at an internal node there are
		two phases of importance. So we separately code it */ 
		insertInternal(node, data);
}

static void splitLeaf(node23p node, int data) 
{
	// Use newRight to tell the parent to update. 
	assert(node->countKeys == 2);

	int temp = node->data[1];
	node->countKeys -= 1; 

	if (temp < data) 
	{
		newRight = mkNode(data); 
		newKey = temp;
		return;
	}

	newRight = mkNode(node->data[1]); 

	if (node->data[0] < data) 
	{
		newKey = data;
		return; 
	}

	newKey = node->data[0]; 
	node->data[0] = data; 
	return;
}

static insertInternal(node23p node, int data) 
{
   // Not a leaf node
	int kys;
	int median;
	int who; // Subtree index
	
	node23p newSibling;
	
	assert(node != NULL);
	assert(node->subT[0] != NULL);
	
	newRight = NULL; // Perhaps superflous
	
	/* If duplicate data do not insert */
	if (node->data[0] == data) 
		return;
	
	if (node->countKeys == 2 && node->data[1] == data) 
		return;

	if (node->data[0] > data) 
	{ 
		who = 0;
		insert2(node->subT[0], data);
	} 

	else if (node->countKeys == 2 && node->data[1] < data) 
	{
		who = 2;
		insert2(node->subT[2], data); 
	} 

	else 
	{
		who = 1; 
		insert2(node->subT[1], data);
	}
	   
	/* On return determine if this node is obliged to accommodate
				a new key? */
	if (newRight == NULL) // All done
		return;

	if (node->countKeys == 1) 
	{ // There is space for key 2
		node->countKeys += 1;

		switch (who) 
		{
			case 0:
				node->subT[2] = node->subT[1]; 
				node->data[1] = node->data[0]; 
				node->data[0] = newKey; 
				node->subT[1] = newRight; 
				newRight = NULL;
				return;
			
			case 1:
				node->subT[2] = newRight;
				newRight = NULL; 
				node->data[1] = newKey; 
				return;
		}
	}

	switch (who) 
	{
		case 2: // newKey is largest key
			newSibling = mkNode(newKey); 
			newSibling->subT[1] = newRight; 
			newSibling->subT[0] = node->subT[2]; 
			node->subT[2] = NULL; 
			node->countKeys -= 1;
			newKey = node->data[1]; 
			newRight = newSibling; 
			return;
			
		case 1: // Right key in node is largest 
			newSibling = mkNode(node->data[1]);
			newSibling->subT[1] = node->subT[2];
			newSibling->subT[0] = newRight;
			node->subT[2] = NULL; 
			node->countKeys -= 1; 
			newRight = newSibling; 
			return;
		
		case 0: // newKey is smallest
			newSibling = mkNode(node->data[1]); 
			newSibling->subT[1] = node->subT[2]; 
			newSibling->subT[0] = node->subT[1]; 
			node->subT[2] = NULL;
			median = node->data[0]; // Median key 
			node->data[0] = newKey; 
			node->subT[1] = newRight; 
			node->countKeys -= 1;
			newKey = median;
			newRight = newSibling;
			return;
	}
}
