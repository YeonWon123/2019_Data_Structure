#include<iostream>
#include"List.h"
#include"measure.h"
using namespace std;

int main(void)
{
	measure n1{ "�ߵ�ŷ",3,25,3,40,"PM" };
	measure n2{ "�Ʊ���",4,40,5,10,"PM" };
	measure n3{ "��ī��",1,20,2,10,"PM" };
	measure n4{ "������",1,60,12,10,"AM" };
	measure n5{ "���̸�",1,25,10,10,"AM" };
	measure n6{ "������",3,10,1,10,"PM" };
	measure n7{ "������",1,20,2,10,"PM" };
	measure n8{ "�ߵ���",1,29,8,10,"AM" };
	measure n9{ "�̻��ؾ�",4,11,12,10,"PM" };
	measure n10{ "�����",7,19,9,10,"AM" };

	List object, object2, object3, object4, object5, object6; // object2�� 3�� 4�� ���� 3���� ������ ���ؼ��� ���δ�.
	measure para;

	object.Insert(n1);
	object.Insert(n2);
	object.Insert(n3);
	object.Insert(n4);
	object.Insert(n5);
	object.Insert(n6);
	object.Insert(n7);
	object.Insert(n8);
	object.Insert(n9);
	object.Insert(n10);

	cout << "����1" << endl;
	object.PrintLinkedList(para);

	cout << "--------------------------------------------------" << endl << endl;
	cout << endl << endl;
	object2.InsertToTail(n1);
	object2.InsertToTail(n2);
	object2.InsertToTail(n3);
	object2.InsertToTail(n4);
	object2.InsertToTail(n5);
	object2.InsertToTail(n6);
	object2.InsertToTail(n7);
	object2.InsertToTail(n8);
	object2.InsertToTail(n9);
	object2.InsertToTail(n10);
	
	cout << "����2" << endl;
	object2.PrintLinkedListBackward(para);
		
	cout << "--------------------------------------------" << endl << endl;
	
	cout << "����3" << endl<<endl;

	cout << "���� ������ ����Ǿ� �ִ� ����" << endl << endl;
	object2.PrintLinkedList(para);
	cout << endl << endl;

	cout << "1.���� �պκ� �����͸� ������-�ߵ�ŷdelete" << endl << endl;
	if (object2.Delete("�ߵ�ŷ"))
	{
		cout << "�տ������� ���" << endl;
		object2.PrintLinkedList(para);
		cout << endl << endl;
		cout << "�ڿ������� ���" << endl;
		object2.PrintLinkedListBackward(para);

	}

	cout << endl << endl;

	object3.InsertToTail(n1);
	object3.InsertToTail(n2);
	object3.InsertToTail(n3);
	object3.InsertToTail(n4);
	object3.InsertToTail(n5);
	object3.InsertToTail(n6);
	object3.InsertToTail(n7);
	object3.InsertToTail(n8);
	object3.InsertToTail(n9);
	object3.InsertToTail(n10);

	cout << "2.�߰��κ� �����͸� ������-���̸�delete" << endl << endl;
	if (object2.Delete("���̸�"))
	{
		cout << "�տ������� ���" << endl;
		object2.PrintLinkedList(para);
		cout << endl << endl;
		cout << "�ڿ������� ���" << endl;
		object2.PrintLinkedListBackward(para);
	}

	cout << endl << endl;

	object4.InsertToTail(n1);
	object4.InsertToTail(n2);
	object4.InsertToTail(n3);
	object4.InsertToTail(n4);
	object4.InsertToTail(n5);
	object4.InsertToTail(n6);
	object4.InsertToTail(n7);
	object4.InsertToTail(n8);
	object4.InsertToTail(n9);
	object4.InsertToTail(n10);

	cout << "3.���� �������κ� �����͸� ������-�����delete" << endl << endl;
	if (object4.Delete("�����"))
	{   
		cout << "�տ������� ���" << endl;
		object4.PrintLinkedList(para);
		cout << endl << endl;
		cout << "�ڿ������� ���" << endl;
		object4.PrintLinkedListBackward(para);
	}

	cout << "-----------------------------------------------" << endl << endl;
	cout << "����4" << endl << endl;
	cout << "���� ������ ����Ǿ� �ִ� ����" << endl << endl;
	object.PrintLinkedList(para);
	cout << endl << endl;



	cout << "1. �� �հ� �ǵڸ� swap�� ���--�ߵ�ŷ�� ����� swap" << endl << endl;
	if (object.SwapLinkedList("�ߵ�ŷ", "�����"))
	{
		cout << "�տ������� ���" << endl;
		object.PrintLinkedList(para);
		cout << endl << endl;
		cout << "�ڿ������� ���" << endl;
		object.PrintLinkedListBackward(para);
	}
	else
		cout << "�ٲ��� �ʾҽ��ϴ�." << endl;

	object.SwapLinkedList("�ߵ�ŷ", "�����");  // �ٽ� �������� ���� ���� ���Ͽ�
	cout << endl << endl;

	cout << "2. �ٷ� �̿��� ���--�ߵ���,�̻��ؾ� swap" << endl << endl;

	if (object.SwapLinkedList("�̻��ؾ�", "�ߵ���"))
	{
		cout << "�տ������� ���" << endl;
		object.PrintLinkedList(para);
		cout << endl << endl;
		cout << "�ڿ������� ���" << endl;
		object.PrintLinkedListBackward(para);
	}
	else
		cout << "�ٲ��� �ʾҽ��ϴ�." << endl;
	cout << endl << endl;

	object.SwapLinkedList("�̻��ؾ�", "�ߵ���");  // �ٽ� �������� ���� ���� ���Ͽ�

	cout << "3. �Ѱ� ����̻� ������ ���--���̸�,�Ʊ��� swap" << endl << endl;

	if (object.SwapLinkedList("���̸�", "�Ʊ���"))
	{
		cout << "�տ������� ���" << endl;
		object.PrintLinkedList(para);
		cout << endl << endl;
		cout << "�ڿ������� ���" << endl;
		object.PrintLinkedListBackward(para);
	}
	else
		cout << "�ٲ��� �ʾҽ��ϴ�." << endl;


	object.SwapLinkedList("���̸�", "�Ʊ���");  // �ٽ� �������� ���� ���� ���Ͽ�

	cout << "--------------------------------------------------" << endl << endl;
	cout << "����5" << endl << endl;

	measure p1{ "����",3,25,3,40,"PM" };
	measure p2{ "���찳",4,40,5,10,"PM" };
	measure p3{ "����",1,20,2,10,"PM" };
	measure p4{ "��",1,60,12,10,"AM" };
	measure p5{ "����",1,25,10,10,"AM" };
	measure p6{ "ũ���Ľ�",3,10,1,10,"PM" };
	measure p7{ "������",1,20,2,10,"PM" };
	measure p8{ "������",1,29,8,10,"AM" };
	measure p9{ "ȭ��Ʈ",4,11,12,10,"PM" };
	measure p10{ "����",7,19,9,10,"AM" };

	object5.Insert(p1);
	object5.Insert(p2);
	object5.Insert(p3);
	object5.Insert(p4);
	object5.Insert(p5);
	object5.Insert(p6);
	object5.Insert(p7);
	object5.Insert(p8);
	object5.Insert(p9);
	object5.Insert(p10);



	cout << "�ٿ��� ����Ʈ(����)" << endl << endl;
	object.PrintLinkedList(para);
	cout << endl << endl;
	cout << "������ �߰��� ����Ʈ" << endl << endl;
	object5.PrintLinkedList(para);
	cout << endl << endl;


	cout << "�ΰ��� ����Ʈ�� ���� ���" << endl << endl;
	object.Merge(object5);
	object.PrintLinkedList(para);
	cout << endl << endl;

    


	cout << "reverse�ϱ� �� ����Ʈ�� ���--�տ������� ���" << endl << endl;
	object.PrintLinkedList(para);
	cout << endl << endl;
	cout << "reverse �� ����Ʈ�� ���--�տ������� ���" << endl << endl;
	object.reverse();
	object.PrintLinkedList(para);


	cout << "------------------------------------------" << endl << endl;
	cout << "����6" << endl << endl;



	measure q1{ "������",3,25,3,40,"PM" };
	measure q2{ "�����",4,40,5,10,"PM" };
	measure q3{ "������",1,20,2,10,"PM" };
	measure q4{ "����",1,60,12,10,"AM" };
	measure q5{ "������",3,25,3,40,"PM" };
	measure q6{ "�ź���",3,10,1,10,"PM" };
	measure q7{ "�޹���",1,20,2,10,"PM" };
	measure q8{ "�밡��",1,29,8,10,"AM" };
	measure q9{ "�����",4,40,5,10,"PM" };
	measure q10{ "������",3,25,3,40,"PM" };

	object6.Insert(q1);
	object6.Insert(q2);
	object6.Insert(q3);
	object6.Insert(q4);
	object6.Insert(q5);
	object6.Insert(q6);
	object6.Insert(q7);
	object6.Insert(q8);
	object6.Insert(q9);
	object6.Insert(q10);

	

	cout << "unique�ϱ� �� ����Ʈ�� ���--�տ������� ���" << endl << endl;
	object6.PrintLinkedList(para);
	cout << endl << endl;
	cout << "unique �� ����Ʈ�� ���--�տ������� ���" << endl << endl;
	object6.unique();
	object6.PrintLinkedList(para);
	// unique �� ����Ʈ�� ��� -- �ڿ������� ���
	//cout << "unique �� ����Ʈ�� ���--�ڿ������� ���" << endl << endl;
	//object6.PrintLinkedListBackward(para);



	cout << "---------------------------------------------------" << endl << endl;
	cout << "���� 7��" << endl << endl;
    
	List object7;

	object7.Insert(q1);
	object7.Insert(q2);
	object7.Insert(q3);
	object7.Insert(q6);
	object7.Insert(q4);
	object7.Insert(q6);
	object7.Insert(q7);
	object7.Insert(q8);

	cout << "quicksort�ϱ� �� ����Ʈ�� ���--�տ������� ���" << endl << endl;
	object7.PrintLinkedList(para);
	cout << endl << endl;
	cout << "quicksort �� ����Ʈ�� ���--�տ������� ���" << endl << endl;

	cout << "object6.f() �Լ� ��� ��� : " << object7.f()->elem.getclientname() << " " << object7.f()->elem.getminutes() << endl;
	cout << "object6.l() �Լ� ��� ��� : " << object7.l()->elem.getclientname() << " " << object7.l()->elem.getminutes() << endl;
	object6.quicksort(object6.f(), object6.l());
	object6.PrintLinkedList(para);

	//cout << object.l()->elem.getclientname();

	system("pause");
	return 0;
}