#include <iostream>
#include<iostream>
#include <fstream>

using namespace std;

class clients {
public:
	clients() {
		this->coust = 0;
		this->end = 0;
		this->start = 0;
	}
	clients(const int& start, const int& end, const int& coust) {
		this->coust = coust;
		this->end = end;
		this->start = start;
	}
	int start;
	int end;
	int coust;
};

int main() {
	ifstream ifs;
	ifs.open("input.txt");
	int value;
	int N, Q;
	ifs >> N;
	int y = 0, n = 0;
	clients* client = new clients[N];
	int start, end, cost, type;
	for (int i = 0;i < N;i++) {
		ifs >> start;
		ifs >> end;
		ifs >> cost;
		client[n] = clients(start, end, cost);
		n++;
	}
	ofstream ofs;
	ofs.open("output.txt");
	ifs >> Q;
	ifs.close();
	for (int i = 0;i < Q;i++) {
		ifs >> start;
		ifs >> end;
		ifs >> type;
		int all_cost = 0;
		int all_time = 0;
		switch (type) {
		case 1:
			all_cost = 0;
			for (int i = 0;i < N;i++) {
				if (client[i].start >= start && client[i].start <= end) {
					all_cost += client[i].coust;
				}
			}
			ofs << all_cost << " ";
			break;
		case 2:
			all_time = 0;
			for (int i = 0;i < N;i++) {
				if (client[i].end >= start && client[i].end <= end) {
					all_time += (client[i].end - client[i].start);
				}
			}
			ofs << all_time << " ";
			break;
		}
	}
	ofs.close();

	delete[]client;

	return 0;
}