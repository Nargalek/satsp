#include <iostream>
#include <random>
#include <fstream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <windows.h>

using namespace std;

int mile;
double T=100000;
double Td=3;
int Tmin=0.0000001;

void load(vector <int>&,vector <int>&, int&);
void annealing();
int koordy(int, int, int);
void koszt(vector <int>&, vector <int>&,int,double &);
void kand(vector <int>&, int);

int main(){
	srand(time(NULL));
	vector <int> odleglosci;
	vector <int> rozwiazanie;
	vector <int> nrozwiazanie;
	double droga;
	double ndroga;
	double bestd;
	vector <double> bestr;
	
	load(odleglosci, nrozwiazanie, mile);
	for(int i=0;i<nrozwiazanie.size();i++){
		rozwiazanie.push_back(nrozwiazanie[i]);
		bestr.push_back(nrozwiazanie[i]);
	}
	
	for(int i=0;i<odleglosci.size();i++){
		cout<<" "<<odleglosci[i];
	}
	cout<<"\n";
		for(int i=0;i<rozwiazanie.size();i++){
		cout<<" "<<rozwiazanie[i];
	}
	
	
	cout<<"\nkoordy: "<<koordy(rozwiazanie[0],rozwiazanie[1], rozwiazanie.size());
	
	koszt(odleglosci, rozwiazanie, mile, droga);
	bestd=droga;
	cout<<"\ndroga:"<<droga;
	
	
	int q=0;
	while(T>Tmin){
		system("CLS");
		kand(nrozwiazanie, mile);
		koszt(odleglosci, nrozwiazanie, mile, ndroga);
	 if(ndroga<droga){
	 	droga=ndroga;
	 	cout<<" MNIEJSZE!"<<" droga: "<<droga<<" ndroga: "<<ndroga;
	 	for(int i=0;i<rozwiazanie.size();i++){
	 		rozwiazanie[i]=nrozwiazanie[i];
		 }

	 }else if(ndroga>droga){
	 	if(((ndroga-droga)/T)>=((float)rand()/RAND_MAX)){
	 		droga=ndroga;
//	 	 	cout.setf(ios::fixed);
//   		cout.setf(ios::showpoint);
//			cout.precision(10);
//			cout<<"\n dd: "<<dd<<"\n o: "<<o;
		 	cout<<" Wieksze!"<<" droga: "<<droga<<" ndroga: "<<ndroga;
			for(int i=0;i<rozwiazanie.size();i++){
	 		rozwiazanie[i]=nrozwiazanie[i];
		 }
	 	
	 }
	 }
	 if(droga<bestd){
	 	bestd=droga;
	 	for(int i=0;i<rozwiazanie.size();i++){
		bestr[i]=rozwiazanie[i];
	 }}
		cout<<"\n";
		cout<<"best:"<<bestd<<"\n";
		for(int i=0;i<bestr.size();i++){
		cout<<" "<<bestr[i];
	}
	
	cout<<"\n";
	//system("PAUSE");
	T-=Td;
	Sleep(10);
	}
	
	
	
	
	
	
	cout<<"\n";
	system("PAUSE");
	return 0;
}


void load(vector <int> &ar, vector <int> &nrozwiazanie, int &mile){
	
	ifstream dane("dane.txt");
	dane>>mile;
	for(int i=0;i<mile;i++){
		nrozwiazanie.push_back(i+1);
	}
	for(int i=0;i<nrozwiazanie.size();i++){
		int k=rand()%mile;
		swap(nrozwiazanie[i],nrozwiazanie[k]);
	}
	while (true)			
	{
		int x;
		dane>>x;		
		ar.push_back(x);	
		if (dane.eof())break;	
	}
	
}


int koordy(int a, int b, int mile){
	int c=0;
	c=((a-1)*mile)+b-1;
	return c;
}

void koszt(vector <int>&odleglosci, vector <int>&rozwiazanie, int mile,  double &ndroga){
		ndroga=0;
		for(int j=0;j<mile;j++){
			if(j<mile-1){
			ndroga+=odleglosci[koordy(rozwiazanie[j],rozwiazanie[j+1],mile)];
			}else if(j==mile-1){
			ndroga+=odleglosci[koordy(rozwiazanie[j],rozwiazanie[0],mile)];
			}
		}
}

void kand(vector <int>& nrozwiazanie, int mile){
		int k=rand()%mile;
		int i=rand()%mile;
		swap(nrozwiazanie[i],nrozwiazanie[k]);
	
	
}
