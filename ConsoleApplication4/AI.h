#pragma once
#include "Node.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <math.h>
class AI
{
private:
	const double learningRate = 0.2;
	const std::vector<int> networkSize = { 3,5,6,8,2};
	double random(int fanIn, int fanOut) {
		srand(time(0));
		double dist = sqrt(6) / sqrt((long)fanIn + (long)fanOut);
		double rnd = (double)(rand() % 100) / 100;
		if (rand() % 2 == 0) {
			return rnd * -1 * dist;
		}
		else return rnd * dist;
	}
public:
	std::vector<std::vector<Node>> network;
	void initalise() {
		srand(time(0));
		for (int i = 0; i < networkSize.size()-1; i++) {
			std::vector<Node> temp;
			for (int j = 0; j < networkSize[i]; j++) {
				Node t(networkSize[i+1]);
				for (int k = 0; k < networkSize[i + 1]; k++) {
					t.weight[k] = ((double)(rand() % 100) / 100);// *(rand())
				}
				temp.push_back(t);
			}
			network.push_back(temp);
			temp.empty();
		}
		std::vector<Node> temp;
		for (int i = 0; i < networkSize[networkSize.size() - 1]; i++) {
			Node t(0);
			temp.push_back(t);
		}
		network.push_back(temp);
	}


	double sigmoid(const double& d) {
		const double e = 2.7182818284;
		return (1 / ((double)(pow(e, -d)) + 1));
	}
	void forwardPropagate(std::vector<double>&input) {
		for (int i = 0; i < networkSize[0]; i++) {
			network[0][i].activation=input[i];
		}
		for (int i = 1; i < network.size(); i++) {
			for (int j = 0; j < network[i].size(); j++) {
				double temp = 0;
				for (int k = 0; k < network[i-1].size(); k++) {
					temp += network[i - 1][k].activation * network[i - 1][k].weight[j];
				}
				network[i][j].activation = sigmoid(temp+network[i][0].bias);//uses first node of layer as bias				
			}
		}
	}
	void backPropagate(std::vector<double> target) {
		for (int i = 0; i < networkSize[networkSize.size() - 1]; i++) {
			Node* node = &network[networkSize[networkSize.size() - 1]][i];
			node->delta = node->activation * (1 - node->activation) * (node->activation - target[i]);

		}
		for (int i = network.size() - 2; i > -1; i--) {
			for (int j = 0; j < network[i].size(); j++) {
				Node* node = &network[i][j];
				double temp=0;
				for (int k = 0; k < network[i + 1].size(); k++) {
					temp += network[i + 1][k].delta * node->weight[k];
				}
				
				node->delta = node->activation*(1-node->activation) * temp;
				
			}
		}
		//now updating...
		for (int i = 0; i < network.size()-1; i++) {
			for (int j = 0; j < network[i].size(); j++) {
				Node* node = &network[i][j];
				for (int k = 0; k < network[i + 1].size(); k++) {
					double deltaW = -learningRate * (network[i+1][k].delta)*node->activation;
					node->weight[k] += deltaW;
					network[i][0].bias += -learningRate * network[i + 1][k].delta;//bias b o i (not sure if this correct_
				}
				
			}
		}
	}
	void printNetwork() {
		for (int i = 0; i < network.size(); i++) {
			for (int j = 0; j < network[i].size(); j++) {
				std::cout << network[i][j].activation;
				std::cout << " ";
			}
			std::cout << std::endl;
		}
	}
	
};

