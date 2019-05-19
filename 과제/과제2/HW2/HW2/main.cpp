#include<iostream>
#include"List.h"
#include"measure.h"
using namespace std;

int main(void)
{
	measure n1{ "야도킹",3,25,3,40,"PM" };
	measure n2{ "아구몬",4,40,5,10,"PM" };
	measure n3{ "피카츄",1,20,2,10,"PM" };
	measure n4{ "라이츄",1,60,12,10,"AM" };
	measure n5{ "파이리",1,25,10,10,"AM" };
	measure n6{ "꼬북이",3,10,1,10,"PM" };
	measure n7{ "버터플",1,20,2,10,"PM" };
	measure n8{ "야도란",1,29,8,10,"AM" };
	measure n9{ "이상해씨",4,11,12,10,"PM" };
	measure n10{ "마쟈용",7,19,9,10,"AM" };

	List object, object2, object3, object4, object5, object6; // object2와 3과 4는 문제 3번의 삭제를 위해서도 쓰인다.
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

	cout << "문제1" << endl;
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
	
	cout << "문제2" << endl;
	object2.PrintLinkedListBackward(para);
		
	cout << "--------------------------------------------" << endl << endl;
	
	cout << "문제3" << endl<<endl;

	cout << "원래 데이터 저장되어 있는 순서" << endl << endl;
	object2.PrintLinkedList(para);
	cout << endl << endl;

	cout << "1.가장 앞부분 데이터를 지운경우-야도킹delete" << endl << endl;
	if (object2.Delete("야도킹"))
	{
		cout << "앞에서부터 출력" << endl;
		object2.PrintLinkedList(para);
		cout << endl << endl;
		cout << "뒤에서부터 출력" << endl;
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

	cout << "2.중간부분 데이터를 지운경우-파이리delete" << endl << endl;
	if (object2.Delete("파이리"))
	{
		cout << "앞에서부터 출력" << endl;
		object2.PrintLinkedList(para);
		cout << endl << endl;
		cout << "뒤에서부터 출력" << endl;
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

	cout << "3.가장 마지막부분 데이터를 지운경우-마쟈용delete" << endl << endl;
	if (object4.Delete("마쟈용"))
	{   
		cout << "앞에서부터 출력" << endl;
		object4.PrintLinkedList(para);
		cout << endl << endl;
		cout << "뒤에서부터 출력" << endl;
		object4.PrintLinkedListBackward(para);
	}

	cout << "-----------------------------------------------" << endl << endl;
	cout << "문제4" << endl << endl;
	cout << "원래 데이터 저장되어 있는 순서" << endl << endl;
	object.PrintLinkedList(para);
	cout << endl << endl;



	cout << "1. 맨 앞과 맨뒤를 swap한 경우--야도킹과 마쟈용 swap" << endl << endl;
	if (object.SwapLinkedList("야도킹", "마쟈용"))
	{
		cout << "앞에서부터 출력" << endl;
		object.PrintLinkedList(para);
		cout << endl << endl;
		cout << "뒤에서부터 출력" << endl;
		object.PrintLinkedListBackward(para);
	}
	else
		cout << "바뀌지 않았습니다." << endl;

	object.SwapLinkedList("야도킹", "마쟈용");  // 다시 원본으로 돌려 놓기 위하여
	cout << endl << endl;

	cout << "2. 바로 이웃한 경우--야도란,이상해씨 swap" << endl << endl;

	if (object.SwapLinkedList("이상해씨", "야도란"))
	{
		cout << "앞에서부터 출력" << endl;
		object.PrintLinkedList(para);
		cout << endl << endl;
		cout << "뒤에서부터 출력" << endl;
		object.PrintLinkedListBackward(para);
	}
	else
		cout << "바뀌지 않았습니다." << endl;
	cout << endl << endl;

	object.SwapLinkedList("이상해씨", "야도란");  // 다시 원본으로 돌려 놓기 위하여

	cout << "3. 한개 노드이상 떨어진 경우--파이리,아구몬 swap" << endl << endl;

	if (object.SwapLinkedList("파이리", "아구몬"))
	{
		cout << "앞에서부터 출력" << endl;
		object.PrintLinkedList(para);
		cout << endl << endl;
		cout << "뒤에서부터 출력" << endl;
		object.PrintLinkedListBackward(para);
	}
	else
		cout << "바뀌지 않았습니다." << endl;


	object.SwapLinkedList("파이리", "아구몬");  // 다시 원본으로 돌려 놓기 위하여

	cout << "--------------------------------------------------" << endl << endl;
	cout << "문제5" << endl << endl;

	measure p1{ "연필",3,25,3,40,"PM" };
	measure p2{ "지우개",4,40,5,10,"PM" };
	measure p3{ "가위",1,20,2,10,"PM" };
	measure p4{ "자",1,60,12,10,"AM" };
	measure p5{ "샤프",1,25,10,10,"AM" };
	measure p6{ "크레파스",3,10,1,10,"PM" };
	measure p7{ "싸인펜",1,20,2,10,"PM" };
	measure p8{ "형광펜",1,29,8,10,"AM" };
	measure p9{ "화이트",4,11,12,10,"PM" };
	measure p10{ "볼펜",7,19,9,10,"AM" };

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



	cout << "붙여질 리스트(원본)" << endl << endl;
	object.PrintLinkedList(para);
	cout << endl << endl;
	cout << "꼬리에 추가할 리스트" << endl << endl;
	object5.PrintLinkedList(para);
	cout << endl << endl;


	cout << "두개의 리스트를 붙인 경우" << endl << endl;
	object.Merge(object5);
	object.PrintLinkedList(para);
	cout << endl << endl;

    


	cout << "reverse하기 전 리스트의 경우--앞에서부터 출력" << endl << endl;
	object.PrintLinkedList(para);
	cout << endl << endl;
	cout << "reverse 후 리스트의 경우--앞에서부터 출력" << endl << endl;
	object.reverse();
	object.PrintLinkedList(para);


	cout << "------------------------------------------" << endl << endl;
	cout << "문제6" << endl << endl;



	measure q1{ "강아지",3,25,3,40,"PM" };
	measure q2{ "고양이",4,40,5,10,"PM" };
	measure q3{ "원숭이",1,20,2,10,"PM" };
	measure q4{ "돌고래",1,60,12,10,"AM" };
	measure q5{ "강아지",3,25,3,40,"PM" };
	measure q6{ "거북이",3,10,1,10,"PM" };
	measure q7{ "앵무새",1,20,2,10,"PM" };
	measure q8{ "용가리",1,29,8,10,"AM" };
	measure q9{ "고양이",4,40,5,10,"PM" };
	measure q10{ "강아지",3,25,3,40,"PM" };

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

	

	cout << "unique하기 전 리스트의 경우--앞에서부터 출력" << endl << endl;
	object6.PrintLinkedList(para);
	cout << endl << endl;
	cout << "unique 후 리스트의 경우--앞에서부터 출력" << endl << endl;
	object6.unique();
	object6.PrintLinkedList(para);
	// unique 후 리스트의 경우 -- 뒤에서부터 출력
	//cout << "unique 후 리스트의 경우--뒤에서부터 출력" << endl << endl;
	//object6.PrintLinkedListBackward(para);



	cout << "---------------------------------------------------" << endl << endl;
	cout << "문제 7번" << endl << endl;
    
	List object7;

	object7.Insert(q1);
	object7.Insert(q2);
	object7.Insert(q3);
	object7.Insert(q6);
	object7.Insert(q4);
	object7.Insert(q6);
	object7.Insert(q7);
	object7.Insert(q8);

	cout << "quicksort하기 전 리스트의 경우--앞에서부터 출력" << endl << endl;
	object7.PrintLinkedList(para);
	cout << endl << endl;
	cout << "quicksort 후 리스트의 경우--앞에서부터 출력" << endl << endl;

	cout << "object6.f() 함수 결과 출력 : " << object7.f()->elem.getclientname() << " " << object7.f()->elem.getminutes() << endl;
	cout << "object6.l() 함수 결과 출력 : " << object7.l()->elem.getclientname() << " " << object7.l()->elem.getminutes() << endl;
	object6.quicksort(object6.f(), object6.l());
	object6.PrintLinkedList(para);

	//cout << object.l()->elem.getclientname();

	system("pause");
	return 0;
}