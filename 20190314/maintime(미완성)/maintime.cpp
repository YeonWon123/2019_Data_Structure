#include "Time.h"

// Precondition : �� �Լ��� �Է°�����
// ȯ�ڰ� ������ ������ �ð���, ��� ��� �ð��� �Է¹޴´�.
// Postconditions : �� �Լ� �����, �����Ǵ� ����ð��� ����Ѵ�.
// return : void�� �Լ��̹Ƿ� return���� ������
// �����Ǵ� ����ð�(���ð�)�� ����Ѵ�.
void Addtime(int arrival_minutes, int future_time);

int main()
{
	int numberOfVisits(0), totalWaitingTime(0);
	char answer;
	do {
		bool errorFlag; // arrival, seenByDoctor are instances of Time class
		Time arrival, seenByDoctor;
		cout << "Enter arrival time:";
		arrival.readTime(errorFlag);

		while (errorFlag) {
			cout << "Arrival time was incorrectly formatted; try again: ";
			arrival.readTime(errorFlag);
		}
		cout << "Enter time seen by doctor:";
		seenByDoctor.readTime(errorFlag);
		while (errorFlag) {
			cout << "Seen by doctor time was incorrectly formatted; try again: ";
			seenByDoctor.readTime(errorFlag);
		}
		numberOfVisits++;

		// assume that subtracting one Time from another yields the
		// difference in minutes as an int
		totalWaitingTime += seenByDoctor.subtractTimes(arrival);

		cout << "Done Enter 'y' to quit, anything else to continue: ";
		cin >> answer;
	} while (answer != 'y');
	cout << "Number of visits: " << numberOfVisits << "\n";
	cout << "Total waiting time: " << totalWaitingTime << " minutes.\n";
	cout << "Average wait is " << totalWaitingTime / numberOfVisits
		<< " minutes.\n";

	Time arrival;
	bool errorFlag;
	cout << "Enter arrival time:";
	arrival.readTime(errorFlag);

	while (errorFlag) {
		cout << "Arrival time was incorrectly formatted; try again: ";
		arrival.readTime(errorFlag);
	}

	Addtime(arrival.minutes, totalWaitingTime / numberOfVisits);

	return 0;
}

// Precondition : �� �Լ��� �Է°�����
// ȯ�ڰ� ������ ������ �ð���, ��� ��� �ð��� �Է¹޴´�.
// Postconditions : �� �Լ� �����, �����Ǵ� ����ð��� ����Ѵ�.
// return : void�� �Լ��̹Ƿ� return���� ������
// �����Ǵ� ����ð�(���ð�)�� ����Ѵ�.
void Addtime(int arrival_minutes, int future_time)
{
	// arrival_minutes���� �ð�, ��, PM ����
	int hour = arrival_minutes / 60;
	// ��� ��� �ð��� ���ؼ� �����Ǵ� ����ð� ���
	int minute = arrival_minutes - (arrival_minutes / 60) * 60 + future_time;
	while (minute >= 60) {
		hour++;
		minute = minute - 60;
	}
	if (hour > 12) {
		hour = hour - 12;
	}

	cout << "�����Ǵ� ����ð��� �� "
		<< hour << "�� " << minute << "�� �Դϴ�!";
}