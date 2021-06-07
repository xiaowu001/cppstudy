#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include"node.h"

using namespace std;

int dx[4] = { 0, 0, -1 ,1 };
int dy[4] = { 1, -1, 0, 0 };

struct cmp
{
	bool operator () (node* a,node* b){
		int adis = a->getstep() + a->getdis();
		int bdis = b->getstep() + b->getdis();
		if (adis > bdis) {
			return true;
		}
		else {
			return false;
		}

	}

};

bool search(vector<node*>& vis, node n) {
	int m = vis.size();
	for (int i = 0; i < m; i++) {
		if (*(vis[i]) == n)return true;
	}
	return false;
}


//function general search
int main() {
	vector<int> input;
	cout << "input size:" << endl;
	int size;
	cin >> size;
	cout << "input matrix" << endl;
	int n;
	for (int i = 0; i < size * size; i++) {
		cin >> n;
		input.push_back(n);
	}


	node* start = new node(size, input,0);
	start->init();

	vector<int> pst = start->getmat();
	priority_queue<node*, vector<node*>, cmp> q; //���ȼ���ߵķ��ڶ�����ǰ�棺���ȼ���g(n)+h(n)=>step +manhattan dis��
	vector<node*> vis; //��¼�ѱ����ĵ�
	
	q.push(start);
	node* nxt = new node(size, input, 2);
	
	

	int cnt = 0;
	while (!q.empty()) {
		node* cur = q.top();
		cnt = cur->getstep();
		pst = cur->getmat();
		//����ѭ�����������������
		if (cur->getdis() == 0) {
			cout << "goal" << endl;
			break;
		}
		vis.push_back(cur); //��¼������ÿ��״̬
		q.pop();
		int x, newx;
		int y, newy;
		int newpos;


		for (int i = 0; i < size * size; i++) { 
			cout << i << endl;
			if (pst[i] == 0) {
				x = i / size;
				y = i % size;
				for (int j = 0; j < 4; j++) {//���������ƶ�
					newx = x + dx[j];
					newy = y + dy[j];
					if (newx >= 0 && newy >= 0 && newy < 3 && newx < 3) {//�߽�����
						newpos = newx * size + newy;
						pst[i] = pst[newpos];
						pst[newpos] = 0;
						cnt++;
						node* nxt = new node(size, pst, cnt);
						if (search(vis, *nxt)) {//ȷ�ϵ�û�з��ʹ�
							cnt--;
							pst[newpos] = pst[i];
							pst[i] = 0;
							continue;
						}
						nxt->init();
						q.push(nxt);
						//����
						cnt--;
						pst[newpos] = pst[i];
						pst[i] = 0;
					}
				}
			}
		}

	}
	cout << "the step is:" << cnt << endl;
	//print matrix
	for (int i = 0; i < size * size; i++) {
		cout << pst[i];
	}
}







//int caldis(int size, vector<int>& nums) {
//	int dis = 0;
//	int k = 0;
//	int len = size - 1;
//
//	int cur = 0;
//	int newi = 0;
//	int newj = 0;
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; i++) {
//			cur = nums[i * size + j]-1;
//			if (cur == -1) continue;
//			newi = cur / 3;
//			newj = cur % 3;
//			dis = dis + newi + newj - i - j;
//		}
//	}
//
//	return dis;
//}