// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double otvet = 1;
  double i = 1;
  if (n == 1) {
    return value;
  } else {
	while (i <= n) {
      otvet *= value;
	  i++;
	}
    }
  return  otvet;
}

uint64_t fact(uint16_t n) {
  if ((n == 1) || (n == 0)) {
    return 1;
  } else {
    return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
  double otvet = pown(x, n) / fact(n);
  return otvet;
}

double expn(double x, uint16_t count) {
  double n = 1;
  double otvet = 1;
  if (x == 0) {
    return 1;
  } else {
	  while (n <= count) {
	    otvet = otvet + calcItem(x, n);
		n++;
	  }
	}
  return otvet;
}

double sinn(double x, uint16_t count) {
  double otvet = 0;
  double n = 1;
  while (n <= count) {
    double n_1 = 2 * n - 1;
    double n_2 = pow(-1, n - 1);
    otvet = n_2 * calcItem(x, n_1) + otvet;
    n++;
  }
  return otvet;
}

double cosn(double x, uint16_t count) {
  double otvet = 0;
  double n = 1;
  while (n <= count) {
    double n_1 = 2 * n - 2;
    double n_2 = pow(-1, n - 1);
    otvet = n_2 * calcItem(x, n_1) + otvet;
    n++;
  }
  return otvet;
}
