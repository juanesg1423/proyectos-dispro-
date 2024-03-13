/*FN****************************************************************************
*  Prototipo de la funcion: void Counter_Number(int *count, char *filename);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Cuenta el número de líneas en un archivo y lo almacena en la variable apuntada por 'count'.
*
* *******************************************************************************/
void Counter_Number(int *count, char *filename)
{
    int countx = 0;
    char values[1000];
    FILE *File = fopen(filename, "r");
    if (File == NULL) {
        printf("Error: Cannot open File.\n");
        return;
    }
    while (fgets(values, sizeof(values), File) != NULL)
    {
        countx++;
    }
    *count = countx;
    fclose(File);
}

/*FN****************************************************************************
*  Prototipo de la funcion: int Read_Data(float Matrix[SIZE][SIZE], int Size, char* filename, int count);
*
*  Retorno: Retorna 1 si la lectura de datos es exitosa, 0 si hay un error al abrir el archivo.
*
*  Proposito: Lee datos de un archivo y los almacena en la matriz 'Matrix'.
*
* *******************************************************************************/
int Read_Data(float Matrix[SIZE][SIZE], int Size, char *filename, int count)
{
    FILE *File = fopen(filename, "r");
    if (File == NULL) {
        printf("Error: Cannot open File.\n");
        return 0;
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            int x = fscanf(File, "%f", &Matrix[i][j]);
        }
    }
    fclose(File);
    return 1;
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Print_Matrix(float Matrix[SIZE][SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Imprime la matriz 'Matrix'.
*
* *******************************************************************************/
void Print_Matrix(float Matrix[SIZE][SIZE], int Size, int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%f ", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Matrix_Probability(float Matrix[SIZE][SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Calcula las probabilidades en la matriz 'Matrix' y las actualiza.
*
* *******************************************************************************/
void Matrix_Probability(float Matrix[SIZE][SIZE], int Size, int count)
{
    int one = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (Matrix[i][j] == 1) {
                one++;
            }
        }
        for (int k = 0; k < count; k++) {
            if (Matrix[i][k] == 1) {
                Matrix[i][k] = Matrix[i][k] / one;
            }
        }
        one = 0;
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Abs_Nodos(float Matrix[SIZE][SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Actualiza las filas de la matriz 'Matrix' que contienen ceros.
*
* *******************************************************************************/
void Abs_Nodos(float Matrix[SIZE][SIZE], int Size, int count)
{
    int Zero = 0;
    int rows = 0;
    for (int i = 0; i < count; i++) {
        if (Matrix[i][0] == 0) {
            for (int j = 0; j < count; j++) {
                if (Matrix[i][j] == 0) {
                    Zero++;
                }
                if (Zero == count) {
                    rows = i;
                    if (Zero >= count) {
                        int constant = 1;
                        float result;
                        result = (float)constant / count;
                        for (int j = 0; j < count; j++) {
                            Matrix[rows][j] = result;
                        }
                    }
                    Zero = 0;
                }
            }
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Stochastic_Matrix(float Matrix[SIZE][SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Convierte la matriz 'Matrix' en una matriz estocástica.
*
* *******************************************************************************/
void Stochastic_Matrix(float Matrix[SIZE][SIZE], int Size, int count)
{
    float Alpha = 0.85;
    float sub = 1 - Alpha;
    float div = (float)1 / count;
    int position = 0;
    float add = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            Matrix[i][j] = Matrix[i][j] * Alpha + sub * div;
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Matrix_Transposed(float Matrix[SIZE][SIZE],float MatrixT[SIZE][SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Calcula la matriz transpuesta 'MatrixT' de la matriz 'Matrix'.
*
* *******************************************************************************/
void Matrix_Transposed(float Matrix[SIZE][SIZE], float MatrixT[SIZE][SIZE], int Size, int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            MatrixT[i][j] = Matrix[j][i];
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Print_MatrixT(float MatrixT[SIZE][SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Imprime la matriz transpuesta 'MatrixT'.
*
* *******************************************************************************/
void Print_MatrixT(float MatrixT[SIZE][SIZE], int Size, int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%f ", MatrixT[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Vector_It(float VectorIt[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Inicializa el vector 'VectorIt' con valores de iteración.
*
* *******************************************************************************/
void Vector_It(float VectorIt[SIZE], int Size, int count)
{
    float Iteration = (float)1 / count;
    for (int i = 0; i < count; i++) {
        VectorIt[i] = Iteration;
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Multiplication(float MatrixT[SIZE][SIZE], float VectorIt[SIZE], int Size, int count, float VectorDis[SIZE]);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Realiza la multiplicación de la matriz transpuesta 'MatrixT' por el vector 'VectorIt' y almacena el resultado en 'VectorDis'.
*
* *******************************************************************************/
void Multiplication(float MatrixT[SIZE][SIZE], float VectorIt[SIZE], int Size, int count, float VectorDis[SIZE])
{
    for (int i = 0; i < count; i++) {
        VectorDis[i] = 0;
        for (int j = 0; j < count; j++) {
            VectorDis[i] += (MatrixT[i][j] * VectorIt[j]);
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Print_VectorDis(float VectorDis[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Imprime el vector 'VectorDis'.
*
* *******************************************************************************/
void Print_VectorDis(float VectorDis[SIZE], int Size, int count)
{
    for (int i = 0; i < count; i++) {
        printf("%f ", VectorDis[i]);
    }
    printf("\n");
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Subtraction(float VectorDis[SIZE], float VectorIt[SIZE], float VectorEnd[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Realiza la resta entre el vector 'VectorIt' y el vector 'VectorDis' y almacena el resultado en 'VectorEnd'.
*
* *******************************************************************************/
void Subtraction(float VectorDis[SIZE], float VectorIt[SIZE], float VectorEnd[SIZE], int Size, int count)
{
    float Iteration = (float)1 / count;
    for (int i = 0; i < count; i++) {
        VectorEnd[i] = VectorIt[i] - VectorDis[i];
    }
    for (int i = 0; i < count; i++) {
        VectorEnd[i] = VectorEnd[i] * VectorEnd[i];
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Sum_Root(float VectorEnd[SIZE], int Size, int count, float *distance);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Calcula la raíz cuadrada de la suma de los elementos del vector 'VectorEnd' y almacena el resultado en 'distance'.
*
* *******************************************************************************/
void Sum_Root(float VectorEnd[SIZE], int Size, int count, float *distance)
{
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum = sum + VectorEnd[i];
    }
    *distance = sqrt(sum);
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Compare(float VectorIt[SIZE], float VectorDis[SIZE], float distance, int count, int Size, int *Iteration);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Compara el valor de 'distance' con un umbral 'Epsilon' para determinar si se debe continuar la iteración o detenerse.
*             Actualiza el vector 'VectorIt' si es necesario.
*
* *******************************************************************************/
void Compare(float VectorIt[SIZE], float VectorDis[SIZE], float distance, int count, int Size, int *Iteration)
{
    float Epsilon = 0.01;
    if (distance < Epsilon) {
        printf("\n\nEs verdadero\n");
        *Iteration = 0;
    } else {
        for (int i = 0; i < count; i++) {
            VectorIt[i] = VectorDis[i];
        }
        *Iteration = 1;
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void VectorDis_Memory(float VectorDis[SIZE], float VectorMemory[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Copia los valores del vector 'VectorDis' al vector 'VectorMemory'.
*
* *******************************************************************************/
void VectorDis_Memory(float VectorDis[SIZE], float VectorMemory[SIZE], int Size, int count)
{
    for (int i = 0; i < count; i++) {
        VectorMemory[i] = VectorDis[i];
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Organize(float VectorDis[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Organiza los elementos del vector 'VectorDis' en orden descendente.
*
* *******************************************************************************/
void Organize(float VectorDis[SIZE], int Size, int count)
{
    int pos = 0;
    float tmp = 0;
    for (int i = 0; i < count - 1; i++) {
        pos = i;
        for (int j = i + 1; j < count; j++) {
            if (VectorDis[j] > VectorDis[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            tmp = VectorDis[i];
            VectorDis[i] = VectorDis[pos];
            VectorDis[pos] = tmp;
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Position(float VectorDis[SIZE], float VectorMemory[SIZE], int VectorPos[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Asigna a 'VectorPos' las posiciones correspondientes de los elementos de 'VectorMemory' en 'VectorDis'.
*
* *******************************************************************************/
void Position(float VectorDis[SIZE], float VectorMemory[SIZE], int VectorPos[SIZE], int Size, int count)
{
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (VectorMemory[i] == VectorDis[j]) {
                // Verificar si la posición ya ha sido asignada
                bool alreadyAssigned = false;
                for (int k = 0; k < i; k++) {
                    if (VectorPos[k] == j) {
                        alreadyAssigned = true;
                        break;
                    }
                }
                if (!alreadyAssigned) {
                    VectorPos[i] = j; // Actualiza el vector de posiciones con la posición actual del vector de distancias
                    break;
                }
            }
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Repeated(int VectorPos[SIZE], int count, int Size);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Ajusta las posiciones repetidas en 'VectorPos' para evitar conflictos.
*
* *******************************************************************************/
void Repeated(int VectorPos[SIZE], int count, int Size)
{
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (VectorPos[i] == VectorPos[j]) {
                VectorPos[j] = VectorPos[j] + 1;
            }
        }
    }
}

/*FN****************************************************************************
*  Prototipo de la funcion: void Print_Ranking(int VectorPos[SIZE], float VectorDis[SIZE], int Size, int count);
*
*  Retorno: No tiene retorno (void).
*
*  Proposito: Imprime el ranking de posiciones y sus respectivas distancias.
*
* *******************************************************************************/
void Print_Ranking(int VectorPos[SIZE], float VectorDis[SIZE], int Size, int count)
{
    printf("El Ranking es:\n");
    for (int i = 0; i < count; i++) {
        printf("%d", VectorPos[i]);

        for (int j = 0; j < 1; j++) {
            printf(" %4f", VectorDis[i]);
        }
        printf("\n");
    }
    printf("\n");
}
