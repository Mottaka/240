/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VertexNode.h
 * Author: AbuBakar
 *
 * Created on June 19, 2017, 5:48 PM
 */

#ifndef VERTEXNODE_H
#define VERTEXNODE_H

#include "point2d.h"

using csce240::Point2d;

struct VertexNode
{
    Point2d vertex_;
    VertexNode* next_;
    VertexNode* prev_;
    VertexNode(Point2d& vertex, VertexNode* next, VertexNode* prev);
};

#endif /* VERTEXNODE_H */

