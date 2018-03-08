//============================================================================
// Name        : MagicSquare.cpp
// Author      : Luke Lewis
// Version     :
// Copyright   : 
// Description : Magic Square simulation
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Square {
public:
	Square(int num);
	void display();
	Square(){n = 5;};
private:
	int n;
};

int main() {
	Square magics(5);
	magics.display();
	return 0;
}

Square::Square(int num){
	n = num;
}

void Square::display(){
	vector<vector<int> > vect(n, vector<int>(n, 0));
	int i = 0;
	int j = (n/2);
	vect[i][j] = 1;
	for (int cur = 1; cur < n*n;){
		cur++;
		if (i-1 == -1){
			i = n-1;
		}
		else{
			i--;
		}
		if (j+1 == n){
			j = 0;
		}
		else{
			j++;
		}
		if(vect[i][j] != 0){
			if (i == n-1 || i == n-2){
				i -= (n-2);
			}
			else{
				i += 2;
			}
			if (j == 0){
				j += (n-1);
			}
			else{
				j--;
			}
		}
		vect[i][j] = cur;
	}
	for (vector<vector<int> >::size_type x = 0; x < vect.size(); x++){
		for (vector<int>::size_type y = 0; y < vect[x].size(); y++){
			cout.width(4);
			cout<<left<<vect[x][y]<<' ';
		}
		cout<<endl;
	}

}

