#include "node.h"


node::node(int size, vector<int>& mat, int step) {
	this->size = size;
	this->mat = mat;
	this->step = step;
	this->dis = 0;
}

bool node::operator== (const node& n){
	if (this->size != n.size) {
		
		return false;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (this->mat[i * size + j] != n.mat[i * size + j])
				
				return false;
		}
	}
	return true;
}

void node::caldis(vector<int>& nums) {

	int cur = 0;
	int newi = 0;
	int newj = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cur = nums[i * size + j]-1 ;
			if (cur == -1) continue;
			newi = (cur / 3);
			newj = (cur % 3);
			dis += abs(newi-i)+ abs(newj - j);
		}
	}


}

int node::getdis() {
	return dis;
}
vector<int> node::getmat() {
	return mat;
}

void node::init() {
	caldis(mat);
}

int node::getstep() {
	return step;
}