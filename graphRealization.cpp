#include <iostream>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>
#include "Interface.h"
#include <algorithm>
#include <iterator>

using namespace std;


	Graph::Graph(const Graph &C) { //конструктор копирования
		name = C.name;
		}

	Graph::Graph(double) { //ввод с клавиатуры НЕОРИЕНТИРОВАННОГО графа
		
		while (true) {
		string vertex;
		cout << "Input a vertex :";
		cin >> vertex; // вводим вершину (ключ)
		if (vertex == "!")
			break; // окончание ввода - пустой ввод (прерываемся)
				   // если вершины нет в списке, то создаём её и даём ей пустой список смежности
		int vertexInt =atoi(vertex.c_str());

		if (name.find(vertexInt) == name.end()) {
			set < pair <int, double >> listSm; // множество смежных вершин к введённой - vertex
			name[vertexInt] = listSm; //
		}

		// вводим смежные вершины
		string smVertex;
		while (true) {
			cout << "Input adjacent vertices :";
			cin >> smVertex;
			if (smVertex == "!")
				break;
			pair <int, double> smVertexInt = make_pair(atoi(smVertex.c_str()), 0.0);
			name[vertexInt].insert(smVertexInt);//добавили эту вершину в список смежности
			pair <int, double> vertexInti = make_pair(vertexInt, 0.0);
			// если список смежности уже есть, просто добавляем её
			if (name.find(smVertexInt.first) != name.end())
			{
				
				name[smVertexInt.first].insert(vertexInti);
			}
			else {
				// иначе создаём новый список смежности и добавляем туда введённую vertex
				set < pair <int, double >> temp ; // 
				temp.insert(vertexInti); // добавляем 1
				name[smVertexInt.first] = temp; // 1 впадает в 0
			}
			
		}
	}

	}	

	Graph ::Graph(double, double) { //ввод с клавиатуры ОРИЕНТИРОВАННОГО графа

		while (true) {
			string vertex;
			cout << "Input a vertex :";
			cin >> vertex; // вводим вершину (ключ)
			if (vertex == "!")
				break; // окончание ввода - пустой ввод (прерываемся)
					   // если вершины нет в списке, то создаём её и даём ей пустой список смежности
			int vertexInt = atoi(vertex.c_str());
			if (name.find(vertexInt) == name.end()) {
				set < pair <int, double>> listSm; // множество смежных вершин к введённой - vertex
				name[vertexInt] = listSm; //
			}

			// вводим смежные вершины
			string smVertex;
			while (true) {
				cout << "Input adjacent vertices :";
				cin >> smVertex;
				if (smVertex == "!")
					break;
				pair <int,double> smVertexInt = make_pair(atoi(smVertex.c_str()), 0.0);
				
				name[vertexInt].insert(smVertexInt);
				set <pair <int, double>> listSm; // множество смежных вершин 
				name[smVertexInt.first] = listSm; //

			}
		}

	}

		Graph::Graph(int) { // конструктор неориентированного графа
			ifstream freopen("input.txt");
			string str,vertex;
			while (getline(freopen, str)) {
				int pos = str.find(":"); // ищем :
				if (pos != -1) {
					  vertex = str.substr(0, pos);
					  int vertexInt = atoi(vertex.c_str());
					// если вершины нет в списке, то создаём её и даём ей пустой список смежности
					if (name.find(vertexInt) == name.end()) {
						set <pair <int, double>> listSm; // множество смежных вершин к введённой - vertex
						name[vertexInt] = listSm; //
					}
				}
				else if (str != "***") {
					pair <int, double> strInt = make_pair(atoi(str.c_str()), 0.0);
					int vertexInt = atoi(vertex.c_str());
					pair <int, double> v = make_pair(vertexInt, 0.0);
					name[atoi(vertex.c_str())].insert(strInt);
					name[strInt.first].insert(v);
				}
			}
		}
		Graph::Graph(int, int) { // конструктор ориентированного графа
			ifstream freopen("input.txt");
			string str, vertex;
			while (getline(freopen, str)) {
				int pos = str.find(":"); // ищем :
				if (pos != -1) {
					vertex = str.substr(0, pos);
					pair <int, double> vertexInt = make_pair(atoi(vertex.c_str()), 0.0);
					// если вершины нет в списке, то создаём её и даём ей пустой список смежности
					if (name.find(atoi(vertex.c_str())) == name.end()) {
						set <pair <int, double>> listSm; // множество смежных вершин к введённой - vertex
						name[atoi(vertex.c_str())] = listSm; //
					}
				}
				else if (str != "***") {
					pair <int, double> strInt = make_pair(atoi(str.c_str()), 0.0);
					name[atoi(vertex.c_str())].insert(strInt);
				}
			}

		}
		Graph Graph::addVertexUndirect (int a) { //неор граф

			if (name.find(a) == name.end()) {
				set <pair <int, double>> listSm; // множество смежных вершин к введённой - vertex
				name[a] = listSm; //
			}
			//else this->name[a];
			else {
				cout << "The vertex has already exist" << endl;
				return *this;
			}
			// вводим смежные вершины
			string smVertex;
			while (true) {
				cout << "Input adjacent vertices (to break type '!') :";
				cin >> smVertex;
				if (smVertex == "!")
					break;
				
					pair <int, double> smVertexInt = make_pair(atoi(smVertex.c_str()), 0.0);

					name[a].insert(smVertexInt);
					pair <int, double> vertexInt = make_pair(a, 0.0);
					// если список смежности уже есть, просто добавляем её
					if (name.find(smVertexInt.first) != name.end())
						name[smVertexInt.first].insert(vertexInt);
					else {
						// иначе создаём новый список смежности и добавляем туда введённую vertex
						set <pair <int, double>> temp; // 
						name[smVertexInt.first] = temp; 

					}

			}
			return *this;
		}
		Graph Graph::addVertexDirect( int a) {		
				if (this->name.find(a) == this->name.end()) {
					set <pair <int, double>> listSm; // множество смежных вершин к введённой - vertex
					this->name[a] = listSm; //
				}
				else {
					cout << "The vertex has already exist" << endl;
					return *this;
				}
				// вводим смежные вершины
				string smVertex;
				while (true) {
					cout << "Input adjacent vertices (to break type '!') :";
					cin >> smVertex;
					if (smVertex == "!")
						break;
					pair <int, double> smVertexInt = make_pair(atoi(smVertex.c_str()), 0.0);
					if (this->name.find(smVertexInt.first) == this->name.end())
					{


						this->name[a].insert(smVertexInt);
						set <pair <int, double>> listSm; // множество смежных вершин 
						this->name[smVertexInt.first] = listSm; //
					}
					else {
						this->name[a].insert(smVertexInt);
					}

				}
				return *this;

		}
			Graph Graph::addEdge(int vertex1,int vertex2) { //Добавить ребро
				
				if (this->name.find(vertex1) == name.end() || this->name.find(vertex2) == name.end())
				{
					cout << "Can not find verticies.";
					return *this;
				}
				pair <int, double> v1 = make_pair(vertex1, 0.0);
				pair <int, double> v2 = make_pair(vertex2, 0.0);
				name[vertex1].insert(v2);
				name[vertex2].insert(v1);

				return *this;
			
			
		}
		Graph Graph::addArc(int vertex1, int vertex2) { //Добавить дугу			
			if (this->name.find(vertex1) == name.end() || this->name.find(vertex2) == name.end())
			{
				cout << "Can not find verticies."<<endl;
				return *this;
			}
			pair <int, double> v2 = make_pair(vertex2, 0.0);
			name[vertex1].insert(v2);
			return *this;
		}

		Graph Graph::deleteVertexUndirective(int vertex) { //Удалить вершину
			if (this->name.find(vertex) == name.end())
			{
				cout << "Can not find vertex."<<endl;
				return *this;
			}
			pair <int, double> v2 = make_pair(vertex, 0.0);
			for (auto it2 = this->name[vertex].begin(); it2 != this->name[vertex].end(); ++it2)
			{
				(this->name[it2->first]).erase(v2);
			}
			this->name.erase(vertex);

			return *this;
		}

		Graph Graph::deleteVertexDirective(int vertex) { //Удалить вершину
			if (this->name.find(vertex) == this->name.end())
			{
				cout << "Can not find vertex." << endl;
				return *this;
			}
			pair <int, double> p = make_pair(vertex, 0.0);
			for (auto it = this->name.begin(); it != this->name.end(); ++it)

				if ((this->name[it->first]).find(p) != this->name[it->first].end())
					this->name[it->first].erase(p);

			this->name.erase(vertex);

			return *this;
		}

		Graph Graph::deleteEdge(int vertex1,int vertex2) { //Удалить ребро
			pair <int, double> v1 = make_pair(vertex1, 0.0);
			pair <int, double> v2 = make_pair(vertex2, 0.0);
			this->name[vertex1].erase(v2);
			this->name[vertex2].erase(v1);

			return *this;
		}
		Graph Graph::deleteArc(int vertex1, int vertex2) { //Удалить дугу
			pair <int, double> v2 = make_pair(vertex2, 0.0);
			if (this->name[vertex1].find(v2) != this->name[vertex1].end())
			this->name[vertex1].erase(v2);
			else {
				cout << "Can not find this arc"<<endl;
			}

			return *this;
		}
		void Graph::printGraph() {
			for (auto it = this->name.begin(); it != this->name.end(); ++it) {

				cout << it->first << " : ";
				for (auto it2 = this->name[it->first].begin(); it2 != this->name[it->first].end(); ++it2)
					cout << (*it2).first << ' ';
				cout << endl;
			}
		}
		void Graph::printInFile() {
			ofstream freopen("output.txt");

			for (auto it = this->name.begin(); it != this->name.end(); ++it) {

				freopen << it->first << " : " << endl;
				for (auto it2 = this->name[it->first].begin(); it2 != this->name[it->first].end(); ++it2)
					freopen << (*it2).first << endl;
				freopen << "***" << endl;
			}
		}
			void Graph::printGraphWeight() {
				for (auto it = this->name.begin(); it != this->name.end(); ++it) {

					cout << it->first << " : ";
					for (auto it2 = this->name[it->first].begin(); it2 != this->name[it->first].end(); ++it2)
						cout << (*it2).first << '-' << (*it2).second << ' ';
					cout << endl;
				}
			}
			void Graph::printInFileWeight() {
				ofstream freopen("output.txt");

				for (auto it = this->name.begin(); it != this->name.end(); ++it) {

					freopen << it->first << " : " << endl;
					for (auto it2 = this->name[it->first].begin(); it2 != this->name[it->first].end(); ++it2)
						freopen << (*it2).first << '-' << (*it2).second << ' ' << endl;
					freopen << "***" << endl;
				}
			}

			int Graph::DirectGraphDegree() {
				for (auto it = this->name.begin(); it != this->name.end(); ++it) {
					int c = 0;
					cout << it->first << " : ";
					pair <int, double> v = make_pair(it->first, 0.0);
					for (auto it1 = this->name.begin(); it1 != this->name.end(); ++it1) {
						if ((*it1) == (*it)) c += name[it->first].size();
						else
							if ((this->name[it1->first]).find(v) != this->name[it1->first].end())
								c++;

					}
					cout << c << endl;

				}
				return 0;
			}
			bool Graph::ExistStokForUV(int u, int v) {
				if (this->name.find(u) != this->name.end() && this->name.find(v) != this->name.end()) 
				{
					int in, ou;
					if (this->name[u].size() < this->name[v].size())
					{
						in = u;
						ou = v;
					}
					else 
					{ 
						in = v;
						ou = u;
					}
					for (auto it1 = this->name[in].begin(); it1 != this->name[in].end(); ++it1) {
						for (auto it2 = this->name[ou].begin(); it2 != this->name[ou].end(); ++it2)
							if ((*it1).first == (*it2).first) return true;
					}
				}
				return false;
				
			}



int main() {

	Interface I;
	int graphType = I.chooseGraphType();
	Graph A = I.instructions(graphType);
	I.actions(A, graphType);
	A.DirectGraphDegree();
	int u, v;
	cout << "Input the first vertex" << endl;
	cin >> u;
	cout << "Input the second vertex" << endl;
	cin >> v;
	cout << A.ExistStokForUV(u, v) << endl;
	system("pause");
	
	return 0;
	}
	
