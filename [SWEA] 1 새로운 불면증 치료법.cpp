#include <iostream>
#include <string>

int Solution(int n) {

	int total = (1 << 10) - 1;	// total: 모든 숫자를 봤을 때의 값 -> 1'111'111'111
	int visited = 0;	// visited: 본 숫자 입력
	int cnt = 0;	// cnt: 배수의 값

	while(visited != total) {	// 모든 수를 봤다면 종료
		std::string strNum = std::to_string(n * (++cnt));	// strNum: 이번 숫자

		for(const char& c : strNum) {	// c: 자리수 검사
			int num = c - '0';	// num: 자리수의 값
			visited |= (1 << num);	// 방문 체크
		}
	}

	return n * cnt;
}

void Input(int& n) {

	std::cin >> n;

	return;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;	// T: 테스트 케이스의 수
	std::cin >> T;

	for(int tc=1; tc<= T; ++tc) {	// tc: 테스트 케이스 번호
		int n;	// n: 양 세기 배수 1 <= n <= 10^6
		Input(n);

		std::cout << '#' << tc << ' ' << Solution(n) << '\n';
	}

	return 0;
}