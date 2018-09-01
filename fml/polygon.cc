/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stddef.h>

#include "polygon.h"
#include "vertexnode.h"
#include "point2d.h"

using csce240::Polygon;
using csce240::Vector2d;

unsigned char Polygon::k_init_success_ = 1;
unsigned char Polygon::k_init_not_polygon_ = 2;
unsigned char Polygon::k_init_nonunique_ = 3;
unsigned char Polygon::k_init_has_collinear_ = 4;

Polygon::Polygon()
{
    size_ = 0;
    vertices_ = NULL;
}

Polygon::Polygon(Polygon& original)
{
    vertices_ = NULL;
    size_ = original.size_;
    VertexNode* current = original.vertices_;
    while(current != NULL)
    {
        Add(current->vertex_);
        current = current->next_;
    }
    k_init_success_ = original.k_init_success_;
    k_init_not_polygon_ = original.k_init_not_polygon_;
    k_init_nonunique_ = original.k_init_nonunique_;
    k_init_has_collinear_ = original.k_init_has_collinear_;
}

Polygon::~Polygon()
{
    ClearVertices();
}

int Polygon::Init(Point2d* vertices, int count)
{
	if (count < 3)
	{
		return k_init_not_polygon_;
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = (i + 1); j < count; j++)
		{
			if (vertices[i].EqualTo(vertices[j]))
			{
				return k_init_nonunique_;
			}
		}
	}
	for (int i = 0; (i + 2) < count; i++)
	{
		if (Point2d::Collinear(vertices[i], vertices[i + 1], vertices[i + 2]))
		{
			return k_init_has_collinear_;
		}
	}
	size_ = count;
	for (int i = 0; i < count; i++)
	{
		Add(vertices[i]);
	}
	return k_init_success_;
}

void Polygon::Offset(Vector2d by)
{
    VertexNode* current = vertices_;
    while(current != NULL)
    {
        current->vertex_ = current->vertex_ + by;
        current = current->next_;
    }
}

void Polygon::Scale(double by, Point2d about)
{
    VertexNode* current = vertices_;
    while(current != NULL)
    {
        Vector2d temp = current->vertex_ - about;
        temp = temp.GetUnit();
        temp = temp * by;
        current->vertex_ = current->vertex_ + temp;
        current = current->next_;
    }
}

int Polygon::size()
{
    return size_;
}

string Polygon::ToString()
{
    string temp = "";
    VertexNode* current = vertices_;
    while(current != NULL)
    {
		temp += ">";
        temp += current->vertex_.ToString();
        current = current->next_;
		temp += "-";
    }
	return temp;
}

Polygon& Polygon::operator =(Polygon& original)
{
	if (&original == this)
	{
		return *this;
	}
	size_ = original.size_;
	VertexNode* current = original.vertices_;
	while (current != NULL)
	{
		Add(current->vertex_);
		current = current->next_;
	}
	k_init_success_ = original.k_init_success_;
	k_init_not_polygon_ = original.k_init_not_polygon_;
	k_init_nonunique_ = original.k_init_nonunique_;
	k_init_has_collinear_ = original.k_init_has_collinear_;
	return *this;
}

void Polygon::Add(Point2d& vertex)
{
	VertexNode* newNode = new VertexNode(vertex, NULL, NULL);
    if(vertices_ == NULL)
    {
		vertices_ = newNode;
    }
    else
    {
		VertexNode* current = vertices_;
		while (current->next_ != NULL)
		{
			current = current->next_;
		}
		current->next_ = newNode;
                newNode->prev_ = current;
    }
}

void Polygon::ClearVertices()
{
    VertexNode* current = vertices_;
    while(current != NULL)
    {
        VertexNode* temp = current->next_;
        delete current;
        current = temp;
    }
	size_ = 0;
	vertices_ = NULL;
}
