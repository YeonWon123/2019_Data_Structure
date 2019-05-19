#include "List.h"



List::List()
{
	head = 0;
	tail = 0;
	current = 0;

}


void List::Insert(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;

	if (head == 0)
		tail = addedNode;

	else
		head->prev = addedNode;

	addedNode->next = head;
	head = addedNode;
	addedNode->prev = 0;

}

void List::InsertToTail(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;

	if (head == 0)
		head = addedNode;
	else
		tail->next = addedNode;

	addedNode->prev = tail;
	addedNode->next = 0;
	tail = addedNode;

}

bool List::first(ListElementType & elem)
{
	if (head == 0)
		return false;
	else
	{
		current = head;
		elem = current->elem;
		return true;

	}
	
}

bool List::next(ListElementType & elem)
{
	assert(current);
	if (current->next == 0)
		return false;
	else
	{ 
		current = current->next;
		elem = current->elem;
		return true;
	}
}

bool List::last(ListElementType & elem)
{

	if (tail == 0)
		return false;
	else
	{
		current = tail;
		elem = current->elem;
		return true;
	}
}

bool List::previous(ListElementType & elem)
{
	assert(current);
	if (current->prev == 0)
		return false;
	else
	{
		current = current->prev;
		elem = current->elem;
		return true;

	}
}

void List::PrintLinkedList(ListElementType &elem)
{
	if (first(elem))
	{
	 cout << "�̸�:" << elem.getclientname() << " " << "�׷��:" << elem.getgroubnumber() << " " 
		 << "����:" << elem.getnumber()
		  << " " << "�����ð�:" << elem.gethour() << ":" << elem.getminute() << elem.getAMPM() << endl;

	 while (next(elem))
	 {
		 cout << "�̸�:" << elem.getclientname() << " " << "�׷��:" << elem.getgroubnumber() << " "
			 << "����:" << elem.getnumber()
			 << " " << "�����ð�:" << elem.gethour() << ":" << elem.getminute() << elem.getAMPM() << endl;
	 }

	}
}

void List::PrintLinkedListBackward(ListElementType & elem)
{
	if (last(elem))
	{
		cout << "�̸�:" << elem.getclientname() << " " << "�׷��:" << elem.getgroubnumber() << " "
			<< "����:" << elem.getnumber()
			<< " " << "�����ð�:" << elem.gethour() << ":" << elem.getminute() << elem.getAMPM() << endl;
		while (previous(elem))
		{
			cout << "�̸�:" << elem.getclientname() << " " << "�׷��:" << elem.getgroubnumber() << " "
				<< "����:" << elem.getnumber()
				<< " " << "�����ð�:" << elem.gethour() << ":" << elem.getminute() << elem.getAMPM() << endl;
		}
	  }

}

bool List::SwapLinkedList(string A, string B)
{
	measure backup;
	Link backuppoint;
	if (Search(A))
	{
		backuppoint = current;
		backup = backuppoint->elem;

		if (Search(B))
		{
			backuppoint->elem = current->elem;
			current->elem = backup;
			return true;
		}
		else
			return false;

	}
	else
		return false;
}

int List::Search(string name)
{
	measure elem;
	Link backup = head;
	if (first(elem))
	{
		
		if (elem.getclientname() == name)
		{
			//cout<< "ã�� ���� ����:" << name << endl;
			return 1;
		}
		while (next(elem))
		{
			if (elem.getclientname() == name)
			{
				//cout << "ã�� ���� ����:" << name << endl;
				return 1;
			}
		}
                           
	}
	
	if(current==0)
	{
		//cout << "��ܿ� �̸��� �����ϴ�." << endl;
		return 0;
	}
}

bool List::Delete(string name)
{
	if (Search(name))
	{   
		Link delnode =current;

		if (current == head)
		{
			head = current->next;
			current->next->prev = 0;
		}
		else if (current == tail)
		{
			tail = current->prev;
			current->prev->next = 0;
		}
		else
		{
			delnode->prev->next = current->next;
			current->next->prev = current->prev;
		}
		
	   delete delnode;
	   return true;
	}

	else
	return false;
}

void List::Merge(List & elem)
{
	elem.head->prev = tail;  //�ڿ� ���� ù��° ��尡  ���� ������ ��带 ����Ű�� �Ѵ�.
	tail->next = elem.head; // ������ ��尡  �ڿ����� ù��° ��带 ����Ű�� �Ѵ�.

	tail = elem.tail;  // ���� ����Ʈ�� ������ ���� ������ ��带 ����Ű���Ѵ�.
	
	
}

