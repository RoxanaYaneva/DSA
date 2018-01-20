#include "stdafx.h"
#include "LinkedQueue.h"

#include<iostream>

void fillQueueOfQueues(LinkedQueue<LinkedQueue<int>>&);
LinkedQueue<int> concatenate(LinkedQueue<int>&, LinkedQueue<int>&);
LinkedQueue<int> mergeQueues(LinkedQueue<LinkedQueue<int>>&);

int main() {

	LinkedQueue<LinkedQueue<int>> qq;
	fillQueueOfQueues(qq);

	LinkedQueue<int> result = mergeQueues(qq);
	result.print();

	system("pause");
    return 0;
}

/* 
* This function makes user enter the queue of queues with numbers.
* First the user has to specify how many queues there will be in the main queue and then
* he has to enter the number of elements for the current queue. While he enters the
* numbers in the queues, we should check if the number to be enqueued is greater than the 
* last entered by the user. If the number is greater we enqueue it to the current queue.
* If it is not, the user should enter a new number and so on until he enters a greater number.
*/
void fillQueueOfQueues(LinkedQueue<LinkedQueue<int>>& qq) {
	int numberOfQueues, numberOfElements, element, lastElement;
	std::cout << "Enter how many queues you want to have in the main queue: ";
	std::cin >> numberOfQueues;
	for (int i = 0; i < numberOfQueues; ++i) {
		LinkedQueue<int> currentQueue;
		lastElement = INT_MIN;
		std::cout << "Enter how many elements you want to have in Queue #" << i + 1 << " : ";
		std::cin >> numberOfElements;
		std::cout << "Enter your numbers.\n";
		for (int j = 0; j < numberOfElements; ++j) {
			std::cin >> element;
			while (element < lastElement) {
				std::cout << "You have to enter a greater number than " << lastElement << std::endl;
				std::cin >> element;
			}
			lastElement = element;
			currentQueue.enqueue(element);
		}
		qq.enqueue(currentQueue);
	}
}

/*
* This function concatenates two queues in an ascending order.
*/
LinkedQueue<int> concatenate(LinkedQueue<int>& firstQueue, LinkedQueue<int>& secondQueue) {
	LinkedQueue<int> result;
	int element;

	while (!firstQueue.isEmpty() && !secondQueue.isEmpty()) {
		if (firstQueue.front() <= secondQueue.front()) {
			firstQueue.dequeue(element);
		} else {
			secondQueue.dequeue(element);
		}
		result.enqueue(element);
	}
	while (!firstQueue.isEmpty()) {
		firstQueue.dequeue(element);
		result.enqueue(element);
	}
	while (!secondQueue.isEmpty()) {
		secondQueue.dequeue(element);
		result.enqueue(element);
	}
	return result;
}

/*
* We create one result queue that will have all the elements in the queue of queues (QoQ)
* and at each step we dequeue one queue from the QoQ and concatenate it with the result queue.
*/
LinkedQueue<int> mergeQueues(LinkedQueue<LinkedQueue<int>>& qq) {
	LinkedQueue<int> result, nextQueue;
	if (!qq.isEmpty()) {
		qq.dequeue(result);
	}
	while (!qq.isEmpty()) {
		qq.dequeue(nextQueue);
		result = concatenate(result, nextQueue);
	}
	return result;
}