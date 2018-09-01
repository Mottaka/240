/**
 * Author: Ian Osea
 * CSCE240 SUMMER 2017
 * HW5
 * 
 * */

#include <exception>
#include "main.h"

void printMenu()  {
  cout << "Usage: \n";
  cout << "(1) calc poly.in + number_x number_y\n";
  cout << "(2) calc poly.in + offsets.in polys.out\n";
}

Polygon* getPolygon(istream& in)  {
  int count;
  in >> count;
  if(count < 3)
  {
    cerr << "Number of points is less than 3";
    return NULL;
  }
    
  Point2d* points = new Point2d[count];
  double x, y;
    
  for(int i = 0 ; i < count ; i++)  {
      in >> x >> y;
      Point2d temp(x, y);
      points[i] = temp;
  }
    
  Polygon* newPolygon = new Polygon();
  newPolygon->Init(points, count);
  return newPolygon;
}

void PolyOut(Polygon& poly, istream& offsets_in, ostream& polys_out)  {
  int count;
  offsets_in >> count;
    
  double x, y;
    
  Polygon temp = poly;
    
  for(int i = 0 ; i < count ; i++)  {
    offsets_in >> x >> y;
    Vector2d vector(x, y);
    temp.Offset(vector);
    polys_out << temp.ToString() << endl;
    }
}

int main(int argc, char** argv) {
    
  if(argc < 2)  {
    printMenu();
    return 0;
  }
   if(argc == 5)  {
    ifstream poly_in(argv[1]);
    Polygon* poly = getPolygon(poly_in);
        
      try  {
        stoi(argv[3]);
        double x = atof(argv[3]);
        double y = atof(argv[4]);
        Vector2d vector(x, y);
        poly->Offset(vector);
        cout << poly->ToString() << endl;
        poly_in.close();
       return 0;
        }

       catch(exception e)  {
            
       }
         
      ifstream offsets_in(argv[3]);
      ofstream polys_out(argv[4]);
        
      try  {
        PolyOut(*poly, offsets_in, polys_out);
      }

      catch(char* c)  {
        poly_in.close();
        offsets_in.close();
        polys_out.close();
        return 0;
        }
        
        poly_in.close();
        offsets_in.close();
        polys_out.close();
        
    }
    
  return 0;
}
