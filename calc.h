/*
 *	calc.h
 */ 
 
 
 /*
 *  This struct holds the information of the input and output numbers
 */
struct number {
	char *num;
	char type;
	int isNeg;
}num1,num2,res;

 
 char *reverse(char *str);
 char getRem(int rem);
 char *kylesitoa(int num);
 char *addZeros(char *bin,int zeroCount);
 char *removeZeros(char *num);
 int power(int base, int exponent);
 char *flip(char *num);
 char *octalToBinary(char *num);
 char *decimalToBinary(char *num);
 char *hexToBinary(char *num);
 char *binaryToOctal(char *num);
 char *binaryToDecimal(char *num);
 char *binaryToHex(char *num);
 char *addBin(char *bin1, char *bin2);
 char *subBin(char *bin1, char *bin2);
 int isBinary(char *num);
 int isOctal(char *num);
 int isDecimal(char *num);
 int isHex(char *num);