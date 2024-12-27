#include <stdio.h>
#include <stdbool.h>
bool isLeapYear(int year){

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return true;
        }
        return false;
}
int getDaysInMonth(int year, int month) {
        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && isLeapYear(year)) {
                return 29;
        }
        return daysInMonth[month - 1];
}
int getFirstDayOfWeek(int year, int month) {
        int baseDay = 1; 
        int baseYear = 2024;
        int baseMonth = 10;
        int baseDayOfMonth = 1;
        int daysDiff = 0;
        for (int y = baseYear; y < year; y++) {
                daysDiff += isLeapYear(y) ? 366 : 365;
        }
        for (int m = baseMonth; m < month; m++) {
                daysDiff += getDaysInMonth(baseYear, m);
        }
        daysDiff += (month == baseMonth) ? (baseDayOfMonth - 1) : (getDaysInMonth(baseYear, baseMonth - 1) - baseDayOfMonth + 1 + getDaysInMonth(year, month));
        int firstDayOfWeek = (baseDay + daysDiff % 7 + 7) % 7; 
        return firstDayOfWeek;
}
void printCalendar(int year, int month) {
        int firstDayOfWeek = getFirstDayOfWeek(year, month);
        int daysInMonth = getDaysInMonth(year, month);
        printf("  Sun Mon Tue Wed Thu Fri Sat\n");
        for (int i = 0; i < firstDayOfWeek; i++) {
                printf("     ");
        }
        for (int day = 1; day <= daysInMonth; day++) {
                printf("%3d ", day);
                if ((day + firstDayOfWeek) % 7 == 0 || day == daysInMonth) {
                        printf("\n");
                }
        }
        printf("\n");
}
int main() {
        int year, month;
        printf("请输入年份: ");
        scanf("%d", &year);
        printf("请输入月份: ");
        scanf("%d", &month);
        if (month < 1 || month > 12) {
                printf("月份必须在1到12之间\n");
        } else {
                printCalendar(year, month);
        }
    return 0;
}
