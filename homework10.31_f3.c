#include <stdio.h>
#include <stdbool.h>
bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int year, int month) {
        static int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && isLeapYear(year)) {
                return 29;
        }
        return daysInMonth[month - 1];
}
int daysFromBaseToFirstOfMonth(int year, int month) {
        int baseYear = 2024;
        int baseMonth = 10;
        int baseDay = 29; 
        int baseWeekDay = 2;
        int daysDiff = 0;
        for (int y = baseYear; y < year; y++) {
                daysDiff += isLeapYear(y) ? 366 : 365;
        }
        for (int m = baseMonth + 1; m < month; m++) {
        daysDiff += getDaysInMonth(baseYear, m); 
        }
        int firstDayOfWeek = (baseWeekDay + daysDiff % 7 + 7) % 7;
        return firstDayOfWeek;
}
void printCalendar(int year) {
        for (int month = 1; month <= 12; month++) {
                int firstDayOfWeek = daysFromBaseToFirstOfMonth(year, month);
                int daysInMonth = getDaysInMonth(year, month);
                printf("                      %s %d\n", (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ? "Sun Mon Tue Wed Thu Fri Sat" : "", month);
                for (int i = 0; i < firstDayOfWeek; i++) {
                        printf("    ");
                }
                for (int day = 1; day <= daysInMonth; day++) {
                        printf("%3d ", day);
                        if ((firstDayOfWeek + day - 1) % 7 == 6 || day == daysInMonth) {
                                printf("\n");
                        }
                }
                if (month != 12)
                        printf("\n");
        }
}
int main(){
    int year;
    printf("请输入年份: ");
    scanf("%d", &year);
    printCalendar(year);
    return 0;
}
