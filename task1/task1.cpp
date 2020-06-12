// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>





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
			printf("\n%d\n", temp1->data);
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
			printf("\nTimer List 900: %lld", static_cast<long long int>(duration.count()));
		}
		temp1 = temp1->next;
	}
			
	//}
	
}

void Delete_list_element(list* head, int element)
{
	list* temp1 = head;
	list* temp2 = new list();
	list* temp3 = new list();
	
	auto start = std::chrono::high_resolution_clock::now();
	while (temp1 != NULL)
	{

		if (temp1->data == element-1)
		{
			
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
			
			//printf("\n%d\n",temp1->data);
			temp2 = temp1;//499
			temp1 = temp1->next;//500
			temp3 = temp1;
			temp3 = temp3->next;//501
			//printf("\n%d\n", temp2->data);
			temp2->next = temp3;
			temp2 = temp2->next;
			//delete temp1;
			//printf("\n%d\n", temp2->data);
			
			delete temp1, temp3;//500,501
			
			//temp2 = temp1;
			//printf("\n%d\n", temp2->data);//500
			//temp2 = temp2->next;
			//printf("\ntemp2: %d\n", temp2->data)

			printf("\nTimer List 500: %lld", static_cast<long long int>(duration.count()));
			break;
		}
		temp1 = temp1->next;


	}
	
}

void timer_arr900(int arr[])
{
	auto start = std::chrono::high_resolution_clock::now();
	
	int elem = arr[900];//found it

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	printf("\nArray List 900: %lld", static_cast<long long int>(duration.count()));
			
	
}

void timer_arr500(int arr[])
{
	int *reduced_arr = new int[999];
	int d = 0;
	int *arr2 = new int[100];
	int size = *(&arr2 + 1) - arr2;
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "\n" << size << "\n";
	//printf("\n%d\n", sizeof(reduced_arr[0]));
	for (int i = 0; i < 1000; i++)
	{

		if (arr[d] == 500)
		{
			//printf("\n%d\n", arr[d]);
			//auto stop = std::chrono::high_resolution_clock::now();
			//auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
			d++;
			//arr[d] = arr[d + 1];
			//printf("\n%d\n", arr[d]);
			//printf("\nArray List 500: %lld\n", static_cast<long long int>(duration.count()));
			//break;
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
	printf("\nArray List 500: %lld\n", static_cast<long long int>(duration.count()));
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

		int* arr = new int[1000];
		for (int i = 0; i < 1000; i++)
		{
			arr[i] = i+1;
			//printf("\n%d", arr[i]);
		}
		
		//Search_list_element(head, 602);
		//timer_arr900(arr);
		//Delete_list_element(head, 501);
		timer_arr500(arr);


		/*temp = head;
		while (temp != NULL)
		{
			printf("\n%d\n", temp->data);
			temp = temp->next;
		}*/

		//delete[] arr;
}


