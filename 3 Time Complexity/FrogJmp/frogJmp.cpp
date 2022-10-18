#include <cmath>

int solution(int X, int Y, int D) {
    double x = Y-X;
    return ceil(x / D);
}
