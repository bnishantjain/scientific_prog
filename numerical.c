
# TRAPEZOIDAL_RULE 
# SIMPSON_RULE 
# GAUSS_QUADRATURE 

int main()
{
  int  number_of_interval = 0;
  int method_of_integration = 0;
  float area = 0.0;
  int i = 0;

  printf("\nnumericalIntegration\r\n\n");

  printf("  1 ---> Trapezoidal Rule\n");
 
  printf("  2 ---> Simpson's Rule\n");

  printf("  3 ---> Gauss Quadrature\n\n");

  printf("Press 1 or 2 or 3 ===>  ");

  scanf("%d", &method_of_integration);

  if (method_of_integration < 1 || method_of_integration > 3)
  {
     printf("enter the valid integration type\n");
     return 0;
  }

  switch(method_of_integration)
  {
    case TRAPEZOIDAL_RULE:
         printf("\n number of Intervals  ");

         scanf("%d", &number_of_interval);
         area = trapezodial_rule(number_of_interval);       
         printf("\nArea using Trapezodial Rule for interval[ %d ] is %.10f\n", number_of_interval, area);
    break;

    case SIMPSON_RULE:
         printf("\nEnter the Number of Intervals  ");

         scanf("%d", &number_of_interval);

         if (numner_of_interval % 2 != 0)
         {
            printf("enter Even number of intervals\r\n");
            return 0;
         }

         area = simpson_rule(number_of_interval);
         printf("\nArea using Simpson Rule for interval[ %d ] is %.10f\n", number_of_interval, area);
    break;

    case GAUSS_QUADRATURE:
         area = gauss_quadrature();
         printf("\nArea using Gauss Quadrature for the interval[ %d ] is %.10f\n", 2, area);
    break;

    default:
    
    break;
  }

  printf("\n*Table for three different methods**\n");

  for (i = 1; i <= 6; i++)
  {
      if (i == 2 || i == 5)
      {
         continue;
      }

      number_of_interval = pow(2,i);

      printf("\n***********************************");
      printf("\nArea of Sin(x) for the Interval %d \r\n\n", number_of_interval);
      printf("Trapezodial Rule    %.10f\r\n",trapezodial_rule(number_of_interval));
      printf("Simpson Rule        %.10f\r\n",simpson_rule(number_of_interval));
      printf("Gauss Quadrature    %.10f\r\n", gauss_quadrature()); 
      printf("***********************************\n");
      printf("\n");     
  }

  return 0;
}

