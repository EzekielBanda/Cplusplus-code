#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;

struct Patient
{
	int patientID;
	string gender;
	float age;
	int hypertension;
	int heartDisease;
	string everMarried;
	string workType;
	string residenceType;
	float avgGlucoseLevel;
	float bmi;
	string smokingStatus;
	int stroke;
};

const int Max=5112;
Patient ip[Max];
int count=0;

void ReadFileStoreInArry( string& dataset)
{
	ifstream infile(dataset);
	
	string line="";
	string tempString;
	
	getline(infile,line);
	if(infile.is_open())
	{
		while(getline(infile,line) && count<Max)
		{
			stringstream ss(line);
			
			getline(ss,tempString,',');
			ip[count].patientID= atoi(tempString.c_str());
			
			getline(ss,ip[count].gender,',');
			
			getline(ss,tempString,',');
			ip[count].age= atof(tempString.c_str());
			
			getline(ss,tempString,',');
			ip[count].hypertension= atoi(tempString.c_str());
			
			getline(ss,tempString,',');
			ip[count].heartDisease= atoi(tempString.c_str());
			
			getline(ss,ip[count].everMarried,',');
			getline(ss,ip[count].workType,',');
			getline(ss,ip[count].residenceType,',');
			
			getline(ss,tempString,',');
			ip[count].avgGlucoseLevel= atof(tempString.c_str());
			
			getline(ss,tempString,',');
			if(tempString=="N/A")
				{
					ip[count].bmi= -1.0;
				}
				else
				{
					ip[count].bmi =  atof(tempString.c_str());
				}
		
			
			
			
			
			getline(ss,ip[count].smokingStatus,',');
			
			getline(ss,tempString,',');
			ip[count].stroke= atof(tempString.c_str());
			
		    cout<<ip[count].bmi<<endl;
			count++;
			
			tempString= "";
			line= "";
		}
		
	}
	infile.close();

	}	
	void Dbmi()
	{ ofstream output("stroke_patients.csv");
	
	if(output.is_open())
		if(ip[count].bmi==-1.0)
				{
					output<<"N/A"<<endl;
				}
		 output.close();		
	}

void countRecords()
{
	cout<<"Total number of records: "<<count<<endl;
}


void newFilteredRecords()
{
	ofstream outfile("stroke_patients.csv");
	if(outfile.is_open())
	{
	
		for(int i=0;i<count;i++){
			if(ip[i].stroke==1)
			{
				outfile<<ip[i].patientID<<','<<ip[i].gender<<','<<ip[i].age<<','<<
				ip[i].hypertension<<','<<ip[i].heartDisease<<','<<ip[i].everMarried<<','<<
				ip[i].workType<<','<<ip[i].residenceType<<','<<ip[i].avgGlucoseLevel<<','<<
				ip[i].bmi<<','<<ip[i].smokingStatus<<','<<ip[i].stroke<<endl;
			
			}
		}
		outfile.close();
		
	
	}

}
int main()
{
string dataset="healthcare-dataset-stroke-data.csv";
ReadFileStoreInArry(dataset);
newFilteredRecords();
void Dbmi();

	return 0;
}