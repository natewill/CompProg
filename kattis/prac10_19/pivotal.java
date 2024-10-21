import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class apivotalquestion
{
    public static void main(String[] args) throws IOException
    {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int[] inputArray = new int[size];
        for(int i=0; i<size; i++)
        {
            inputArray[i] = scanner.nextInt();
        }
        
        int[] mins = new int[size];
        int[] maxs = new int[size];

        if(size == 0)
        {
            System.out.print(size);
            System.out.println();
            System.exit(0);
        }
        if(size == 1)
        {
            System.out.print(size);
            System.out.print(" ");
            System.out.print(inputArray[0]);
            System.out.println();
            System.exit(0);
        }

        maxs[0] = inputArray[0];
        for(int i=1; i<size; i++)
        {
            if(inputArray[i]>maxs[i-1])
            {
                maxs[i] = inputArray[i];
            }
            else
            {
                maxs[i] = inputArray[i-1];
            }
        }
        
        mins[size-1] = inputArray[size-1];
        for(int i=size-2; i>=0; i--)
        {
            if(inputArray[i]<mins[i+1])
            {
                mins[i] = inputArray[i];
            }
            else
            {
                mins[i] = inputArray[i+1];
            }
        }
        ArrayList<Integer> pivot = new ArrayList<Integer>();
        for(int j=0; j<size; j++)
        {
            if (j == 0) {
                if (inputArray[j] < mins[j +1])
                {
                    pivot.add(inputArray[j]);
                }
            }
            else if (j == size -1) {
                if (maxs[j -1] <= inputArray[j])
                {
                    pivot.add(inputArray[j]);
                }
            }
            else if(maxs[j - 1] <= inputArray[j] && inputArray[j] < mins[j + 1])
            {
                pivot.add(inputArray [j]);
            }
        }
        System.out.print(pivot.size());
        for(int i=0; i<pivot.size()&&i<100;i++)
        {
            System.out.print(" ");
            System.out.print(pivot.get(i));
        }
        System.out.println();
    }
}