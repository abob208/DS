/*
資訊二乙 10627238 蔡朋穎
資訊二乙 10627234 陳守倫 
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
		void WriteOut(string filename) ; // 將vector中的資料寫入新檔中 
		void ReWriteOut(string filename) ; // 將vector中的資料覆寫入檔中 
		vector<Information> Get() ; // return a vector of Information 
		Information Get(int i) ;
		InformationBuffer Screen( int numOfStudent, int numOfGraduate) ; // 篩選符合資訊的資料 
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
		string originalString ; // 寫入時使用 
		
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
		bool writeAble ; // 用於mission3，合併兩個檔案時，排除寫入過的資料 
	
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
	cout << "歡迎使用本程式\n\n" ;
	cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n\n" ;
	
	while ( cin >> instruction ) {
		
	  if ( instruction == '0' ) {
	  		cout << "謝謝您使用!" ;
			return 0 ;
		} 
	  else if ( instruction == '1' ) Mission::mission1() ;
	  
	  else if ( instruction == '2' ) Mission::mission2() ;
	  
	  else if ( instruction == '3' ) Mission::mission3() ;
	
	  else cout << " 非法輸入，請重新輸入指令 :  " ;
	  
	  cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n" ;
		
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
		// 辨識temp是否為數字字串，如果是，就做處理 
		// else 就是輸入完整檔案的情況 
		file.open(temp.c_str(), ios_base::in) ;
		if ( !file.is_open() ) cout << "oops, there is no such file !" ;
	
	}
	
	string garbage ;
	getline(file, garbage ) ;
	getline(file, garbage ) ;
	getline(file, garbage ) ; // 讀掉前三行 
	
	InformationBuffer<Information> text = InformationBuffer<Information>( file ) ;
	file.close() ;
	cout << "共有 : " << text.Get().size()  << "筆資料。\n\n" ;
	
	
	// 處理檔案名稱 
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
		// 辨識temp是否為數字字串，如果是，就做處理 
		// else 就是輸入完整檔案的情況 
		file.open(temp.c_str(), ios_base::in) ;
		if ( !file.is_open() ) cout << "oops, there is no such file !" ;
		
	}
	
	InformationBuffer<Information> text = InformationBuffer<Information>( file ) ; // 將檔案中的資料進行解析 
	file.close() ;
	
	
	cout << "請輸入要篩選的資料，學生人數要大於等於多少人 : " ;
	int numOfStudent ;
	cin >> numOfStudent ;
	cout << "請輸入要篩選的資料，上學年畢業人數要大於等於多少人 : " ;
	int numOfGraduate ;
	cin >> numOfGraduate ;
	
	
	text = text.Screen( numOfStudent, numOfGraduate ) ;
	
	cout << "共有 : " << text.Get().size()  << "筆資料。\n\n" ;
	
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
		// 辨識temp是否為數字字串，如果是，就做處理 
		// else 就是輸入完整檔案的情況 
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
	
	// 處理合併後檔案名稱 
	
	if ( !ComfirmType::isInt(temp1) ) {
		temp1 = StringProccess:: GetFileNumber( temp1 ) ;
	}
	if ( !ComfirmType::isInt(temp2) ) {
		temp2 = StringProccess:: GetFileNumber( temp2 ) ;
	}
	
	string newfilename ;
	newfilename = "output" + temp1 + "_" + temp2 + ".txt" ;
	
	cout << "共有 : " << newText.Get().size()  << "筆資料。\n\n" ;
	
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
	
    while( i < text1.Get().size() ) { // 根據text1的資料，依序將 "同學校也同系所" 與 "只有同學校" 的資料並再一起 
    		text3.Add( text1.Get(i) ) ;
    		j = 0 ;
    		
    		while ( j < text2.Get().size() ) {  // 學校與系所都相同 的先處理 
    			
    			if ( text2.Get(j).Getschoolnumber().compare( text1.Get(i).Getschoolnumber() ) == 0 && text2.Get(j).GetDepartmentnumber().compare( text1.Get(i).GetDepartmentnumber() ) == 0 ) { 
    				if ( text2.Get(j).WriteAble() ) {
    					text3.Add( text2.Get(j) ) ;
    					writeAble.at(j) = false ;
    					
					}
				}
				
				j++ ;
    			
			}
			
			// 處理只有學校相同的資料	
    		if ( i+1 < text1.Get().size() ) { // 界線檢查 
    			
    			if ( text1.Get(i).Getschoolnumber().compare( text1.Get(i+1).Getschoolnumber() ) != 0 ) { // 檢查使否已經無同學校的資料再text1中，如果沒有，就把text2中所有同學笑的資料先push_back 
    				
    				j = 0 ;
    				while ( j < text2.Get().size() ) {
    			
    					if ( text2.Get(j).Getschoolnumber().compare( text1.Get(i).Getschoolnumber() ) == 0 ) { // 學校與系所都相同 
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
	
	j = 0 ; // 初始化 
	while ( j < text2.Get().size() ) { // 將text2中尚未處理的資料處理完  
	
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
	string garbage ; // 非資訊之字串 
	
	
	schoolnumber = StringProccess::getNextToken( temp ) ;
	schoolname = StringProccess::getNextToken( temp ) ;
	Departmentnumber = StringProccess::getNextToken( temp ) ;
	Departmentname = StringProccess::getNextToken( temp ) ;
	D_or_P_Department = StringProccess::getNextToken( temp ) ; // 日間部 : D 進修部 : P 
	garbage = StringProccess::getNextToken( temp ) ; // 日/進 
	level = StringProccess::getNextToken( temp ) ;
	garbage = StringProccess::getNextToken( temp ) ; // "學士" 字串 
	numOfStudent = StringProccess::getNextToken( temp ) ;
	numOfTeacher = StringProccess::getNextToken( temp ) ;
	numOfGraduateStudent = StringProccess::getNextToken( temp ) ;
	garbage = StringProccess::getNextToken( temp ) ; // 城市編號 
	city = StringProccess::getNextToken( temp ) ; // 城市名稱 
	system =  StringProccess::getNextToken( temp ) ;  // 體系編號 
	garbage = StringProccess::getNextToken( temp ) ; // 體系字串 
	writeAble = true ; // 是否可寫入 
	
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


bool StringProccess::hasToken( string &str ) { // 將空白切掉，直到非空白字元，有找到回傳true 
	

	while ( str.at(0) == ' ' ||  str.at(0) == '\t' ) { 
		
		str = str.substr(1,string::npos) ;
		
	}
	
	if( str.length() == 0 ) return false ;
	
	return true ; 
	
}

string StringProccess::getNextToken( string &str) { //  紀錄token之後，將其從字串中切掉 
	
	string temp ;
	
	if ( StringProccess::hasToken( str ) ) {
	
	
		while ( str.at(0) != ' ' &&  str.at(0) != '\t' && str.length() > 1 ) {
		
			temp = temp + str.at(0) ;
			str = str.substr(1,string::npos) ;
		}
		
		if ( str.at(0) != ' ' &&  str.at(0) != '\t' ) temp = temp + str.at(0) ; // 最後一個元素 
	
	}
	

	return temp ;
	
}

string StringProccess:: GetFileNumber( string str ) {
	
	int i = 0 ;
	int start = 0, end = 0 ;
	
	
		
	while ( !isdigit(str.at(i)) ) {
		i++ ; // 得到第一個數字字元的位置 
	}
	
	start = i ;
	end = i ; 
	end -- ;  // 避免index多一 
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

