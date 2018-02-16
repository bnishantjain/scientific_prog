#include<stdio.h>
#maximum row is 3
#maximum column is 3
#matrix row is 4
#matrix column is 4
/*
 *   determinant is name of the function 
 * input: float matrix[rows][columns]
 *
*/

float determinant(float matrix[rows][columns])
{

	return matrix[0][0]*matrix[1][1]*matrix[2][2] + 
		matrix[0][1]*matrix[1][2]*matrix[2][0] +  
		matrix[0][2]*matrix[1][0]*matrix[2][1] - 
		matrix[0][0]*matrix[1][2]*matrix[2][1] - 
		matrix[0][1]*matrix[1][0]*matrix[2][2] - 
		matrix[0][2]*matrix[1][1]*matrix[2][0]; 
}


/*
* FUCNTION NAME   : cramer_rule
 * PARAMETER IN    : float hilbert_matrix[hilber_rows][hilber_columns]
 *                   float temp_matrix[rows][columns],int ignore_col
*/

void cramer_rule(
		float hilbert_matrix[hilber_rows][hilber_columns],
		float temp_matrix[rows][columns], int ignore_col)
{
	int row = 0, col = 0, i= 0, j =0;

	for (row = 1; row < HILBERT_MATRIX_ROWS; row++)
	{
		for (col = 0; col < HILBERT_MATRIX_COLS; col++)
		{
			if (ignore_col == col)
			{
				continue;
			}

			temp_matrix[i][j] = hilbert_matrix[row][col];
			j++;
		}

		i++;
		j = 0;
	}

	return;
}

/*
* FUCNTION NAME   : cramers_rule_for_determinant
 * PARAMETER IN    : float hilbert_matrix[HILBERT_MATRIX_ROWS]
 *                                       [HILBERT_MATRIX_COLS]
*/

float cramers_rule_for_determinant(float hilbert_matrix[hilber_rows][hilber_columns])
{

	float detA = 0, detB = 0, detC= 0, detD = 0;
	float temp_matrix[MAX_ROWS][MAX_COLS];
	float determinant = 0.0;
	int row = 0, col = 0, i= 0, j =0;
        cramer_rule(hilbert_matrix, temp_matrix, 0);
	detA = determinant(temp_matrix);

        cramer_rule(hilbert_matrix, temp_matrix, 1);

	detB = determinant(temp_matrix);

        cramer_rule(hilbert_matrix, temp_matrix, 2);

	detC = determinant(temp_matrix);

        cramer_rule(hilbert_matrix, temp_matrix, 3);

	detD = determinant(temp_matrix);

	determinant = hilbert_matrix[0][0]*detA -
		hilbert_matrix[0][1]*detB +
		hilbert_matrix[0][2]*detC -
		hilbert_matrix[0][3]*detD;

	return determinant;
}


/*

/*
 * name of function   : collatz_conjecture
 * input  : k_int num
 */
*/
int main()
{
	int row = 0,col = 0;
	float determinant = 0;
	float hilbert_matrix[hilber_rows][hilber_columns];
	for (row = 0; row < HILBERT_MATRIX_ROWS; row++)
	{
		for (col = 0; col < HILBERT_MATRIX_COLS; col++)
		{
			hilbert_matrix[row][col] = (float)1/(row+1+col);
		}
	}

	determinant = cramers_rule_for_determinant(hilbert_matrix);

	printf("\n**"); 
	printf("\n Hilbert matrix for determinant (4X4) is\r\n");
	printf("**\n");

	for (row = 0; row < HILBERT_MATRIX_ROWS; row++)
	{
		for (col = 0; col < HILBERT_MATRIX_COLS; col++)
		{
			printf("%f\t",hilbert_matrix[row][col]);
		}
		printf("\n");
	}

	printf("\n*");
	printf("\n determinant of 4X4 hilbertmatrix is ===> %.10f\r\n", determinant);
	printf("**\n");

	return 0;
}

