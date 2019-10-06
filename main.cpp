// --------------------------------------------------------------------------------
// AUTHOR: Jason Luckow
//Collaborators: Matthew Padgett, Harrison Spencer, Coby Kromis (Function design)

// FILENAME: Lab1.cpp

// SPECIFICATION: To get familiar with linked lists and perform math, logical,
//					and common linked list operations.

// FOR: CS 2413 Data Structure Lab Section 503

// TEST CASES for Create Linked List and display:
// Test case1: Creates linked list from txt file from Blackboard
// Input: Stuct node
// Output:linked list rom Blackboard

// TEST CASES for Insertions:
// Test case1: Displays how insertions can happen at the beginning, end, and after a node
// Input: Struct node, float
// Output: shows insertions into created list 

// TEST CASES for Deletions:
// Test case1: Displays how deletions can happen at the beginning, end, and at specific node
// Input: Stuct node, float (for specific node)
// Output: shows that nodes have been deleted

// TEST CASES for Min/Max:
// Test case1: Displays the min and max of the linked list
// Input: Struct node
// Output:shows min/max

// TEST CASES for Linked List Stats:
// Test case1: Displays mean, median, mode, and range of the linked list
// Input: Struct node
// Output: shows mean, median, mode, and range

// TEST CASES for Delete duplications:
// Test case1: Deletes duplicates in linked list
// Input: Struct node
// Output: deletes duplicates

// TEST CASES for insertInOrder:
// Test case1: inserts a number in the order that it should go in a sorted list
// Input: Struct node, float
// Output: shows inserted number in a sorted list

// --------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>

using namespace std;

struct node{
    float data;
    struct node *next;
};

typedef node NODE;

NODE *start = NULL;

//Functions
NODE *create_ll(NODE *);
// NAME: create_ll
// INPUT PARAMETERS: Stuct node 
// OUTPUT: Creates linked list
// PURPOSE: to create a linked list

NODE *display(NODE *);
// NAME: display
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays linked list
// PURPOSE: to display the linked list created

NODE *sort_list(NODE *);
// NAME: sort_list
// INPUT PARAMETERS: Stuct node
// OUTPUT: sorts linked list
// PURPOSE: Tto sort linked list

NODE *delete_duplicates(NODE *);
// NAME: remove_duplicates
// INPUT PARAMETERS: Stuct node
// OUTPUT: shows linked list with no duplicates
// PURPOSE: to delete duplicates in linked list

NODE *find_max(NODE *);
// NAME: find_max
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays the max in the linked list
// PURPOSE: to find max in linked list

NODE *find_min(NODE *);
// NAME: find_min
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays the min in the linked list
// PURPOSE: to find min in linked list

NODE *find_mean(NODE *);
// NAME: find_mean
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays the mean in the linked list
// PURPOSE: to find mean in linked list

NODE *find_median(NODE *);
// NAME: find_median
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays the median in the linked list
// PURPOSE: to find median in linked list

NODE *find_mode(NODE *);
// NAME: find_mode
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays the mode in the linked list
// PURPOSE: to find mode in linked list

NODE *find_range(NODE *);
// NAME: find_range
// INPUT PARAMETERS: Stuct node
// OUTPUT: displays the range in the linked list
// PURPOSE: to find range in linked list

NODE *insert_beg(NODE *, float);
// NAME: insert_beg
// INPUT PARAMETERS: Stuct node, float for number needing to be inserted
// OUTPUT: float at beginning of linked list
// PURPOSE: to insert a number at beginning of linked lsit

NODE *insert_end(NODE *, float);
// NAME: insert_end
// INPUT PARAMETERS: Stuct node, float for number needing to be inserted
// OUTPUT: A float number at the beginning of linked list
// PURPOSE: to insert a number at end of linked lsit

NODE *insert_after(NODE *, float, float);
// NAME: insert_after
// INPUT PARAMETERS: Stuct node, float for number needing to be inserted, float for number after
// OUTPUT: A float number after a node in the linked list
// PURPOSE: to insert a number after a node in linked list

NODE *insertInOrder(NODE *, float);
// NAME: insertInOrder
// INPUT PARAMETERS: Stuct node, float for number needing to be inserted
// OUTPUT: A float number in a sorted linked list
// PURPOSE: to insert a number in a sorted linked list

NODE *delete_beg(NODE *);
// NAME: delete_beg
// INPUT PARAMETERS: Stuct node
// OUTPUT: removes float number from beginning of linked list
// PURPOSE: delete node at beginning of linked list

