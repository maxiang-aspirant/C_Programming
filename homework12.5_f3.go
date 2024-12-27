package main
import ("fmt"
	"time"
)

func main(){
	now := time.Now()  // access time and store it in now 
	year, month, day := now.Date() // access day,month and year and store them in variable 'day,month,year'
	cal := getMonthCalendar(year,int(month))
	fmt.Printf("    %d年 %d月\n",year,month)
	fmt.Println("Sunday Monday Tuesday Wednesday Thursday Friday Saturday")
	for _, week := range cal{
		for _, day := range week{
			if day == 0{
				fmt.Print("   ")
			}
			else{
				fmt.Printf("%2d ", day)
			}
		}
		fmt.Println()
	}
}
func getMonthCalendar(year, month int) [][]int{  
	firstDay := time.Date(year,time.Month(month),1,0,0,0,0,time.UTC).Weekday()  //get the first day of the month and store the value in variable 'firstDay'
	daysInMonth := time.Date(year,time.Month(month)+1,0,0,0,0,0,time.UTC).Day()
	calendar := make([][]int,0)
	week := make([]int,0)
	for i := 0;i < int(firstDay);i++{
		week = append(week,0)
	}
	for day := 1;day <= daysInMonth;day++{
		week = append(week,day)
		if (len(week)-int(firstDay))%7 == 0 && len(week) != int(firstDay) {
			calendar = append(calendar,week)
			week = make([]int,0)
		}
        }
	if len(week) > 0{
		calendar = append(calendar, week)
	}
	return calendar
}
