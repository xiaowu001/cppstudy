#pragma once
#include<iostream>
#include<vector>

using namespace std;

class node
{
public:
	node(int size, vector<int>& mat,int step);
	void init();
	bool operator== (const node& n);

	void caldis(vector<int>& nums);
	int getdis();
	int getstep();
	vector<int> getmat();
private :
	int dis;
	int step;
	int size;
	vector<int> mat;

};

