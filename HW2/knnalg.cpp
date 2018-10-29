// Salvador Romero
//K Nearest Neighbor Algorithm
// HW 2 Problem 1

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

 struct plant{
 float sepLen;
 float sepWid;
 float petLen;
 float petWid;
 string name;
};

int main(){

   vector <plant> iris;
    iris.push_back(plant());

    ifstream dataFile;
    dataFile.open("irisdataset.txt");

    //if the file is unable to open
    if(!dataFile){
        cout << "unable to open file";
        exit(1);
    }

    int plantCount=0;
    float First, Second, Third , Fourth, Fifth;
    float normalize;
    char com1, com2, com3, com4;
    string plantname;

    while (true){

    iris.push_back(plant());

    dataFile >> First;
    First = ((First - 4.3)/(7.9-4.3));
    iris[plantCount].sepLen=First;

    dataFile >> com1;

    dataFile >> Second;
    Second =((Second-2.0)/(4.4-2.0));
    iris[plantCount].sepWid=Second;

    dataFile >> com2;

    dataFile >> Third;

    Third = ((Third-1.0)/(6.9-1.0));
    iris[plantCount].petLen=Third;
    dataFile >> com3;

    dataFile >> Fourth;
    Fourth= (Fourth-0.1)/(2.5-0.1);
    iris[plantCount].petWid = Fourth;

    dataFile >> com4;

    dataFile >> plantname;
    iris[plantCount].name = plantname;

    plantCount= plantCount + 1;
    if(dataFile.eof()) break;
    }

    //normalize = (iris[].sepLen-4.3)/(7.9-4.3);
    //cout<< normalize << endl;
    //cout << iris[128].sepLen << endl;
    /*for(int i = 0; i<plantCount-1;i++){


        cout << setw(12) <<iris[i].sepLen<<" ";
        cout << setw(12) <<iris[i].sepWid<<" ";
        cout << setw(12) <<iris[i].petLen<<" ";
        cout << setw(12) <<iris[i].petWid<<" ";
        cout << iris[i].name << endl;
    }
    */

    float userSepLen = 0;
    float userSepWid=0;
    float userPetLen=0;
    float userPetWid;
    float sLval = 0;
    float sWval = 0;
    float pLval = 0;
    float pWval = 0;
    float distance = 0;
    float nearest = 10;
    int index = 0;
    int found = 0;
    int kValue =0;
    int test = 0;


    bool inVec = false;
    vector <int> foundVals;

    cout << "Enter kValue "<<endl;
    cin >> kValue;
    cout << "Enter the sepal length in cm: ";
    cin >> userSepLen;
    userSepLen = (userSepLen-4.3)/(7.9-4.3);
    cout << "Enter the sepal width in cm: ";
    cin >> userSepWid;
    userSepWid = (userSepWid-2.0)/(4.4-2.0);
    cout << "Enter petal lenth in cm: ";
    cin >> userPetLen;
    userPetLen = (userPetLen-1.0)/(6.9-1.0);
    cout << "Enter petal width in cm: ";
    cin >> userPetWid;
    userPetWid= (userPetWid-0.1)/(2.5-0.1);

for(int p=0;p<kValue;p++)
{
    nearest = 10;

    for(int i = 0; i < plantCount-1;i++){

        for(int k = 0; k < foundVals.size();k++)
            if(i==foundVals.at(k))
                inVec=true;

        if(!inVec){

            sLval=userSepLen-iris[i].sepLen;
            sWval=userSepWid-iris[i].sepWid;
            pLval=userPetLen-iris[i].petLen;
            pWval=userPetWid-iris[i].petWid;

            sLval=pow(sLval,2);
            sWval=pow(sWval,2);
            pLval=pow(pLval,2);
            pWval=pow(pWval,2);

            distance = sqrt(sLval+sWval+pLval+pWval);

            if(distance < nearest){
                nearest=distance;
                index = i;
            }

        }
        inVec=false;
        }



    foundVals.push_back(index);

}

    for(int v = 0; v < foundVals.size();v++)
        {
        cout <<"neighbor"<< v+1 << " :"<< foundVals.at(v) +1;
        cout <<" "<<iris[foundVals.at(v)].name<<endl;

        }
}

//Test examples
//4.9, 3.0, 1.4,0.2
//4.9, 2.4, 3.3,1,0
//4.9, 2.5, 4.5,1.7
