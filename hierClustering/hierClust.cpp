#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Coordinate{
	string name;
	double x_cor;
	double y_cor;
};

double distCor(Coordinate one, Coordinate two);

int main()
{
	const int totalPoints=12;
	double distx;
	double disty;


	vector<Coordinate> points;
	;

	for(int i=0; i<totalPoints;i++)

		{
            points.push_back(Coordinate());
			int k=i +1;
			string kstring = to_string(k);
			points[i].name = ( "A" + kstring);
			//cout << points[i].name <<endl;

		}

        points[0].x_cor =2.0;
        points[0].y_cor =2.0;
        points[1].x_cor =3.01;
        points[1].y_cor =2.0;
        points[2].x_cor =4.02;
        points[2].y_cor =2.0;
        points[3].x_cor =5.03;
        points[3].y_cor =2.0;
        points[4].x_cor =6.04;
        points[4].y_cor =2.0;
        points[5].x_cor =7.05;
        points[5].y_cor =2.0;
        points[6].x_cor =2.0;
        points[6].y_cor =3.5;
        points[7].x_cor =3.01;
        points[7].y_cor =3.5;
        points[8].x_cor =4.02;
        points[8].y_cor =3.5;
        points[9].x_cor =5.03;
        points[9].y_cor =3.5;
        points[10].x_cor =6.04;
        points[10].y_cor =3.5;
        points[11].x_cor =7.05;
        points[11].y_cor =3.5;


        vector<vector<int>> clusters;

        for(int i = 0; i<points.size();i++)
            {
            vector<int>temp;
            temp.push_back(i);
            clusters.push_back(temp);
            }

        double minDist=6;
        double tempDist;

        int clustSize=0;
        int groupSize=0;
        int GRPSIZE=0;

        for(int i=0;i<(clusters.size());i++)
            {
              for(int k=0;k<clusters[k].size();i++)
                {
                        minDist=distCor(points[clusters[i][k]],points[clusters[i+1][n]]);
                        cout<<"here"<<endl;
                }
                    cout<<"aqui"<<endl;
                }

}
double distCor(Coordinate one,Coordinate two)
{
    double mindist;
    double xDiff=0;
    double yDiff=0;

    xDiff=two.x_cor-one.x_cor;
    yDiff=two.y_cor-one.y_cor;

    mindist= sqrt(pow(xDiff,2)+pow(yDiff,2));
    //cout << xDiff << " "<< yDiff<< endl;
    return mindist;
}
