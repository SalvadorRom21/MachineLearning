//Salvador Romero
//LinearRegression Algorithm
//HW 2 problem 2

//preMpg(Max = 46.6, Min = 9)
//preCyl(Max = 8 , Min = 3)
//preDis(Max = 455, Min = 68)
//preHorse(Max = 230 , Min = 6)
//preWeight(Max = 5140, Min =1613)
//preAcceleration (Max = 24.8, Min = 8)

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

struct car{

    float mpg;
    float cylinders;
    float displacement;
    float horsepower;
    float weight;
    float acceleration;
};
int main()
{
    vector <car> cars;
    ifstream dataFile;
    dataFile.open("linearRegression.txt");

    float Min=7000;
    float holder;
    float Max=0;
    float maxHold;

    if(!dataFile){
        cout << "unable to open file";
        exit(1);
    }
    ofstream outFile;
    outFile.open("output.txt");
    if(!outFile){
        cout << "output file not created";
        }


    int carCount = 0;
    float preMpg,preCyl,preDisp,preHorse,preWeight,preAcceleration;

    //preMpg(Max = 46.6, Min = 9)
    //preCyl(Max = 8 , Min = 3)
    //preDis(Max = 455, Min = 68)
    //preHorse(Max = 230 , Min = 6)
    //preWeight(Max = 5140, Min =1613)
    //preAcceleration (Max = 24.8, Min = 8)

    while(true){

        cars.push_back(car());

        dataFile >> preMpg;
        preMpg = ((preMpg-9)/(46.6-9.0));
        cars[carCount].mpg = preMpg;

        dataFile >> preCyl;
        preCyl= ((preCyl-3.0)/(8.0-3.0));
        cars[carCount].cylinders = preCyl;


        dataFile >> preDisp;
        preDisp=((preDisp-68.0)/(455.0-68.0));
        cars[carCount].displacement=preDisp;

        dataFile >> preHorse;
        preHorse=((preHorse-6.0)/(230.0-6.0));
        cars[carCount].horsepower=preHorse;

        dataFile >> preWeight;
        preWeight = ((preWeight-1613.0)/(5140.0-1613.0));
        cars[carCount].weight = preWeight;

        dataFile >> preAcceleration;
        preAcceleration=((preAcceleration - 8.0)/(24.8-8.0));
        cars[carCount].acceleration = preAcceleration;

    
          carCount = carCount +1;

          if(dataFile.eof()) break;
        }

        carCount = carCount-1;


        float mpgT=0;
        float cylT=0;
        float dispT=0;
        float horsT=0;
        float weightT=0;
        float accelerationT = 0;

        float learningRate = .23;
        float err;
        float prediction;

        for(int i = 0; i <carCount;i++){
        prediction = mpgT +
        (cylT * cars[i].cylinders) +
        (dispT * cars[i].displacement) +
        (horsT * cars[i].horsepower) +
        (weightT * cars[i].weight)+
        (accelerationT * cars[i].acceleration);

        err = prediction - cars[i].mpg;

        mpgT= mpgT - learningRate * err;
        cylT = cylT - learningRate * err * cars[i].cylinders;
        dispT = dispT - learningRate* err * cars[i].displacement;
        horsT = horsT - learningRate* err * cars[i].horsepower;
        weightT = weightT - learningRate * err * cars[i].horsepower;
        accelerationT = accelerationT - learningRate * err * cars[i].acceleration;
        }
        cout << "Done training" << endl;
        //cout << "Our predicted function:" << endl;

        //To finish the program I will need to update the loop so that the model continues to learn
        //and will repeat with the training data. The program will continute to run until it its 
        //err value remains within an exeptable number.

        // Also modify this so that i train the model using training, validation , and test data
        // so the program will perfrom the best.

        float userCyl = 0;
        float userDis = 0;
        float userHors = 0;
        float userWeight= 0 ;
        float userAcc = 0;
        float finalPrediction;

        cout <<"Enter the number of Cylinders:";
        cin >> userCyl;
        userCyl = (userCyl-3)/(8-3);
        cout <<"Enter the Diplacement:";
        cin >> userDis;
        userDis = (userDis - 68)/(455-68);
        cout << "Enter the Horsepower:";
        cin >> userHors;
        userHors = (userHors - 6)/(230-6);
        cout << "Enter the Wieght:";
        cin >> userWeight;
        userWeight = (userWeight- 1613)/(5140 - 1613);
        cout << "Enter the Acceleration:";
        cin >> userAcc;
        userAcc = (userAcc - 8)/(24.8-8);

        finalPrediction= mpgT+
        (cylT*userCyl)+
        (dispT*userDis)+
        (horsT * userHors)+
        (weightT * userWeight)+
        (accelerationT * userAcc);

    //preMpg(Max = 46.6, Min = 9)
    //preCyl(Max = 8 , Min = 3)
    //preDis(Max = 455, Min = 68)
    //preHorse(Max = 230 , Min = 6)
    //preWeight(Max = 5140, Min =1613)
    //preAcceleration (Max = 24.8, Min = 8)


        finalPrediction = finalPrediction*(46.6-9)+9;
        cout << "MPG prediction:"<< finalPrediction<< endl;



}
