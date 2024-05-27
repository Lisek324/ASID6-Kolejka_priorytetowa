#include<iostream>


struct element {
	int data;
	int prio;
	struct element* nextElement;
};


void showList(element* head) {

	if (head == NULL) {
		std::cout << "Empty list";
	}
	else {
		element* currentElement = head;                 
		while (currentElement != NULL) {
			std::cout << currentElement->data << ":"<<currentElement->prio<<" ";
			currentElement = currentElement->nextElement; 
		}
		std::cout << "\n";
	}
}
int listSize(element* head) {
	int c = 0;                                          
	if (head == NULL) {                                 
		return 0;
	}
	else {
		element* currentElement = head;                 
		while (currentElement != NULL) {                
			c++;
			currentElement = currentElement->nextElement; 
		}
		return c;                                       
	}
}

void popFront(element** head) {
	element* tmp = NULL;
	if (*head != NULL) {
		tmp = (*head)->nextElement;                     

		delete* head;                                   
		*head = tmp;                                    
	}
}
void popBack(element** head) {
	if (*head != NULL) {
		if ((*head)->nextElement == NULL)               
		{
			*head = NULL;                               
		}
		else
		{
			element* currentElement = *head;            
			while (currentElement->nextElement->nextElement != NULL)
			{
				currentElement = currentElement->nextElement;
			}
			delete currentElement->nextElement;         

			currentElement->nextElement = NULL;         
		}
	}
}
void popByIndex(element** head, int index) {
	if (index == 0) {
		popFront(head);
	}
	else {
		element* currentElement = *head;                
		element* tmp;

		int i = 0;
		while (currentElement->nextElement != NULL && i < index - 1) {
			currentElement = currentElement->nextElement;
			i++;
		}
		tmp = currentElement->nextElement;                  
		currentElement->nextElement = tmp->nextElement;     
		delete tmp;                                         
	}
}

void pushItem(element** head, int number, int prio) {
	
	element* currentElement = *head;            
	element* tmp;                               
	if (currentElement == NULL || currentElement->prio>prio) 
	{  
		element* currentElement = new element;
		currentElement->data = number; 
		currentElement->prio = prio;
		currentElement->nextElement = (*head);
		*head = currentElement;
	}
	else {
		while (currentElement->nextElement != NULL &&  prio > currentElement->nextElement->prio)
		{
			currentElement = currentElement->nextElement;
		}

		tmp = currentElement->nextElement;
		currentElement->nextElement = new element;
		currentElement->nextElement->data = number;
		currentElement->nextElement->prio = prio;
		currentElement->nextElement->nextElement = tmp;
	}
	
}

int main()
{
	element* head = NULL;                          
	int action = -1;                                
	int num = -1;                                   
	int indx = -1;                                  
	int p = -1;
	while (true)
	{
		std::cout << "Elements in list: ";
		showList(head);
		std::cout << "\n";
		std::cout << "1.Push an item with priority\n";
		std::cout << "2.Remove fist element\n";
		std::cout << "3.Remove last element\n";
		std::cout << "4.Remove element with given index\n";
		std::cout << "5.Exit\n";
		std::cout << "Enter action ";
		std::cin >> action;

		switch (action)
		{
		case 0:
			return 0;
			break;
		case 1:
			std::cout << "Type a number ";
			std::cin >> num;
			std::cout << "Give a priority ";
			std::cin >> p;
			pushItem(&head, num, p);
			break;
		case 2:
			std::cout << "Removed first element.\n ";
			popFront(&head);
			break;
		case 3:
			std::cout << "Removed last element.\n ";
			popBack(&head);
			break;
		case 4:
			std::cout << "Type index to remove ";
			std::cin >> num;
			std::cout << "Element removed with given index\n";
			popByIndex(&head, num);
			break;
		case 5:
			return 0;
			break;
		default:
			std::cout << "Invalid operation \n";
			break;
		}
	}
}