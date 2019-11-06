#include "Prime.h"


Prime::~Prime() {
}

// �ж�n�Ƿ�Ϊ����
bool Prime::isPrime(unsigned n) {
	bool is_prime = false;
	int sqrt_of_n = static_cast<int>(sqrt(n));
	unsigned i;

	// ��n�ֱ����2������n��������������������
	for (i = 2; i <= sqrt_of_n; ++i) {
		if (!(n % i))	break;
	}

	// û������������n��nΪ����
	if (i == 1 + sqrt_of_n)	is_prime = true;

	return is_prime;
}

// ��ð���ǰn������������
std::vector<unsigned> Prime::getPrimeSequence() {
	unsigned n = 2;
	unsigned count = amount;

	while (count) {
		if (isPrime(n)) {
			primes.push_back(n);
			--count;
		}
		++n;
	}

	return primes;
}
