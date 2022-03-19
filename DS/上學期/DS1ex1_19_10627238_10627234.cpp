//10627234 資訊二乙 陳守倫
//10627238 資訊二乙 蔡朋穎 
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

int times = 0 ; // 紀錄執行次數 
int L = 0 ; //最大遞回層數 

int main(int argc, char** argv) {
	
	char instruction = 0 ;
	cout << "歡迎使用本程式\n\n" ;
	cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n4 : 執行任務4\n" ;
	
	while ( cin >> instruction ) {
		
	  if ( instruction == '0' ) {
	  		cout << "謝謝您使用!" ;
			return 0 ;
		} 
	  else if ( instruction == '1' ) Mission1() ;
	  
	  else if ( instruction == '2' ) Mission2() ;
	  
	  else if ( instruction == '3' ) Mission3() ;
	  
	  else if ( instruction == '4' ) Mission4() ;
	
	  else cout << " 非法輸入，請重新輸入指令 :  " ;
	  
	  cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n4 : 執行任務4\n" ;
		
	}
	
	
	
	
	return 0;
}

void Mission1() {
	
	cout << "請輸入一個正整數N，以找到1~N的所有不重複排列組合 : " ;
	int number = 0 ;
	// 執行直到合法輸入為止 
	while ( cin >> number && number <= 0 ) {
		
		cout << "此為不合法的輸入，請輸入一個正整數N，且N大於，以找到1~N的所有不重複排列組合 : " ;
		cin >> number ;
	}
	
	cout << '\n' ;
	
	
	// 根據輸入的數字初始化一個vector
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
	cout << "任務1完成\n\n\n" ;
	times = 0 ; // 初始化 
	
	
}


void Mission2() {
	
	cout << "請輸入一個大於2且小於9的正整數，決定要做幾個相異數字數的排列組合 : " ;
	int number = 0, temp = 0 ; // number 有多少個數要做排列組合 temp 用來暫存要排列的數字 
	vector<int> allNumber ; 
	
	while ( cin >> number && number < 1 && number > 9 ) {
		
		cout << "此為不合法的輸入，請輸入一個大於2且小於9的正整數，決定要做幾個數的排列組合 : " ;
		cin >> number ;
	}
	
	// 初始化一個向量儲存所有要排列的數 
	
	for ( int i = number ; i > 0 ; ) {
		cin >> temp ;
		if ( temp > 0 ) {
		
			allNumber.push_back(temp) ;
			i-- ;
		}
		else cout << "Error : 請輸入正整數! " << '\n' ; 
		
	}
	
	clock_t t ;
	t = clock() ;
	
	Permute( allNumber, 0) ;
	
	t = clock() - t ;

	cout << "T = " << (float)t * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	cout << "(" << number << "," << (float)t * 1000 / CLOCKS_PER_SEC <<"ms)\n" ;
	cout << "任務2完成\n\n\n" ;
	cout << '\n' ;
	times = 0 ; // 初始化 
	
}


void Mission3() {
	
	cout << "請輸入一個正整數N，且N不大於9，以找到1~9中取出N個數的的所有不重複排列組合 : " ;
	int number = 0 ;
	
	// 執行直到合法輸入為止 
	while ( cin >> number && number <= 0 ) {
		
		cout << "此為不合法的輸入，請輸入一個正整數N，且N小於9，以找到1~9中隨機N個數字的所有不重複排列組合 : " ;
	}
	
	cout << '\n' ;
	
	// 開始初始化資料
	vector<int> temp ; 
	vector<bool> selectedNumber ( 10, false ) ;
	
	clock_t t ;
	t = clock() ;
	
	PermuteNotAllElement(selectedNumber, number, temp) ;
	
	t = clock() - t ;
	cout << "T = " << (float)t * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	 
	
}

void Mission4() {
	
	cout << "請輸入一個正整數N，找到1~N中取出M個數的的所有不重複排列組合 : " ;
	int number = 0 ;
	int M = 0 ;
	// 執行直到合法輸入為止 
	while ( cin >> number && number <= 0 ) {
		
		cout << "此為不合法的輸入，請輸入一個正整數N，找到1~N中隨機M個數字的所有不重複排列組合 : " ;
	}
	
	while ( cin >> M && M <= 0 || M > number ) {
		
		cout << "此為不合法的輸入，請輸入一個正整數M，找到1~N中隨機M個數字的所有不重複排列組合 : " ;
	}
	cout << '\n' ;

	// 開始初始化資料
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
		Print( temp ) ; // 找到指定數量的數字形成一個組合以後，印出來
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
		Print( temp ) ; // 找到指定數量的數字形成一個組合以後，印出來
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
	
	if ( indexOfConfirmedNumber < allNumber.size() ) { // 還沒達到basecase(即確認一個組合，即general case)  
	
		
		
		for ( int i = indexOfConfirmedNumber ; i < allNumber.size() ; i++ ) {
			
			swap(allNumber[indexOfConfirmedNumber], allNumber[i]) ; // 讓每一輪剩下的數字都輪過那一輪要確認的位置 
			Permute(allNumber, indexOfConfirmedNumber+1) ; // 遞迴呼叫，確認過的位置固定後，將剩下的數字再遞迴處理 
			swap(allNumber[indexOfConfirmedNumber], allNumber[i]) ; // 讓每一輪剩下的數字都輪過那一輪要確認的位置 
		
			
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

