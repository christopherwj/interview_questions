#include <stdio.h>
struct Computer
{
  float cost;
  int year;
  float cpu_speed;
  char cpu_type[16];
} model;
void main() 
{
  printf("Enter the type of the CPU inside your computer: ");
  gets(model.cpu_type);
  printf("Enter the speed(GHz) of the CPU: ");
  scanf("%f", &model.cpu_speed);
  printf("Enter the year your computer was made: ");
  scanf("%d", &model.year);
  printf("Enter the much you paid for the computer: ");
  scanf("%f", &model.cost);

  printf("\nCPU type: %s", model.cpu_type);
  printf("\nCPU speed: %f GHz", model.cpu_speed);
  printf("\nYear: %d", model.year);
  printf("\nCost: $%4.2f", model.cost);
}
