#include <iostream>
#include <climits>
#include <vector>


using namespace std;


void swapNum(int nums[], int x, int y){
  int tmp;

  tmp = nums[x];
  nums[x] = nums[y];
  nums[y] = tmp;
}

bool checkSorted(int nums[], int size){
  bool sorted = true;

  for(int i = 0; i < size - 1; i++){
    if(nums[i] <= nums[i+1]){
    }else{
      sorted = false;

      cout << "not sorted\n";
    }
  }

  return sorted;
}

void selectionSort(int nums[], int size){
  int bound = 0;
  
  
  //  while(!checkSorted(nums, size)){
  
  while(bound < size){

  int min = INT_MAX;
  int minIndex = bound;
    
  for(int i = bound; i < size; i++){
    if(min >= nums[i]){
      min = nums[i];
      cout << "min: " << min << " \n";
      minIndex = i;
    }
  }

  swapNum(nums, bound, minIndex);
  cout << "swap\n";
  cout << "bound: " << bound << " \n";
  bound++;
  }

  cout << "selectionSort: \n";
  for(int i = 0; i < size; i++){
    cout << nums[i] << ", ";
  }
  cout << "\n";
}


int main(){
  int nums[9] = {2,3,6,1,7,9,2,7,4};
  int size = sizeof(nums)/sizeof(int);


  for(int i = 0; i < size; i++){
    cout << nums[i] << ", ";
  }
  cout << "\n";

  selectionSort(nums, size);

  for(int i = 0; i < size; i++){
    cout << nums[i] << ", ";
  }
  cout << "\n";

  

  
}
