#pragma once
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <math.h>       /* sqrt */

struct Node{
public:
	double* weight;
	double bias=0;
	double delta;
	double activation;

	Node(int forwardNumber) {
		
			weight = new double[forwardNumber];			
	}
};
