#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream dat1("data/file1", ios::binary);
	ofstream out1("data/file3", ios::binary);
	
	if (!dat1) 
		cout<<"Couldnt open input file"<<endl;
	else if(!out1) 
		cout<<"Couldnt open output file"<<endl;
	else {
		while(!dat1.eof()) {
			int average, sum = 0, temp = 0;
			for(int i = 0; i < 3; i++) {
				dat1.read(reinterpret_cast<char*>(&temp), sizeof(char));
				sum+=temp;
			}
			average = sum / 3;
			int toWrite = average < 75 ? 0 : average > 150 ? 255 : 100;
			for(int i = 0; i < 3; i++) 
				out1.write(reinterpret_cast<char*>(&toWrite), sizeof(toWrite));
		}
		dat1.close();
		out1.close();
	}
	cout<<"Finished"<<endl;
}
