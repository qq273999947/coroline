#pragma once

template<class V,class E>
class GraphMatrix
{
public:
	GraphMatrix(size_t size,V * array)
		:_vArray(new V[size])
		,_size(size)
	{
		for(int i = 0;i < size;++i)
		{
			_vArray[i] = array[i];
		}

		_edges = new E*[size];
		for(int i = 0; i < size;++i)
		{
			_edges[i] = new E[size];
			memset(_edges[i],E(),sizeof(E)*size);
		}
	}
	~GraphMatrix()
	{
		delete[] _vArray;
		_vArray = NULL;
		for(int i = 0;i < _size;++i)
		{
			delete[] _edges[i];
		}
		delete[] _edges;
		_edges = NULL;

		_size = 0;
	}
public:
	size_t GetIndex(const V& v)
	{
		for(int i = 0;i < _size;++i)
		{
			if(_vArray[i] == v)
			{
				return i;
			}
		}
		return -1;
	} 
	void AddEdges(const V&src,const V&dst,const E&w)
	{
		size_t SrcIndex = GetIndex(src);
		size_t DstIndex = GetIndex(dst);

		if(SrcIndex != -1 && DstIndex != -1)
		{
			_edges[SrcIndex][DstIndex] = w;
			_edges[DstIndex][SrcIndex] = w;
		}
	}
	void Display()
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << _vArray[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < _size; ++i)
		{
			for (int j = 0; j < _size; ++j)
			{
				cout << _edges[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
protected:
	V* _vArray;
	E **_edges;
	size_t _size;
};