NODE *delete_end(NODE *);
// NAME: delete_end
// INPUT PARAMETERS: Stuct node
// OUTPUT: removes a float number from the end of linked list
// PURPOSE: delete node at end of linked list

NODE *delete_node(NODE *, float);
// NAME: delete_node
// INPUT PARAMETERS: Stuct node, float for node needing to be deleted
// OUTPUT: removes specific node from linked list
// PURPOSE: delete specific node in linked list
// --------------------------------------------------------------------------------
int main(int argc, char *argv[]){

	cout<< "Test Case for Create Linked lists\n";
	start = create_ll(start);
	start = display(start);
		
	cout<< "Test Case for Insertions\n";
	start = insert_beg(start, 40.29);
	start = insert_end(start, 10.5);
	start = insert_after(start, 31.42, 70.34);
	start = display(start);
		
	cout<< "Test Case for Deletions\n";
	start = delete_beg(start);
	start = delete_end(start);
	start = delete_node(start, 31.40);
	start = display(start);
		
	cout<< "Test Case for Min/Max\n";
	start = find_max(start);
	start = find_min(start);
		
	cout<< "\nTest Case for Linked List Stats\n";
	start = find_range(start);
	start = find_mean(start);
	start = find_median(start);
	start = find_mode(start);
		
	cout<< "Test Case for Delete Duplications\n";
	start = delete_duplicates(start);
	start = display(start);
		
	cout<< "Test Case for insertInOrder\n";
	start = insertInOrder(start, 58.25);
	start = display(start);
		
	system("pause");
	return 0;
}

NODE *create_ll(NODE *start){
	
	FILE *fp;
	float val;
	NODE *new_node, *ptr;
	
	fp = fopen("../FloatLinkedListInput.txt", "r");
	
	if(fp == NULL) {
		
		printf("File could not be opened.");
		
		system("pause");
		exit(0);
	}
	
	fscanf(fp, "%f", &val);
	
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> data = val;
	new_node -> next = NULL;
	
	start = new_node;
	ptr = start;
	
	while(fscanf(fp, "%f", &val) != -1) {
		
		new_node = (NODE*)malloc(sizeof(NODE));
		new_node -> data = val;
		new_node -> next = NULL;
		
		ptr -> next = new_node;
		ptr = new_node;
		
	}

	fclose(fp);
	return start;
}

NODE *display(NODE *start){
	
	NODE *ptr;
	ptr = start;
	
	while(ptr != NULL)
	{
		cout << ptr -> data << "\t";
		ptr = ptr -> next;
	}
	
	cout << "\n";
	
	cout << endl;
	return start;
}

