#include "Funciones.h"
#define SIZE 3292

int main(void) {
    int Iteration = 0;
    int count = 3292;
    float distance = 0;
    char *filename = "readme.txt";
    //Counter_Number (&count, filename);
    Read_Data(Matrix, SIZE, filename, count);
    //Print_Matrix(Matrix, SIZE, count);
   	//Counter_Number (&count, filename);
    //Print_Counter_Number(); 
    Matrix_Probability(Matrix, SIZE, count);
    //Print_Matrix(Matrix, SIZE, count);
    Abs_Nodos(Matrix,SIZE,count);
    //Print_Matrix(Matrix, SIZE, count);
    Stochastic_Matrix(Matrix, SIZE, count);
    //Print_Matrix(Matrix, SIZE, count);
    Matrix_Transposed(Matrix,MatrixT, SIZE, count);
    //Print_MatrixT(MatrixT, SIZE, count);
    Vector_It(VectorIt,SIZE,count);
    Multiplication (MatrixT,VectorIt,SIZE, count, VectorDis);
    //Print_MatrixT(MatrixT, SIZE, count);
    //Print_VectorDis(VectorDis, SIZE, count);
    Subtraction(VectorDis,VectorIt,VectorEnd, SIZE, count);
   	// Print_VectorDis(VectorDis, SIZE, count);
    Sum_Root(VectorEnd,SIZE,count, &distance);
    Compare(VectorIt,VectorDis,distance,count,SIZE,&Iteration);
    
  while(Iteration==1)
    {
      Multiplication (MatrixT,VectorIt,SIZE, count, VectorDis);
      //Print_MatrixT(MatrixT, SIZE, count);
      //Print_VectorDis(VectorDis, SIZE, count);
      Subtraction(VectorDis,VectorIt,VectorEnd, SIZE, count);
      //Print_VectorDis(VectorDis, SIZE, count);
      Sum_Root(VectorEnd,SIZE,count, &distance);
      Compare(VectorIt,VectorDis,distance,count,SIZE, &Iteration);
    }
    VectorDis_Memory(VectorDis,VectorMemory,SIZE,count);
    //Print_VectorDis(VectorDis, SIZE, count);
    Organize(VectorDis,SIZE,count);
    //Print_VectorDis(VectorDis, SIZE, count);
    Position(VectorDis,VectorMemory, VectorPos, SIZE,count);
    //Repeated(VectorPos,count,SIZE);
    Print_Ranking(VectorPos,VectorDis, SIZE, count);
    
    
    
    return 0;
}
