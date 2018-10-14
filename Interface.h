#pragma once
#include <iostream>
#include "Graph.h"

using namespace std;

class Interface {
public:
	int graphType;
	Interface() {}
	int chooseGraphType() {
		int graphType;
		cout << "1 - Create directive graph " << endl; //ориентированный
		cout << "2 - Create undirective graph " << endl;//неориентированный

		cin >> graphType;
		return graphType;
	}
	Graph instructions(int graphType) {

		Graph A;
		switch (graphType) {
		case 1:
		{
			cout << "1 - Read from keyboard" << endl;
			cout << "2 - Read from file" << endl;
			int i;
			cin >> i;
			if (i == 1)
				A = Graph(1.0, 1.0);
			else if (i == 2)
				A = Graph(1, 1);
			else {
				cout << "Command error" << endl;
				this->instructions(graphType);
			}
			break;
		}
		case 2:
		{
			cout << "1 - Read from keyboard" << endl;
			cout << "2 - Read from file" << endl;
			int i;
			cin >> i;
			if (i == 1)
				A = Graph(1.0);
			else if (i == 2)
				A = Graph(1);
			else {
				cout << "Command error" << endl;
				this->instructions(graphType);
			}
			break;
		}
		default:
		{
			cout << "Command error" << endl;
			this->instructions(graphType);
		}

		}
		A.printGraph();
		return A;
	}
	int actions(Graph &C, int graphType) {
		int Action;
		cout << "1 - Add vertex " << endl;
		cout << "2 - Add arc/edge " << endl;
		cout << "3 - Delete Vertex " << endl;
		cout << "4 - Delete arc/edge " << endl;
		cout << "5 - Print graph in console " << endl;
		cout << "6 - Print graph in file " << endl;
		cout << "7 - Exit " << endl;
		cin >> Action;
		switch (Action)
		{
		case 1: {
			int a;
			cout << "Add a vertex :";
			cin >> a;
			if (graphType == 1) //граф ориентированный
			{
				C.addVertexDirect(a);
			}
			else
			{	
				C.addVertexUndirect(a);
			}
			break;
		}
		case 2: {
			int vertex1, vertex2;
			cout << "Input the first vertex : ";
			cin >> vertex1;
			cout << "Input the second vertex : ";
			cin >> vertex2;
			if (graphType == 1) //граф ориентированный
				C.addArc(vertex1, vertex2);
			else C.addEdge(vertex1, vertex2);
			break;
		}
		case 3: {
			int vertex;
			cout << "Delete vertex : ";
			cin >> vertex;
			if (graphType == 1) //граф ориентированный
				C.deleteVertexDirective(vertex);
			else
				C.deleteVertexUndirective(vertex);
			break;
		}
		case 4: {
			cout << "Delete Edge : " << endl;
			int vertex1, vertex2;
			cout << "Input the first vertex : ";
			cin >> vertex1;
			cout << "Input the second vertex : ";
			cin >> vertex2;
			if (graphType == 1) //граф ориентированный
				C.deleteArc(vertex1, vertex2);
			else C.deleteEdge(vertex1, vertex2);
			break;
		}
		case 5: {
			C.printGraph();
			break;
		}
		case 6: {
			C.printInFile();
			break;
		}
		case 7: {
			return 0;
		}
		default: {
			cout << "Command error " << endl;
			this->actions(C, graphType);
		}
				 break;
		}
		this->actions(C, graphType);
	}


};