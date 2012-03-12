#include <stdlib.h>
#include <stdio.h>

#define EPS 0.000001

static float fabsf(float x) {
  return x < 0 ? -x : x;
}

static int sqrt_good_enough(float x, float guess) {
  return fabsf(x/guess - guess) < EPS * guess;
}

static float sqrt_improve(float guess, float x) {
  return (guess + x/guess)/2;
}

static float sqrt_iter(float x, float guess) {
  if (sqrt_good_enough(x, guess))
    return guess;
  else
    return sqrt_iter(x, sqrt_improve(guess, x));
}

float sqrt(float x) {
  if (x == 0.0) return 0.0;
  else return sqrt_iter(x, 1.0f);
}

int main(int argc, char** argv) {
  float x = atof(argv[1]);
  printf("The square root of %.2f is %.2f\n", x, sqrt(x));
  return 0;
}

