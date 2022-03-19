
/*
��19��
10627238 ���B�o
10627234 ���u��
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;


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


class InformationBuffer {

	public :
	    InformationBuffer() ; // constructor - default
		InformationBuffer( fstream &file ) ; // constructor - with a file stream u can directly get a processed data of  all school information
		InformationBuffer( vector<Information> temp ) ;

		void Add(Information obj) ; // add new data(Information) into vector-info
		void WriteOut(string filename) ; // �Nvector������Ƽg�J�s�ɤ�
		void ReWriteOut(string filename) ; // �Nvector��������мg�J�ɤ�
		clockid_t getSoet_time() ;
		string getSort_Way() ;
		vector<Information> Get() ; // return a vector of Information
		Information Get(int i) ;
        // RADIX sort
        void rSort();

		void selectSorting() ;
		void bubbleSortion() ;
		void mergeSorting() ;
		void quickSorting() ;
		void improved_quickSorting() ;


		void Print() ; // print all information with a '\t' as interval between per data member in Information obj

		// �W���D��
		void Write_Sort_time( string filename ) ;

	private :
		vector<Information> info ;	 // store all school's information( Information obj ) from input file
		clockid_t unit_Time ;
		string SortWay ;

		// for merge sorting
		void Merge( int first, int last, int mid ) ;
		void mergesort( int first, int last ) ;
		// FOR Quick sort
		void quickSort( int first, int last ) ;
		void Partition( int first, int last, int &pivotIndex ) ;
		// FOR improved Quick sort
		void improved_quickSort( int first, int last ) ;
		void Improved_Partition(int first, int last, int &pivotIndex) ;
		Information FindPivot( int first, int last ) ;

} ;

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
		static int StrToInt( string str ) ;
};

class Mission {

	public :
		static void mission1() ;
		static void mission2() ;
		static void mission3() ;

        static void mission4() ;
        static void mission5() ;
        static void mission6() ;

};


int main()
{
    char instruction = 0 ;
	cout << "�w��ϥΥ��{��\n\n" ;
	cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n4 : �������6(�D�ԥ���)\n\n" ;

	while ( cin >> instruction ) {

	  if ( instruction == '0' ) {
	  		cout << "���±z�ϥ�!" ;
			return 0 ;
		}
	  else if ( instruction == '1' ) Mission::mission1() ;

	  else if ( instruction == '2' ) Mission::mission2() ;

	  else if ( instruction == '3' ) Mission::mission3() ;

	  else if ( instruction == '4' ) Mission::mission6() ;

	  else cout << " �D�k��J�A�Э��s��J���O :  " ;

	  cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n4 : �������6(�D�ԥ���)\n\n" ;

	}

    return 0;
}


void Mission::mission1(){

    string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;
	while ( !file.is_open() ) {
		cout << "plz enter a complete file name or file number to perform bubbleSort & SelectSort of it : " ;
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

	InformationBuffer text = InformationBuffer( file ) ;
	file.close() ;
	InformationBuffer text2 = InformationBuffer( text.Get() ) ;
	text.bubbleSortion() ;
	text2.selectSorting() ;
	cout << "�@�� : " << text.Get().size()  << "����ơC\n\n" ;
	int i = 0 ;



    string file1, file2 ;

	// �B�z�ɮצW��
	if ( ComfirmType::isInt(temp) ) {
		file1 = "bubble_sort" + temp + ".txt" ;
		file2 = "select_sort" + temp + ".txt" ;
	}
	else {
		temp = StringProccess:: GetFileNumber( temp ) ;
		file1 = "bubble_sort" + temp + ".txt" ;
		file2 = "select_sort" + temp + ".txt" ;
	}

	text.WriteOut( file1 ) ;
	text2.WriteOut( file2 ) ;

	cout << text.getSort_Way().c_str() << double(text.getSoet_time())*1000 / CLOCKS_PER_SEC << " ms" << '\n' ;
	cout << text2.getSort_Way().c_str() << double(text2.getSoet_time())*1000 / CLOCKS_PER_SEC << " ms"<< '\n'  ;


}

void Mission::mission2() {

    string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;
	while ( !file.is_open() ) {
		cout << "plz enter a complete file name or file number to perform quickSort & MergeSort of it : " ;
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

    // �ǳƨ����ƶi��Ƨ�
	InformationBuffer text = InformationBuffer( file ) ;
	file.close() ;
	InformationBuffer text2 = InformationBuffer( text.Get() ) ;

	// �I�s�Ƨ�method
	text.mergeSorting() ;
	text2.quickSorting() ;
	cout << "�@�� : " << text.Get().size()  << "����ơC\n\n" ;
	int i = 0 ;



    string file1, file2 ;

	// �B�z�ɮצW��
	if ( ComfirmType::isInt(temp) ) {
		file1 = "merge_sort" + temp + ".txt" ;
		file2 = "quick_sort" + temp + ".txt" ;
	}
	else {
		temp = StringProccess:: GetFileNumber( temp ) ;
		file1 = "merge_sort" + temp + ".txt" ;
		file2 = "quick_sort" + temp + ".txt" ;
	}

	text.WriteOut( file1 ) ;
	text2.WriteOut( file2 ) ;

    cout << text.getSort_Way().c_str() << double(text.getSoet_time())*1000 / CLOCKS_PER_SEC << " ms" << '\n'  ;
	cout << text2.getSort_Way().c_str() << double(text2.getSoet_time())*1000 / CLOCKS_PER_SEC << " ms"<< '\n'  ;

}

void Mission::mission3(){

    string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;
	while ( !file.is_open() ) {
		cout << "plz enter a complete file name or file number to perform RadixSort of it : " ;
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

	InformationBuffer text = InformationBuffer( file ) ;
	file.close() ;
	text.rSort();

	string file1 ;

	// �B�z�ɮצW��
	if ( ComfirmType::isInt(temp) ) {
		file1 = "radix_sort" + temp + ".txt" ;
	}
	else {
		temp = StringProccess:: GetFileNumber( temp ) ;
		file1 = "radix_sort" + temp + ".txt" ;
	}


	text.WriteOut( file1 ) ;

	cout << text.getSort_Way().c_str() << double(text.getSoet_time())*1000 / CLOCKS_PER_SEC << " ms"<< '\n'  ;



}

void Mission::mission6() {


    // Ū�J���
    string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;
	while ( !file.is_open() ) {
		cout << "�п�J�ɮ׽s���A�i�椭�رƧǫ�A�N�ƧǮɶ��s��sort_time.txt�� : " ;
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

	InformationBuffer text = InformationBuffer( file ) ;
	file.close() ;

	InformationBuffer text_bubble_sort = InformationBuffer( text.Get() ) ;
	InformationBuffer text_select_sort = InformationBuffer( text.Get() ) ;
	InformationBuffer text_quick_sort = InformationBuffer( text.Get() ) ;
	InformationBuffer text_merge_sort = InformationBuffer( text.Get() ) ;
	InformationBuffer text_radix_sort = InformationBuffer( text.Get() ) ;

	text_bubble_sort.bubbleSortion() ;
	text_merge_sort.mergeSorting() ;
	text_quick_sort.quickSorting() ;
	text_radix_sort.rSort() ;
	text_select_sort.selectSorting() ;


	fstream file2 ;
    file2.open( "sort_Time.txt", ios_base::in ) ;
    if ( !file.is_open() ) {
        file2.open( "sort_Time.txt", ios_base::out ) ;
        file2 << "\t��ܱƧ�\t��w�Ƨ�\t�ֳt�Ƨ�\t�X�ֱƧ�\t��ƱƧ�\n" << '\n' ;
    }
    file2.close() ;
    file2.open( "sort_Time.txt", ios_base::app ) ;
    file2 << StringProccess::GetFileNumber(temp) ;
    file2.close() ;


    text_select_sort.Write_Sort_time( "sort_Time.txt" ) ;
    text_bubble_sort.Write_Sort_time( "sort_Time.txt" ) ;
    text_quick_sort.Write_Sort_time( "sort_Time.txt" ) ;
    text_merge_sort.Write_Sort_time( "sort_Time.txt" ) ;
    text_radix_sort.Write_Sort_time( "sort_Time.txt" ) ;

    file2.open( "sort_Time.txt", ios_base::app ) ;
    file2 << '\n' ;
    file2.close() ;

}

bool ComfirmType::isInt(string str) {

	int i = 0 ;

	while (i < str.size()) {
		if( isdigit(str.at(i)) ) i++ ;
		else return false ;
	}

	return true ;
}

InformationBuffer::InformationBuffer() {

}

InformationBuffer::InformationBuffer( fstream &file ) {

	string inputALine ;

	while( getline(file, inputALine) ) {

		Information temp = Information(inputALine) ;

		info.push_back( temp ) ;
	}
}



void InformationBuffer::WriteOut(string filename) {

	fstream file ;


	file.open( filename.c_str(), ios_base::out ) ;

	int i = 0 ;
	while( i < info.size() ) {

		file << info.at(i).GetALine() << '\n';
		i++ ;

	}

	file.close() ;

}

void InformationBuffer::Write_Sort_time( string filename ) {

    fstream file ;
    file.open( filename.c_str(), ios_base::app ) ;
    file << "\t" << double(unit_Time)*1000 / CLOCKS_PER_SEC << " ms"  ;
    file.close() ;
}

InformationBuffer::InformationBuffer( vector<Information> temp ) {

    info = temp ;

}

void InformationBuffer::ReWriteOut(string filename) {


	fstream file ;

	file.open( filename.c_str(), ios_base::trunc | ios_base::out ) ;

	int i = 0 ;
	while( i < info.size() ) {

		file << info.at(i).GetALine() << '\n';
		i++ ;

	}

	file.close() ;

}


void InformationBuffer::Print() {

	int i = 0 ;
	while( i < info.size() ) {

		cout << info.at(i).GetALine() << '\n';
		i++ ;

	}
}

void InformationBuffer::Add( Information obj ) {

	info.push_back( obj ) ;

}

vector<Information> InformationBuffer::Get() {
	return info ;
}

Information InformationBuffer:: Get(int i) {

	return info.at(i) ;

}

void InformationBuffer::selectSorting() {

    unit_Time = clock() ;
    SortWay = "Selection sort: " ;

    for( int last = info.size()-1 ; last > 0 ; --last ) {

        // ��̤p
        int indexSoFar = 0 ;
        for ( int i = 1 ; i < last+1  ; ++i ) {
            if ( StringProccess::StrToInt( info.at( indexSoFar ).GetnumOfGraduateStudent() ) > StringProccess::StrToInt( info.at( i ).GetnumOfGraduateStudent() )  ) { // �o�{���p��
                indexSoFar = i ;
            }
        }
        // swap
        Information temp = info.at( indexSoFar ) ;
        info.at( indexSoFar ) = info.at( last ) ;
        info.at(last) = temp ;
    }

    unit_Time = clock() - unit_Time ;

}

void InformationBuffer::bubbleSortion() {

    unit_Time = clock() ;
    SortWay = "Bubble sort:" ;

    for ( int pass = 1 ; pass < info.size() ; ++pass ) {

        for ( int i = 0; i < info.size()-pass ; i++ ) {
            if ( StringProccess::StrToInt( info.at( i ).GetnumOfGraduateStudent() ) < StringProccess::StrToInt( info.at( i+1 ).GetnumOfGraduateStudent() )  ) { // �o�{���p��
                Information temp = info.at( i ) ;
                info.at( i ) = info.at( i+1 ) ;
                info.at(i+1) = temp ;
            }
        }

    }

    unit_Time = clock() - unit_Time ;

}

void InformationBuffer::mergeSorting() {

    unit_Time = clock() ;
    SortWay = "Merge sort:" ;

    mergesort( 0, info.size()-1 ) ;

    unit_Time = clock() - unit_Time ;

}

void InformationBuffer::mergesort( int first, int last ) {

    if ( first < last ) {

        int mid = (first+last)/2 ;

        mergesort( first, mid );

        mergesort(mid+1, last) ;

        Merge( first, mid, last ) ;

    }

}

void InformationBuffer::Merge( int first, int mid, int last ) {

    Information temp[info.size()] ;
    int first1 = first, last1 = mid ;
    int first2 = mid+1, last2 = last ;
    int i = first ;
    for (; (first1<=last1) && (first2<= last2); ++i) {
        if ( StringProccess::StrToInt(info.at(first1).GetnumOfGraduateStudent()) < StringProccess::StrToInt(info.at(first2).GetnumOfGraduateStudent()) ) {
            temp[i] = info.at( first2 ) ; // ���j�����X
            ++first2 ;
        }
        else {
            temp[i] = info.at(first1) ;
            ++ first1 ;
        }
    }

    // if left not finish
    for( ; first1 <= last1; ++first1, ++i ) {
        temp[i] = info.at(first1) ;
    }
    // if right not finish
    for( ; first2 <= last2; ++first2, ++i ) {
       temp[i] = info.at(first2) ;
    }

    for ( i = first; i <=last; ++i ) {
        info.at(i) = temp[i] ;
    }

}


void InformationBuffer::improved_quickSorting(){

    unit_Time = clock() ;
    SortWay = "Improved Quick sort:" ;

    quickSort( 0, info.size()-1 ) ;

    unit_Time = clock() - unit_Time ;
}

void InformationBuffer::improved_quickSort( int first, int last ) {

    int pivotIndex ;
    if ( first < last ) {

        Improved_Partition( first, last, pivotIndex ) ;
        improved_quickSort( first, pivotIndex-1 ) ;
        improved_quickSort( pivotIndex+1, last ) ;

    }

}


void InformationBuffer::Improved_Partition( int first, int last, int&pivotIndex ) {
    // ���Ĥ@�ӷ�pivot
    Information pivot = FindPivot(first, last) ;
    int lastS1 = first ;
    int firstUnknown = first+1 ;
    while ( firstUnknown <= last ) {

        if ( StringProccess::StrToInt(info.at(firstUnknown).GetnumOfGraduateStudent()) > StringProccess::StrToInt(pivot.GetnumOfGraduateStudent()) ) {
            ++lastS1 ;
            Information temp = info.at( lastS1 ) ;
            info.at(lastS1) = info.at( firstUnknown ) ;
            info.at(firstUnknown) = temp ;
        }
        ++firstUnknown ;
    }

    Information temp = info.at( lastS1 ) ;
    info.at(lastS1) = info.at( first ) ;
    info.at(first) = temp ;
    pivotIndex = lastS1 ;

}

Information InformationBuffer::FindPivot( int first, int last) {

    return info.at(first) ;


}

void InformationBuffer::quickSorting(){

    unit_Time = clock() ;
    SortWay = "Quick sort:" ;

    quickSort( 0, info.size()-1 ) ;

    unit_Time = clock() - unit_Time ;
}

void InformationBuffer::quickSort( int first, int last ) {

    int pivotIndex ;
    if ( first < last ) {

        Partition( first, last, pivotIndex ) ;
        quickSort( first, pivotIndex-1 ) ;
        quickSort( pivotIndex+1, last ) ;

    }

}

void InformationBuffer::Partition( int first, int last, int&pivotIndex ) {
    // ���Ĥ@�ӷ�pivot
    Information pivot = info.at(first) ;
    int lastS1 = first ;
    int firstUnknown = first+1 ;
    while ( firstUnknown <= last ) {

        if ( StringProccess::StrToInt(info.at(firstUnknown).GetnumOfGraduateStudent()) > StringProccess::StrToInt(pivot.GetnumOfGraduateStudent()) ) {
            ++lastS1 ;
            Information temp = info.at( lastS1 ) ;
            info.at(lastS1) = info.at( firstUnknown ) ;
            info.at(firstUnknown) = temp ;
        }
        ++firstUnknown ;
    }

    Information temp = info.at( lastS1 ) ;
    info.at(lastS1) = info.at( first ) ;
    info.at(first) = temp ;
    pivotIndex = lastS1 ;

}


void InformationBuffer::rSort(){

    unit_Time = clock() ;
    SortWay = "Radix sort:" ;


    int max = StringProccess::StrToInt(info.at(0).GetnumOfGraduateStudent());
    for (int i = 1; i < info.size(); ++i)
    {
        if (max < StringProccess::StrToInt(info.at(i).GetnumOfGraduateStudent()))
        max = StringProccess::StrToInt(info.at(i).GetnumOfGraduateStudent());
    }
    int d = 1;
    while (max >= 10)
    {
        max /= 10;
        ++d;
    }


    vector<Information> tmp(info.size()) ;
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for(i =1; i <= d; i++)
    {
        for(j = 0; j < 10; j++)
            count[j] = 0;
        for(j = 0; j <info.size() ; j++)
        {
            k = (StringProccess::StrToInt(info.at(j).GetnumOfGraduateStudent()) / radix) % 10;
            count[k]++;
        }
        for(j = 8; j >= 0; j--)
            count[j] = count[j + 1] + count[j];
        for(j = info.size() - 1 ; j >= 0; j--)
        {
            k = ( StringProccess::StrToInt(info.at(j).GetnumOfGraduateStudent())/ radix) % 10;
            tmp[count[k]-1] = info.at(j);
            count[k]--;
        }
        for(j = 0 ; j < info.size(); j++)
            info.at(j) = tmp.at(j);
        radix = radix * 10;
    }
    tmp.clear();
    delete []count;
    unit_Time = clock() - unit_Time ;
}

clockid_t InformationBuffer::getSoet_time() {

    return unit_Time ;

}

string InformationBuffer::getSort_Way() {

    return SortWay ;

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

int StringProccess::StrToInt(string str) {
    str = StringProccess::ComfirmAllDigit( str ) ;
    int sum = 0 ;
    int num = 0 ;
    while ( str.length() > 1 ) {
        num = str.at(0) - '0' ;
        int i = str.length() ;
        while ( i > 1 ) {
            num = num * 10 ;
            i-- ;
        }
        sum = sum + num ;
        str = str.substr( 1, string::npos ) ;
    }

    num = str.at(0) - '0' ;
    sum = sum + num ;

    return sum ;
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

