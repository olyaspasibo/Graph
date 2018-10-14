#pragma once

using namespace std;
class Graph {
	map <int, set < pair<int, double> > > name; // names of characters
public:

	Graph() {}//empty constructor

	Graph(const Graph &C);   //конструктор копирования
	Graph(double);//ввод с клавиатуры НЕОРИЕНТИРОВАННОГО графа
	Graph(double, double); //ввод с клавиатуры ОРИЕНТИРОВАННОГО графа
	Graph(int); // конструктор неориентированного графа	
	Graph(int, int); // конструктор ориентированного графа	
	
	Graph addVertexUndirect(int vertex); //неор граф		
	Graph addVertexDirect(int vertex);
	Graph addEdge(int vertex1,int vertex2); //Добавить ребро
	Graph addArc(int vertex1,int vertex2);//Добавить дугу
		

	Graph deleteVertexUndirective(int vertex); //Удалить вершину
	Graph deleteVertexDirective(int vertex); //Удалить вершину
	Graph deleteEdge(int vertex1,int vertex2); //Удалить ребро
	Graph deleteArc(int vertex1,int vertex2); //Удалить дугу
	
	int DirectGraphDegree();
	bool ExistStokForUV(int u,int v);
	void printGraph();
	void printInFile();
	void printGraphWeight();
	void printInFileWeight();

};