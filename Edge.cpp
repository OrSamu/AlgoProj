#include "Edge.h"

Edge::Edge(int src, int dst)
{
	source = src;
	dest = dst;
}

Edge::Edge(const Edge& edg)
{
	source = edg.source;
	dest = edg.dest;
}

int Edge::GetSource()
{
	return source;
}

int Edge::GetDest()
{
	return dest;
}

void Edge::SetSource(int src)
{
	source = src;
}

void Edge::SetDest(int dst)
{
	dest = dst;
}