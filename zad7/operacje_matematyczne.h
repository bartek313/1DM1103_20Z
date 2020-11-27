#ifndef operacje_matematyczne.h
#define operacje_matematyczne.h

void suma(struct Macierz m1, struct Macierz m2, struct Macierz *m3);
void substract(struct Macierz m1, struct Macierz m2, struct Macierz *m3);
float prodSkalarny(struct Macierz m1, struct Macierz m2);
void prodWektorowy(struct Macierz m1, struct Macierz m2, struct Macierz *m3);
void multiply(struct Macierz m1, float a, struct Macierz *m3);
float norm(struct Macierz m1);

#endif