#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;
//class to get number that will put in new ex if there exist common prefix
class Numbers {
private:
	int experssion;

public:
	int getNumber() {
        return experssion;
    }

void setNumber(int ex) {
        experssion = ex;
		
    }
};       
//when i need to append int value to string specially to put the new number of new rule to output string 
string conv (int x) {
	stringstream st;
	st << x;
	
	return st.str();
}
	Numbers n;               //object from class to access functions

//function to get common string in each rule
string getcommonstring (string A,string B) {
	string common="";
	 int commonlength=0;
     int min=0;
	 //i want to get string of minimum length to compare the minimum length of common
	 if (A.length() > B.length()){
            min=B.length();
            }
            else if (B.length() > A.length())
            {
              min=A.length();  
            }
            else{
                min=A.length();
            }
			
		  for (int i=0;i<min;i++){            
	
			  if (A[i] != B[i]){                     //any two char not equal that is mean commanlength=i 
				  commonlength=i; 
					 break;
			  }
			  if (i+1==min){                         //to check if next the end of string or not
           commonlength=i+1;
           }
		  }
	
		  common=A.substr(0,commonlength);                //divide string to get common string
	
		
		  return common;
}
/*function to get length of common string in each rule to use it in RHS
        function as same as getcommonstring function but it return length*/
int getCommonStringIndex (string A,string B) {
	string common="";
	 int commonlength=0;
     int min=0;
	 if (A.length() > B.length()){
            min=B.length();
            }
            else if (B.length() > A.length())
            {
              min=A.length();  
            }
            else{
                min=A.length();
            }
		  for (int i=0;i<min;i++){
          
			  if (A[i] != B[i]){ 
				  commonlength=i;
					 break;
			  }
			  if (i+1==min){
			  commonlength=i+1;
           }
		  }
		  common=A.substr(0,commonlength);
	
		  return commonlength;
}
//function to read all rules from file "before.txt" until reach to $
string get_strings_from_file () {
	ifstream f;
	f.open("before.txt"); 
	string linefile="";

	getline(f,linefile,'$');                          //to get all lines in the file
	return linefile;
}
//this function takes string that returned from get_strings_from_file () and get each line in vector 
vector<string> get_each_line (string line) {
	vector<string> allline;
	 int begin = 0;
    int end = 0;

    for (int i = 0; i < line.length(); ++i) {     
        if (line[i] == '\n') {
           end = i;
            allline.push_back(line.substr(begin, end - begin));       //to devide string and the delimiter is end line '\n'
            begin = (i + 1);
        }
    }
	return allline;
}
//function takes all line and return string after equal
string get_string_After_equal (string allline) {
	string afterequal="";
	int i=0;
	string beforeequal="";
	while (allline[i] != '=') {
		beforeequal+=allline[i];	
		i++;
	}
	if (allline[i]=='=') {
		beforeequal+=allline[i];
		i++;
	}
	while (i<(allline.length())) {
		afterequal+=allline[i];
		i++;
	}
	return afterequal;
}
//function takes all line and return string before equal to put them again in new file
string get_string_Before_equal (string allline) {
	int i=0;
	string beforeequal="";
	while (allline[i] != '=') {
		beforeequal+=allline[i];	
		i++;
	}
	if (allline[i]=='=') {
		beforeequal+=allline[i];
		i++;
	}
	return beforeequal;
}
//function only to print any vector
void printVector(vector<string> vect){

	 for (int i=0;i<vect.size();i++) {
		 cout<<"print Vector--> "<<vect[i]<<endl;
	 }

}
//function to separate line after equal with delimiter | 
vector<string> get_between_or (string afterequal) {
	 vector<string> betweenor;
	int i=0;
	int flag=0;
	string q="";
	while (flag ==0) {
	if (afterequal[i] == '|') {
		i++;
		if (i==afterequal.length()) {                       //if reach to the end of line
			flag=1;
			break;
		}
	}
	while (afterequal[i] != '|' && afterequal[i] != '\n') {
		q+=afterequal[i];
		i++;
		if (i==afterequal.length()) {
			flag=1;
			break;
		}
	}
	betweenor.push_back(q);
	q="";

}
	return betweenor;
}
//function to get common strings and compare the common to another elements in vector
vector<string> get_similarity (vector<string> vect) {
	vector<string> same;
	string common="";
	for (int x=0;x<(vect.size());x++) {
	for (int y=x+1;y<(vect.size());y++) {
		if (x<(vect.size())) {
			common=getcommonstring(vect[x],vect[y]);
			 int sameflag=0;
			 
			 for (int z=0;z<same.size();z++){
				 if (common.compare(same.at(z))==0) {
					  sameflag++;
				}
			 }
			 if (sameflag ==0 && common.length()!=0) {
				  same.push_back(common);
			  }
			 
	}
}
	}
	return same;
}
//function to get unique strings that are not repeated again in vector
vector<string> get_unique (vector<string> vect) {
	vector<string> unique;
	for (int j=0;j<vect.size();j++) {
	 int differnet=0;
	
	 for (int k=0;k<vect.size();k++) {
		  if (k !=j){                                 // to not compare the string to its self again and again in for loop
			  if ((vect[k]).at(0) == (vect[j]).at(0)){
				 
			  differnet=1;                    
				  break;
				  
			 }
	 }

}
	  if (differnet==0){
		  unique.push_back(vect[j]);
        }
}

	return unique;
}
//function to check if the common string has Remainder right-hand side or not
vector<string> rightHandSide(string LHS, vector<string> comp) {
        vector<string> RHSArray;
		string RHS;
        for (int i = 0; i < comp.size(); i++) {
            int index = getCommonStringIndex(LHS, comp[i]);
            if (index != 0) {
				RHS= comp[i].substr(index);
				if (RHS.empty()) {
					RHSArray.push_back("E");                    // if the string does not have the Remainder right-hand side, place E
                } else {
					RHSArray.push_back(RHS);
                }
            }
        }
		for (int i=0;i<RHSArray.size();i++) {
			cout<<"------------------------------------RHS------>"<<RHSArray[i] <<endl;
		}
        return RHSArray;
    }
