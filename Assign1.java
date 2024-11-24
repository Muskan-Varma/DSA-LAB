import java.util.*;
import java.util.Scanner;

public class Assign1
{
	void reheapDown(int a[], int n, int i)
	{
		int j, temp;
		while((2*i + 1) < n)
		{
			j = 2*i + 1;
			if(j+1 < n && a[j+1] > a[j])
			{
				j = j + 1;
			}
			if(a[i] > a[j])
			{
				break;
			}
			else
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i = j;
			}
		}
	}
	
	void buildHeap(int a[], int n)
	{
		for(int i = (n-2)/2; i>= 0; i--)
		{
			reheapDown(a, n, i);
		}
	}
	
	void heapSort(int a[], int n)
	{
		buildHeap(a, n);
		int n1 = n;
		for(int i = n1-1; i>0; i--)
		{
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;
			n1--;
			reheapDown(a, n1, 0);
		}
	}

	int shellSort(int arr[], int n)
	{

		for (int gap = n/2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i += 1)
			{
				int temp = arr[i];
				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];
				arr[j] = temp;
			}
		}
		return 0;
	}

	public static void main(String args[])
	{
		int arr[] = new int[50];
		int n = 0, sortType;
		char ch, mainChoice;
		Scanner s = new Scanner(System.in);
		do
		{	
			n = 0;
			do
			{
				System.out.print("Enter element: ");
				arr[n] = s.nextInt();
				n++;
				System.out.print("Do you want to add element? (y/n)");
				ch = s.next().charAt(0);
			}while(ch == 'y');
			Assign1 h = new Assign1();

			System.out.print("1. Shell sort \n2. Heap Sort \n");
			System.out.print("Enter Choice: ");
			sortType = s.nextInt();
			if(sortType == 1)
			{
				h.shellSort(arr, n);
				System.out.print("Sorted Array Using Shell Sort: ");
				for(int i = 0; i<n; i++)
				{
					System.out.print(arr[i]);
					System.out.print(" - ");
				}
				System.out.println("");
			}
			else if(sortType == 2)
			{
				h.heapSort(arr, n);
				System.out.print("Sorted Array Using Heap Sort: ");
				for(int i = 0; i<n; i++)
				{
					System.out.print(arr[i]);
					System.out.print(" - ");
				}
				System.out.println("");
			}
			else
			{
				System.out.print("Invalid choice: ");
			}
			System.out.print("Do you want to continue?");
			mainChoice = s.next().charAt(0);
		}while(mainChoice == 'y');

		s.close();
		System.out.println("Exiting...");
	}
}