#include<stdio.h>
int isLeapYear(int year){
	return (year%4==0 && year%100!=0 ||year%400==0  );
}
int dayssince2024(int day,int month,int year){
	int days = 0;
	int m;
	int start_year = 2024;
	int i=start_year;
	if(year>start_year){
	            for(i;i<year;i++){
			    days += isLeapYear(i) ? 366 : 365;
	            }
        }
	else if(year==start_year){
		int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeapYear(year)){
            month_days[1] = 29;
        }
        for(m=0;m<month - 1;m++){
            days += month_days[m];
        }
        days += day;
        }
	return days;
}
int main(){
	int day,month,year;
	printf("Please input Year:");
	scanf("%d",&year);
	printf("Please input Month:");
	scanf("%d",&month);
	printf("Please input Day:");
	scanf("%d",&day);
	int days =dayssince2024(day,month,year);
	int weekdays_index = days%7;
	const char* weekdays[]= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        printf("The input date is: %s\n",weekdays[weekdays_index]);
        return 0;
}


