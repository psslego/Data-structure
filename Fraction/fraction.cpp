#include<stdio.h>
#include<stdio.h>
struct Fraction {
	int numerator; // ����
	int denominator; //�и�
};

int abs(int a)
{
	return a > 0 ? a : -a;
}

// �м��� ������/�и� ������� ����ϴ� �Լ�
void print(struct Fraction r)
{
	int numerator, denominator;
	// �и� ������ ��� �и� ����� �Ͽ� ���
	if (r.denominator < 0) {
		r.numerator *= -1;
		r.denominator *= -1;
	}

	printf("%d/%d\n", r.numerator, r.denominator);
}


int gcd(int a, int b) {
	int r;
	while (a % b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return b;
}
// �м� r�� ���м� ���·� ��ȯ
struct Fraction reduce(struct Fraction r) {
	int gcdNumDen;
	if (r.numerator == 0 || r.denominator == 0)
		return r;
	gcdNumDen = gcd(abs(r.numerator), abs(r.denominator));
	r.numerator /= gcdNumDen;
	r.denominator /= gcdNumDen;
	return r;
}
// �� �м��� ���Ͽ� �̸� ��ȯ
struct Fraction add(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.denominator + r2.numerator *r1.denominator;
	return reduce(r);  // r�� ���м��� �ٲپ� ��ȯ��
}
//�� �м��� �����Ͽ� �̸� ��ȯ
struct Fraction sub(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
	return reduce(r); //r�� ���м��� �ٲپ� ��ȯ��
}
//�� �м��� ���Ͽ� �̸� ��ȯ
struct Fraction mult(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.numerator;
	return reduce(r); //r�� ���м��� �ٲپ� ��ȯ��
}
//�� �м��� ������ �̸� ��ȯ
struct Fraction div(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.numerator;
	r.numerator = r1.numerator * r2.denominator;
	return reduce(r); //r�� ���м��� �ٲپ� ��ȯ��
}

int main() {
	struct Fraction r1, r2, result;
	scanf("%d%d%d%d", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
	result = add(r1, r2);
	print(add(r1, r2));
	result = sub(r1, r2);
	print(sub(r1, r2));
	result = mult(r1, r2);
	print(mult(r1, r2));
	result = div(r1, r2);
	print(div(r1, r2));

	return 0;
}

