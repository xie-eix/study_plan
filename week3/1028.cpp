#include<vector>
#include<iostream>
#include <algorithm>
int main(){
   /*  std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    int &ref = v[0];
    v.push_back(3);
    std::cout << ref << std::endl;  */


    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   /*  v.erase(std::remove_if(v.begin(),v.end(),[](int x){return x%2 == 0;}),v.end());
    for(int x:v){
        std::cout << x ;
    } */

    for(auto it = v.begin(); it != v.end();){
        if(*it % 2 == 0){
            it = v.erase(it);
        }else{
            ++it;
        }
    }
    for(int x:v){
        std::cout << x ;
    }
    return 0;
}