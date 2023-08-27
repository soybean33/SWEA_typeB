#include <iostream>
#include <string>

std::string Solution(const int& n, const int& m) {
	std::string answer = "OFF";	// answer: 마지막 N개의 비트가 모두 켜져 있다면 "ON", 아니면 "OFF"

	int lastNBit = (1 << n) - 1;	// lastNBit: 마지막 N개의 비트를 1로 표시 2^N - 1
	if(lastNBit == (m & lastNBit)) {answer = "ON";}	// AND 연산을 한 값이 같다면 N개의 비트가 모두 1

	return answer;
}

void Input(int& n, int& m) {

	std::cin >> n >> m;

	return;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t;	// t: 테스트 케이스의 개수
	std::cin >> t;

	for(int tc=1; tc<=t; ++tc) {	// tc: 테스트 케이스 번호
		int n, m;
		Input(n, m);

		std::cout << '#' << tc << ' ' << Solution(n, m) << '\n';
	}

	return 0;
}