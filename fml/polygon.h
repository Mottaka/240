/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Polygon.h
 * Author: AbuBakar
 *
 * Created on June 19, 2017, 5:57 PM
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "vertexnode.h"

using namespace std;
namespace csce240
{
	class Polygon
	{

	private:

		int size_;
		VertexNode* vertices_;

	public:

		static unsigned char k_init_success_, k_init_not_polygon_, k_init_nonunique_, k_init_has_collinear_;

		Polygon();
		Polygon(Polygon& original);
		~Polygon();
		int Init(Point2d* vertices, int count);
		void Offset(Vector2d by);
		void Scale(double by, Point2d about);
		int size();
		string ToString();
		Polygon& operator=(Polygon& original);
		void Add(Point2d& vertex);
		void ClearVertices();
	};
}
#endif /* POLYGON_H */

