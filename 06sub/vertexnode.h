/**
 * Author: Ian Osea
 * CSCE240 SUMMER 2017
 * HW6
 * 
 * */

#ifndef _240_HW_06_VERTEXNODE_H
#define _240_HW_06_VERTEXNODE_H

#include "point2d.h"

using csce240::Point2d;

struct VertexNode
{
    Point2d vertex_;
    VertexNode* next_;
    VertexNode* prev_;
    VertexNode(Point2d& vertex, VertexNode* next, VertexNode* prev);
};

#endif 

