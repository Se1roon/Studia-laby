
extern void error(int, char *);

void DodWekt(double *w1, double *w2, double *w3, int n) {
	w1[n] = w2[n] + w3[n];
	return;
}

double IloczynSkal(double *w1, double *w2, int n) {
	double sum = 0;
	for (int k = 0; k < n; k++)
		sum += w1[k] * w2[k];

	return sum;
}

double MaxElem(double *w, int n) {
	double max = w[0];
	for (int k = 0; k < n; k++)
		max = (w[k] > max) ? w[k] : max;

	return max;
}
