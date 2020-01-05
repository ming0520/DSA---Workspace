
class List{

INITIALIZE  first SET TO 0, free SET TO 0, mySize SET TO -1, myBack SET TO 0

class Node{
public:
INITIALIZE Data
INITIALIZE Next SET TO -1
}

public:
Node myList[CAPACITY]
/*----------------------------------------------------------------------
Purpose: Construct a list
Precondition: None
Postcondition: An empty list Constructed
-----------------------------------------------------------------------*/
List(void){
INITIALIZE  i SET TO 0
WHILE i LESS THAN CAPACITY - 1
	MY myList[i].Data SET TO '\0'
	MY myList[i].Next SET TO i+1
	i INCREASE BY 1
END WHILE
MY myList[i].Next SET TO -1
}

/*----------------------------------------------------------------------
Purpose: Initialize the list
Precondition: none
Postcondition: Preset data inserted into the list
-----------------------------------------------------------------------*/
void Initialize(void){
INITIALIZE data[] SET TO {'J','Z','C','P','B','M','K','Q','?','?'}
INITIALIZE next[] SET TO {3,6,0,-1,2,1,7,8,9,-1}

INITIALIZE  i SET TO 0
WHILE i LESS THAN 10
	MY myList[i].Data SET TO data[i]
	MY myList[i].Next SET TO next[i]
	i INCREASE BY 1
END WHILE
first SET TO 4, free SET TO 5, mySize SET TO 4, myBack SET TO 3

}
/*----------------------------------------------------------------------
Purpose: Check if a list is empty.

Precondition:  None
Postcondition: true is returned if the list is empty,
	false if not.
-----------------------------------------------------------------------*/
bool Empty(void){
RETURN(mySize IS EQUAL -1)
}
/*----------------------------------------------------------------------
Purpose: Check if a list is full

Precondition:  None
Postcondition: true is returned if the list is full,
	false if not.
-----------------------------------------------------------------------*/
bool Full(void){
RETURN (MY mySize IS EQUAL CAPACITY - 1)
}
/*----------------------------------------------------------------------
Purpose: Display all the element in list.

Precondition:  None
Postcondition: all element displayed
-----------------------------------------------------------------------*/
void DisplayElement(void){
DISPLAY "Node\tData\tNext\n")
INITIALIZE  counter SET TO 0

INITIALIZE  i SET TO 0
WHILE  i LESS THAN CAPACITY
	DISPLAY "%i\t%c\t%i\n",counter,MY myList[i].Data,MY myList[i].Next)
	counter INCREASE BY 1
	i INCREASE BY 1
END WHILE
}
/*----------------------------------------------------------------------
Purpose: Display a list.

Precondition:  None
Postcondition: A list displayed
-----------------------------------------------------------------------*/
void Display(void){
IF MY Empty()
	DISPLAY "List is empty!"
	RETURN
END IF
DISPLAY "Node\tData\tNext\n")
INITIALIZE  i SET TO MY first
WHILE i NOT EQUAL -1
	DISPLAY "%i\t%c\t%i\n",i,MY myList[i].Data,MY myList[i].Next)
		i SET TO MY myList[i].Next
