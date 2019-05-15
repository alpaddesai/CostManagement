/*
 * CompanyCostManagement.h
 *
 *  Created on: May 15, 2019
 *      Author: ADG
 */

#ifndef COMPANYCOSTMANAGEMENT_H_
#define COMPANYCOSTMANAGEMENT_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <ostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::unique_ptr;
using std::ostream;
using std::vector;
using std::setw;
using std::string;
using std::ostringstream;

class CompanyCostManagement
{
	friend ostream& operator<<(ostream& output, CompanyCostManagement& obj);

public:
	CompanyCostManagement(int a, int b, int c, int d, double e, string name);
	virtual ~CompanyCostManagement();
	virtual double calculateCost()=0;

protected:
    int prodVolume;
    int SellingPrice;
    int UnitDirectMaterialsLabor;
   	int DirectLaborHours;
    double DirectLaborHrsPerUnit;
	string companyName;
};


class VolumeBasedCosting: public CompanyCostManagement
{


public:
    VolumeBasedCosting(int a, int b, int c, int d, double e, string name);
     ~VolumeBasedCosting();
     virtual double calculateCost();

private:
     static const int overHeadRate = 20;
 };

 class ActivityBasedCosting: public CompanyCostManagement
 {

public:
	ActivityBasedCosting(int a, int b, int c, int d, double e, string name, int f, int g, int h, int i);
    ~ActivityBasedCosting();
    virtual double calculateCost();

private:
   static const int ActivityEngineeringHoursRate = 10;
   static const int ActivityNumberofSetupsRate =1000;
   static const int ActivityMachineHoursRate =10;
   static const int ActivityPackingOrdersRate =5;

   int EngineeeringHours;
   int NumSetups;
   int MachineHours;
   int NumPackingOrders;

 };



#endif /* COMPANYCOSTMANAGEMENT_H_ */
