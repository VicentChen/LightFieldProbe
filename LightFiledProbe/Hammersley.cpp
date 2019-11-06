#include "Hammersley.h"


Hammersley::Hammersley(unsigned d, unsigned a) : Sequence(d, a) {
	Prime p(dimension - 1);
	bases = p.getPrimeSequence();
	calcSequence();
}

Hammersley::Hammersley(std::vector<unsigned> b, unsigned a) : Sequence(b.size() + 1, a) {
	bases = b;
	calcSequence();
}


Hammersley::~Hammersley()
{
}

// ��������index�ڻ�Ϊbase��radical inversion
double Hammersley::radicalInversion(unsigned base, unsigned index) {
	int weight = 1;					// ���λ��Ȩ��
	double result = 0;

	// ��index��base����������
	for (; index; index /= base) {
		result = result * base + index % base;
		weight *= base;
	}

	// ������Ƶ�С�����Ҳ�
	return result / weight;
}

// ����dά�ռ�������Ϊindex�ڻ�Ϊbase��Hammersley��
std::vector<double> Hammersley::getHammersleyPoint(unsigned index) {
	std::vector<double> point;

	// ��һά��index���Ե������
	point.push_back(static_cast<double>(index) / static_cast<double>(amount));

	// ���μ�����õ�ÿһά������ֵ
	for (const auto &p : bases) {
		point.push_back(radicalInversion(p, index));
	}

	return point;
}

void Hammersley::calcSequence()
{
	for (unsigned i = 0; i < amount; ++i) {
		points.push_back(getHammersleyPoint(i));
	}
}