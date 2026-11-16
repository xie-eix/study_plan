#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

int main(){
    int n = 100000000;
    // std::cin >> n;
    std::vector<int> num1;
    std::vector<int> num2;
    auto start1 = std::chrono::high_resolution_clock::now();
    num1.reserve(n);
    // int max,min,sum,verge;
    for(int i = 0; i < n; i++){
        /* int temp;
        std::cin >> temp; */
        num1.push_back(i);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "Time taken: " << duration1.count() << " ms" << std::endl;
   
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; i++){
        num2.push_back(i);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "Time taken: " << duration2.count() << " ms" << std::endl;

    /* max = num1[0];
    min = num1[0];
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += num1[i];
        max = std::max(max,num1[i]); 
        min = std::min(min,num1[i]);
    }
    verge = sum / n;
    std::cout << max << " " << min << " " << sum << " " << verge << std::endl; */

    /* int temp,index = 0;
    while(index < num.size() - index - 1){
        temp = num[index];
        num[index] = num[num.size() - 1 - index];
        num[num.size() - 1 - index] = temp;
        index++;
    }
    for(int i = 0; i < num.size(); i++){
        std::cout << num[i] << " ";
    }
    std::cout << std::endl; */
}