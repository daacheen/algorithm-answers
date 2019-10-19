import java.time.LocalDate;
import java.util.Scanner;

public class Main {
	
	static int[] data = new int[] { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	static int diff(LocalDate s, LocalDate e) {
		int diff = 0;
		while (!e.equals(s)) {
			s = s.plusDays(1);
			diff++;
		}
		
		return diff;
	}
	
	static String format(int n) {
		if (n == 0) {
			return "   ";
		}
		
		if (n / 10 == 0) { 
			return "  " + n; 
		}
		
		return " " + n;
	}
	
	static boolean isLeap(int year) {
		return (year % 4 ==0 && year % 100 != 0) 
				|| (year % 400 == 0);
	}
	
	static int daysOfMonth(int year, int month) {
		if (month == 2) {
			return isLeap(year) ? 29 : 28;
		}
	
		return data[month];
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int year = s.nextInt();
		int month = s.nextInt();
		
		s.close();
		
		// get the first day
		int dayDiff = diff(LocalDate.of(1900, 1, 1), LocalDate.of(year, month, 1));
		
		// 0 sunday, 1 monday, 2 tuesday
		int weekdayDiff = (dayDiff + 1) % 7;
		
		System.out.println("Sun Mon Tue Wed Thu Fri Sat");
		
		int weekCount = 0;
		
		for (int i=0;i<weekdayDiff;i++) {
			System.out.print(format(0));
			System.out.print(" ");
			weekCount++;
		}
		
		int totalDays = daysOfMonth(year, month);
		
		for (int i=1;i<=totalDays;i++) {
			if (weekCount == 7) {
				weekCount =0;
				System.out.println();
			}
			System.out.print(format(i));
			System.out.print(" ");
			weekCount++;
		}
		

	}

}