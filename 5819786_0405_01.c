#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

struct term {
	float coef;
	int expon;
}terms[MAX_TERMS] = { {4.0,3}, {3.0,2}, {2.0,1}, {1.0,0}, {3.0,2}, {2.0,1}, {8.0,0} };
int avail = 7;

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		if (terms[i].coef == 0.0) {
			continue;
		}
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1f\n", terms[e].coef);
}


struct term poly_multiply(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	*Cs = avail + 1;
	int C_index = 0;
	for (int i = As;i <= Ae;i++) {
		for (int j = Bs;j <= Be;j++) {
			terms[*Cs + C_index].coef = terms[i].coef * terms[j].coef;
			terms[*Cs + C_index].expon = terms[i].expon + terms[j].expon;
			C_index++;
		}
	}

	for (int i = *Cs; i < *Cs + C_index; i++) {
		for (int j = i + 1; j < *Cs + C_index; j++) {
			if (terms[i].expon == terms[j].expon) {
				terms[i].coef += terms[j].coef;
				terms[j].coef = 0;
			}
		}
	}
	*Ce = *Cs + C_index - 1;
};


int main() {
	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;

	print_poly(As, Ae);
	print_poly(Bs, Be);
	poly_multiply(As, Ae, Bs, Be, &Cs, &Ce);

	printf("------------------------------------------------------------\n");
	print_poly(Cs, Ce);

	return 0;
}