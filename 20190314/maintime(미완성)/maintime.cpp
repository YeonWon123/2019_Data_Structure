#include "Time.h"

// Precondition : 이 함수는 입력값으로
// 환자가 병원에 도착한 시간과, 평균 대기 시간을 입력받는다.
// Postconditions : 이 함수 종료시, 예측되는 진료시간을 출력한다.
// return : void형 함수이므로 return값은 없으며
// 예측되는 진료시간(대기시간)을 출력한다.
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

// Precondition : 이 함수는 입력값으로
// 환자가 병원에 도착한 시간과, 평균 대기 시간을 입력받는다.
// Postconditions : 이 함수 종료시, 예측되는 진료시간을 출력한다.
// return : void형 함수이므로 return값은 없으며
// 예측되는 진료시간(대기시간)을 출력한다.
void Addtime(int arrival_minutes, int future_time)
{
	// arrival_minutes에서 시간, 분, PM 추출
	int hour = arrival_minutes / 60;
	// 평균 대기 시간을 더해서 예측되는 진료시간 출력
	int minute = arrival_minutes - (arrival_minutes / 60) * 60 + future_time;
	while (minute >= 60) {
		hour++;
		minute = minute - 60;
	}
	if (hour > 12) {
		hour = hour - 12;
	}

	cout << "예측되는 진료시간은 약 "
		<< hour << "시 " << minute << "분 입니다!";
}