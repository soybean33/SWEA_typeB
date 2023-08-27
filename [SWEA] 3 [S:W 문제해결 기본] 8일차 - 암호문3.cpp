#include <iostream>
#include <list>

void InputSolution(int& n, std::list<int>& l) {	
	int m;	// m: 명령의 개수
	std::cin >> m;

	for(int i=0; i<m; ++i) {
		char order;	// order: 명령어 -> I 삽입, D 삭제, A 추가

		std::cin >> order;

		if(order == 'I') {	// I x y s: 앞에서부터 x번째 암호문 바로 다음에 y개의 암호문을 삽입, s는 덧붙일 암호문
			int x, y, s;	// x: 삽입할 암호문 위치, y: 삽입할 암호문의 개수, s: 삽입할 암호문
			std::cin >> x >> y;
			
			std::list<int>::iterator it = l.begin();	// it: 반복자
			for(int i=0; i<x; ++i) {++it;}	// 해당 위치 까지 이동
			for(int i=0; i<y; ++i) {
				std::cin >> s;
				l.insert(it, s);	// 삽입
			}

		}
		else if(order == 'D') {	// D x y: 앞에서부터 x번째 암호문 바로 다음부터 y개의 암호문을 삭제
			int x, y;	// x: 삭제할 암호문 위치, y: 삭제할 암호문의 개수
			std::cin >> x >> y;

			std::list<int>::iterator it = l.begin();	// it: 반복자
			for(int i=0; i<x-1; ++i) {++it;};
			for(int i=0; i<y; ++i) {
				it = l.erase(it);	// 삭제 -> 다시 해당 위치를 삭제해야하므로 return 값 받음
			}
		}
		else if(order == 'A') {	// A y s: 암호문 뭉치 맨 뒤에 y개의 암호문을 덧붙임, s는 덧붙일 암호문
			int y, s;	// y: 덧붙일 암호문의 개수, s: 덧붙일 암호문
			std::cin >> y;

			for(int i=0; i<y; ++i) {
				std::cin >> s;
				l.push_back(s);
			}
		}
	}

	std::list<int>::iterator it = l.begin();	// it: 반복자
	for(int i=0; i<10; ++i) {	// 10개의 암호문 출력
		std::cout << *it << ' ';
		++it;
	}

	return;
}

void Input(int& n, std::list<int>& l) {

	std::cin >> n;

	for(int i=0; i<n; ++i) {
		int ciphertext;	// ciphertext: 원본 암호문
		std::cin >> ciphertext;
		l.push_back(ciphertext);
	}

	return;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	for(int tc=1; tc<=10; ++tc) {	// 10개의 테스트 케이스
		int n;	// n: 원본 암호문 뭉치 속 암호문의 개수
		std::list<int> l;	// l[i]: i 번째 암호문

		Input(n, l);

		std::cout << '#' << tc << ' ';
		InputSolution(n, l);
		std::cout << '\n';
	}

	return 0;
}