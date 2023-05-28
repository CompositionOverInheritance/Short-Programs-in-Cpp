#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void swapNum(int nums[], int x, int y){  // swaps contents of two indices
  int tmp;

  tmp = nums[x];
  nums[x] = nums[y];
  nums[y] = tmp;
}

bool checkSort(int arr[], int size){  // check whether the array is sorted

  bool sorted = true;

  for(int i = 0; i < size - 1; i++){
    if(arr[i] <= arr[i+1]){
    }else{
      sorted = false;
    }
  }

  return sorted;
}

void bubbleSort(int nums[], int size){  // the bubble sort

  while(!checkSort(nums, size)){
    for(int i = 0; i < size - 1; i++){
      if(nums[i] > nums[i+1]){
	swapNum(nums, i, i+1);
      }
    }
  }
}


int main(){

  srand(time(NULL));
  int randomNum = rand() % 25 + 1;

  int nums[9] = {5, 2, 7, 1, 8, 2, 4, 5, 3};
  int size = sizeof(nums)/sizeof(int);

  int randNums[20];
  int randSize = sizeof(randNums)/sizeof(int);
  

  for(int i = 0; i < randSize; i++){
    randNums[i] = randomNum;
    randomNum = rand() % 25 + 1;
  }
  


  
  for(int i : nums){   // displays array before sorting
    cout << i << ", ";
  }
  cout << "\n\n";


  cout << "Random array: \n";
  for(int i : randNums){   // displays random array before sorting
    cout << i << ", ";
  }
  cout << "\n\n";
  
  cout << "=======================================\n\n";

  bubbleSort(nums, size); // modifies the given array
  bubbleSort(randNums, randSize);
  
  for(int i : nums){   // displays array after sorting
    cout << i << ", ";
  }
  cout << "\n\n";

  cout << "Random array sorted: \n";
  for(int i : randNums){   // displays random array after sorting
    cout << i << ", ";
  }
  cout << "\n\n";
}
