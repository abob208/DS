/*
��T�G�A 10627238 ���B�o
��T�G�A 10627234 ���u�� 
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include <cctype>
#include <cstdlib>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std ;

template <class Information> class InformationBuffer {
	
	public :
	    InformationBuffer() ; // constructor - default
		InformationBuffer( fstream &file ) ; // constructor - with a file stream u can directly get a processed data of  all school information
		
		void Add(Information obj) ; // add new data(Information) into vector-info
		void WriteOut(string filename) ; // �Nvector������Ƽg�J�s�ɤ� 
		void ReWriteOut(string filename) ; // �Nvector��������мg�J�ɤ� 
		vector<Information> Get() ; // return a vector of Information 
		Information Get(int i) ;
		InformationBuffer Screen( int numOfStudent, int numOfGraduate) ; // �z��ŦX��T����� 
		InformationBuffer combine( InformationBuffer<Information> &text1, InformationBuffer<Information> &text2 ) ;
		
		void Print() ; // print all information with a '\t' as interval between per data member in Information obj
		
	private :
		vector<Information> info ;	 // store all school's information( Information obj ) from input file
	
} ;

class Information {
	
	public :
		Information() ; // constructor - default
		Information( string info ) ; // proccess a line to get each needed-information
		
		
		void SetInfo( string info ) ;
		void SetWriteAble() ;
		
		string GetALine() const ;
		string Getschoolnumber() const ;
		string GetDepartmentnumber() const ;
		string GetnumOfStudent() const ;
		string GetnumOfTeacher() const ;
		string GetnumOfGraduateStudent() const ;
		bool WriteAble() const ;
		
	private :
		string originalString ; // �g�J�ɨϥ� 
		
		string schoolnumber ;
		string schoolname ;
		string Departmentnumber ;
		string Departmentname ; 	
		string D_or_P_Department ;
		string level ;
		string numOfStudent ;
		string numOfTeacher ;
		string numOfGraduateStudent ;
		string city ; // number
		string system ;
		bool writeAble ; // �Ω�mission3�A�X�֨���ɮ׮ɡA�ư��g�J�L����� 
	
};

class ComfirmType {
	public :
		static bool isInt( string str ) ;
};

class StringProccess{
	public :
		static bool hasToken( string &str ) ;
		static string getNextToken( string &str ) ;
		static string GetFileNumber( string str ) ;
		static string ComfirmAllDigit( string str ) ;
};

class Mission {
	
	public :
		static void mission1() ;
		static void mission2() ;
		static void mission3() ;
	
};






int main(int argc, char** argv) {
	
	
	char instruction = 0 ;
	cout << "�w��ϥΥ��{��\n\n" ;
	cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n\n" ;
	
	while ( cin >> instruction ) {
		
	  if ( instruction == '0' ) {
	  		cout << "���±z�ϥ�!" ;
			return 0 ;
		} 
	  else if ( instruction == '1' ) Mission::mission1() ;
	  
	  else if ( instruction == '2' ) Mission::mission2() ;
	  
	  else if ( instruction == '3' ) Mission::mission3() ;
	
	  else cout << " �D�k��J�A�Э��s��J���O :  " ;
	  
	  cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n" ;
		
	}
	
	
	return 0;
}



void Mission::mission1(){
	
	string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;
	while ( !file.is_open() ) {
		cout << "plz enter a complete file name or file number to create a copy of it : " ;
		cin >>temp ;
		
		if ( ComfirmType::isInt(temp) ) temp = "input" + temp + ".txt" ;
		// ����temp�O�_���Ʀr�r��A�p�G�O�A�N���B�z 
		// else �N�O��J�����ɮת����p 
		file.open(temp.c_str(), ios_base::in) ;
		if ( !file.is_open() ) cout << "oops, there is no such file !" ;
	
	}
	
	string garbage ;
	getline(file, garbage ) ;
	getline(file, garbage ) ;
	getline(file, garbage ) ; // Ū���e�T�� 
	
	InformationBuffer<Information> text = InformationBuffer<Information>( file ) ;
	file.close() ;
	cout << "�@�� : " << text.Get().size()  << "����ơC\n\n" ;
	
	
	// �B�z�ɮצW�� 
	if ( ComfirmType::isInt(temp) ) {
		temp = "copy" + temp + ".txt" ;
	}
	else {
		temp = StringProccess:: GetFileNumber( temp ) ;
		temp = "copy" + temp + ".txt" ;
	}
	
	text.WriteOut( temp ) ;
	
	
	
	
}

void Mission :: mission2(){
	
	string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;
	while ( !file.is_open() ) {
		cout << "plz enter a complete file name or file number to create a copy of it : " ;
		cin >>temp ;
		
		if ( ComfirmType::isInt(temp) ) temp = "copy" + temp + ".txt" ;
		// ����temp�O�_���Ʀr�r��A�p�G�O�A�N���B�z 
		// else �N�O��J�����ɮת����p 
		file.open(temp.c_str(), ios_base::in) ;
		if ( !file.is_open() ) cout << "oops, there is no such file !" ;
		
	}
	
	InformationBuffer<Information> text = InformationBuffer<Information>( file ) ; // �N�ɮפ�����ƶi��ѪR 
	file.close() ;
	
	
	cout << "�п�J�n�z�諸��ơA�ǥͤH�ƭn�j�󵥩�h�֤H : " ;
	int numOfStudent ;
	cin >> numOfStudent ;
	cout << "�п�J�n�z�諸��ơA�W�Ǧ~���~�H�ƭn�j�󵥩�h�֤H : " ;
	int numOfGraduate ;
	cin >> numOfGraduate ;
	
	
	text = text.Screen( numOfStudent, numOfGraduate ) ;
	
	cout << "�@�� : " << text.Get().size()  << "����ơC\n\n" ;
	
	text.ReWriteOut( temp.c_str() ) ;
	
	
}

void Mission :: mission3(){
	
	
	string temp1,temp2 ;
	fstream file1, file2 ;
	file1.open(temp1.c_str(), ios_base::in) ;
	file2.open(temp2.c_str(), ios_base::in) ;
	
	while ( !file1.is_open() || !file2.is_open() ) {
		
		cout << "\nplz enter complete file name or file number of two files to create a combination of them according to file1 : << '\n' " ;
		if ( !file1.is_open() ) {
			cout << "\nnow plz enter file1's complete file name or file number : " ;
		    cin >>temp1 ;
		}
		if ( !file2.is_open() ) {
			cout << "\nnow plz enter file2's complete file name or file number : " ;
			cin >>temp2 ;
		}
		
		if ( ComfirmType::isInt(temp1) ) temp1 = "copy" + temp1 + ".txt" ;
		if ( ComfirmType::isInt(temp2) ) temp2 = "copy" + temp2 + ".txt" ;
		// ����temp�O�_���Ʀr�r��A�p�G�O�A�N���B�z 
		// else �N�O��J�����ɮת����p 
		if ( !file1.is_open() ) file1.open(temp1.c_str(), ios_base::in) ;
		if ( !file2.is_open() ) file2.open(temp2.c_str(), ios_base::in) ;
		
		if ( !file1.is_open() ) cout << "\noops, there is no such file like file1 !\n" ;
		if ( !file2.is_open() ) cout << "\noops, there is no such file like file2 !\n" ;
		
	}
	
	InformationBuffer<Information> text1 = InformationBuffer<Information>( file1 ) ; 
	InformationBuffer<Information> text2 = InformationBuffer<Information>( file2 ) ; 
	file1.close() ;
	file2.close() ;
	
	InformationBuffer<Information> newText ; 
	newText = newText.combine( text1,text2 ) ;
	
	// �B�z�X�֫��ɮצW�� 
	
	if ( !ComfirmType::isInt(temp1) ) {
		temp1 = StringProccess:: GetFileNumber( temp1 ) ;
	}
	if ( !ComfirmType::isInt(temp2) ) {
		temp2 = StringProccess:: GetFileNumber( temp2 ) ;
	}
	
	string newfilename ;
	newfilename = "output" + temp1 + "_" + temp2 + ".txt" ;
	
	cout << "�@�� : " << newText.Get().size()  << "����ơC\n\n" ;
	
	newText.WriteOut(newfilename) ;
	
}


bool ComfirmType::isInt(string str) {
	
	int i = 0 ;
	
	while (i < str.size()) {
		if( isdigit(str.at(i)) ) i++ ;
		else return false ;
	}
	
	return true ;
}

template <class Information> InformationBuffer<Information>::InformationBuffer() {

}

template <class Information> InformationBuffer<Information>::InformationBuffer( fstream &file ) {

	string inputALine ;

	while( getline(file, inputALine) ) {
	
		Information  temp = typename Information::Information(inputALine) ;
		
		info.push_back( temp ) ;
	}
}



template <class Information> void InformationBuffer<Information>::WriteOut(string filename) {
	
	fstream file ;
	
	
	file.open( filename.c_str(), ios_base::out ) ;
	
	int i = 0 ;
	while( i < info.size() ) {
		
		file << info.at(i).GetALine() << '\n';
		i++ ;
		
	}
	
	file.close() ;
	
}

template <class Information> void InformationBuffer<Information>::ReWriteOut(string filename) {
	
	
	fstream file ;
	
	file.open( filename.c_str(), ios_base::trunc | ios_base::out ) ;
	
	int i = 0 ;
	while( i < info.size() ) {
		
		file << info.at(i).GetALine() << '\n';
		i++ ;
		
	}
	
	file.close() ;
	
}


template <class Information> void InformationBuffer<Information>::Print() {
	
	int i = 0 ;
	while( i < info.size() ) {
		
		cout << info.at(i).GetALine() << '\n';
		i++ ;
		
	}
}

template <class Information> void InformationBuffer<Information>::Add( Information obj ) {
	
	info.push_back( obj ) ;
	
}

template <class Information> vector<Information> InformationBuffer<Information>::Get() {
	return info ;
}

template <class Information> Information InformationBuffer<Information>:: Get(int i) {
	
	return info.at(i) ;
	
}


template <class Information> InformationBuffer<Information> InformationBuffer<Information>::Screen( int numOfStudent, int numOfGraduate) {
	
	InformationBuffer<Information> text2 = InformationBuffer<Information>() ;
	int i = 0 ;
	while( i < info.size() ) {
		
		int temp ;
		string allDigit ;
		allDigit = StringProccess::ComfirmAllDigit(info.at(i).GetnumOfStudent()) ;
		temp = atoi( allDigit.c_str() ) ;
		
		if ( temp >= numOfStudent ) {
			allDigit = StringProccess::ComfirmAllDigit(info.at(i).GetnumOfGraduateStudent()) ;
			temp = atoi( allDigit.c_str() ) ;
			if (temp >= numOfGraduate) {
				text2.Add( info.at(i) ) ;
			}
		}
		
		i++ ;
		
	}
	
	
	return text2 ;
	
}

template <class Information> InformationBuffer<Information> InformationBuffer<Information>::combine( InformationBuffer<Information> &text1, InformationBuffer<Information> &text2 ) {
	
	int i = 0, j = 0 ; // index
	
	
	vector<bool> writeAble( text2.Get().size(), true ) ;
	
	InformationBuffer<Information> text3 = InformationBuffer<Information>() ;
	
    while( i < text1.Get().size() ) { // �ھ�text1����ơA�̧ǱN "�P�Ǯդ]�P�t��" �P "�u���P�Ǯ�" ����ƨæA�@�_ 
    		text3.Add( text1.Get(i) ) ;
    		j = 0 ;
    		
    		while ( j < text2.Get().size() ) {  // �ǮջP�t�ҳ��ۦP �����B�z 
    			
    			if ( text2.Get(j).Getschoolnumber().compare( text1.Get(i).Getschoolnumber() ) == 0 && text2.Get(j).GetDepartmentnumber().compare( text1.Get(i).GetDepartmentnumber() ) == 0 ) { 
    				if ( text2.Get(j).WriteAble() ) {
    					text3.Add( text2.Get(j) ) ;
    					writeAble.at(j) = false ;
    					
					}
				}
				
				j++ ;
    			
			}
			
			// �B�z�u���ǮլۦP�����	
    		if ( i+1 < text1.Get().size() ) { // �ɽu�ˬd 
    			
    			if ( text1.Get(i).Getschoolnumber().compare( text1.Get(i+1).Getschoolnumber() ) != 0 ) { // �ˬd�ϧ_�w�g�L�P�Ǯժ���ƦAtext1���A�p�G�S���A�N��text2���Ҧ��P�ǯ�����ƥ�push_back 
    				
    				j = 0 ;
    				while ( j < text2.Get().size() ) {
    			
    					if ( text2.Get(j).Getschoolnumber().compare( text1.Get(i).Getschoolnumber() ) == 0 ) { // �ǮջP�t�ҳ��ۦP 
    						if ( writeAble.at(j) == true ) {
    							text3.Add( text2.Get(j) ) ;
    							
    							writeAble.at(j) = false ;
							}		
						}
				
						j++ ;
					}
    				
				}
    			
			}
    		i++ ;
	} 
	
	j = 0 ; // ��l�� 
	while ( j < text2.Get().size() ) { // �Ntext2���|���B�z����ƳB�z��  
	
		if( writeAble.at(j) == true ) text3.Add( text2.Get(j) ) ;	
		
		j ++ ;
	}
	
	
	
	return text3 ;
	
}

Information::Information(){
	


} 

Information::Information( string str ){
	
	SetInfo( str ) ;

} 


void Information::SetInfo( string str ) {
	
	originalString = str ;
	string temp = str ;
	string garbage ; // �D��T���r�� 
	
	
	schoolnumber = StringProccess::getNextToken( temp ) ;
	schoolname = StringProccess::getNextToken( temp ) ;
	Departmentnumber = StringProccess::getNextToken( temp ) ;
	Departmentname = StringProccess::getNextToken( temp ) ;
	D_or_P_Department = StringProccess::getNextToken( temp ) ; // �鶡�� : D �i�׳� : P 
	garbage = StringProccess::getNextToken( temp ) ; // ��/�i 
	level = StringProccess::getNextToken( temp ) ;
	garbage = StringProccess::getNextToken( temp ) ; // "�Ǥh" �r�� 
	numOfStudent = StringProccess::getNextToken( temp ) ;
	numOfTeacher = StringProccess::getNextToken( temp ) ;
	numOfGraduateStudent = StringProccess::getNextToken( temp ) ;
	garbage = StringProccess::getNextToken( temp ) ; // �����s�� 
	city = StringProccess::getNextToken( temp ) ; // �����W�� 
	system =  StringProccess::getNextToken( temp ) ;  // ��t�s�� 
	garbage = StringProccess::getNextToken( temp ) ; // ��t�r�� 
	writeAble = true ; // �O�_�i�g�J 
	
}

string Information::GetALine() const {
	
	return originalString ;
	
}

string Information::GetnumOfGraduateStudent() const {

	return numOfGraduateStudent ;

}

string Information::GetnumOfStudent() const {

    return numOfStudent ;

}

string Information::Getschoolnumber() const {

    return schoolnumber ;

}

string Information::GetDepartmentnumber() const {

    return Departmentnumber ;

}

void Information::SetWriteAble() {
	
	writeAble = false ;
	
	
}



bool Information::WriteAble() const {
	
	return writeAble ;
	
}


bool StringProccess::hasToken( string &str ) { // �N�ťդ����A����D�ťզr���A�����^��true 
	

	while ( str.at(0) == ' ' ||  str.at(0) == '\t' ) { 
		
		str = str.substr(1,string::npos) ;
		
	}
	
	if( str.length() == 0 ) return false ;
	
	return true ; 
	
}

string StringProccess::getNextToken( string &str) { //  ����token����A�N��q�r�ꤤ���� 
	
	string temp ;
	
	if ( StringProccess::hasToken( str ) ) {
	
	
		while ( str.at(0) != ' ' &&  str.at(0) != '\t' && str.length() > 1 ) {
		
			temp = temp + str.at(0) ;
			str = str.substr(1,string::npos) ;
		}
		
		if ( str.at(0) != ' ' &&  str.at(0) != '\t' ) temp = temp + str.at(0) ; // �̫�@�Ӥ��� 
	
	}
	

	return temp ;
	
}

string StringProccess:: GetFileNumber( string str ) {
	
	int i = 0 ;
	int start = 0, end = 0 ;
	
	
		
	while ( !isdigit(str.at(i)) ) {
		i++ ; // �o��Ĥ@�ӼƦr�r������m 
	}
	
	start = i ;
	end = i ; 
	end -- ;  // �קKindex�h�@ 
	while ( i < str.size()  ) {
		if ( isdigit(str.at(i)) ) end++ ; 
		i++ ;
	}
		
	return str.substr( start, end-start+1 )	;
	
}

string StringProccess::ComfirmAllDigit( string str ) {
	
	int i = 0 ;
	string allDigit ;
	while( i < str.size() ) {
		
		if( isdigit(str.at(i))) {
			
			allDigit = allDigit + str.at(i) ;
			
		}
		
		i++ ;
		
	}
	
	return allDigit ;
	
}

