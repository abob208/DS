//10627234 ��T�G�A ���u��
//10627238 ��T�G�A ���B�o 
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std ;

void Mission1() ;

void Mission2() ;

void Mission3() ;

void Mission4() ;

void Permute( vector<int> allNumber, int indexOfConfirmedNumber) ;

void PermuteNotAllElement( vector<bool> isSelected, int numOfChoosedNumber, vector<int> temp ) ;

void PermuteNotAllElement2( vector<bool> isSelected, int numOfChoosedNumber, vector<int> temp, int M ) ;

void Print( vector<int> allNum ) ;

int times = 0 ; // �������榸�� 
int L = 0 ; //�̤j���^�h�� 

int main(int argc, char** argv) {
	
	char instruction = 0 ;
	cout << "�w��ϥΥ��{��\n\n" ;
	cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n4 : �������4\n" ;
	
	while ( cin >> instruction ) {
		
	  if ( instruction == '0' ) {
	  		cout << "���±z�ϥ�!" ;
			return 0 ;
		} 
	  else if ( instruction == '1' ) Mission1() ;
	  
	  else if ( instruction == '2' ) Mission2() ;
	  
	  else if ( instruction == '3' ) Mission3() ;
	  
	  else if ( instruction == '4' ) Mission4() ;
	
	  else cout << " �D�k��J�A�Э��s��J���O :  " ;
	  
	  cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n4 : �������4\n" ;
		
	}
	
	
	
	
	return 0;
}

void Mission1() {
	
	cout << "�п�J�@�ӥ����N�A�H���1~N���Ҧ������ƱƦC�զX : " ;
	int number = 0 ;
	// ���檽��X�k��J���� 
	while ( cin >> number && number <= 0 ) {
		
		cout << "�������X�k����J�A�п�J�@�ӥ����N�A�BN�j��A�H���1~N���Ҧ������ƱƦC�զX : " ;
		cin >> number ;
	}
	
	cout << '\n' ;
	
	
	// �ھڿ�J���Ʀr��l�Ƥ@��vector
	vector<int> allNumber ; 
	for ( int i = 1 ; i <= number ; i ++  ) {
		
		allNumber.push_back(i) ;
		
	}
	
	clock_t t ;
	t = clock() ;
	
	Permute( allNumber, L) ;
	
	t = clock() - t ;
	cout << "[" << times << "]" << "\n" ;
	cout << "T = " << (float)t * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "L = " << L << "\n" ;
	cout << "(" << number << "," << L << ")\n" ; 
	
	L = 0 ;
	cout << "����1����\n\n\n" ;
	times = 0 ; // ��l�� 
	
	
}


void Mission2() {
	
	cout << "�п�J�@�Ӥj��2�B�p��9������ơA�M�w�n���X�Ӭ۲��Ʀr�ƪ��ƦC�զX : " ;
	int number = 0, temp = 0 ; // number ���h�֭Ӽƭn���ƦC�զX temp �ΨӼȦs�n�ƦC���Ʀr 
	vector<int> allNumber ; 
	
	while ( cin >> number && number < 1 && number > 9 ) {
		
		cout << "�������X�k����J�A�п�J�@�Ӥj��2�B�p��9������ơA�M�w�n���X�Ӽƪ��ƦC�զX : " ;
		cin >> number ;
	}
	
	// ��l�Ƥ@�ӦV�q�x�s�Ҧ��n�ƦC���� 
	
	for ( int i = number ; i > 0 ; ) {
		cin >> temp ;
		if ( temp > 0 ) {
		
			allNumber.push_back(temp) ;
			i-- ;
		}
		else cout << "Error : �п�J�����! " << '\n' ; 
		
	}
	
	clock_t t ;
	t = clock() ;
	
	Permute( allNumber, 0) ;
	
	t = clock() - t ;

	cout << "T = " << (float)t * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "(" << number << "," << (float)t * 1000 / CLOCKS_PER_SEC <<"ms)\n" ;
	cout << "����2����\n\n\n" ;
	cout << '\n' ;
	times = 0 ; // ��l�� 
	
}


void Mission3() {
	
	cout << "�п�J�@�ӥ����N�A�BN���j��9�A�H���1~9�����XN�Ӽƪ����Ҧ������ƱƦC�զX : " ;
	int number = 0 ;
	
	// ���檽��X�k��J���� 
	while ( cin >> number && number <= 0 ) {
		
		cout << "�������X�k����J�A�п�J�@�ӥ����N�A�BN�p��9�A�H���1~9���H��N�ӼƦr���Ҧ������ƱƦC�զX : " ;
	}
	
	cout << '\n' ;
	
	// �}�l��l�Ƹ��
	vector<int> temp ; 
	vector<bool> selectedNumber ( 10, false ) ;
	
	clock_t t ;
	t = clock() ;
	
	PermuteNotAllElement(selectedNumber, number, temp) ;
	
	t = clock() - t ;
	cout << "T = " << (float)t * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	 
	
}

