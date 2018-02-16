

# PI (3.14159265)
#LOWER_BOUND is (0)
#UPPER_BOUND is (PI/3)


/********************************************************************
 * FUCNTION NAME   : simpson_rule
 * PARAMETER IN    : int number_of_points
  ********************************************************************/

float simpson_rule(int number_of_points)
{
	float area = 0.0;
	int i = 0;
	float interval_value = 0.0;
        int number_of_interval = 0;

        number_of_interval =  number_of_points + 1;

 	interval_value = (UPPER_BOUND - LOWER_BOUND)/number_of_interval;

        area = tan(LOWER_BOUND) + tan(UPPER_BOUND);

	for (i = 1; i <= (number_of_points); i++)
	{
		if (i % 2 == 0)
		{
			area += (2*tan(i*interval_value));
		}
		else
		{
			area +=  (4*tan(i*interval_value));
		}
	}

	area = (area * interval_value)/3;

	return area;
}

/* * FUCNTION NAME   : main
 * PARAMETER IN    : 
**/

int main()
{
	int number_of_points = 0;
	float area = 0.0;
	float actual_result = 0.0;
        float threshold = 0.00001;

	scanf("%d", &number_of_points);

	if (number_of_points % 2 == 0)
	{
		printf("enter the odd value\n");
		return 0;
	}

	area = simpson_rule(number_of_points);

	actual_result = -log(cos(UPPER_BOUND)) + log(cos(LOWER_BOUND));

	
	printf("\n RESULT : log(2) is the integral Value of(y = tan(x); 0 <= x <= Pi/3) ", actual_result); 
        printf("*******************************************************************************************************************\n");

        number_of_points = 0;

        do {
             
         number_of_points += 1;
      
         area = simpson_rule(number_of_points);

       } while(fabs(actual_result - area) >= threshold);  

       printf("\n");
       printf("\nnumber of intervals =====> %d\r\n", number_of_points + 1);
       printf("\nnumber of points    =====> %d\r\n", number_of_points + 2);
       printf("*****************************************************\n");

       return 0;
}

