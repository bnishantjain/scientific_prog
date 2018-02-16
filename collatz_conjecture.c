
defining first number as 4
#defining second number as 2
defining third number as 1
defining maximum display strength as 40 

/*
 * name of function   : collatz_conjecture
 * input  : k_int num
 */
u_int collatz_conjecture(k_int num)
{
	u_int result = 0;
	if (num % 2 == 0)
	{
		result = num/2;
	}
	else
	{
		result = (3*num)+1;
	}

	/* Return the result as per the input to this function*/
	return result;
}


/*
*name of function : count
 * input  : k_int num
*/

u_int count(k_int num)
{
	u_int count = 0;

        if (num == 0)
        {
           return count;
        }

	while(num != 0)
	{
		num /= 10;
		count++;
	}

	return count;
}


/********************************************************************
 *name of fucntion   : print_inOrder
 * input : k_int num, int *str_position, int is_third_num
 
*/

void print_inOrder(k_int num, int *str_position, u_int is_third_num)
{
	u_int ndigits = 0;

	ndigits = count(num);

	if (*str_position + 1 + ndigits  > MAX_DISPLAY_STRING_LEN)
	{
                /*Exceeds the 40 characeter in the single line*/
		printf("\n");
		*str_position = 0;
	}

	if (is_third_num == 1 && num == 1)
	{
		printf("%u\n",num);
	}
	else
	{
		printf("%u, ", num);
	}

	*str_position = *str_position + 2 + ndigits;
return;
}

/*
 *name of function  : main
 * input  : int argc, char *argv[]
 */

int main(int argc, char *argv[])
{

	k_int num = 0;
	int ndigits = 0;
	int str_position = 0;

	/* Check input is specified valid number*/

	if (argc != 2)
	{
		printf("check the Input again \n");
		return 0;
	}

	num = atoi(argv[1]);
 
	while (num > 0)
	{
		if (num == FIRST_NUM)
		{
			print_inOrder(FIRST_NUM, &str_position, 0);
			print_inOrder(SECOND_NUM, &str_position, 0);
			print_inOrder(THIRD_NUM, &str_position, 1);

			break;
		}

		print_inOrder(num, &str_position, 0);

		num = collatz_conjecture(num);
	}
   
	return 0;
}
