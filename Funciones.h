#include <stdbool.h>
#define SIZE 3292

int Read_Data(float Matrix[SIZE][SIZE], int Size, char* filename, int count);
void Print_Matrix(float Matrix[SIZE][SIZE], int Size, int count);
void Counter_Number (int *count, char*filename);
void Abs_Nodos(float Matrix[SIZE][SIZE], int Size, int count);
void Matrix_Probability(float Matrix[SIZE][SIZE], int Size, int count);
void Stochastic_Matrix(float Matrix[SIZE][SIZE], int Size, int count);
void Matrix_Transposed (float Matrix[SIZE][SIZE],float MatrixT[SIZE][SIZE], int Size, int count);
void Print_MatrixT(float MatrixT[SIZE][SIZE], int Size, int count);
void Vector_It(float VectorIt[SIZE], int Size, int count);
void Multiplication (float MatrixT[SIZE][SIZE],float VectorIt[SIZE], int Size, int count, float VectorDis[SIZE]);
void Print_VectorDis(float VectorDis[SIZE], int Size, int count);
void Subtraction(float VectorDis[SIZE],float VectorIt[SIZE],float VectorEnd[SIZE], int Size, int count);
void Sum_Root(float VectorEnd[SIZE], int Size, int count, float *distance);
void Compare(float VectorIt[SIZE],float VectorDis[SIZE],float distance,int count,int Size, int *Iteration);
void Organize(float VectorDis[SIZE], int Size, int count);
void VectorDis_Memory(float VectorDis[SIZE],float VectorMemory[SIZE],int Size, int count);
void Position(float VectorDis[SIZE],float VectorMemory[SIZE],int VectorPos[SIZE],int Size, int count);
void Print_Ranking(int VectorPos[SIZE],float VectorDis[SIZE], int Size, int count);
void Repeated(int VectorPos[SIZE],int count,int Size);


float Matrix[SIZE][SIZE];
float MatrixT[SIZE][SIZE];
float VectorIt[SIZE];
float VectorDis[SIZE];
float VectorEnd[SIZE];
float VectorMemory[SIZE];
int VectorPos[SIZE];



