#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> vec;


int normalSum(vector<int> nums){
  int ans = 0;

  for(int i = 0 ; i < nums.size(); i++){
    ans += nums[i];
  }
  
  return ans;
}


void thSum(int start, int end, vector<int> nums, int& ans){

  for( int i = start; i < end; i++){
    ans += nums[i];
  }
}


int thVecSplit(vector<int> nums){
  int midPoint = 0;

  if(nums.size() % 2 == 0){
    midPoint = nums.size()/2;
    cout << midPoint << endl;
  }else{
    midPoint = (nums.size()/2)+1;
    cout << midPoint << endl;
  }
  
  return midPoint;
}


int main(){

  for(int i = 0; i < 10000;i++){
    vec.push_back(i);
  }

  int vecSum = normalSum(vec);
  
  cout << vecSum << " <- sum of vector\n";
  cout << "==========\n";

  int split = thVecSplit(vec);

  int sumA = 0;
  int sumB = 0;

  thread th1(thSum, 0, split, ref(vec), ref(sumA));

  thread th2(thSum, split, vec.size(), ref(vec), ref(sumB));
  

  th1.join();
  th2.join();

  vecSum = sumA + sumB;
  cout << vecSum << " <- sum by threads\n";

  return 0;
}
