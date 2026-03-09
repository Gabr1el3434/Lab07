#include <stdio.h>

int main() {

	char *months[12] = {"January","February","March","April","May","June",
                        "July","August","September","October","November","December"};

    	double sales[12] = {
        	23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,
        	72400.31,56210.89,67230.84,68233.12,80950.34,95225.22
    	};

    	int i,j;

    	printf("Monthly Sales Report for 2024\n");
    	printf("Month\t\tSales\n");
    	for(i=0;i<12;i++)
        	printf("%-10s %.2f\n",months[i],sales[i]);

    	double min=sales[0], max=sales[0], sum=0;
    	int min_i=0, max_i=0;

    	for(i=0;i<12;i++){
        	if(sales[i] < min){ min=sales[i]; min_i=i; }
        	if(sales[i] > max){ max=sales[i]; max_i=i; }
        	sum += sales[i];
    	}

    	printf("\nSales summary report:\n");
    	printf("Minimum sales: %.2f (%s)\n",min,months[min_i]);
    	printf("Maximum sales: %.2f (%s)\n",max,months[max_i]);
    	printf("Average sales: %.2f\n",sum/12);

    	printf("\nSix-Month moving average report:\n");
    	for(i=0;i<=6;i++){
        	double total=0;
        	for(j=i;j<i+6;j++)
            		total += sales[j];
        	printf("%s-%s %.2f\n",months[i],months[i+5],total/6);
    	}

    	printf("\nSales report (highest to lowest):\n");
    	printf("Month\t\tSales\n");

    	for(i=0;i<11;i++){
        	int max_index=i;
        	for(j=i+1;j<12;j++)
            		if(sales[j] > sales[max_index])
                		max_index=j;

        	double temp=sales[i];
        	sales[i]=sales[max_index];
        	sales[max_index]=temp;

        	char *mtemp=months[i];
        	months[i]=months[max_index];
        	months[max_index]=mtemp;
    	}

    	for(i=0;i<12;i++)
        	printf("%-10s $%.2f\n",months[i],sales[i]);

    	return 0;
}