void List::reverse()
{

	Link curr, temp;
	
	head->prev = 0;  // merge�� �Ұ��  prev�� ���� �ƴ� �� �ִ�.
	curr = head;
    temp = curr->prev;
	while (curr != 0)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;

	}
	
	tail = head;
	temp = temp->prev;
	head = temp;
	
	
}

void List::unique()
{
	current = head;
	Link searchnode = current->next;
	Link delnode = 0;

	while (current != 0)
	{
		searchnode = current->next;

		while (searchnode != 0)
		{
			if (current->elem == searchnode->elem)
			{
				delnode = searchnode;

				if (searchnode->next != 0)
				{
					searchnode->prev->next = delnode->next;
					delnode->next->prev = delnode->prev;
					
				}
				else
					searchnode->prev->next = 0;

				searchnode = searchnode->next;
				delete(delnode);
			}
			  else
			 searchnode = searchnode->next;
			
		}
            current = current->next;
	}
}

void List::quicksort(Link first , Link last)
{
	// cout << "\n\n first���� last���� ����غ��� \n\n";
	Link temp = first;

	// temp != NULL�� ������ġ
	while (temp != NULL) {
		cout << temp->elem.getclientname() << " " << temp->elem.getminutes() << "\n";

		// temp == last�϶� break���� ������, 
		// �� �� pivot�� ������ NULL���� ��� print�ϰ� ��
		if (temp == last) break;

		temp = temp->next;
	}
	// cout << "��� ��!\n";


	if (last != NULL && first != last && first != last->next)
	{
		// cout << "first : " << first << "\n";
		// cout << "last->next : " << last->next << "\n";

		Link pivot = partition(first, last);
		// cout << "����Լ� ȣ��! pivot : " << pivot->elem.getclientname() << " " << pivot->elem.getminutes() << " �̰�, �� ������ ȣ����" << endl;

		quicksort(first, pivot->prev);

		// cout << "����Լ� ȣ��! pivot : " << pivot->elem.getclientname() << " " << pivot->elem.getminutes() << " �̰�, �� �������� ȣ����" << endl;
		// cout << "���ڷ� " << pivot->next << "�� " << last << " �� ����, �׸��� last->next�� " << last->next << " �̴�.";
		quicksort(pivot->next, last);	
	}
	else {
		// cout << "����Լ� ȣ������ ����!\n";
		return;
	}

}

List::Link List::partition(Link first, Link last)
{
	  Link lastsmall = first;
	  Link i = first->next;
	  Link pivot = last->next;
	  measure object;

	  // ���� ó�� : first->next�� last�� ��� (��, first�� last�� �ִ� ���)

	  for (; i != NULL; i = i->next)
	  {
		 
		  if (i->elem.getminutes() <= first->elem.getminutes())
		  {
			  lastsmall = lastsmall->next;

			  cout << i->elem.getclientname() << "�� �ð��� " << i->elem.getminutes()
				  << "��" << lastsmall->elem.getclientname() << "�� �ð��� " << lastsmall->elem.getminutes() << "�� ���� �ٲ�ϴ�!" << endl;

			  // swapelements(a[], lastsmall, i);
			  object = lastsmall->elem;
			  lastsmall->elem = i->elem;
			  i->elem = object;
		  }

		  if (i->next == pivot) break;
	  }
	  
	  cout << "����������, \n";
	  cout << first->elem.getclientname() << "�� �ð��� " << first->elem.getminutes()
		  << "��" << lastsmall->elem.getclientname() << "�� �ð��� " << lastsmall->elem.getminutes() << "�� ���� �ٲ�ϴ�!\n\n" << endl;

	  object = first->elem;
	  first->elem = lastsmall->elem;
	  lastsmall->elem = object;

	  return lastsmall;
}

  List::Link List::partitino2(Link first, Link last)
  {

	  int x = last->elem.getminutes();
	  Link i = first->prev;
	  measure object;
	  
	  for (Link j = first; j != last; j = j->next)
	  {
		  if (j->elem.getminutes() <= x)
		  {
			  i = (i == NULL) ? first : i->next;
			  object = i->elem;
			  i->elem = j->elem;
			  j->elem = object;

		  }
	  }
		  i = (i == NULL) ? first : i->next;
		  object = i->elem;
		  i->elem = first->elem;
		  first->elem = object;
	  

	  return i;
  }

  List::Link List::f()
  {
	  return  head;
  }

  List::Link List::l()
  {
	  return tail;
  }



List::~List()
{
	while (head != 0)
	{
		Link delnode = head;
		head = head->next;
		delete delnode;
	}


}