END WHILE
}
/*----------------------------------------------------------------------
Purpose: Insert a value into the list

Precondition:  item is the value to be inserted
Postcondition: item has been inserted into the list
-----------------------------------------------------------------------*/
void Insert (char data){
IF MY Full()){
	DISPLAY "List is full!"
	RETURN
END IF
IF MY first IS EQUAL -1
	MY first SET TO free
	MY myList[MY free].Data SET TO data
ELSE
	MY myList[MY free].Data SET TO data
	MY myList[MY myBack].Next SET TO free

END IF
MY myBack SET TO free
MY free SET TO MY myList[MY free].Next
MY myList[MY myBack].Next SET TO -1
MY mySize INCREASE BY 1


}
/*----------------------------------------------------------------------
Purpose: Display variable used in class and value of it

Precondition:  None
Postcondition: variable used in class and value of it displayed
-----------------------------------------------------------------------*/
void DisplayInfo(void){
DISPLAY "First: " AND first AND " Free: " AND free AND " myBack: " AND myBack
		AND " mySize " AND mySize
}
/*----------------------------------------------------------------------
Purpose: Count number or node

Precondition:  None
Postcondition: RETURN counter
-----------------------------------------------------------------------*/
int  CountNode(void){
INITIALIZE  counter SET TO 0
	INITIALIZE  i SET TO MY first
WHILE i NOT EQUAL -1
	counter  INCREASE BY 1
		i SET TO MY myList[i].Next
END WHILE
RETURN counter
}
/*----------------------------------------------------------------------
Purpose: Check list is in ascending order

Precondition:  None
Postcondition: RETURN true when list is in asc order otherwise
-----------------------------------------------------------------------*/
bool isAsc(void){
INITIALIZE ptr SET TO MY first
WHILE MY myList[ptr].Next NOT EQUAL -1
	INITIALIZE data SET TO MY myList[ptr].Data
	INITIALIZE nextData SET TO MY myList[MY myList[ptr].Next].Data
	IF data GREATER THAN nextData
		RETURN false
	END IF
	ptr SET TO MY myList[ptr].Next
END WHILE
RETURN true
}
/*----------------------------------------------------------------------
Purpose: Remove a value from the list at a given value

Precondition:  The list is not empty
Postcondition: element at the position determined by pos has been
	removed (provided pos is a legal value).
----------------------------------------------------------------------*/
void Delete (char data){
IF MY Empty()){
	DISPLAY "List is empty!"
	RETURN
INITIALIZE  prev SET TO MY first
INITIALIZE  i SET TO MY myList[prev].Next

IF MY myList[prev].Data IS EQUAL data
	MY first SET TO i
	MY myList[prev].Data SET TO '\0'
	MY myList[prev].Next SET TO free
	free SET TO prev
	MY mySize SET TO -1
	RETURN
END IF

WHILE  i NOT EQUAL -1
	IF MY myList[i].Data IS EQUAL data
		MY myList[prev].Next SET TO MY myList[i].Next
		MY myList[i].Data SET TO '\0'
		MY myList[i].Next SET TO MY free
		MY free SET TO i
		MY mySize--
		break
	END IF
	prev SET TO MY myList[prev].Next
	i SET TO MY myList[i].Next
END WHILE
}
/*----------------------------------------------------------------------
Purpose: Arrange the list in ascending order

Precondition:  None
Postcondition: List in ascending order
-----------------------------------------------------------------------*/
void Asc(){
IF MY isAsc() IS EQUAL true
	RETURN
END IF

INITIALIZE  ptr SET TO MY first

WHILE MY myList[ptr].Next NOT EQUAL -1
		INITIALIZE temp, curr, next
		curr SET TO MY myList[ptr].Data
		next SET TO MY myList[MY myList[ptr].Next].Data
		IF curr GREATER THAN next
			temp SET TO curr
			curr SET TO next
			next SET TO temp
			MY myList[ptr].Data SET TO curr
			MY myList[MY myList[ptr].Next].Data SET TO next
		END IF
		ptr SET TO MY myList[ptr].Next
END WHILE

IF MY isAsc() IS EQUAL false
	MY Asc()
END IF
}
/*----------------------------------------------------------------------
Purpose: Display a break line

Precondition:  None
Postcondition: A breakline displayed
----------------------------------------------------------------------*/
void BreakLine(){
DISPLAY ("---------------Break Line---------------------")
}
}

INITIALIZE  main() {
List l
l.Initialize()


DISPLAY "Question 3 a"
l.DisplayElement()
l.BreakLine()


DISPLAY "Question 3 b"
l.Display()
l.BreakLine()


DISPLAY "Question 3 c"
l.Insert('F')
l.Display()
l.DisplayInfo()
l.BreakLine()


DISPLAY "Question 3 d"
DISPLAY "Delete J,P,C,B"
l.Delete('J')
l.Delete('P')
l.Delete('C')
l.Delete('B')

DISPLAY "Question 3 e"
DISPLAY "Insert A, Delete P, Insert K, Delete C"

l.Insert('A')
l.Delete('P')
l.Insert('K')
l.Delete('C')
l.Display()
l.BreakLine()

DISPLAY "Question 3 f"
DISPLAY "Node count: " AND l.CountNode() ANDendl
l.BreakLine()


DISPLAY "Question 3 g"
IF l.isAsc() IS EQUAL true){
DISPLAY "Is ascending order"
}
ELSE
DISPLAY "Not ascending order"
}
l.BreakLine()

DISPLAY "After arrange" ANDendl
l.Asc()
l.Display()
IF l.isAsc() IS EQUAL true){
DISPLAY "Is ascending order"
}
ELSE
DISPLAY "Not ascending order"
}
}
