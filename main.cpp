#include <iostream>
#include <exception>
using namespace std;

void check0(int);

class div0:public exception{ //class จัดการตัวหารเป็น 0
	public:
	virtual const char* what() const throw(){
		
		return "Divided by zero";
	}
};

class fail:public exception{ //class จัดการตัวหารเป็น 0
	public:
	virtual const char* what() const throw(){

		return "Input failed. Not a number.";
	}
};

class outRange : public exception { 
public:
    virtual const char* what() const throw() {

        return "Value out of range (-10000 to 10000)"; 
    }
};

int main(){
	int x,y;
	double d;
	int a=1;
do{
	try{

		cout<<"Enter 2 numbers: ";
		cin>>x>>y;

		if(cin.fail()){
			cin.clear();
			cin.ignore(50,'\n');
			throw fail();
		}

		// //Curated exception handling with const
		// if(cin.fail()) throw("Incorrect type entered");
	
		// if(abs(x)>1000 ||abs(y)>1000) throw("alue out of range");

		// if (y==0) throw("Error divide by zero");

		// //Curated exception handling with int
		// if(cin.fail()) throw 101;
		
		// if(abs(x)>1000 ||abs(y)>1000) throw 102;

		// if (y==0) throw 103;

		//Curated exception handling 
		
		// if(cin.fail()) throw 101; //ใข้ fail แทนการ throw 101
		
		if(abs(x) > 10000 || abs(y) > 10000) throw outRange();

		check0(y); //เช็คตัวหารเป็น 0 
		a=0;


		//Normal codex
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;

		int i;
		double* myarray;
		for(i=0;i<100000;i++){
			cout<<"Allocating memory...."<<i<<endl;
			myarray = new double[500000000];
		} //bad allocating memory
		cout<<endl;

		}


	// catch(const char* error){ //จะไม่ถูกเรียกใช้งาน ถ้าไม่มี throw มา
	// 	cerr<<error<<endl;
	// 	a=1;
	// 	cin.clear();
	// 	cin.ignore(50,'\n');
	// }

	// catch(int e){
	// 	switch(e){
	// 		case 101: cerr<<"Stupid! Not numbers"<<endl; break;
	// 	}
	// }

	// catch(exception &e){
	// 	cout<<e.what()<<endl;
	// 	a=0;
	// }

	catch (exception &e){
		cerr << "\nError: " << e.what() << endl; //รวบให้เหลือ catch เดียว แก้โดยสร้าง class มาเพิ่ม
	}

}while(a);
	return 0;
}


void check0(int x){
	if(x==0) throw div0();
}