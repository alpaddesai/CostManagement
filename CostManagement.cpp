/*
 * CostManagement.cpp
 *
 *  Created on: May 15, 2019
 *      Author: ADG
 */

#include "CompanyCostManagement.h"


//*******************************************************************/


ostream& operator<<(ostream& output, CompanyCostManagement& obj)
{

          output <<obj.companyName <<" Production Volume"<<setw(20)<<obj.prodVolume<<endl
			     <<obj.companyName <<" Selling Price "<<setw(20)<<"$"<<obj.SellingPrice<<endl
			     <<obj.companyName <<" Unit direct materials and labor  $"<<obj.UnitDirectMaterialsLabor<<endl
			     <<obj.companyName <<" Direct labor-hours"<< setw(20)<<obj.DirectLaborHours<<endl
			     <<obj.companyName <<" Direct labor-hours per unit"<<setw(10)<<obj.DirectLaborHrsPerUnit<<endl;

return output;
}


//*******************************************************************/

CompanyCostManagement::CompanyCostManagement(int a, int b, int c, int d, double e, string name):prodVolume(a),SellingPrice(b),UnitDirectMaterialsLabor(c),DirectLaborHours(d),DirectLaborHrsPerUnit(e),companyName(name)
{


}

CompanyCostManagement::~CompanyCostManagement()
{

}

//*******************************************************************/

VolumeBasedCosting::VolumeBasedCosting(int a, int b, int c, int d, double e, string name): CompanyCostManagement(a,b,c,d,e,name)
{


}


VolumeBasedCosting::~VolumeBasedCosting()
{

}

//*******************************************************************/

ActivityBasedCosting::ActivityBasedCosting(int a, int b, int c, int d, double e, string name,int f, int g, int h, int i): CompanyCostManagement(a,b,c,d,e,name)
{
	    this->EngineeeringHours=f;
	    this->NumSetups=g;
	    this->MachineHours=h;
	    this->NumPackingOrders=i;

}


ActivityBasedCosting::~ActivityBasedCosting()
{

}



//*******************************************************************/
double VolumeBasedCosting::calculateCost()
{

double VariableCostPerUnit=0;

double TotalOverhead = (this->DirectLaborHours*overHeadRate);
VariableCostPerUnit = (TotalOverhead/this->prodVolume);

cout<< " Value of Total Cost per unit is $"<<VariableCostPerUnit<<endl<<endl;

return VariableCostPerUnit;
}


//*******************************************************************/

double ActivityBasedCosting::calculateCost()
{

double VariableCostPerUnit=0;

double DriverActivityEngHrsCostPerUnit=ActivityEngineeringHoursRate*this->EngineeeringHours;
double DriverActivityNumSetupsCostPerUnit=ActivityNumberofSetupsRate*this->NumSetups;
double DriverActivityMachineHoursCostPerUnit=ActivityMachineHoursRate*this->MachineHours;
double DriverActivityNumPackingOrdersCostPerUnit=ActivityPackingOrdersRate*this->NumPackingOrders;

VariableCostPerUnit = (DriverActivityEngHrsCostPerUnit/this->prodVolume) + (DriverActivityNumSetupsCostPerUnit/this->prodVolume)
                      + (DriverActivityMachineHoursCostPerUnit/this->prodVolume) + (DriverActivityNumPackingOrdersCostPerUnit/this->prodVolume);

cout<< " Value of Total Cost per unit is $"<<VariableCostPerUnit<<endl<<endl;

return VariableCostPerUnit;
}

//*******************************************************************/