NODE *sort_list(NODE *start){
	
	NODE *ptr1, *ptr2;
	float temp;
	ptr1 = start;
	
	while(ptr1 -> next != NULL){
		
		ptr2 = ptr1 -> next;
		
		while(ptr2 != NULL){
			
			if(ptr1 -> data > ptr2 -> data){
				
				temp = ptr1 -> data;
				ptr1 -> data = ptr2 -> data;
				ptr2 -> data = temp;
				
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return start; // Had to be added
}

NODE *delete_duplicates(NODE *start){
	
	NODE *ptr, *pre, *Temp;
	
	sort_list(start);
	
	ptr = start -> next;
	pre = start;
	
	while (ptr -> next != NULL){
		
		if (pre -> data == ptr -> data){
			
			Temp = ptr;
			ptr = ptr -> next;
			pre -> next = ptr;
			free(Temp);
			
		}
		
		else{
			
			pre = ptr;
			ptr = ptr -> next;
			
		}
	}
	return start;
}

NODE *find_max(NODE *start){
	
	start = sort_list(start);
	NODE *ptr = start;
	
	while(ptr -> next != NULL){
		
		ptr = ptr -> next;
		
	}
	
	cout << "\nMax: "<< ptr->data<<endl;
	return start;
}

NODE *find_min(NODE *start){
	
	start = sort_list(start);
	cout <<"\nMin: "<< start->data<<endl;
	
	return start;
}

NODE *find_mean(NODE *start){
	
	NODE *ptr;
	int count = 0;
	float sum = 0;
	ptr = start;
	
	while(ptr != NULL){
		
		sum += (ptr -> data);
		count++;
		ptr = ptr -> next;
		
	}
	cout << "Mean: " << sum / count<< "\n\n";
	
	return start;
}

NODE *find_median(NODE *start){
	
	NODE *ptr;
	float count = 0, median = 0, mid = 0;
	ptr = start;
	
	while(ptr != NULL){
		
		ptr = ptr -> next;
		count++;
		
		}
	
	ptr = start;
	
	if((int)count % 2 == 0){
		count = floor((count + 1) / 2) - 1;
		
		for(mid = 0; mid < count; mid++)
			ptr = ptr -> next;
		median = (ptr -> data + ptr -> next -> data) / 2;
	}
	else {
		count = ((count + 1) / 2) - 1;
			
		for(mid = 0; mid < count; mid++)
			ptr = ptr -> next;
		median = ptr -> data;
	}
	
	cout << "Median: " << median << "\n";
	
	return start;
}

NODE *find_mode(NODE *start){
	
	int modecount = 0, count = 0; 
	float current, mode;
	NODE *ptr;
	
	ptr = start;
	
	current =  ptr -> data;
	
	if(ptr -> next != NULL){
		while(ptr -> next != NULL){
			if(current == ptr -> data)
				count++;
			if(ptr -> data == mode)
				modecount++;
			if(count > modecount){
				modecount = count;
				mode = current;
			}
			if(current != ptr -> data){
				count = 0;
				current = ptr -> data;
			}
			ptr = ptr->next;
		}
	}
	else
		mode = ptr -> data;
		
	cout<<"\nMode is: "<< mode<<"\n\n";
	
	return start;
}

NODE *find_range(NODE *start){
	
	NODE *ptr = start;
	
	while(ptr -> next != NULL){
		
		ptr = ptr -> next;
		
	}
	
	cout <<"\nRange: "<< ptr->data - start->data <<"\n\n";
	
	return start;
}

NODE *insert_beg(NODE *start, float num){
	
	NODE *new_node;
	
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node -> data = num;
	new_node -> next = start;
	start = new_node;
	
	return start;
}

NODE *insert_end(NODE *start, float num){
	
	NODE *ptr, *new_node;
	
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node -> data = num;
	new_node -> next = NULL;
	ptr = start;
	while(ptr -> next != NULL)
	ptr = ptr -> next;
	ptr -> next = new_node;
	
	return start;
}

NODE *insert_after(NODE *start, float num, float val){
	
	NODE *new_node, *ptr, *preptr;
	
	new_node = (NODE *)malloc(sizeof(NODE));
	new_node -> data = num;
	ptr = start;
	preptr = ptr;
	
	while(preptr -> data != val && ptr -> next != NULL){
		
		preptr = ptr;
		ptr = ptr -> next;
		
	}
	
	if (preptr -> data == val){
		
		preptr -> next=new_node;
		new_node -> next = ptr;
		
		} 
		else{
		
		cout << "\nERROR: That value does not exist in this list!\n\n";
		
		}
	
	return start;
}

NODE *insertInOrder(NODE *start, float num){
	
	NODE *pre, *ptr, *new_node = (NODE*)malloc(sizeof(NODE));
	
	if(start == NULL){
		
		start = create_ll(start);
		
		return start;
	}
	
	start = sort_list(start);
	ptr = start;
	new_node -> data = num;
	
	if(ptr -> data > num){
		
		new_node -> next = ptr;
		start = new_node;
		
		return start;
		}
	
	while(ptr -> next != NULL){
		
		if(ptr -> data == num){
			
			new_node -> next = ptr -> next;
			ptr -> next = new_node;
			
			return start;
			}
			
		pre = ptr;
		ptr = ptr -> next;
		
		if(pre -> data < num && ptr -> data > num){
			
			new_node -> next = ptr;
			pre -> next = new_node;
			
			return start;
		
		}
	}
	
	new_node -> next = NULL;
	ptr -> next = new_node;
	
	return start;
}

NODE *delete_beg(NODE *start){
	
	NODE *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	
	return start;
}

NODE *delete_end(NODE *start){
	
	NODE *ptr, *preptr;
	ptr = start;
	
	while(ptr -> next != NULL){
		
		preptr = ptr;
		ptr = ptr -> next;
		
	}
	
	preptr -> next = NULL;
	free(ptr);
	
	return start;
}

NODE *delete_node(NODE *start, float val){
	
	NODE *ptr, *preptr;

	ptr = start;
	
	if(ptr -> data == val){
		
		start = delete_beg(start);
		
		return start;
	}
	else{
		while(ptr -> data != val){
			
			preptr = ptr;
			ptr = ptr -> next;
			
			}
		preptr -> next = ptr -> next;
		free(ptr);
		
		return start;
	}
}
