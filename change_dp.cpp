#include <iostream>
#include <vector>
using namespace std;
vector<int> coins;

int get_change(int m) {
	vector<int> min_coins;
	min_coins.resize(m+1);
	for(int i = 0 ; i < min_coins.size() ; i++){
		if(i == 0){
			min_coins[i] = 0;
		}
		else{
			int smallest_min_coins;
			for(int j = 0 ; j < coins.size() ; j++){
				if(j == 0){
					smallest_min_coins = min_coins[i-coins[j]];
				}
				else{
					if(i - coins[j] >= 0){
						if(smallest_min_coins > min_coins[i-coins[j]]){
							smallest_min_coins = min_coins[i-coins[j]];
						}
						}
					}
				}
			min_coins[i] = smallest_min_coins + 1;
			}
		}
	return min_coins[m];
}

int main(){
  coins.push_back(1);
  coins.push_back(3);
  coins.push_back(4);
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
