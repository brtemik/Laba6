/** 
	\file: main.cpp
	*/

#include <iostream>
#include <fstream>
#include <conio.h>

/*! \brief void main() - tochka vhoda v programmu

*	Chityvaet razmer grafa, potom matricu grafa.

*	( -1 == "puti net" )

*   Vyvodit ostovnoe derevo, naydennnoe algoritmom Prima */

void main() {
	/* to make program read from file, 	
		delete all strings, marked with "//===//",
		and realize all strings, marked with "// * //".
	*/


	//std::ifstream in;					// * //
	//in.open("in.txt", std::ios::in);	// * //

	int n;
	std::cout << "razmer grafa:";		//===//
	//in >> n;							// * //
	std::cin >> n;						//===//

	int** G = new int* [n];
	for(int i=0; i<n; i++) {
		G[i] = new int [n];
		for (int j=0; j<n; j++)
			std::cin >> G[i][j];			//===//
			//in >> G[i][j];				// * //
	}

	//in.close();							// * //

	// Ostovnoe derevo. 1-point1, 2-point2, 3-distance between(1,2);
	int* ostWood[3];
		ostWood[0] = new int [n-1];
		ostWood[1] = new int [n-1];
		ostWood[2] = new int [n-1];

	//points, that are already in wood
	bool* wood = new bool [n];
	for (int i=0; i<n; i++) wood[i] = false;


	wood[0] = true;
	int point1, point2, size;
	for (int Iteration=0; Iteration < n+1; Iteration++){
		size = -1;
		// chosing the first point
		for (int i=0; i<n; i++){
			// if first point is a part of the wood
			if ( wood[i] ) {
				// chosing the second point
				for (int j=0; j<n; j++){
					// if the second point isn't a part of the wood
					if ( !wood[j] ) {
						// if the road exists and it's less then size ~~ [ distance(point1, point2) ]
						if ( G[i][j] > 0 && ( size<0 || G[i][j] < size) )
						{
							// remember this way
							point1 = i;
							point2 = j;
							size = G[i][j];
						}
					}
				}
			}
		}

		wood[point2] = true;
		ostWood[0][Iteration] = point1;
		ostWood[1][Iteration] = point2;
		ostWood[2][Iteration] = size;
	}

	std::cout << "point1 point2 distance\n";
	for (int j=0; j<n-1; j++){
		for (int i=0; i<3; i++){
			std::cout << ostWood[i][j] << "      ";
		}
		std::cout << "\n";
	}

	getch();
}