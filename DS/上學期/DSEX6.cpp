/*
第19組
10627238 蔡朋穎
10627234 陳守倫
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

int numOfData = 1 ;
int numOfNode = 1 ;

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

struct pokemo{
    string Num ;
    string Name ;
    string Type1 ;
    string Type2 ;
    string Total ;
    string HP ;
    string Attack ;
    string Defense ;
    string Sp_Atk ;
    string Sp_Def ;
    string Speed ;
    string Generation ;
    string Legendary ;

};

struct BstNode{

    vector<pokemo> item ;
    string key ;
    BstNode *leftChildPtr ;
    BstNode *rightChildPtr ;

};

class BST {

    public :
        BST() ;
        ~BST() ;
        void CreatBST() ;
        bool isEmpty() ;
        void Insert( pokemo data ) ;
        void Insert( BstNode* &bst,BstNode *ptr ) ;
        BstNode* Serch( string key ) ;
        BstNode* Find_Max() ;
        void Find_Max( BstNode* bst, BstNode*& target ) ;
        BstNode*& Find( BstNode*& parent, BstNode* target ) ;

        void Screen_BY_KEY( string key ) ;
        void Screen( string key, BstNode* root ) ;
        void print( vector<pokemo> data ) ;
        void inorderTraverse() ;
        string Get_HP() ;
        int findHeight() ;
        void Delete( BstNode* bst ) ;

    private :
        BstNode* root ;

        void traverse( BstNode* bst ) ;
        int find_hight( BstNode* bst ) ;
        void clear_bst( BstNode* &bst ) ;
        void DELETE_CASE1( BstNode* &bst ) ;
        void DELETE_CASE2( BstNode* &bst ) ;
        void DELETE_CASE3( BstNode* &bst ) ;
};

class ComfirmType{

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
		static void mission1( BST &data ) ;
		static void mission2( BST &data ) ;
		static void mission3( BST &data ) ;

};



int main()
{
    char instruction = 0 ;
    BST Data = BST() ;
	cout << "歡迎使用本程式\n\n" ;
	cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n\n" ;

	while ( cin >> instruction ) {

	  if ( instruction == '0' ) {
	  		cout << "謝謝您使用!" ;
			return 0 ;
		}
	  else if ( instruction == '1' ) Mission::mission1( Data ) ;

	  else if ( instruction == '2' ) Mission::mission2( Data ) ;

	  else if ( instruction == '3' ) Mission::mission3( Data ) ;

	  else cout << " 非法輸入，請重新輸入指令 :  " ;

	  cout << "功\能列表 : \n0 : 離開本程式\n1 : 執行任務1\n2 : 執行任務2\n3 : 執行任務3\n\n" ;

	}



}

void Mission::mission1( BST &data ) {
    data.~BST() ;
    data.CreatBST() ;
    cout << "HP tree Hight = " << data.findHeight() << '\n' ;
}

void Mission::mission2( BST &data ) {
    if ( !data.isEmpty() ) {
    cout << "輸入HP篩選門檻的最小值 : " ;
    string temp ;
    cin >> temp ;
    data.Screen_BY_KEY( temp ) ;
    cout << "Number of visited nodes : " << numOfNode << '\n' ;
    numOfNode = 1 ;
    }
    else {
        cout <<  "\n\n----there is no tree ! plz execute Mission 1 first !----\n\n" ;
    }
}

void Mission::mission3( BST &data ) {
    BstNode* target = data.Find_Max() ;
    data.Delete( target ) ;
    if ( target != NULL ) {
        cout << "HP tree Hight = " << data.findHeight() << '\n' ;
    }
    else {
        cout << "\n\n----there is no tree ! plz execute Mission 1 first !----\n\n" ;
    }
}

BST::BST() {
    root = NULL ;
}

BST::~BST(){
    clear_bst( root ) ;
}

void BST::Delete( BstNode* bst ) {

    if ( bst != NULL ) {
    cout << "delete_key : " << bst->key << '\n' ;
    if ( bst == NULL ) return ;
    else if ( bst->item.size() > 1 ) {
        pokemo data = bst->item.at( bst->item.size()-1 ) ;
        cout << "#\tName\tType 1\tType 2\tTotal\tHP\tAttack\tDefense\tSp.Atk\tSp.Def\tSpeed\tGeneration\tLegendary\n" ;
        cout << data.Num << '\t' << data.Name << '\t' << data.Type1 << '\t' << data.Type2 << '\t'  << data.Total << '\t' << data.HP << '\t' << data.Attack << '\t' << data.Defense << data.Sp_Atk << '\t'  << data.Sp_Def << '\t' << data.Speed << '\t'  << data.Generation << '\t' << data.Legendary << '\t'  << '\n' ;
        bst->item.pop_back() ;
    }
    else {
        pokemo data = bst->item.at( bst->item.size()-1 ) ;
        cout << "#\tName\tType 1\tType 2\tTotal\tHP\tAttack\tDefense\tSp.Atk\tSp.Def\tSpeed\tGeneration\tLegendary\n" ;
        cout << data.Num << '\t' << data.Name << '\t' << data.Type1 << '\t' << data.Type2 << '\t'  << data.Total << '\t' << data.HP << '\t' << data.Attack << '\t' << data.Defense << data.Sp_Atk << '\t'  << data.Sp_Def << '\t' << data.Speed << '\t'  << data.Generation << '\t' << data.Legendary << '\t'  << '\n' ;
        bst->item.pop_back() ;

        if ( bst->leftChildPtr != NULL && bst->rightChildPtr != NULL ) {
            cout << "case1" << '\n' ;
            DELETE_CASE1(bst) ;
        }
        else if ( bst->leftChildPtr == NULL && bst->rightChildPtr == NULL ) {
            cout << "case2" << '\n' ;
            DELETE_CASE2(bst) ;
        }
        else {
            cout << "case3" << '\n' ;
            DELETE_CASE3(bst) ;
        }

    }
    }

}

void BST::DELETE_CASE1( BstNode*& bst ) {

    // find inorder_successor
    BstNode* temp = bst , *pre_temp = NULL ;
    temp = temp->rightChildPtr ;
    while ( temp != NULL ) {
        pre_temp = temp ;
        temp = temp->leftChildPtr ;
    }

    bst->item = pre_temp->item ;
    bst->key = pre_temp->key ;

    if ( pre_temp->leftChildPtr != NULL ) {
        pre_temp->item = pre_temp->rightChildPtr->item ;
        pre_temp->key = pre_temp->rightChildPtr->key ;
        BstNode* target = pre_temp->rightChildPtr ;
        pre_temp->rightChildPtr = NULL ;
        delete target ;
    }
    else {
        BstNode* target = pre_temp ;
        pre_temp = NULL ;
        delete target ;
    }

}

void BST::DELETE_CASE2( BstNode*& bst ) {

    BstNode*& target = Find( root, bst ) ;
    BstNode* temp = target ;
    target = NULL ;
    delete temp ;

}

void BST::DELETE_CASE3( BstNode*& bst ) {

    if ( bst->leftChildPtr != NULL ) {
        BstNode*& target = Find( root, bst ) ;
        BstNode* temp = target ;
        target = target->leftChildPtr ;
        delete temp ;
    }
    else {
        BstNode*& target = Find( root, bst ) ;
        BstNode* temp = target ;
        target = target->rightChildPtr ;
        delete temp ;
    }

}

BstNode*& BST::Find( BstNode*& parent, BstNode* target ) {

    if ( parent == NULL ) return parent ;
    else if ( StringProccess::StrToInt(parent->key) == StringProccess::StrToInt(target->key) ) return parent ;
    else if ( StringProccess::StrToInt(parent->key) < StringProccess::StrToInt(target->key) ) return Find( parent->rightChildPtr, target ) ;
    else Find( parent->leftChildPtr, target ) ;

}

void BST::Find_Max( BstNode* bst, BstNode*& target) {

    if ( bst != NULL ) {
        target = bst ;
        Find_Max( bst->rightChildPtr, target ) ;
    }

}

BstNode* BST::Find_Max() {

    BstNode *target = NULL ;
    Find_Max( root, target ) ;
    return target ;

}

void BST::clear_bst( BstNode* &bst ) {

    if ( bst != NULL ) {

        clear_bst( bst->leftChildPtr ) ;
        clear_bst( bst->rightChildPtr ) ;
        delete bst ;
        bst = NULL ;

    }

}

bool BST::isEmpty() {

    if ( root == NULL ) return true ;

    return false ;

}

void BST::Screen_BY_KEY( string key ) {

    Screen( key, root ) ;
    numOfData = 1 ;

}

void BST::Screen( string key, BstNode* bst ) {

    if ( bst != NULL ) {

        Screen( key, bst->rightChildPtr ) ;

        if ( StringProccess::StrToInt( bst->key ) >= StringProccess::StrToInt(key) ) {
            print( bst->item ) ;

        }
        Screen( key, bst->leftChildPtr ) ;

    }

}

void BST::print( vector<pokemo> data ) {

    int i = 0 ;
    while ( i < data.size() ) {

        cout << "[" << numOfData << "]"<< '\t' << data.at(i).Num << '\t' << data.at(i).Name << '\t' << data.at(i).Type1 << '\t' << data.at(i).Total << '\t' << data.at(i).HP << '\t' << data.at(i).Attack << '\t' << data.at(i).Defense << '\n' ;
        numOfData++ ;
        i++ ;
    }

}

int BST::find_hight( BstNode* bst ) {

    if ( bst == NULL ) return -1 ;
    return 1 + max(find_hight(bst->leftChildPtr), find_hight(bst->rightChildPtr));
}

int BST::findHeight() {

    int hight = find_hight( root ) ;
    return hight + 1 ;

}

void BST::Insert( BstNode* &bst,BstNode *ptr ) {

    if(bst==NULL) bst = ptr;
    else if(StringProccess::StrToInt(bst->key) > StringProccess::StrToInt(ptr->key)) Insert(bst->leftChildPtr,ptr);
    else Insert(bst->rightChildPtr,ptr);

}

void BST::Insert( pokemo data ) {

    BstNode* position = root, *pre_position = NULL ;

    while ( position != NULL ) {

        pre_position = position ;
        if ( StringProccess::StrToInt(position->key) > StringProccess::StrToInt(data.HP) ) position = position->leftChildPtr ;
        else if ( StringProccess::StrToInt(position->key) == StringProccess::StrToInt(data.HP) ) position = NULL ;
        else position = position->rightChildPtr ;

    }

    if ( root == NULL ) {

        BstNode* temp = new BstNode ;
        temp->item.push_back( data ) ;
        temp->key = data.HP ;
        temp->leftChildPtr = NULL ;
        temp->rightChildPtr = NULL ;
        root = temp ;

    }
    else if ( StringProccess::StrToInt(pre_position->key) > StringProccess::StrToInt(data.HP) ) {
        BstNode* temp = new BstNode ;
        temp->item.push_back( data ) ;
        temp->key = data.HP ;
        temp->leftChildPtr = NULL ;
        temp->rightChildPtr = NULL ;
        pre_position->leftChildPtr = temp ;
    }
    else if ( StringProccess::StrToInt(pre_position->key) == StringProccess::StrToInt(data.HP) ) pre_position->item.push_back( data ) ;
    else {
        BstNode* temp = new BstNode ;
        temp->item.push_back( data ) ;
        temp->key = data.HP ;
        temp->leftChildPtr = NULL ;
        temp->rightChildPtr = NULL ;
        pre_position->rightChildPtr = temp ;
    }

}

void BST::CreatBST() {

    string temp ;
	fstream file ;
	file.open(temp.c_str(), ios_base::in) ;

	while ( !file.is_open() ) {
		cout << "plz enter a complete file name or file number to create BST of it [0 : quit] : " ;
		cin >>temp ;

        if ( temp.compare( "0" ) == 0 ) return ;
		else if ( ComfirmType::isInt(temp) ) temp = "input" + temp + ".txt" ;
		// 辨識temp是否為數字字串，如果是，就做處理
		// else 就是輸入完整檔案的情況
		file.open(temp.c_str(), ios_base::in) ;
		if ( !file.is_open() ) cout << "oops, there is no such file !" ;

	}


	getline(file, temp ) ; // 讀掉不需要的input



	while ( getline(file, temp ) ) {

        if ( numOfData == 1 ) cout << "\t#\tName\t\tType 1\tHP\tAttack\tDefense\n" ;
        pokemo data ;
        data.Num = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Name = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Type1 = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Type2 = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Total = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.HP = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Attack = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Defense = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Sp_Atk = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Sp_Def = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Speed = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Generation = StringProccess::getNextToken( temp ) ;
        temp = temp.substr( 1, string::npos ) ;
        data.Legendary = StringProccess::getNextToken( temp ) ;

        cout << "[" << numOfData << "]" << "\t" << data.Num << "\t" << data.Name << "\t" << data.Type1 << "\t"<< data.HP << "\t" << data.Attack << "\t" << data.Defense << "\n" ;
        numOfData = numOfData + 1 ;
        Insert( data ) ;

	}

    numOfData = 1 ;
}

void BST::inorderTraverse() {

    traverse( root ) ;
}

void BST::traverse( BstNode* data ) {

    if ( data != NULL ) {

        traverse( data->leftChildPtr ) ;
        cout << data->key << '\n' ;
        traverse( data->rightChildPtr ) ;

    }


}

bool ComfirmType::isInt(string str) {

	int i = 0 ;

	while (i < str.size()) {
		if( isdigit(str.at(i)) ) i++ ;
		else return false ;
	}

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

string StringProccess::getNextToken( string &str) { //  紀錄token之後，將其從字串中切掉

	string temp = "" ;

    while ( str.at(0) != '\t' && str.length() > 1 ) {

        temp = temp + str.at(0) ;
        str = str.substr(1,string::npos) ;
    }

    if ( str.at(0) != ' ' &&  str.at(0) != '\t' ) temp = temp + str.at(0) ; // 最後一個元素


	return temp ;

}
