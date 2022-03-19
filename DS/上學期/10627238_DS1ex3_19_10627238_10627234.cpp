/*
19組
蔡朋穎 10627238
陳守倫 10627234
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype> // for Null
#include <vector>
#include <cmath>
using namespace std;

enum CaseOfElement { none = 0, Operand = 1, Operator = 2, OpenParenthesis = 3, CloseParenthesis = 4 };

struct Node{

    string item ;
    CaseOfElement caseOfElement ;
    Node *next ;

};

class Stack{

    public :
        Stack() ;
        Stack( string str ) ; // constructor
        ~Stack() ; // destructor
        string pop() ;
        void push(string str) ;
        string Top() ;

        Node* Get_Formula_List() ; // 返還一個指標帶有一個list ( head's reverse version ***( 執行後member - head 指向NULL。
        Node* Get_Formula_List_PostStackToPrefix() ;

        static void Delete( Node* headOfList ) ; // 歸還一個鏈結表所借用的空間
        static Node* GetPostfixFromInfix( Node* headOfInfixList ) ; // 取回一個後序運算式List ***( 執行後member - head 指向NULL。
        static Node* GetPrefixFromInfix( Node* headOfInfixList ) ; // 取回一個前序運算式List ***( 執行後member - head 指向NULL。
        static int PriorityComfirm( string temp ) ; // 回傳運算元的優先順序
    private :
        Node *head = NULL ;

};

class ComfirmType {
	public :
		static bool isInt( string str ) ;
		static bool isInfix( string str ) ; // 檢查輸入之字串是否為中序式
};


class StringProccess{
	public :
		static bool hasToken( string &str ) ;
		static string getNextToken( string &str ) ; // 必須修改為可以切出運算元，運算子，左右括號....
        static int StrToInt(string str) ;
};


class Mission {

	public :
		static void mission1() ;
		static void mission2() ;
		static void mission3() ;

		static void mission4_mission2_Chalenge() ;
		static void mission5_Newmission_Chalenge() ;

};



int main()
{
    char instruction = 0 ;
	cout << "歡迎使用本程式\n\n" ;
	cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1 : 輸入一個算式，判斷其是否為中序表達式\n2 : 執行任務2 : 經由任務一判斷為中序式以後，呼叫此任務將其轉為後序表達式\n3 : 執行任務3 : 將由任務2得出的後序表達式求值\n\n" ;
    cout << "上機挑戰區 : \n4 : 輸入一個中序式轉前序式\n5 : 輸入一個中序式求解以前序求解\n" ;
	while ( cin >> instruction ) {

	  if ( instruction == '0' ) {
	  		cout << "謝謝您使用!" ;
			return 0 ;
		}
	  else if ( instruction == '1' ) Mission::mission1() ;

	  else if ( instruction == '2' ) Mission::mission2() ;

	  else if ( instruction == '3' ) Mission::mission3() ;

	  else if ( instruction == '4' ) Mission::mission4_mission2_Chalenge() ;

	  else if ( instruction == '5' ) Mission::mission5_Newmission_Chalenge() ;

	  else cout << " 非法輸入，請重新輸入指令 :  " ;

	  cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n" ;
      cout << "上機挑戰區 : \n4 : 輸入一個中序式轉前序式\n5 : 輸入一個中序式求解以前序求解\n" ;
	}

    return 0;
}


void Mission::mission1(){
    char a ;
    cout << "plz enter a formula(infix) to confirm whether it's a  legitimate infix expression : " ;
    string temp ;
    cin.get(a) ; // 讀掉指令的換行
    getline( cin, temp ) ;
    if ( ComfirmType::isInfix( temp )) cout << "這是一個合法的中序式。" ;
    else cout << "這不是一個合法的中序式。" ;

    // enter後繼續的功能
    cout << "按下enter鍵繼續哦哦哦!!!" ;
    cin.get(a) ;
}

void Mission :: mission2(){

    char a ;
    cout << "plz enter a formula(infix) to get it's postfix : " ;
    string temp ;
    cin.get(a) ; // 讀掉指令的換行
    getline( cin, temp ) ;
    if ( ComfirmType::isInfix( temp )) {

        Stack Infix = Stack( temp ) ; // 將中序運算式存成stack
        Node* headOfInfix = Infix.Get_Formula_List() ; // 得到中序運算式( 依照 運算元，運算子，括號做成 node )


        // 得到後序式
        Node* Postfix ;
        Postfix = Stack::GetPostfixFromInfix( headOfInfix ) ;

        // 印出postfix
        Node* head = Postfix ;
        while ( head != NULL ) {
            cout << head->item ;
            if ( head->next != NULL ) cout << ", " ;
            head = head->next ;
        }

        cout << "\n" ;
        // 歸還記憶體空間
        Stack::Delete( Postfix ) ;
        Stack::Delete( headOfInfix ) ;
    }
    else {
            cout << "這不是一個中序運算式\n" ;
    }


    // enter後繼續的功能
    cout << "按下enter鍵繼續哦哦哦!!!" ;
    cin.get(a) ;


}

void Mission :: mission3(){

    bool error = false ;
    char a ;
    cout << "plz enter a formula(postfix) to calculate its value : " ;
    string temp ;
    cin.get(a) ; // 讀掉指令的換行
    getline( cin, temp ) ;
    Stack postfix = Stack( temp ) ;
    Node* headOfPostfix = postfix.Get_Formula_List() ;
    Node* cur = headOfPostfix ;

    Stack calculate ;

    while ( cur != NULL ) {

        if ( cur->caseOfElement == Operand ) {
            calculate.push( cur->item ) ;

        }
        else if( cur->caseOfElement == Operator ) { // 運算元
            if ( cur->item.compare( "+" ) == 0 ) {
                int sum, a, b ;
                a = StringProccess::StrToInt(calculate.pop()) ;
                b = StringProccess::StrToInt(calculate.pop()) ;
                sum = a + b ;

                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;

                calculate.push( temp ) ;
            }
            else if ( cur->item.compare( "-" ) == 0 ) {
                int sum = 0, a, b ;
                a = StringProccess::StrToInt(calculate.pop()) ;
                b = StringProccess::StrToInt(calculate.pop()) ;
                sum = b - a ;

                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;

                calculate.push( temp ) ;
            }
            else if ( cur->item.compare( "/" ) == 0 ) {
                int sum = 0, a, b ;
                a = StringProccess::StrToInt(calculate.pop()) ;
                b = StringProccess::StrToInt(calculate.pop()) ;

                if ( a == 0 ) error = true ;
                else sum = b/a ;

                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;

                calculate.push( temp ) ;
            }
            else if ( cur->item.compare( "*" ) == 0 ) {
                int sum = 0, a, b ;
                a = StringProccess::StrToInt(calculate.pop()) ;
                b = StringProccess::StrToInt(calculate.pop()) ;
                sum = a * b ;

                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;

                calculate.push( temp ) ;
            }
             else if ( cur->item.compare( "%" ) == 0 ) {
                int sum = 0, a, b ;
                a = StringProccess::StrToInt(calculate.pop()) ;
                b = StringProccess::StrToInt(calculate.pop()) ;

                if ( a == 0 ) error = true ;
                else sum = b%a ;

                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;

                calculate.push( temp ) ;
            }


        }
        cur = cur->next ;
    }

    if ( error == false ) {
        cout << "Answer : " << calculate.pop() << '\n' ;
    }
    else {
        cout << "除數不可為0\n" ;
    }

    // 歸還記憶體
    calculate.~Stack() ;

    // enter後繼續的功能
    cout << "按下enter鍵繼續哦哦哦!!!" ;
    cin.get(a) ;

}

void Mission::mission4_mission2_Chalenge() {

    char a ;
    cout << "plz enter a formula(infix) to get it's Prefix : " ;
    string temp ;
    cin.get(a) ; // 讀掉指令的換行
    getline( cin, temp ) ;
    if ( ComfirmType::isInfix( temp )) {

        Stack Infix = Stack( temp ) ; // 將中序運算式存成stack
        Node* headOfInfix = Infix.Get_Formula_List() ; // 得到中序運算式( 依照 運算元，運算子，括號做成 node )


        // 得到後序式
        Node* Prefix ;
        Prefix = Stack::GetPrefixFromInfix( headOfInfix ) ;

        // 印出postfix
        Node* head = Prefix ;

        while ( head != NULL ) {
            cout << head->item ;
            if ( head->next != NULL ) cout << ", " ;
            head = head->next ;
        }

        cout << "\n" ;
        // 歸還記憶體空間
        Stack::Delete( Prefix ) ;
        Stack::Delete( headOfInfix ) ;
    }
    else {
            cout << "這不是一個中序運算式\n" ;
    }


    // enter後繼續的功能
    cout << "按下enter鍵繼續哦哦哦!!!" ;
    cin.get(a) ;


}

void Mission::mission5_Newmission_Chalenge() {

    bool error = false ;
    char a ;
    cout << "plz enter a formula(infix) to calculate its value in pre-OrderWay : " ;
    string temp ;
    cin.get(a) ; // 讀掉指令的換行
    getline( cin, temp ) ;
    Stack Infix = Stack( temp ) ; // 將中序運算式存成stack
    Node* headOfInfix = Infix.Get_Formula_List() ; // 得到中序運算式( 依照 運算元，運算子，括號做成 node )


    // 得到後序式
    Node* Prefix ;
    Prefix = Stack::GetPrefixFromInfix( headOfInfix ) ;

    // 計算前序式
    Node* cur = Prefix ;


    Stack calculate ;
    int numOfOperandInStack = 0 ;

    while ( cur != NULL ) {

        if ( cur->caseOfElement == Operand ) {
            numOfOperandInStack ++ ;
            temp = calculate.pop() ;

            if ( ComfirmType::isInt( temp ) ) {
                numOfOperandInStack ++ ;
            }

            calculate.push(temp) ;
        }
        else numOfOperandInStack = 0 ;

        calculate.push( cur->item ) ;

        cout << numOfOperandInStack ;

        if ( numOfOperandInStack == 2 ) {
            string operator_  ;
            int num1, num2 ;
            num1 = StringProccess::StrToInt(calculate.pop()) ;
            num2 = StringProccess::StrToInt(calculate.pop()) ;
            operator_ = calculate.pop() ;

            if ( operator_.compare( "+" ) == 0 ) {
                int sum = num1 + num2 ;
                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;
                calculate.push( temp ) ;
            }
            else if ( operator_.compare( "-" ) == 0 ) {
                int sum = num1 - num2 ;
                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;
                calculate.push( temp ) ;
            }
            else if ( operator_.compare( "*" ) == 0 ) {
                int sum = num1*num2 ;
                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;
                calculate.push( temp ) ;
            }
            else if ( operator_.compare( "/" ) == 0 ) {
                int sum = num2/num1 ;
                char buffer[33] ;
                itoa(sum,buffer,10) ;
                string temp = buffer ;
                calculate.push( temp ) ;
            }

            numOfOperandInStack = 0 ;
        }
        else numOfOperandInStack = 0 ;

        cur = cur->next ;
    }

    if ( error == false ) {
        cout << "Answer : " << calculate.pop() << '\n' ;
    }
    else {
        cout << "除數不可為0\n" ;
    }

    // 歸還記憶體
    calculate.~Stack() ;

    // enter後繼續的功能
    cout << "按下enter鍵繼續哦哦哦!!!" ;
    cin.get(a) ;

}


bool StringProccess::hasToken( string &str ) { // 將空白切掉，直到非空白字元，有找到回傳true

    bool findToken = false ;
    while ( str.length() > 0 && findToken == false ) {

        if ( str.at(0) == '\t' || str.at(0) == ' ' || str.at(0) == '\n' ) {
            if ( str.length() > 1 ) str = str.substr( 1, string::npos ) ;
            else str = "" ;
        }
        else {
            findToken = true ;
        }

    }

    return findToken ;


}

string StringProccess::getNextToken( string &str) { //  紀錄token之後，將其從字串中切掉

    string temp ;
    bool findToken = false ;

    if ( isdigit(str.at(0)) ) { // 運算元

        while ( str.length() > 0 && findToken == false  ) {

            if ( isdigit(str.at(0)) ) {
                temp = temp + str.at(0) ;
                if ( str.length() > 1 ) str = str.substr( 1, string::npos ) ;
                else str = "" ;
            }
            else findToken = true ;

        }
    }
    else { // 運算自或其他符號

        temp = temp + str.at(0) ;
        if ( str.length() > 1 ) str = str.substr( 1, string::npos ) ;
        else str = "" ;
    }

    return temp ;
}

int StringProccess::StrToInt(string str) {
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

bool ComfirmType::isInt(string str) {

	int i = 0 ;

	while (i < str.size()) {
		if( isdigit(str.at(i)) ) i++ ;
		else return false ;
	}

	return true ;
}


bool ComfirmType::isInfix(string str) {

    int i = 0 ; // index
    int openParenthesis = 0, closeParenthesis = 0 ;
    bool isInfix =false ;
    vector<string> error ;
    Stack formula = Stack( str ) ;
    Node *ListOfFormula = formula.Get_Formula_List() ;
    formula.~Stack() ;

    Node* temp = ListOfFormula ;


    CaseOfElement preCase = none ;

    while ( error.size() == 0 && temp != NULL ) {

        if ( temp->caseOfElement == Operand ) {

            if ( preCase == Operand || preCase == CloseParenthesis ) {
                error.push_back( "多餘的運算元" ) ;
            }
            else preCase = Operand ;

        }

        else if ( temp->caseOfElement == Operator ) {

            if ( preCase == Operator || preCase == OpenParenthesis ) {
                error.push_back( "多餘的運算子" ) ;
            }
            else preCase = Operator ;
        }

        else if ( temp->caseOfElement == OpenParenthesis ) {

            if ( preCase == Operand || preCase == CloseParenthesis ) {
                error.push_back( "缺少運算子" ) ;
            }
            else {
                    preCase == OpenParenthesis ;
                    openParenthesis ++ ;
            }
        }

        else if ( temp->caseOfElement == CloseParenthesis ) {

            if ( preCase == Operator ) {
                error.push_back( "多餘的運算子" ) ;
            }
            else if ( preCase == OpenParenthesis ) {
                error.push_back( "冗贅的括號對使用" ) ;
            }
            else {
                if (closeParenthesis < openParenthesis ) {
                    preCase = CloseParenthesis ;
                    closeParenthesis++ ;
                }
                else {
                    error.push_back( "多餘的右括號使用" ) ;
                }

            }
        }

        else if ( temp->caseOfElement == none ){

            string mes ;
            mes = mes + temp->item + " 是非法字元" ;
            error.push_back( mes.c_str() ) ;

        }




        temp = temp->next ;

    }


    if (  temp == NULL ) {
        if (closeParenthesis > openParenthesis ) {
            error.push_back( "多餘的右括號" ) ;
        }
        else if (closeParenthesis < openParenthesis ) {
            error.push_back( "多餘的左括號" ) ;
        }
    }

    Stack::Delete(ListOfFormula) ; // 歸還記憶體


    if ( error.size() != 0 ) {
            int i = 0 ;
        while ( i < error.size() ) {
            cout << error.at(i) << '\n' ;
            i++ ;
        }
    }
    else isInfix = true ;

    return isInfix ;

}

Stack::Stack() {} ;

Stack::Stack( string str ) {
    string temp = str ;
    while ( StringProccess::hasToken( temp ) ) {

        push( StringProccess::getNextToken( temp ) ) ;

    }

}

Stack::~Stack() {

    Node *target = NULL ;
    while ( head != NULL ) {

        target = head ;
        head = head->next ;
        delete target ;

    }

}

string Stack::pop() {

    Node *pre = NULL, *cur = NULL ;
    string temp ;

    if ( head != NULL ) {
        cur = head ;
        temp = cur->item ;
        head = head->next ;
        delete cur ;
    }
    else return NULL ;

    return temp ;

}

void Stack::push( string str ) {


    Node *pre = NULL, *cur = NULL, *temp = NULL ;

    temp = new Node ;
    // 設定此node的item
    temp->item = str ;
    if ( ComfirmType::isInt(temp->item) ) temp->caseOfElement = Operand ;
    else if ( temp->item.compare( "(" ) == 0 ) temp->caseOfElement = OpenParenthesis ;
    else if ( temp->item.compare( ")" ) == 0 ) temp->caseOfElement = CloseParenthesis ;
    else if ( temp->item.compare( "+" ) == 0 || temp->item.compare( "-" ) == 0 || temp->item.compare( "*" ) == 0 || temp->item.compare( "/" ) == 0 || temp->item.compare( "%" ) == 0 ) temp->caseOfElement = Operator ;
    else temp->caseOfElement = none ;

    temp->next = head ;
    head = temp ;

}

Node* Stack::Get_Formula_List() {

    Node* temp = NULL, *cur ;
    while ( head != NULL ) {
        cur = head ;
        head = head->next ;
        if ( temp == NULL ) { // 第一個元素
            temp = cur ;
            cur->next =NULL ;

        }
        else{

            cur->next = temp ;
            temp = cur ;

        }
    }

    return temp ;

}

Node* Stack::Get_Formula_List_PostStackToPrefix() {

    Node* temp ;
    temp = head ;
    head = NULL ;
    return temp ;

}

void Stack::Delete( Node* headOfList ) {

    Node *target = NULL ;
    while ( headOfList != NULL ) {

        target = headOfList ;
        headOfList = headOfList->next ;
        delete target ;

    }

}

int Stack::PriorityComfirm( string temp ) {

    if ( temp.compare( "+" ) == 0 || temp.compare( "-" ) == 0 ) return 1 ;
    else if ( temp.compare( "*" ) == 0 || temp.compare( "/" ) == 0 || temp.compare( "%" ) == 0 ) return 2 ;

    return 0 ;

}

string Stack::Top() {

    if ( head != NULL ) {
        return head->item ;
    }

    return " " ;

}

Node* Stack::GetPostfixFromInfix( Node* headOfInfixList ) {

    Stack OperatorStack ;
    Stack PostfixStack ;
    Node* postfix ;


    while ( headOfInfixList != NULL ) {
        // 運算子直接放入後序式堆疊
        if ( headOfInfixList->caseOfElement == Operand ) {
            PostfixStack.push( headOfInfixList->item ) ;
        }
        //若堆疊頂端之運算元運算優先度>將要進入堆疊的運算元，則頂端要先輸出到後序式堆疊中
        else if( headOfInfixList->caseOfElement == Operator ) {

            if ( Stack::PriorityComfirm(OperatorStack.Top()) >=  Stack::PriorityComfirm(headOfInfixList->item) ) {
                PostfixStack.push( OperatorStack.pop() ) ;
                OperatorStack.push( headOfInfixList->item ) ;
            }
            else { OperatorStack.push( headOfInfixList->item ) ;
            }
        }
        // 若是左括號
        else if ( headOfInfixList->caseOfElement == OpenParenthesis ) OperatorStack.push( headOfInfixList->item ) ;
        // 若是右括號，則將運算子堆疊中的運算子輸出至左括號
        else if ( headOfInfixList->caseOfElement == CloseParenthesis ) {

            while ( OperatorStack.Top().compare( "(" ) != 0 ) {
                PostfixStack.push( OperatorStack.pop() ) ;
            }
            string garbage = OperatorStack.pop() ; // 處理遺留的左括號
        }

        headOfInfixList = headOfInfixList->next ;

    }

    // 將所有剩餘的運算元輸出到後序式堆疊中
    while ( OperatorStack.Top().compare( " " ) != 0 ) {
        PostfixStack.push( OperatorStack.pop() ) ;
    }

    // 得到由右到左的後序式list
    postfix = PostfixStack.Get_Formula_List() ;
    return postfix ;

}

Node* Stack::GetPrefixFromInfix( Node* headOfInfixList ) {

    Stack OperatorStack ;
    Stack PostfixStack ;

    Node* prefix ;


    while ( headOfInfixList != NULL ) {
        // 運算子直接放入後序式堆疊
        if ( headOfInfixList->caseOfElement == Operand ) {
            PostfixStack.push( headOfInfixList->item ) ;
        }
        //若堆疊頂端之運算元運算優先度>將要進入堆疊的運算元，則頂端要先輸出到後序式堆疊中
        else if( headOfInfixList->caseOfElement == Operator ) {

            if ( Stack::PriorityComfirm(OperatorStack.Top()) >  Stack::PriorityComfirm(headOfInfixList->item) ) {
                PostfixStack.push( OperatorStack.pop() ) ;
                OperatorStack.push( headOfInfixList->item ) ;
            }
            else { OperatorStack.push( headOfInfixList->item ) ;
            }
        }
        // 若是左括號
        else if ( headOfInfixList->caseOfElement == OpenParenthesis ) OperatorStack.push( headOfInfixList->item ) ;
        // 若是右括號，則將運算子堆疊中的運算子輸出至左括號
        else if ( headOfInfixList->caseOfElement == CloseParenthesis ) {

            while ( OperatorStack.Top().compare( "(" ) != 0 ) {
                PostfixStack.push( OperatorStack.pop() ) ;
            }
            string garbage = OperatorStack.pop() ; // 處理遺留的左括號
        }

        headOfInfixList = headOfInfixList->next ;

    }

    // 將所有剩餘的運算元輸出到後序式堆疊中
    while ( OperatorStack.Top().compare( " " ) != 0 ) {
        PostfixStack.push( OperatorStack.pop() ) ;
    }

    // 得到由右到左的後序式list
    prefix = PostfixStack.Get_Formula_List_PostStackToPrefix() ;

    return prefix ;

}
