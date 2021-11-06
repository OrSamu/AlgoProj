#pragma once

class Edge
{
	private:
		int source;
		int dest;
	public:
		Edge(int src, int dst);
		Edge(const Edge& edg);
		int GetSource();
		int GetDest();
		void SetSource(int src);
		void SetDest(int dst);
};

