// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>



#define ARRAY_SIZE 1000

class list {
public:
	list* next;
	int data;

	list(int data1)
	{
		data = data1;
		next = NULL;
	}

	list() {};
};

void Search_list_element(list* head,int element)
{
	list* temp1 = head;
	
	auto start = std::chrono::high_resolution_clock::now();
	//for(int i=0; i<900; i++)
	//{
	while (temp1->next != NULL)
	{
		
		if (temp1->data == element)
		{
			break;
			
		}
		temp1 = temp1->next;
	}
			
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	printf("\nSearch_list_element: %lld", static_cast<long long int>(duration.count()));
	
}

void Delete_list_element(list* head, int element)
{
	list* current = head;
	//list* next = NULL;
	list* prev = NULL;
	
	auto start = std::chrono::high_resolution_clock::now();
	while (current != NULL)
	{
		
		//printf("\n%d\n", prev->data);
		
		if (current->data == element)
		{
			
			if (prev == NULL) {
				//printf("\n%d\n", current->data);
				head = head->next;
				delete current;
				break;
			}
			
			prev->next = current->next;
			delete current;
			//printf("\n%d\n", prev->data);
			
			break;
		}
		
		//printf("\n%d\n", prev->data);
		prev = current;
		//next = current->next;
		current = current->next;

	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	printf("\nDelete_list_element: %lld", static_cast<long long int>(duration.count()));
	
}

void timer_arr900(int arr[], int element)
{
	auto start = std::chrono::high_resolution_clock::now();
	if (element < ARRAY_SIZE && element >= 0) {
		int elem = arr[element];//found it
	}
	

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	printf("\nSearch_array_elem: %lld", static_cast<long long int>(duration.count()));
			
	
}

void timer_arr_reduced500(int arr[], int element)
{
	int *reduced_arr = new int[ARRAY_SIZE-1];
	int d = 0;
	
	auto start = std::chrono::high_resolution_clock::now();
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
	

		if (arr[d] == element)
		{
			
			d++;
			
		}
		reduced_arr[i] = arr[d];
		d++;
		
		
	}

	//for (int i = 0; i < 1000; i++)
	//{
	//	printf("\n%d\n", reduced_arr[i]);
	//}
	//
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	printf("\nDelete_array_elem: %lld\n", static_cast<long long int>(duration.count()));
	delete[] arr;
}



int main()
{
	
		list* head = NULL;
		head = new list(1);

		list* newlist,* temp;
		temp = head;
		for (int i = 2; i <= 1000; ++i)
		{
			newlist = new list(i);
			
			temp->next = newlist;
			temp = temp->next;		
		}

		int* arr = new int[ARRAY_SIZE];
		for (int i = 0; i < 1000; i++)
		{
			arr[i] = i+1;
			//printf("\n%d", arr[i]);
		}
		
		Search_list_element(head, 602);
		timer_arr900(arr, 602);
		Delete_list_element(head, 1000);
		timer_arr_reduced500(arr, 1000);

}


