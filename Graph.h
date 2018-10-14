#pragma once

using namespace std;
class Graph {
	map <int, set < pair<int, double> > > name; // names of characters
public:

	Graph() {}//empty constructor

	Graph(const Graph &C);   //����������� �����������
	Graph(double);//���� � ���������� ������������������ �����
	Graph(double, double); //���� � ���������� ���������������� �����
	Graph(int); // ����������� ������������������ �����	
	Graph(int, int); // ����������� ���������������� �����	
	
	Graph addVertexUndirect(int vertex); //���� ����		
	Graph addVertexDirect(int vertex);
	Graph addEdge(int vertex1,int vertex2); //�������� �����
	Graph addArc(int vertex1,int vertex2);//�������� ����
		

	Graph deleteVertexUndirective(int vertex); //������� �������
	Graph deleteVertexDirective(int vertex); //������� �������
	Graph deleteEdge(int vertex1,int vertex2); //������� �����
	Graph deleteArc(int vertex1,int vertex2); //������� ����
	
	int DirectGraphDegree();
	bool ExistStokForUV(int u,int v);
	void printGraph();
	void printInFile();
	void printGraphWeight();
	void printInFileWeight();

};