// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "List.h"
#include <iostream>

int main()
{
	cout << endl << "1. insert 함수를 이용하여 10개의 data를 넣고 PrintLinkedList 함수로 출력해 본다." << endl << endl;

	List linkedlist1;
	
	linkedlist1.insert({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist1.insert({ "박민지", 1, 2, 11, 30, "AM" });
	linkedlist1.insert({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist1.insert({ "김상진", 2, 4, 12, 00, "PM" });
	linkedlist1.insert({ "이상록", 5, 5, 12, 14, "PM" });
	linkedlist1.insert({ "이진서", 2, 6, 12, 17, "PM" });
	linkedlist1.insert({ "이주호", 2, 7, 12, 36, "PM" });
	linkedlist1.insert({ "강산해", 3, 8, 15, 26, "PM" });
	linkedlist1.insert({ "남상민", 4, 9, 15, 43, "PM" });
	linkedlist1.insert({ "진주리", 3, 10, 16, 02, "PM" });
	
	linkedlist1.PrintLinkedList();
	
	cout << "\n\n2. insertToTail 함수를 이용하여 10개의 data를 넣고 PrintLinkedListBackward 함수로 출력해 본다.\n" <<
		"   (데이터는 1과 동일) "<< endl << endl;

	List linkedlist2;
	linkedlist2.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist2.insertToTail({ "박민지", 1, 2, 11, 30, "AM" });
	linkedlist2.insertToTail({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist2.insertToTail({ "김상진", 2, 4, 12, 00, "PM" });
	linkedlist2.insertToTail({ "이상록", 5, 5, 12, 14, "PM" });
	linkedlist2.insertToTail({ "이진서", 2, 6, 12, 17, "PM" });
	linkedlist2.insertToTail({ "이주호", 2, 7, 12, 36, "PM" });
	linkedlist2.insertToTail({ "강산해", 3, 8, 15, 26, "PM" });
	linkedlist2.insertToTail({ "남상민", 4, 9, 15, 43, "PM" });
	linkedlist2.insertToTail({ "진주리", 3, 10, 16, 02, "PM" });

	linkedlist2.PrintLinkedListBackward();

	cout << "\n\n3. search, deleteNode 함수를 구현하고 지운 뒤 두 함수로 출력해본다." << 
		" 원본 데이터는 2의 것을 사용하였다."<< endl << endl;

	List linkedlist3;
	linkedlist3.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist3.insertToTail({ "박민지", 1, 2, 11, 30, "AM" });
	linkedlist3.insertToTail({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist3.insertToTail({ "김상진", 2, 4, 12, 00, "PM" });
	linkedlist3.insertToTail({ "이상록", 5, 5, 12, 14, "PM" });
	linkedlist3.insertToTail({ "이진서", 2, 6, 12, 17, "PM" });
	linkedlist3.insertToTail({ "이주호", 2, 7, 12, 36, "PM" });
	linkedlist3.insertToTail({ "강산해", 3, 8, 15, 26, "PM" });
	linkedlist3.insertToTail({ "남상민", 4, 9, 15, 43, "PM" });
	linkedlist3.insertToTail({ "진주리", 3, 10, 16, 02, "PM" });

	List linkedlist4;
	linkedlist4.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist4.insertToTail({ "박민지", 1, 2, 11, 30, "AM" });
	linkedlist4.insertToTail({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist4.insertToTail({ "김상진", 2, 4, 12, 00, "PM" });
	linkedlist4.insertToTail({ "이상록", 5, 5, 12, 14, "PM" });
	linkedlist4.insertToTail({ "이진서", 2, 6, 12, 17, "PM" });
	linkedlist4.insertToTail({ "이주호", 2, 7, 12, 36, "PM" });
	linkedlist4.insertToTail({ "강산해", 3, 8, 15, 26, "PM" });
	linkedlist4.insertToTail({ "남상민", 4, 9, 15, 43, "PM" });
	linkedlist4.insertToTail({ "진주리", 3, 10, 16, 02, "PM" });


	cout << "3-1. 가장 앞부분의 data를 지워보고 PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl << endl;

	linkedlist2.deleteNode("이소라");
	cout << "지운 데이터 : 이름이 '이소라' 인 데이터(head에 있는 데이터)" << endl;
	cout << "PrintLinkedList() 결과" << endl;
	linkedlist2.PrintLinkedList();
	cout << endl << endl << "PrintLinkedListBackward() 결과" << endl;
	linkedlist2.PrintLinkedListBackward();

	cout << "\n\n3-2. 중간 부분의 data를 지워보고 PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl << endl;
	linkedlist3.deleteNode("이상록");
	cout << "지운 데이터 : 이름이 '이상록' 인 데이터(가운데에 있는 데이터)" << endl;
	cout << "PrintLinkedList() 결과" << endl;
	linkedlist3.PrintLinkedList();
	cout << endl << endl << "PrintLinkedListBackward() 결과" << endl;
	linkedlist3.PrintLinkedListBackward();

	cout << "\n\n3-3. 마지막 부분의 data를 지워보고 PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl << endl;
	linkedlist4.deleteNode("진주리");
	cout << "지운 데이터 : 이름이 '진주리' 인 데이터(tail에 있는 데이터)" << endl;
	cout << "PrintLinkedList() 결과" << endl;
	linkedlist4.PrintLinkedList();
	cout << endl << endl << "PrintLinkedListBackward() 결과" << endl;
	linkedlist4.PrintLinkedListBackward();

	cout << "\n\n\n4. SwapLinkedList 함수를 이용하여 두 노드를 바꿔 보고 PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl << endl;
	cout << "\n4-1. 가장 앞의 데이터와 가장 뒤의 데이터를 바꿔보기" << endl << endl;
	linkedlist4.insertToTail({ "진주리", 3, 10, 16, 02, "PM" }); // 3번 과정에서 지운 노드를 다시 복원함
	linkedlist4.swapLinkedList("이소라", "진주리");
	cout << "바꾼 데이터 : 이름이 '이소라'인 데이터(head)와 이름이 '진주리' 인 데이터(tail)" << endl;
	cout << "PrintLinkedList() 결과" << endl;
	linkedlist4.PrintLinkedList();
	cout << endl << endl << "PrintLinkedListBackward() 결과" << endl;
	linkedlist4.PrintLinkedListBackward();

	cout << "\n\n4-2. 바로 이웃한 두 개의 데이터를 바꿔보기" << endl << endl;
	linkedlist2.insert({ "이소라", 3, 1, 11, 15, "AM" }); // 3번 과정에서 지운 노드를 다시 복원함
	linkedlist2.swapLinkedList("김상진", "이상록");
	cout << "바꾼 데이터 : 이름이 '김상진'인 데이터(4번째)와 이름이 '이상록' 인 데이터(5번째)" << endl;
	cout << "PrintLinkedList() 결과" << endl;
	linkedlist2.PrintLinkedList();
	cout << endl << endl << "PrintLinkedListBackward() 결과" << endl;
	linkedlist2.PrintLinkedListBackward();
	
	cout << "\n\n4-3. 한 개 노드 이상 떨어져 있는 임의의 두 노드의 데이터를 바꿔보기" << endl << endl;
	linkedlist4.swapLinkedList("이소라", "진주리"); // 4-1번 과정에서 바꾼 노드를 다시 복원함
	linkedlist4.swapLinkedList("박민지", "강산해");
	cout << "바꾼 데이터 : 이름이 '박민지'인 데이터(2번째)와 이름이 '강산해' 인 데이터(8번째)" << endl;
	cout << "PrintLinkedList() 결과" << endl;
	linkedlist4.PrintLinkedList();
	cout << endl << endl << "PrintLinkedListBackward() 결과" << endl;
	linkedlist4.PrintLinkedListBackward();

	
	cout << "\n\n5-1. merge 함수를 이용하여 두 링크드 리스트를 합쳐 보고 PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl << endl;
	cout << "입력을 하는 두 리스트를 먼저 출력한다.\n\n";
	cout << "linkedlist1 출력\n\n";
	linkedlist1.PrintLinkedList();
	cout << "\n\nlinkedlist4 출력\n\n";
	linkedlist4.PrintLinkedList();

	linkedlist1.merge(linkedlist4);

	cout << endl << endl;
	cout << "merge 이후 linkedlist1 출력 - linkedlist1.PrintLinkedlist() 결과 \n\n";
	linkedlist4.PrintLinkedList();
	cout << endl;
	cout << "merge 이후 linkedlist1 출력 - linkedlist1.PrintLinkedListBackward() 결과 \n\n";
	linkedlist4.PrintLinkedListBackward();
	cout << endl;

	/*
	cout << "linkedlist4.PrintLinkedlist...\n\n";
	linkedlist4.PrintLinkedList();
	cout << endl;
	cout << "linkedlist4.PrintLinkedListBackward...\n\n";
	linkedlist4.PrintLinkedListBackward();
	*/

	cout << "\n\n5-2. reverse 함수를 이용하여 링크드 리스트를 뒤집어 보고, PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl;
	cout << "(5-1 과정에서 합쳐진 linkedlist1을 이용하였음)\n\n";
	linkedlist1.reverse();
	cout << "reverse() 수행 완료 후 linkedlist4.PrintLinkedlist() 수행 결과\n\n";
	linkedlist1.PrintLinkedList();
	cout << endl;
	cout << "reverse() 수행 완료 후 linkedlist4.PrintLinkedListBackward() 수행 결과\n\n";
	linkedlist1.PrintLinkedListBackward();

	cout << "\n\n6. unique 함수를 이용하여 중복되는 데이터를 없애고, PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다.\n" <<
		"중복되는 데이터(이소라, 3, 1, 11, 15, AM)는 첫 번째, 다섯 번째, 마지막 번째에 존재하고, \n" << 
		"또 다른 중복되는 데이터(조유정, 1, 3, 11, 36, AM)는 세 번째와 여덟 번째에 존재한다."<< endl << endl;
	List linkedlist5;
	linkedlist5.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist5.insertToTail({ "박민지", 1, 2, 11, 30, "AM" });
	linkedlist5.insertToTail({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist5.insertToTail({ "김상진", 2, 4, 12, 00, "PM" });
	linkedlist5.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist5.insertToTail({ "이상록", 5, 5, 12, 14, "PM" });
	linkedlist5.insertToTail({ "이진서", 2, 7, 12, 17, "PM" });
	linkedlist5.insertToTail({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist5.insertToTail({ "이주호", 2, 6, 12, 36, "PM" });
	linkedlist5.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });

	cout << "원래의 linkedlist5 출력\n";
	linkedlist5.PrintLinkedList();
	linkedlist5.unique();

	cout << endl << endl << "unique 함수 수행 후 linkedlist5.PrintLinkedList() 결과" << endl;
	linkedlist5.PrintLinkedList();
	cout << endl << endl << "unique 함수 수행 후 linkedlist5.PrintLinkedListBackward() 결과" << endl;
	linkedlist5.PrintLinkedListBackward();

	
	cout << "\n\n7. quicksort 함수를 이용하여 데이터를 도착 순서대로 정렬하고, PrintLinkedList와 PrintLinkedListBackward를 이용하여 출력해 본다." << endl << endl;
	List linkedlist6;
	linkedlist6.insertToTail({ "박민지", 1, 2, 11, 30, "AM" });
	linkedlist6.insertToTail({ "진주리", 3, 10, 16, 02, "PM" });
	linkedlist6.insertToTail({ "이진서", 2, 7, 12, 17, "PM" });
	linkedlist6.insertToTail({ "강산해", 3, 8, 15, 26, "PM" });
	linkedlist6.insertToTail({ "김상진", 2, 4, 12, 00, "PM" });
	linkedlist6.insertToTail({ "남상민", 4, 9, 15, 43, "PM" });
	linkedlist6.insertToTail({ "이상록", 5, 5, 12, 14, "PM" });
	linkedlist6.insertToTail({ "조유정", 1, 3, 11, 36, "AM" });
	linkedlist6.insertToTail({ "이소라", 3, 1, 11, 15, "AM" });
	linkedlist6.insertToTail({ "이주호", 2, 6, 12, 36, "PM" });

	cout << "정렬 전 linkedlist6() 출력 \n\n";
	linkedlist6.PrintLinkedList();
	
	linkedlist6.quicksort();

	cout << endl << endl << "quicksort 함수 수행 후 linkedlist6.PrintLinkedList() 출력" << endl;
	linkedlist6.PrintLinkedList();
	
	cout << endl << endl << "quicksort 함수 수행 후 linkedlist6.PrintLinkedListBackward() 출력" << endl;
	linkedlist6.PrintLinkedListBackward();


	linkedlist1.~List();
	linkedlist2.~List();
	linkedlist3.~List();
	linkedlist4.~List();
	linkedlist5.~List();
	linkedlist6.~List();

 	return 0;
}