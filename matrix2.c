#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define num20


/* Method Declaration */
int** create_matrix(int row, int col);      // ÇÔ¼ö »ý¼Í
void print_matrix(int** matrix, int row, int col);  // ÇÔ¼ö Ãâ·Â
int free_matrix(int** matrix, int row, int col);    // ÇÒ´ç Ãë¼Ò   
int fill_data(int** matrix, int row, int col);      // µ¥ÀÌÅÍ ³ÖÀ½
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);  // µ¡¼À
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);   // »¬¼À
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);       // ÀüÄ¡
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);  // °ö¼À

int main()
{

    char command;
    printf("[----- [½ÅÅÂ¾ç]  [2017038096] -----]\n");
    int row, col;

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);       // Çà·Ä ÀÔ·Â 
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);
    printf("\nMatrix Created.\n");

    printf("A\n");
    print_matrix(matrix_a, row, col);
    printf("----------------------------\n");
    printf("B\n");
    print_matrix(matrix_b, row, col);
    printf("----------------------------\n");

    srand((unsigned)time(NULL));

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }

    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            print_matrix(matrix_a, col, row);
            printf(" ÀüÄ¡ ÈÄ\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    int count = 0;
    int** arr = (int**)malloc(sizeof(int) * row);
    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(sizeof(int) * col);
    }

    // ÃÊ±âÈ­
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }

    return(arr);
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }printf("\n");
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {

            matrix[i][j] = rand() % 20; // 0~19 »çÀÌÀÇ ³­¼ö°¡ Ãâ·ÂµË´Ï´Ù.
        }
    }
    print_matrix(matrix, row, col);
    return 1;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_result = create_matrix(col, row);
    int r, c;
    for (r = 0; r < row; r++) {

        for (c = 0; c < col; c++) {

            matrix_result[r][c] = matrix_a[r][c] + matrix_b[r][c];      // µ¡¼À
        }
    }
    print_matrix(matrix_result, row, col);
    free_matrix(matrix_result, row, col);   // ÇÁ¸®
    return 1;
}

/* matrix_sub = matrix_a - matrix_b */  
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_result = create_matrix(col, row);
    int r, c;
    for (r = 0; r < row; r++) {

        for (c = 0; c < col; c++) {

            matrix_result[r][c] = matrix_a[r][c] - matrix_b[r][c];      // »¬¼À
        }
    }
    print_matrix(matrix_result, row, col);
    free_matrix(matrix_result, row, col);
    return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    int r, c;
    for (r = 0; r < row; r++) {

        for (c = 0; c < col; c++) {

            matrix_t[c][r] = matrix[r][c];      // ÀüÄ¡
        }
    }
    return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)  // °ö¼À
{
    int i, j, k;
    int** matrix_result = create_matrix(col, row);

    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            for (k = 0; k < col; k++) {
                matrix_result[i][j] += matrix_a[i][k] * matrix_t[k][j];
            }
        }
    }
    if (row > col) {
        print_matrix(matrix_result, col, col);
    }
    else {
        print_matrix(matrix_result, row, row);
    }
    return 1;
}