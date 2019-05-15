/*
 * TestCaseCostManagement.cpp
 *
 *  Created on: May 15, 2019
 *      Author: ADG
 */

#include "CompanyCostManagement.h"

int calculateCostFunction( CompanyCostManagement *);

int main()
{

cout<<"Execute Company cost management"<<endl;

vector <CompanyCostManagement *> costAnalysis(4);

VolumeBasedCosting *costAnalysisA = new VolumeBasedCosting(5000,400,200,25000,5,"AW");
VolumeBasedCosting *costAnalysisB= new VolumeBasedCosting(20000,200,80,75000,3.75,"SZ");
ActivityBasedCosting *costAnalysisC= new ActivityBasedCosting(5000,400,200,25000,5,"AW",5000,200,50000,5000);
ActivityBasedCosting *costAnalysisD= new ActivityBasedCosting(20000,200,80,75000,3.75,"SZ",7500,100,100000,10000);

costAnalysis[0]=costAnalysisA;
costAnalysis[1]=costAnalysisB;
costAnalysis[2]=costAnalysisC;
costAnalysis[3]=costAnalysisD;

for (int i =0;i<5;i++)
calculateCostFunction(costAnalysis[i]);

 
 delete costAnalysisA;
 delete costAnalysisB;
 delete costAnalysisC;
 delete costAnalysisD;
 
return 0;
}

int calculateCostFunction(CompanyCostManagement *ptrObject)
{
cout<<*ptrObject<<endl;
double variableCost=ptrObject->calculateCost();
return 0;
}

/* OUTPUT
Execute Company cost management
AW Production Volume                5000
AW Selling Price                    $400
AW Unit direct materials and labor  $200
AW Direct labor-hours               25000
AW Direct labor-hours per unit         5

 Value of Total Cost per unit is $100

SZ Production Volume               20000
SZ Selling Price                    $200
SZ Unit direct materials and labor  $80
SZ Direct labor-hours               75000
SZ Direct labor-hours per unit      3.75

 Value of Total Cost per unit is $75

AW Production Volume                5000
AW Selling Price                    $400
AW Unit direct materials and labor  $200
AW Direct labor-hours               25000
AW Direct labor-hours per unit         5

 Value of Total Cost per unit is $155

SZ Production Volume               20000
SZ Selling Price                    $200
SZ Unit direct materials and labor  $80
SZ Direct labor-hours               75000
SZ Direct labor-hours per unit      3.75

 Value of Total Cost per unit is $61.25
*/