void Mission4() {
	
	cout << "�п�J�@�ӥ����N�A���1~N�����XM�Ӽƪ����Ҧ������ƱƦC�զX : " ;
	int number = 0 ;
	int M = 0 ;
	// ���檽��X�k��J���� 
	while ( cin >> number && number <= 0 ) {
		
		cout << "�������X�k����J�A�п�J�@�ӥ����N�A���1~N���H��M�ӼƦr���Ҧ������ƱƦC�զX : " ;
	}
	
	while ( cin >> M && M <= 0 || M > number ) {
		
		cout << "�������X�k����J�A�п�J�@�ӥ����M�A���1~N���H��M�ӼƦr���Ҧ������ƱƦC�զX : " ;
	}
	cout << '\n' ;

	// �}�l��l�Ƹ��
	vector<int> temp ; 
	vector<bool> selectedNumber ( number+1, false ) ;
	

	clock_t t ;
	t = clock() ;
	
	PermuteNotAllElement2(selectedNumber, number, temp, M ) ;
	
	t = clock() - t ;
	cout << "T = " << (float)t * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	 
	
}
void Print( vector<int> allNum ) {
	
	for( int i = 0 ; i < allNum.size() ; i++ ) {
		
		cout << allNum.at(i) << ' ' ;
		
	}
	
	cout << '\n' ;
	
}

void PermuteNotAllElement( vector<bool> isSelected, int numOfChoosedNumber, vector<int> temp ) {
	

	
	if ( temp.size() == numOfChoosedNumber ) {
	    times ++ ;
	    cout << '[' << times << ']' << " : " ; 
		Print( temp ) ; // �����w�ƶq���Ʀr�Φ��@�ӲզX�H��A�L�X��
	}
	else {
		
		for( int i = 1; i <= 9 ; i ++ ) {
			
			if ( !isSelected.at(i) ) {
				isSelected.at(i) = true ;
				temp.push_back(i) ;
				PermuteNotAllElement( isSelected, numOfChoosedNumber, temp ) ;
				isSelected.at(i) = false ;
				temp.pop_back() ;
			}
			
		}
		
	} 
	
	
	
}

void PermuteNotAllElement2( vector<bool> isSelected, int numOfChoosedNumber, vector<int> temp, int M ) {
	

	
	if ( temp.size() == M ) {
	    times ++ ;
	    cout << '[' << times << ']' << " : " ; 
		Print( temp ) ; // �����w�ƶq���Ʀr�Φ��@�ӲզX�H��A�L�X��
	}
	else {
		
		for( int i = 1; i <= numOfChoosedNumber ; i ++ ) {
			
			if ( !isSelected.at(i) ) {
				isSelected.at(i) = true ;
				temp.push_back(i) ;
				PermuteNotAllElement2( isSelected, numOfChoosedNumber, temp, M ) ;
				isSelected.at(i) = false ;
				temp.pop_back() ;
			}
			
		}
		
	} 
	
	
	
}
void Permute( vector<int> allNumber, int  indexOfConfirmedNumber ) {  
	
	if ( indexOfConfirmedNumber < allNumber.size() ) { // �٨S�F��basecase(�Y�T�{�@�ӲզX�A�Ygeneral case)  
	
		
		
		for ( int i = indexOfConfirmedNumber ; i < allNumber.size() ; i++ ) {
			
			swap(allNumber[indexOfConfirmedNumber], allNumber[i]) ; // ���C�@���ѤU���Ʀr�����L���@���n�T�{����m 
			Permute(allNumber, indexOfConfirmedNumber+1) ; // ���j�I�s�A�T�{�L����m�T�w��A�N�ѤU���Ʀr�A���j�B�z 
			swap(allNumber[indexOfConfirmedNumber], allNumber[i]) ; // ���C�@���ѤU���Ʀr�����L���@���n�T�{����m 
		
			
		}
		
		
	}
	
	else {
		if ( L = 0 ) L = indexOfConfirmedNumber ;
		else if ( L < indexOfConfirmedNumber ) L = indexOfConfirmedNumber ;
		
		times ++ ;
		//cout << '[' << times << ']' << " : " ;
		//Print( allNumber ) ;
		
	}
	
	
}

