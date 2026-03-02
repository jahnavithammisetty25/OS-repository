#include <stdio.h>

int main()
{
    int n, i, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    int low = 0, high = n - 1, mid;
    int found = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            printf("Element found");
            found = 1;
            break;
        }
        else if(arr[mid] < key)
        {
        low = mid + 1;
        }
        else
        {
        high = mid - 1;
        }
    }
    if(found == 0)
    {
    printf("Element not found");
    }
  return 0;
}
