import java.util.*;
class BinarySearch {
    public static int find(int key,int[] a)
    {
        int low = 0;
        int high = a.length-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(a[mid]==key)
                return mid;
            else if(key>a[mid])
                low = mid + 1;
            else if(key<a[mid])
                high = mid -1;
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[6];
        for(int i=0;i<6;i++) a[i] = sc.nextInt();
        for(int i:a) System.out.print(i+" ");
        System.out.println();
        System.out.println("After Changing value during fuction call");
        System.out.println(find(12,a));
    }
}