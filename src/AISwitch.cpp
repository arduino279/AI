#include <iostream>
#define N 10
float x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float y[N] = {2, 4, 5, 7, 9, 11, 12, 15, 16, 18};
float a = 0;
float b = 0;
float alpha = 0.01;

void train_model() {
  while (true) {
    float error = 0;
    for (int i = 0; i < N; i++) {
      error += pow(y[i] - (a * x[i] + b), 2);
    }
    error /= N;
    std::cout << "Generating Output ... " << b << std::endl;
    if (error < 0.01) {
      break;
    }
    float da = 0;
    float db = 0;
    for (int i = 0; i < N; i++) {
      da += -2 * x[i] * (y[i] - (a * x[i] + b));
      db += -2 * (y[i] - (a * x[i] + b));
    }
    da /= N;
    db /= N;
    a = a - alpha * da;
    b = b - alpha * db;
  }
}

float predict(float x) {
  return a * x + b;
}

int main() {
  train_model();
  std::cout << "Input: ";
  float x_new;
  std::cin >> x_new;
  float y_new = predict(x_new);
  std::cout << "Output: " << y_new << std::endl;
  return 0;
}
