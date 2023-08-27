#include <iostream>
#include <list>

int Solution(int m, const int& l, std::list<int>& linkedList) {

	while(m--) {	// m 번 반복
		char order;	// order: 명령
		std::cin >> order;

		if(order == 'I') {	// I index num: index번 인덱스 앞에 num을 추가하고, 한 칸 씩 뒤로 이동
			int index, num;	// index: 인덱스, num: 추가할 번호
			std::cin >> index >> num;

			std::list<int>::iterator it = linkedList.begin();	// it: 반복자
			for(int i=0; i<index; ++i) {++it;}	// 삽입 위치까지 이동
			linkedList.insert(it, num);	// 삽입
		}
		else if(order == 'D') {	// D index: index번 인덱스 자리를 지우고, 한 칸 씩 앞으로 이동
			int index;	// index: 인덱스
			std::cin >> index;

			std::list<int>::iterator it = linkedList.begin();	// it: 반복자
			for(int i=0; i<index; ++i) {++it;}	// 삭제 위치까지 이동
			linkedList.erase(it);	// 삭제
		}
		else if(order == 'C') {	// C index num: index번 인덱스 자리를 num으로 바꿈
			int index, num;	// index: 인덱스, num: 바꿀 수
			std::cin >> index >> num;

			std::list<int>::iterator it = linkedList.begin();	// it: 반복자
			for(int i=0; i<index; ++i) {++it;}	// 변경 위치까지 이동
			*it = num;	// 변경
		}
	}

	if(linkedList.size() > l) {	// 편집이 끝난후 l 번 인덱스가 있는 경우
		std::list<int>::iterator it = linkedList.begin();	// it: 반복자
		for(int i=0; i<l; ++i) {++it;}	// l 번 인덱스까지 이동
		return *it;	// l 번 인덱스 값 return
	}

	return -1;	// l이 존재하지 않으면 -1
}

void Input(int& n, int& m, int& l, std::list<int>& linkedList) {

	std::cin >> n >> m >> l;

	for(int i=0; i<n; ++i) {	// n개의 수 입력
		int num;	// num: 수
		std::cin >> num;
		linkedList.push_back(num);
	}

	return;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t;	// t: 테스트케이스의 수

	std::cin >> t;

	for(int tc=1; tc<=t; ++tc) {
		int n, m, l;	// n: 수열의 길이, m: 추가 횟수, l: 출력할 인덱스 번호
		std::list<int> linkedList;	// linkedList: 연결 리스트

		Input(n, m, l, linkedList);

		std::cout << '#' << tc << ' ' << Solution(m, l, linkedList) << '\n';
	}

	return 0;
}