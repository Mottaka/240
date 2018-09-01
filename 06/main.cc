#include "main.h"

void printMenu()
{
    cout << "Usage: \n";
    cout << "(1) calc poly.in + number_x number_y\n";
    cout << "(2) calc poly.in + offsets.in polys.out\n";
    cout << "(3) calc poly.in x number_scalar number_x number_y\n";
    cout << "(4) calc poly.in x by.in about.in polys.out\n";
}

Polygon* getPolygon(istream& in)
{
    int count;
    in >> count;
    if(count < 3)
    {
        cerr << "Number of points is less than 3";
        return NULL;
    }
    
    Point2d* points = new Point2d[count];
    double x, y;
    
    for(int i = 0 ; i < count ; i++)
    {
        in >> x >> y;
        Point2d temp(x, y);
        points[i] = temp;
    }
    
    Polygon* newPolygon = new Polygon();
    newPolygon->Init(points, count);
    return newPolygon;
}

void PolyOut(Polygon& poly, istream& offsets_in, ostream& polys_out)
{
    int count;
    offsets_in >> count;
    
    double x, y;
    
    for(int i = 0 ; i < count ; i++)
    {
        Polygon temp = poly;
        offsets_in >> x >> y;
        Vector2d vector(x, y);
        temp.Offset(vector);
        polys_out << temp.ToString() << endl;
    }
}

void PolyOut(Polygon& poly, istream& by_in, istream& about_in, ostream& polys_out)
{
    int count;
    by_in >> count;
    about_in >> count;
   
    double x, y, by;
    
    for(int i = 0 ; i < count ; i++)
    {
        Polygon temp = poly;
        by_in >> by;
        about_in >> x >> y;
        Point2d about(x, y);
        temp.Scale(by, about);
        polys_out << temp.ToString() << endl;
    }
}

int main(int argc, char** argv) {
    
    if(argc < 2)
    {
        printMenu();
        return 0;
    }
    if(argc == 5)
    {
        ifstream poly_in(argv[1]);
        Polygon* poly = getPolygon(poly_in);
        
        try
        {
            stoi(argv[3]);
            double x = atof(argv[3]);
            double y = atof(argv[4]);
            Vector2d vector(x, y);
            poly->Offset(vector);
            cout << poly->ToString() << endl;
            poly_in.close();
            return 0;
        }
        catch(exception e)
        {
            
        }
        
        
        ifstream offsets_in(argv[3]);
        ofstream polys_out(argv[4]);
        
        try
        {
            PolyOut(*poly, offsets_in, polys_out);
        }
        catch(char* c)
        {
            poly_in.close();
            offsets_in.close();
            polys_out.close();
            return 0;
        }
        
        poly_in.close();
        offsets_in.close();
        polys_out.close();
        
    }
    else if(argc == 6)
    {
        ifstream poly_in(argv[1]);
        Polygon* poly = getPolygon(poly_in);
        
        try
        {
            stoi(argv[3]);
            double scalar = atof(argv[3]);
            double x = atof(argv[4]);
            double y = atof(argv[5]);
            Point2d point(x, y);
            poly->Scale(scalar, point);
            cout << poly->ToString() << endl;
            poly_in.close();
            return 0;
        }
        catch(exception e)
        {
            
        }
        
        ifstream by_in(argv[3]);
        ifstream about_in(argv[4]);
        ofstream polys_out(argv[5]);
        
        try
        {
            PolyOut(*poly, by_in, about_in, polys_out);
        }
        catch(char* c)
        {
            by_in.close();
            about_in.close();
            polys_out.close();
            return 0;
        }
        
        by_in.close();
        about_in.close();
        polys_out.close();
    }
    
    
    
  return 0;
}
