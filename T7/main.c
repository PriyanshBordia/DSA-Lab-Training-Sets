#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctype.h>

char town[] = "VILL: RUPA KI NANGAL";

struct Huff 
{
    int freq;
    char alpha;
    struct Huff *left;
    struct Huff *right;
    struct Huff *parent;
};

void heapifyUp(int index);
void heapifyDown(int index);

char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int freq[] = {21912, 16587, 14810, 14003, 13318, 12666, 11450, 10977, 10795, 7874, 7253, 5246, 4943, 4761, 4200, 3853, 3819, 3693, 3316, 2715, 2019, 1257, 315, 205, 188, 128};

// int freq[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// int freq[] = {3,0,0,0,0,0,1,0,2,0,2,3,0,2,0,1,0,1,0,0,1,1,0,0,0,0};

struct Huff alphabet[26];   	// External nodes of Huffman tree. 
struct Huff *heap[30];
int heapSz = 0; 				// index 0 is not used in this heap

void initAlphaNodes(void) 
{
	/* Fill freq data in array alphabet. 
			Alphabets are External nodes in our Huffman tree.
				External nodes are declared in our code. 
	*/
	for (int i = 0; i < 26; i++) 
	{
		alphabet[i].alpha = letters[i]; 
		alphabet[i].freq = freq[i]; 
		alphabet[i].left = NULL; 
		alphabet[i].right = NULL;
	} 
}

struct Huff *makeHuffNode(int freq, struct Huff *left, struct Huff *right) 
{
	struct Huff *newNode = malloc(sizeof(struct Huff)); 

	assert (newNode != NULL);
	
	newNode->alpha = ' '; 		// symbol marks internal node 
	newNode->freq = freq;
	newNode->right = right; 
	newNode->left = left; 

	if (left != NULL) 
	{
		left->parent = newNode; 
		
		if (left->alpha == ' ')
			left->alpha = '0';
	}

	if (right != NULL) 
	{
		right->parent = newNode;
		right->alpha = '1'; 
	}
		
	return newNode;
}

void addToHeap(struct Huff *newNode) 
{ 
	assert(heapSz < 30);	
	
	heap[++heapSz] = newNode;
	heapifyUp(heapSz); 				// Make the priority queue good. Creating a min heap
}

struct Huff *removeMin(void) 
{
   	assert (heapSz > 1);
		
	struct Huff *tmp = heap[1];
	heap[1] = heap[heapSz--]; 
	heapifyDown(1);
	return tmp;
}

void initExternalHeapNodes(void) 
{
	for (int i = 0; i < 26; i++) 				 
	{ 
		addToHeap(makeHuffNode(alphabet[i].freq, &alphabet[i], NULL));
	}
}

void swapAtIdx(int x, int y) 
{
	/* Used by heapify functions */
    struct Huff *tmp;

    tmp = heap[x]; 
    heap[x] = heap[y]; 
    heap[y] = tmp;
}

void heapifyUp(int index) 
{
	/* Removed about 10 lines of code */
	if (index <= 1)
		return;
	
	if (heap[index]->freq > heap[index / 2]->freq)
		return;

	else
	{
		swapAtIdx(index, index / 2);
		heapifyUp(index / 2);
		return;
	}
}

void heapifyDown(int parent) 
{
	int child = -1; 
	int child1 = 2*parent;
	int	child2 = 2*parent + 1;

	if (child1 > heapSz)																	//	|		|
		return;										  	
													 
	else if (child2 > heapSz)
	{	
		child = child1; 
		if (heap[parent]->freq > heap[child]->freq)
			swapAtIdx(parent, child);
		return;
	}
	
	else
	{
		if ((heap[parent]->freq > heap[child1]->freq) && (heap[parent]->freq > heap[child2]->freq))
		{	
			child = (heap[child1]->freq > heap[child2]->freq) ? child2 : child1;
			{
				swapAtIdx(parent, child);
				heapifyDown(child);
			}
		}

		else if (heap[parent]->freq > heap[child1]->freq)
		{
			child = child1;
			swapAtIdx(parent, child);
			heapifyDown(child);
		}

		else if (heap[parent]->freq > heap[child2]->freq)
		{
			child = child2;
			swapAtIdx(parent, child);
			heapifyDown(child);
		}
		
		else
			return;	
	}
}

int heapIsRootOnly(void) 
{ 
	return heapSz == 1;
}

void emitLetterCode(char c) 
{ 
	int i = c - 'A';
	struct Huff *bit = alphabet[i].parent; 

	while (bit != NULL) 
	{
		printf("%c", bit->alpha);	
		bit = bit->parent; 
	}
}

int main(void) 
{
	struct Huff *left, *right, *newNode, *node; 
 
    initAlphaNodes();
    initExternalHeapNodes();

	while (!heapIsRootOnly()) 
	{
		left = removeMin();
		if (heapIsRootOnly()) 
		{ 
			right = heap[1];
			heap[1] = makeHuffNode(left->freq + right->freq, left, right);
			break; 
		}
		
		right = removeMin(); 
		addToHeap(makeHuffNode(left->freq + right->freq, left, right));
	}
		/* Code town */
	printf("Words in %s are coded as follows\n", town); 
	
	int i = -1;
	while (town[++i] != '\0')
	{
		if (isspace(town[i]))
			printf("\n");
		
		else if (!isupper(town[i]))
			printf("\n%c", town[i]); 
		
		else
      		emitLetterCode(town[i]);
    }

    /*printf("Data in alphabet[] array:\n");
	for (int i = 1; i <= 26; ++i)
	{
		struct Huff *ptr = heap[i]->left;
		assert(ptr != NULL);
		printf("%c\t%d\n", ptr->alpha, ptr->freq);
	}*/
    
    printf("\n");
    return 0;
}
