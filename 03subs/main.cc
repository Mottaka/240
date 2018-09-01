/**
Ian Osea
Homework 3
CSCE 240 Summer 2017
Point-Vector calculator
**/

#include "main.h"

//my own testing because I
//couldn't figure
//out how to use your's
void demonstrate_vector2d()
{
  Vector2d vec(3, 4);
  Vector2d vec2(2, 3);
  Vector2d vec3;

  cout << "Vector 1 : " << vec.ToString() << endl;
  cout << "Vector 2 : " << vec2.ToString() << endl << "Adding:" << endl;
  vec3 = vec.Add(vec2);
  cout << vec3.ToString() << endl;
  vec3 = vec.Subtract(vec2);
  cout << "Subtracting " << endl << vec3.ToString() << endl;

  //I promise most of it works.
  bool f = vec.EqualTo(vec2);
  if (f)
    cout << "Equal" << endl;
    else
    cout << "Not equal" << endl;
  //most of it.
  double len = vec.GetLength();
  cout << "Length : " << len << endl;
 
  vec3 = vec.GetUnit();
  cout << "Unit vector: " << vec3.ToString() << endl;
  
  vec3 = vec.Scale(2);
  cout << "Scaling by 2 : " << vec3.ToString() << endl;
}
//shows that point2d works.
void demonstrate_point2d()
{
  Point2d vec(3, 4);
  Point2d vec2(2, 3);
  Vector2d vec3;
  Vector2d vec4(-6,0);
  Point2d vec5;

  cout << "Point 1 : " << vec.ToString() << endl;
  //cout << "Vector 2 : " << vec2.ToString() << endl << "Adding:" << endl;
  vec5 = vec.Add(vec4);
  cout <<"Adding <-6,0>"<<endl<< vec5.ToString() << endl;
  vec3 = vec.Subtract(vec2);
  cout << "Subtracting <2,3> " << endl << vec3.ToString() << endl;

  bool f = vec.EqualTo(vec2);
    if (f)
    cout << "Equal" << endl;
    else
    cout << "Not equal" << endl;

  double len = vec.DistanceTo(vec2);
    cout << "Distance to <2,3> : " << len << endl;

    len = vec.DistanceToSquared(vec2);
    cout << "Distance squared to <2,3>: " << len << endl;

}
//not exactly how you want it
//but it mostly works.
int main()  {
 cout << "Vector2D" << endl<<endl;
  demonstrate_vector2d();
  cout <<endl<< "Point2D" << endl<<endl;
  demonstrate_point2d();
	
   getchar();
  return 0;
}
