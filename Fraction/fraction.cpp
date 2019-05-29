#include<stdio.h>
#include<stdio.h>
struct Fraction {
	int numerator; // 분자
	int denominator; //분모
};

int abs(int a)
{
	return a > 0 ? a : -a;
}

// 분수를 “분자/분모” 양식으로 출력하는 함수
void print(struct Fraction r)
{
	int numerator, denominator;
	// 분모가 음수인 경우 분모를 양수로 하여 출력
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
// 분수 r을 기약분수 형태로 반환
struct Fraction reduce(struct Fraction r) {
	int gcdNumDen;
	if (r.numerator == 0 || r.denominator == 0)
		return r;
	gcdNumDen = gcd(abs(r.numerator), abs(r.denominator));
	r.numerator /= gcdNumDen;
	r.denominator /= gcdNumDen;
	return r;
}
// 두 분수를 더하여 이를 반환
struct Fraction add(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.denominator + r2.numerator *r1.denominator;
	return reduce(r);  // r을 기약분수로 바꾸어 반환함
}
//두 분수를 뺄셈하여 이를 반환
struct Fraction sub(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
	return reduce(r); //r을 기약분수로 바꾸어 반환함
}
//두 분수를 곱하여 이를 반환
struct Fraction mult(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.denominator;
	r.numerator = r1.numerator * r2.numerator;
	return reduce(r); //r을 기약분수로 바꾸어 반환함
}
//두 분수를 나누어 이를 변환
struct Fraction div(struct Fraction r1, struct Fraction r2) {
	struct Fraction r;
	r.denominator = r1.denominator * r2.numerator;
	r.numerator = r1.numerator * r2.denominator;
	return reduce(r); //r을 기약분수로 바꾸어 반환함
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