//function to repeated if there is exist common inside common is same as void main but to repeated in more than one round
string allInFunction(vector<string> comp, int v) {
	string finalOutput="" ;
	int newV;
	vector<string> betweenor;
	vector<string> same;
	vector<string> unique;
	 vector<string> temp;
	 vector<string> finalunique;
	
	cout<<"--------------------- SAME --------------------"<<endl;
	same=get_similarity(comp);
		

	cout<<"--------------------- Unique --------------------"<<endl;
	unique=get_unique(comp);
	
	 
	cout<<"--------------------- Final Unique --------------------"<<endl;
	
	 for (int i = 0 ; i <=comp.size(); i++) {
            temp = get_unique(same);
			if (temp.empty()==false) {
				for (int i=0;i<temp.size();i++) {
					finalunique.push_back(temp.at(i));
				}
            }
			temp.clear();
			same=get_similarity(same);

		}
	 if (unique.empty()== false) {
            for (int i = 0; i < unique.size(); i++) {

				finalOutput = finalOutput.append(unique[i]);
                if (i < unique.size() - 1) {
                    finalOutput = finalOutput.append(" | ");
                }
            }
        }
	 
	for (int i = 0; i < finalunique.size(); i++) {

		int exp = n.getNumber() + 1;
			n.setNumber(exp);
            newV = v + 1;
            finalOutput = finalOutput.append(" | ");
            finalOutput = finalOutput.append(finalunique[i]);
            finalOutput = finalOutput.append("<");
			finalOutput = finalOutput.append(conv(newV));
            finalOutput = finalOutput.append(">");
			
        }         

	    for (int end = 0; end <finalunique.size(); end++) {
			
		vector<string> newComp=rightHandSide(finalunique[end],comp);

		int theExperss = v + 1;
            finalOutput = finalOutput.append("\n");
			finalOutput = finalOutput.append("<");
			finalOutput = finalOutput.append(conv(theExperss));
            finalOutput = finalOutput.append(">");
            finalOutput = finalOutput.append("::=");

			

		for (int f = 0; f < finalunique.size(); f++) { 
			vector<string> Rsame;
			vector<string> Runique;
			vector<string> Rtemp;
			vector<string> Rfinalunique;

			Rsame=get_similarity(newComp);
			Runique=get_unique(newComp);

			 for (int i = 0; i <= newComp.size(); i++) {
				  Rtemp = get_unique(Rsame);

			if (Rtemp.empty()==false) {
				for (int i=0;i<Rtemp.size();i++) {
					Rfinalunique.push_back(Rtemp.at(i));
				}
            }
			Rtemp.clear();
			Rsame=get_similarity(Rsame);
			 }
			 if (Rsame.empty()) {

                    break;
                }
		}
		if (!newComp.empty()) {

               string outt = allInFunction(newComp, v + 1);
			   finalOutput = finalOutput.append(outt);
            }
		
		}
		return finalOutput;
		
}
void main () {

	vector<string> betweenor;          //vector has strings between |
	vector<string> same;               //vector has same strings
	vector<string> unique;             //vector has unique strings
	string finalOutput="";
	bool firstUniuqueEmpty = false;         //if unique in first round is empty
	string s=get_strings_from_file ();
	vector<string> lines=get_each_line(s);          //vector has each line
	int sizee=0;
	for (int y=0;y<lines.size();y++) {
		cout<<"------------------Line Number---> "<< y <<" "<<endl;
		sizee=n.getNumber();                                          //to get last value of number in begin of each line
	string beforeequal=get_string_Before_equal (lines[y]);
	 finalOutput.append(beforeequal);
	string af=get_string_After_equal (lines[y]);
	betweenor=get_between_or(af);
	printVector(betweenor);
	
	cout<<"--------------------- SAME --------------------"<<endl;
	same=get_similarity(betweenor);                 //get same elements from main vector(betweenor)
	printVector(same);

	cout<<"--------------------- Unique --------------------"<<endl;
	unique=get_unique(betweenor);                  //get unique elements from main vector(betweenor)
	printVector(unique);
	if (unique.empty()) {                  //to check if unique vector is empty or not in first round
            firstUniuqueEmpty = true;
        }
	cout<<"--------------------- Final Unique --------------------"<<endl;
	 vector<string> temp;
	 vector<string> finalunique;
	 for (int i = 0 ; i <=betweenor.size(); i++) {
            temp = get_unique(same);                       //get unique elements from same vector 
			if (temp.empty()==false) { 
				for (int i=0;i<temp.size();i++) {
					finalunique.push_back(temp.at(i));
				}
            }
			temp.clear();                 //to avoid duplicate of elements in temp
			same=get_similarity(same);              //get same elements from same vector and put them again in same vector

		}
	 if (same.empty()==false) {                    //check to push elements in finalunique or not
	 for (int i=0;i<same.size();i++) {
					finalunique.push_back(same.at(i));
				}
	 }
	 printVector(finalunique);


	 if (unique.empty() == false) {                        //to append unique elements that is out from rule to finalOutput
            for (int i = 0; i <unique.size(); i++) {

				finalOutput = finalOutput.append(unique[i]);
                if (i < unique.size() -1 ) {
                    finalOutput = finalOutput.append(" | ");
                }
            }
        }

        for (int i = 0; i < finalunique.size(); i++) {

			int exp = n.getNumber() + 1;                    //get last value of number and plus one to avoid a repeat
			n.setNumber(exp);
            if (!firstUniuqueEmpty || i > unique.size()) {
                finalOutput = finalOutput.append(" | ");
            }
            finalOutput = finalOutput.append(finalunique[i]);
            finalOutput = finalOutput.append("<");
			finalOutput = finalOutput.append(conv(exp));
            finalOutput = finalOutput.append(">");
			
        }
	
	//cout<<"----------------NEW COMP-----------------"<<endl;
	    for (int end = 0; end <finalunique.size(); end++) {                  //vector that has same elements and begin to get Remainder RHS from sting
			
		vector<string> newComp=rightHandSide(finalunique[end],betweenor);
		
			
		  int theExperss = end + 1 + sizee;
            finalOutput = finalOutput.append("\n");
			finalOutput = finalOutput.append("<");
			finalOutput = finalOutput.append(conv(theExperss));
            finalOutput = finalOutput.append(">");
            finalOutput = finalOutput.append("::=");
			
		for (int f = 0; f <finalunique.size(); f++) {      //repeat the same steps for all RHS
			printVector(newComp);
			vector<string> Rsame;
			vector<string> Runique;
			vector<string> Rtemp;
			vector<string> Rfinalunique;
			Rsame=get_similarity(newComp);
			Runique=get_unique(newComp);
			 for (int i = 0; i <=newComp.size(); i++) {
		
				  Rtemp = get_unique(Rsame);

			if (Rtemp.empty()==false) {
				for (int i=0;i<Rtemp.size();i++) {
					Rfinalunique.push_back(Rtemp.at(i));
				}
            }
			Rtemp.clear();
			Rsame=get_similarity(Rsame);
			 }
			 if (Rsame.empty()) {

                    break;
                }
			
		}
		if (!newComp.empty()) {                                        //check if new comp is empty or not that contains RHS of common strings
			                                                           //and append them to finalOutput string in the same sequence
			string outt = allInFunction(newComp,n.getNumber());
				
				finalOutput = finalOutput.append(outt);
            }
		}
		
		
	 finalOutput.append("\n");
	}
	cout<<"------------------final output--------------------------"<<endl;
	cout<<finalOutput<<endl;


	  ofstream h;
	 h.open ("After.txt");   
	 h << finalOutput;             //to write finalOutput to file text named "After.txt"

	system("pause");

}