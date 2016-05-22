#pragma once
#include <cassert>
#include <queue>

template<class V,class E>
struct LinkEdge
{
	LinkEdge(int srcIndex = - 1,int dstIndex = -1,const E&weight = E())
		:_srcIndex(srcIndex)
		,_dstIndex(dstIndex)
		,_weight(weight)
		,_next(NULL)
	{}
	int _srcIndex;//原顶点下标
	int _dstIndex;//目标顶点下标
	E _weight;
	LinkEdge<V,E>* _next;
};

template<class V,class E>
struct LinkVertex
{
	LinkVertex(const V&Vertex = V())
		:_Vertex(Vertex)
		,_head(NULL)
	{}
	V _Vertex;//顶点
	LinkEdge<V,E>* _head;
};
template<class V,class E>
struct CompareLinkEdge
{
	bool operator()(LinkEdge<V,E>*l,LinkEdge<V,E>*r)
	{
		return l->_weight < r->_weight;
	}
};
template<class V,class E>
class GraphLink
{
public:
	GraphLink(bool dir = false)
		:_LinkTable(NULL)
		,_VertexSize(0)
		,_HasDir(dir)
	{}
	GraphLink(const V* Array,int size,bool dir = false)
		:_VertexSize(size)
		,_HasDir(dir)
	{
		_LinkTable = new LinkVertex<V,E>[size];
		for(int i = 0;i < size;++i)
		{
			_LinkTable[i] = Array[i];
		}
	}
	~GraphLink()
	{
		delete[] _LinkTable;
		_VertexSize = 0;
	}
public:
	int GetVertexIndex(const V&vertex)
	{
		for(int i = 0;i < _VertexSize;++i)
		{
			if(_LinkTable[i]._Vertex == vertex)
			{
				return i;
			}
		}
		return -1;
	}
	void _ADDEdge(int srcIndex,int dstIndex,const E& weight)
	{
		LinkEdge<V,E>*tmp = new LinkEdge<V,E>(srcIndex,dstIndex,weight);

		tmp->_next = _LinkTable[srcIndex]._head;
		_LinkTable[srcIndex]._head = tmp;

	}
	void AddEdge(const V&src,const V&dst,const E& weight)
	{
		int srcIndex = GetVertexIndex(src);
		int dstIndex = GetVertexIndex(dst);
		assert(srcIndex != -1 && dstIndex != -1);

		//有向图or无向图
		if(_HasDir)
		{
			_ADDEdge(srcIndex,dstIndex,weight);
		}
		else
		{
			_ADDEdge(srcIndex,dstIndex,weight);
			_ADDEdge(dstIndex,srcIndex,weight);
		}
	}
	void Display()
	{
		for(int i = 0;i < _VertexSize;++i)
		{
			cout<<_LinkTable[i]._Vertex<<"["<<i<<"]->";
			LinkEdge<V,E>*cur = _LinkTable[i]._head;
			while(cur)
			{
				cout<<cur->_weight<<"["<<cur->_dstIndex<<"]->";
				cur = cur->_next;
			}
			cout<<"NULL"<<endl;
		}
	}
	void DFS(const int cur)//深度优先
	{
		cout<<"DFS:";
		bool *visited = new bool[_VertexSize];
		memset(visited,0,sizeof(bool)*_VertexSize);

		_DFS(cur,visited);
		cout<<endl;
	}
	void BFS(const int cur)//广度优先
	{
		cout<<"BFS:";
		bool *visited = new bool[_VertexSize];
		memset(visited,0,sizeof(bool)*_VertexSize);

		_BFS(cur,visited);
		cout<<endl;
	}

protected:
	void _BFS(int cur,bool *visited)
	{
		visited[cur] = true;

		queue<int> q;
		q.push(cur);
		while(!q.empty())
		{
			cur = q.front();
			q.pop();
			
			LinkEdge<V,E>* edge = _GetFirstEdge(cur);
			while(edge)
			{
				if (visited[edge->_dstIndex] == false)
				{
					cout<<_LinkTable[edge->_srcIndex]._Vertex<<"->"
						<<_LinkTable[edge->_dstIndex]._Vertex<<" ";

					visited[edge->_dstIndex] = true;
					q.push(edge->_dstIndex);
				}

				edge = edge->_next;
			}
		}
	}
	LinkEdge<V,E>* _GetFirstEdge(const int src)
	{
		return _LinkTable[src]._head;
	}
	LinkEdge<V,E>* _GetNextEdge(const int src,const int cur)
	{
		LinkEdge<V,E>* edge = _LinkTable[src]._head;
		while(edge)
		{
			if(edge->_dstIndex == cur)
			{
				return edge->_next;//找邻接表里的下一条边
			}
			edge = edge->_next;
		}
		return NULL;
	}
	void _DFS(const int src,bool *visited)
	{
		//cout<<_LinkTable[src]._Vertex<<" ";
		visited[src] = true;

		LinkEdge<V,E>* edge = _GetFirstEdge(src);

		while(edge)
		{
			if(visited[edge->_dstIndex] == false)
			{
				cout<<_LinkTable[edge->_srcIndex]._Vertex<<"->"<<_LinkTable[edge->_dstIndex]._Vertex<<" ";

				_DFS(edge->_dstIndex,visited);
			}
			edge = edge->_next;
		}
	}
private:
	LinkVertex<V,E>* _LinkTable;
	int _VertexSize;
	bool _HasDir;
};