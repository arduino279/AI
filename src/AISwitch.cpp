#include <iostream>
#include <cmath>
#define N 15
float x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
float y[N] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
float a = 0;
float b = 0;
float alpha = 0.0001;

void train_model() {
  while (true) {
    float error = 0;
    for (int i = 0; i < N; i++) {
      error += pow(y[i] - (a * x[i] + b), 2);
    }
    error /= N;
    std::cout << "Error: " << error << std::endl;
    if (error < 0.1) {
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
    alpha / (1 + error); // dynamic learning rate
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
