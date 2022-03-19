/*
19��
���B�o 10627238
���u�� 10627234
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

        Node* Get_Formula_List() ; // ���٤@�ӫ��бa���@��list ( head's reverse version ***( �����member - head ���VNULL�C
        Node* Get_Formula_List_PostStackToPrefix() ;

        static void Delete( Node* headOfList ) ; // �k�٤@���쵲��ҭɥΪ��Ŷ�
        static Node* GetPostfixFromInfix( Node* headOfInfixList ) ; // ���^�@�ӫ�ǹB�⦡List ***( �����member - head ���VNULL�C
        static Node* GetPrefixFromInfix( Node* headOfInfixList ) ; // ���^�@�ӫe�ǹB�⦡List ***( �����member - head ���VNULL�C
        static int PriorityComfirm( string temp ) ; // �^�ǹB�⤸���u������
    private :
        Node *head = NULL ;

};

class ComfirmType {
	public :
		static bool isInt( string str ) ;
		static bool isInfix( string str ) ; // �ˬd��J���r��O�_�����Ǧ�
};


class StringProccess{
	public :
		static bool hasToken( string &str ) ;
		static string getNextToken( string &str ) ; // �����קאּ�i�H���X�B�⤸�A�B��l�A���k�A��....
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
	cout << "�w��ϥΥ��{��\n\n" ;
	cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1 : ��J�@�Ӻ⦡�A�P�_��O�_�����Ǫ�F��\n2 : �������2 : �g�ѥ��Ȥ@�P�_�����Ǧ��H��A�I�s�����ȱN���ର��Ǫ�F��\n3 : �������3 : �N�ѥ���2�o�X����Ǫ�F���D��\n\n" ;
    cout << "�W���D�԰� : \n4 : ��J�@�Ӥ��Ǧ���e�Ǧ�\n5 : ��J�@�Ӥ��Ǧ��D�ѥH�e�ǨD��\n" ;
	while ( cin >> instruction ) {

	  if ( instruction == '0' ) {
	  		cout << "���±z�ϥ�!" ;
			return 0 ;
		}
	  else if ( instruction == '1' ) Mission::mission1() ;

	  else if ( instruction == '2' ) Mission::mission2() ;

	  else if ( instruction == '3' ) Mission::mission3() ;

	  else if ( instruction == '4' ) Mission::mission4_mission2_Chalenge() ;

	  else if ( instruction == '5' ) Mission::mission5_Newmission_Chalenge() ;

	  else cout << " �D�k��J�A�Э��s��J���O :  " ;

	  cout << "�\\��C�� : \n0 : ���}���{��\n1 : �������1\n2 : �������2\n3 : �������3\n" ;
      cout << "�W���D�԰� : \n4 : ��J�@�Ӥ��Ǧ���e�Ǧ�\n5 : ��J�@�Ӥ��Ǧ��D�ѥH�e�ǨD��\n" ;
	}

    return 0;
}


void Mission::mission1(){
    char a ;
    cout << "plz enter a formula(infix) to confirm whether it's a  legitimate infix expression : " ;
    string temp ;
    cin.get(a) ; // Ū�����O������
    getline( cin, temp ) ;
    if ( ComfirmType::isInfix( temp )) cout << "�o�O�@�ӦX�k�����Ǧ��C" ;
    else cout << "�o���O�@�ӦX�k�����Ǧ��C" ;

    // enter���~�򪺥\��
    cout << "���Uenter���~��@�@�@!!!" ;
    cin.get(a) ;
}

void Mission :: mission2(){

    char a ;
    cout << "plz enter a formula(infix) to get it's postfix : " ;
    string temp ;
    cin.get(a) ; // Ū�����O������
    getline( cin, temp ) ;
    if ( ComfirmType::isInfix( temp )) {

        Stack Infix = Stack( temp ) ; // �N���ǹB�⦡�s��stack
        Node* headOfInfix = Infix.Get_Formula_List() ; // �o�줤�ǹB�⦡( �̷� �B�⤸�A�B��l�A�A������ node )


        // �o���Ǧ�
        Node* Postfix ;
        Postfix = Stack::GetPostfixFromInfix( headOfInfix ) ;

        // �L�Xpostfix
        Node* head = Postfix ;
        while ( head != NULL ) {
            cout << head->item ;
            if ( head->next != NULL ) cout << ", " ;
            head = head->next ;
        }

        cout << "\n" ;
        // �k�ٰO����Ŷ�
        Stack::Delete( Postfix ) ;
        Stack::Delete( headOfInfix ) ;
    }
    else {
            cout << "�o���O�@�Ӥ��ǹB�⦡\n" ;
    }


    // enter���~�򪺥\��
    cout << "���Uenter���~��@�@�@!!!" ;
    cin.get(a) ;


}

void Mission :: mission3(){

    bool error = false ;
    char a ;
    cout << "plz enter a formula(postfix) to calculate its value : " ;
    string temp ;
    cin.get(a) ; // Ū�����O������
    getline( cin, temp ) ;
    Stack postfix = Stack( temp ) ;
    Node* headOfPostfix = postfix.Get_Formula_List() ;
    Node* cur = headOfPostfix ;

    Stack calculate ;

    while ( cur != NULL ) {

        if ( cur->caseOfElement == Operand ) {
            calculate.push( cur->item ) ;

        }
        else if( cur->caseOfElement == Operator ) { // �B�⤸
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
        cout << "���Ƥ��i��0\n" ;
    }

    // �k�ٰO����
    calculate.~Stack() ;

    // enter���~�򪺥\��
    cout << "���Uenter���~��@�@�@!!!" ;
    cin.get(a) ;

}

void Mission::mission4_mission2_Chalenge() {

    char a ;
    cout << "plz enter a formula(infix) to get it's Prefix : " ;
    string temp ;
    cin.get(a) ; // Ū�����O������
    getline( cin, temp ) ;
    if ( ComfirmType::isInfix( temp )) {

        Stack Infix = Stack( temp ) ; // �N���ǹB�⦡�s��stack
        Node* headOfInfix = Infix.Get_Formula_List() ; // �o�줤�ǹB�⦡( �̷� �B�⤸�A�B��l�A�A������ node )


        // �o���Ǧ�
        Node* Prefix ;
        Prefix = Stack::GetPrefixFromInfix( headOfInfix ) ;

        // �L�Xpostfix
        Node* head = Prefix ;

        while ( head != NULL ) {
            cout << head->item ;
            if ( head->next != NULL ) cout << ", " ;
            head = head->next ;
        }

        cout << "\n" ;
        // �k�ٰO����Ŷ�
        Stack::Delete( Prefix ) ;
        Stack::Delete( headOfInfix ) ;
    }
    else {
            cout << "�o���O�@�Ӥ��ǹB�⦡\n" ;
    }


    // enter���~�򪺥\��
    cout << "���Uenter���~��@�@�@!!!" ;
    cin.get(a) ;


}

void Mission::mission5_Newmission_Chalenge() {

    bool error = false ;
    char a ;
    cout << "plz enter a formula(infix) to calculate its value in pre-OrderWay : " ;
    string temp ;
    cin.get(a) ; // Ū�����O������
    getline( cin, temp ) ;
    Stack Infix = Stack( temp ) ; // �N���ǹB�⦡�s��stack
    Node* headOfInfix = Infix.Get_Formula_List() ; // �o�줤�ǹB�⦡( �̷� �B�⤸�A�B��l�A�A������ node )


    // �o���Ǧ�
    Node* Prefix ;
    Prefix = Stack::GetPrefixFromInfix( headOfInfix ) ;

    // �p��e�Ǧ�
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
        cout << "���Ƥ��i��0\n" ;
    }

    // �k�ٰO����
    calculate.~Stack() ;

    // enter���~�򪺥\��
    cout << "���Uenter���~��@�@�@!!!" ;
    cin.get(a) ;

}


bool StringProccess::hasToken( string &str ) { // �N�ťդ����A����D�ťզr���A�����^��true

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

string StringProccess::getNextToken( string &str) { //  ����token����A�N��q�r�ꤤ����

    string temp ;
    bool findToken = false ;

    if ( isdigit(str.at(0)) ) { // �B�⤸

        while ( str.length() > 0 && findToken == false  ) {

            if ( isdigit(str.at(0)) ) {
                temp = temp + str.at(0) ;
                if ( str.length() > 1 ) str = str.substr( 1, string::npos ) ;
                else str = "" ;
            }
            else findToken = true ;

        }
    }
    else { // �B��۩Ψ�L�Ÿ�

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
                error.push_back( "�h�l���B�⤸" ) ;
            }
            else preCase = Operand ;

        }

        else if ( temp->caseOfElement == Operator ) {

            if ( preCase == Operator || preCase == OpenParenthesis ) {
                error.push_back( "�h�l���B��l" ) ;
            }
            else preCase = Operator ;
        }

        else if ( temp->caseOfElement == OpenParenthesis ) {

            if ( preCase == Operand || preCase == CloseParenthesis ) {
                error.push_back( "�ʤֹB��l" ) ;
            }
            else {
                    preCase == OpenParenthesis ;
                    openParenthesis ++ ;
            }
        }

        else if ( temp->caseOfElement == CloseParenthesis ) {

            if ( preCase == Operator ) {
                error.push_back( "�h�l���B��l" ) ;
            }
            else if ( preCase == OpenParenthesis ) {
                error.push_back( "���ت��A����ϥ�" ) ;
            }
            else {
                if (closeParenthesis < openParenthesis ) {
                    preCase = CloseParenthesis ;
                    closeParenthesis++ ;
                }
                else {
                    error.push_back( "�h�l���k�A���ϥ�" ) ;
                }

            }
        }

        else if ( temp->caseOfElement == none ){

            string mes ;
            mes = mes + temp->item + " �O�D�k�r��" ;
            error.push_back( mes.c_str() ) ;

        }




        temp = temp->next ;

    }


    if (  temp == NULL ) {
        if (closeParenthesis > openParenthesis ) {
            error.push_back( "�h�l���k�A��" ) ;
        }
        else if (closeParenthesis < openParenthesis ) {
            error.push_back( "�h�l�����A��" ) ;
        }
    }

    Stack::Delete(ListOfFormula) ; // �k�ٰO����


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
    // �]�w��node��item
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
        if ( temp == NULL ) { // �Ĥ@�Ӥ���
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
        // �B��l������J��Ǧ����|
        if ( headOfInfixList->caseOfElement == Operand ) {
            PostfixStack.push( headOfInfixList->item ) ;
        }
        //�Y���|���ݤ��B�⤸�B���u����>�N�n�i�J���|���B�⤸�A�h���ݭn����X���Ǧ����|��
        else if( headOfInfixList->caseOfElement == Operator ) {

            if ( Stack::PriorityComfirm(OperatorStack.Top()) >=  Stack::PriorityComfirm(headOfInfixList->item) ) {
                PostfixStack.push( OperatorStack.pop() ) ;
                OperatorStack.push( headOfInfixList->item ) ;
            }
            else { OperatorStack.push( headOfInfixList->item ) ;
            }
        }
        // �Y�O���A��
        else if ( headOfInfixList->caseOfElement == OpenParenthesis ) OperatorStack.push( headOfInfixList->item ) ;
        // �Y�O�k�A���A�h�N�B��l���|�����B��l��X�ܥ��A��
        else if ( headOfInfixList->caseOfElement == CloseParenthesis ) {

            while ( OperatorStack.Top().compare( "(" ) != 0 ) {
                PostfixStack.push( OperatorStack.pop() ) ;
            }
            string garbage = OperatorStack.pop() ; // �B�z��d�����A��
        }

        headOfInfixList = headOfInfixList->next ;

    }

    // �N�Ҧ��Ѿl���B�⤸��X���Ǧ����|��
    while ( OperatorStack.Top().compare( " " ) != 0 ) {
        PostfixStack.push( OperatorStack.pop() ) ;
    }

    // �o��ѥk�쥪����Ǧ�list
    postfix = PostfixStack.Get_Formula_List() ;
    return postfix ;

}

Node* Stack::GetPrefixFromInfix( Node* headOfInfixList ) {

    Stack OperatorStack ;
    Stack PostfixStack ;

    Node* prefix ;


    while ( headOfInfixList != NULL ) {
        // �B��l������J��Ǧ����|
        if ( headOfInfixList->caseOfElement == Operand ) {
            PostfixStack.push( headOfInfixList->item ) ;
        }
        //�Y���|���ݤ��B�⤸�B���u����>�N�n�i�J���|���B�⤸�A�h���ݭn����X���Ǧ����|��
        else if( headOfInfixList->caseOfElement == Operator ) {

            if ( Stack::PriorityComfirm(OperatorStack.Top()) >  Stack::PriorityComfirm(headOfInfixList->item) ) {
                PostfixStack.push( OperatorStack.pop() ) ;
                OperatorStack.push( headOfInfixList->item ) ;
            }
            else { OperatorStack.push( headOfInfixList->item ) ;
            }
        }
        // �Y�O���A��
        else if ( headOfInfixList->caseOfElement == OpenParenthesis ) OperatorStack.push( headOfInfixList->item ) ;
        // �Y�O�k�A���A�h�N�B��l���|�����B��l��X�ܥ��A��
        else if ( headOfInfixList->caseOfElement == CloseParenthesis ) {

            while ( OperatorStack.Top().compare( "(" ) != 0 ) {
                PostfixStack.push( OperatorStack.pop() ) ;
            }
            string garbage = OperatorStack.pop() ; // �B�z��d�����A��
        }

        headOfInfixList = headOfInfixList->next ;

    }

    // �N�Ҧ��Ѿl���B�⤸��X���Ǧ����|��
    while ( OperatorStack.Top().compare( " " ) != 0 ) {
        PostfixStack.push( OperatorStack.pop() ) ;
    }

    // �o��ѥk�쥪����Ǧ�list
    prefix = PostfixStack.Get_Formula_List_PostStackToPrefix() ;

    return prefix ;

}
