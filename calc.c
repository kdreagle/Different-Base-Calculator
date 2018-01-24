/*
 *	calc.c
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>
#include "calc.h"


/*
 *	This function returns a reversed string
 */  
char *reverse(char *str){
	int i;
	char *rev;
	rev = (char*)malloc(sizeof(char)*strlen(str));
	for (i = 0; i < strlen(str);i++)
		rev[i] = str[strlen(str)-i-1];
	rev[strlen(str)] = '\0';
	return rev;
}

/*
 *  This funtion takes an int and turns it into a char
 *  I also just realized I could have just used the intToChar
 *  function that was given in class instead :(
 *  I only made this function to save space in my itoa fucntion
 *  - rem stands for remainder
 */ 
char getRem(int rem) {
	char c;
	switch(rem) {
		case 0:
			c='0'; break;
		case 1:
			c='1'; break;
		case 2:
			c='2'; break;
		case 3:
			c='3'; break;
		case 4:
			c='4'; break;
		case 5:
			c='5'; break;
		case 6:
			c='6'; break;
		case 7:
			c='7'; break;
		case 8:
			c='8'; break;
		case 9:
			c='9'; break;
	}
	return c;
}

/*
 *	The itoa function that we were given in class didn't seem to
 *  work for me. Maybe I copied it down incorrectly :(
 *  Anyways, I wrote my own itoa function. It only works on
 *  positive numbers, which is all I need.
 */ 
char *kylesitoa(int num) {
	if (num == 0)
		return "0";
	if (num == 1)
		return "1";
	char *str;
	int rem;
	int i; 
	str = (char*)malloc(sizeof(char));
	for (i = 0; num > 1; i++) {
		str = (char*)realloc(str,sizeof(char)*(strlen(str)+1));
		rem = num %10;
		num /= 10;
		str[i] = getRem(rem);
	}
	if(num >= 10) {
		rem = num % 10;
		str[strlen(str)] = getRem(rem);
	}
	if (num == 1)
		str[strlen(str)] = '1';
	str = reverse(str);
	return str;
}

/*
 *	This function adds zeros to the leftmost side of a binary number. 
 *  This function is used to make adding binary numbers easier.
 *  This function is also used to make conversion from binary to 
 *  octal and binary to hex easier.
 */ 
char *addZeros(char *bin,int zeroCount) {
	int i;
	bin = reverse(bin);
	for (i = 0; i < zeroCount; i++) {
		bin = (char*)realloc(bin,sizeof(char)*(strlen(bin)+1));
		strcat(bin,"0");
	}
	bin = reverse(bin);
	return bin;
}

/*
 *	This function removes any extra zeros on the leftmost side of a 
 *  binary number. This is just to make binary output consistent.
 */ 
char *removeZeros(char *num) {
	int i = 0;
	num = reverse(num);
	while (num[strlen(num)-i-1] != '1') {i++;}
	num[strlen(num)-i] = '\0';
	num = reverse(num);
	return num;
}

/*
 *	This function calculates the power of an integer. I know there's a 
 *  built in pow fucntion but I wanted a more simplistic function.
 */ 
int power(int base, int exponent) {
	int total;
	int i;
	total = 1;
	for (i = 0; i < exponent; i++)
		total *= base;
	return total;
}

/*
 *	This function flips the bits of a binary number, which is used for 
 *  the subtraction of binary numbers.
 */ 
char *flip(char *num){
	int i;
	for (i = 0; i < strlen(num); i++) {
		if (num[i] == '0')
			num[i] = '1';
		else
			num[i] = '0';
	}
	return num;
}


/*
 *	The next six functions are self-explanatory.
 *  binaryToOctal, binaryToHex, hexToBinary, and octalToBinary
 *  all have very similar algorithms
 */ 
char *octalToBinary(char *num) {
	int i;
	char *octal;
	octal = (char*)malloc(sizeof(char)*(strlen(num)*3+1));
	for (i = 0; i < strlen(num); i++) {
		switch (num[i]) {
			case '0':
				strcat(octal,"000"); break;
			case '1':
				strcat(octal,"001"); break;
			case '2':
				strcat(octal,"010"); break;
			case '3':
				strcat(octal,"011"); break;
			case '4':
				strcat(octal,"100"); break;
			case '5':
				strcat(octal,"101"); break;
			case '6':
				strcat(octal,"110"); break;
			case '7':
				strcat(octal,"111"); break;
		}
	}
	octal[strlen(octal)] = '\0';
	return octal;
}

char *decimalToBinary(char *num) {
	char *dec;
	dec = (char*)malloc(sizeof(char));
	int n = atoi(num);
	while (n > 1 ) {
		dec = (char*)realloc(dec,sizeof(char)*(strlen(dec)+1));
		if (n % 2 == 0)
			strcat(dec,"0");
		else 
			strcat(dec,"1");
		n /= 2;
	}
	if (n % 2 == 0)
		strcat(dec,"0");
	else 
		strcat(dec,"1");
	dec = reverse(dec);
	return dec;
}

char *hexToBinary(char *num) {
	int i;
	char *hex;
	hex = (char*)malloc(sizeof(char)*(strlen(num)*4+1));
	for (i = 0; i < strlen(num); i++) {
		switch (num[i]) {
			case '0':
				strcat(hex,"0000"); break;
			case '1':
				strcat(hex,"0001"); break;
			case '2':
				strcat(hex,"0010"); break;
			case '3':
				strcat(hex,"0011"); break;
			case '4':
				strcat(hex,"0100"); break;
			case '5':
				strcat(hex,"0101"); break;
			case '6':
				strcat(hex,"0110"); break;
			case '7':
				strcat(hex,"0111"); break;
			case '8':
				strcat(hex,"1000"); break;
			case '9':
				strcat(hex,"1001"); break;
			case 'A': case 'a':
				strcat(hex,"1010"); break;
			case 'B': case 'b':
				strcat(hex,"1011"); break;
			case 'C': case 'c':
				strcat(hex,"1100"); break;
			case 'D': case 'd':
				strcat(hex,"1101"); break;
			case 'E': case 'e':
				strcat(hex,"1110"); break;
			case 'F': case 'f':
				strcat(hex,"1111"); break;
		}
	}
	hex[strlen(hex)] = '\0';
	return hex;
}

char *binaryToOctal(char *num) {
	int pos;
	int i;
	char *octal;
	char *digit;
	digit = (char*)malloc(sizeof(char)*3);
	if (strlen(num) % 3 != 0)
		num = addZeros(num,3-strlen(num)%3);
	octal = (char*)malloc(sizeof(char)*(strlen(num)/3));
	for (pos = 0; pos < strlen(num);) {
		for(i=0;i<3;i++,pos++)
			digit[i] = num[pos];
		if (strcmp(digit,"000") == 0)
			octal[pos/3-1] = '0';
		else if (strcmp(digit,"001") == 0)
			octal[pos/3-1] = '1';
		else if (strcmp(digit,"010") == 0)
			octal[pos/3-1] = '2';
		else if (strcmp(digit,"011") == 0)
			octal[pos/3-1] = '3';
		else if (strcmp(digit,"100") == 0)
			octal[pos/3-1] = '4';
		else if (strcmp(digit,"101") == 0)
			octal[pos/3-1] = '5';
		else if (strcmp(digit,"110") == 0)
			octal[pos/3-1] = '6';
		else if (strcmp(digit,"111") == 0)
			octal[pos/3-1] = '7';
	}
	free(digit);
	return octal;
}

char *binaryToDecimal(char *num) {
	int i;
	char *digit;
	int decimal = 0;
	char * res;
	digit = (char*)malloc(sizeof(char)*2);
	res = (char*)malloc(sizeof(char)*(strlen(num)+1));
	for(i = 0; i < strlen(num); i++ ) {
		digit[0] = num[i];
		digit[1] = '\0';
		decimal += atoi(digit) * power(2,strlen(num)-i-1);
	}
	free(digit);
	res = kylesitoa(decimal);
	return res;
}

char *binaryToHex(char *num) {
	int pos;
	int i;
	char *hex;
	char *digit;
	digit = (char*)malloc(sizeof(char)*4);
	if (strlen(num) % 4 != 0)
		num = addZeros(num,4-strlen(num)%4);
	hex = (char*)malloc(sizeof(char)*(strlen(num)/4));
	for (pos = 0; pos < strlen(num);) {
		for(i=0;i<4;i++,pos++)
			digit[i] = num[pos];
		if (strcmp(digit,"0000") == 0)
			hex[pos/4-1] = '0';
		else if (strcmp(digit,"0001") == 0)
			hex[pos/4-1] = '1';
		else if (strcmp(digit,"0010") == 0)
			hex[pos/4-1] = '2';
		else if (strcmp(digit,"0011") == 0)
			hex[pos/4-1] = '3';
		else if (strcmp(digit,"0100") == 0)
			hex[pos/4-1] = '4';
		else if (strcmp(digit,"0101") == 0)
			hex[pos/4-1] = '5';
		else if (strcmp(digit,"0110") == 0)
			hex[pos/4-1] = '6';
		else if (strcmp(digit,"0111") == 0)
			hex[pos/4-1] = '7';
		else if (strcmp(digit,"1000") == 0)
			hex[pos/4-1] = '8';
		else if (strcmp(digit,"1001") == 0)
			hex[pos/4-1] = '9';
		else if (strcmp(digit,"1010") == 0)
			hex[pos/4-1] = 'a';
		else if (strcmp(digit,"1011") == 0)
			hex[pos/4-1] = 'b';
		else if (strcmp(digit,"1100") == 0)
			hex[pos/4-1] = 'c';
		else if (strcmp(digit,"1101") == 0)
			hex[pos/4-1] = 'd';
		else if (strcmp(digit,"1110") == 0)
			hex[pos/4-1] = 'e';
		else if (strcmp(digit,"1111") == 0)
			hex[pos/4-1] = 'f';
	}
	free(digit);
	return hex;
}

/*
 *	This function is also self-explanatory. Both binary numbers must be
 *  the same string length. addZeros takes care of this.
 *  The variable carry indicates if a 1 should be carried over.
 */ 
char *addBin(char *bin1, char *bin2) {
	int i;
	int carry;
	char *sum;
	sum = (char*)malloc(sizeof(char)*(strlen(bin1)+2));
	carry = 0;
	bin1 = reverse(bin1);
	bin2 = reverse(bin2);
	for (i=0; i < strlen(bin1);i++) {
		if (bin1[i] == '0' && bin2[i] == '0') {
			if (carry == 0) 
				sum[i] = '0';
			else 
				sum[i] = '1';
			carry = 0;
		} else if (bin1[i] == '0' && bin2[i] == '1') {
			if (carry == 0) {
				sum[i] = '1';
			}else {
				sum[i] = '0';
				carry = 1;
			}
		} else if (bin1[i] == '1' && bin2[i] == '0') {
			if (carry == 0) {
				sum[i] = '1';
			}else {
				sum[i] = '0';
				carry = 1;
			}
		} else if (bin1[i] == '1' && bin2[i] == '1') {
			if (carry == 0) 
				sum[i] = '0';
			else
				sum[i] = '1';
			carry = 1;
		}
	}
	if (carry == 1) {
		sum[strlen(bin1)] = '1';
		sum = reverse(sum);
		sum[strlen(bin1)+1] = '\0';
	} else {
		sum = reverse(sum);
		sum[strlen(bin1)] = '\0';
	}
	return sum;
}


/*
 *	This function subtracts two binary numbers. Both binary numbers
 *  must be the same string length. This is done using 2's complement.
 */ 
char *subBin(char *bin1, char *bin2) {
	char *diff;
	char *uno;
	diff = (char *)malloc(sizeof(char)*(strlen(bin1)+1));
	uno = "1";
	bin2 = flip(bin2);
	// uno is the bit '1' that must be added to the flipped bit
	uno = addZeros(uno,strlen(bin2)-1);
	bin2 = addBin(bin2,uno);
	// The following if/else if makes the numbers the same string length again
	if (strlen(bin1) > strlen(bin2))
		bin2 = addZeros(bin2,strlen(bin1)-strlen(bin2));
	else if (strlen(bin1) < strlen(bin2))
		bin1 = addZeros(bin1,strlen(bin2)-strlen(bin1));
	diff = addBin(bin1,bin2);
	diff = reverse(diff);
	// The following if/else cuts off any extra numbers in the resulting binary number.
	if (strlen(diff) > strlen(bin1))
		diff[strlen(bin1)] = '\0';
	else
		diff[strlen(bin1)-1] = '\0';
	diff = reverse(diff);
	return diff;
}

/*
 *	This function multiplies two binary numbers.
 */ 
char *multBin(char *bin1, char *bin2) {
	int i;
	char *prod;
	prod = (char*)malloc(sizeof(char)*(strlen(bin1)+strlen(bin2)));
	bin1 = (char*)realloc(bin1,sizeof(char)*(strlen(bin1)+strlen(bin2)));
	bin2 = reverse(bin2);
	if (bin2[0] == '0') {
		for (i = 0; i < strlen(bin1); i++)
			prod[i] = '0';
	} else if (bin2[0] == '1') {
		prod = bin1;
	}
	for (i = 1; i < strlen(bin2); i++) {
		bin1 = reverse(bin1);
		bin1 = addZeros(bin1,1);
		bin1 = reverse(bin1);
		if (bin2[i] == '1') {
			if (strlen(bin1) > strlen(prod))
				prod = addZeros(prod,strlen(bin1)-strlen(prod));
			else if (strlen(bin1) < strlen(prod))
				bin1 = addZeros(bin1,strlen(prod)-strlen(bin1));
			prod = addBin(prod,bin1);
		}
	}
	return prod;
}

/*
 *	The next four functions check if a number matches its given base
 */ 
int isBinary(char *num) {
	int i;
	for (i = 0; i < strlen(num); i++) {
		switch(num[i]) {
			case '0': break;
			case '1': break;
			default: return 0; break;
		}
	}
	return 1;
}

int isOctal(char *num) {
	int i;
	for (i = 0; i < strlen(num); i++) {
		switch(num[i]) {
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			default: return 0; break;
		}
	}
	return 1;
}

int isDecimal(char *num) {
	int i;
	for (i = 0; i < strlen(num); i++) {
		switch(num[i]) {
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			case '8': break;
			case '9': break;
			default: return 0; break;
		}
	}
	return 1;
}

int isHex(char *num) {
	int i;
	for (i = 0; i < strlen(num); i++) {
		switch(num[i]) {
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			case '8': break;
			case '9': break;
			case 'A': case 'a': break;
			case 'B': case 'b': break;
			case 'C': case 'c': break;
			case 'D': case 'd': break;
			case 'E': case 'e': break;
			case 'F': case 'f': break;
			default: return 0; break;
		}
	}
	return 1;
}

int main(int argc, char **argv) {
	
	// Checks if there are enough arguments
	if (argc != 5) {
		fprintf(stderr,"ERROR: Invalid number of arguments.\n");
		return 1;
	}
	
	char op;
	op = argv[1][0];
	
	// Checks if the operation symbol is valid
	if (op != '+' && op != '-' && op != '*') {
		fprintf(stderr,"ERROR: Invalid operation symbol.\n");
		return 1;
	}
	
	num1.num = (char *)malloc(sizeof(argv[2])*strlen(argv[2]));
	num2.num = (char *)malloc(sizeof(argv[3])*strlen(argv[3]));

	int i;
	
	// The next two if/else blocks initializes values in the struct, and handles any bases errors
	if (argv[2][0] != '-') {
		num1.isNeg = 0;
		if (argv[2][0] == 'b' || argv[2][0] == 'o' || argv[2][0] == 'x' || argv[2][0] == 'd') {
			num1.type = argv[2][0];
		} else {
			fprintf(stderr,"Invalid base.\n");
			return 1;
		}
		for (i = 0; i < strlen(argv[2])-1; i++)
			num1.num[i] = argv[2][i+1];
	} else {
		num1.isNeg = 1;
		if (argv[2][1] == 'b' || argv[2][1] == 'o' || argv[2][1] == 'x' || argv[2][1] == 'd') {
			num1.type = argv[2][1];
		} else {
			fprintf(stderr,"Invalid base.\n");
			return 1;
		}
		for (i = 0; i < strlen(argv[2])-2; i++)
			num1.num[i] = argv[2][i+2];
	}


	if (argv[3][0] != '-') {
		num2.isNeg = 0;
		if (argv[3][0] == 'b' || argv[3][0] == 'o' || argv[3][0] == 'x' || argv[3][0] == 'd') {
			num2.type = argv[3][0];
		} else {
			fprintf(stderr,"Invalid base.\n");
			return 1;
		}
		for (i = 0; i < strlen(argv[3])-1; i++)
			num2.num[i] = argv[3][i+1];
	} else {
		num2.isNeg = 1;
		if (argv[3][1] == 'b' || argv[3][1] == 'o' || argv[3][1] == 'x' || argv[3][1] == 'd') {
			num2.type = argv[3][1];
		} else {
			fprintf(stderr,"Invalid base.\n");
			return 1;
		}
		for (i = 0; i < strlen(argv[3])-2; i++)
			num2.num[i] = argv[3][i+2];
	}

	// Check if numbers match their bases
	switch (num1.type) {
		case 'b':
			if (isBinary(num1.num)) break;
			else {
				fprintf(stderr,"ERROR: First number is not binary.\n");
				return 1;
			} break;
		case 'o':
			if (isOctal(num1.num)) break;
			else {
				fprintf(stderr,"ERROR: First number is not octal.\n");
				return 1;
			} break;
		case 'd':
			if (isDecimal(num1.num)) break;
			else {
				fprintf(stderr,"ERROR: First number is not decimal.\n");
				return 1;
			} break;
		case 'x':
			if (isHex(num1.num)) break;
			else {
				fprintf(stderr,"ERROR: First number is not hexadecimal.\n");
				return 1;
			} break;
	} 
	
	switch (num2.type) {
		case 'b':
			if (isBinary(num2.num)) break;
			else {
				fprintf(stderr,"ERROR: Second number is not binary.\n");
				return 1;
			} break;
		case 'o':
			if (isOctal(num2.num)) break;
			else {
				fprintf(stderr,"ERROR: Second number is not octal.\n");
				return 1;
			} break;
		case 'd':
			if (isDecimal(num2.num)) break;
			else {
				fprintf(stderr,"ERROR: Second number is not decimal.\n");
				return 1;
			} break;
		case 'x':
			if (isHex(num2.num)) break;
			else {
				fprintf(stderr,"ERROR: Second number is not hexadecimal.\n");
				return 1;
			} break;
	} 
	
	
	// This if/else block sets the base of the result, and returns error if the output base is invalid.
	if (argv[4][0] == 'b' || argv[4][0] == 'o' || argv[4][0] == 'x' || argv[4][0] == 'd') {
		res.type = argv[4][0];
	} else {
		fprintf(stderr,"Invalid base.\n");
		return 1;
	}
	
	
	// The next two switch statements convert the inputs to binary
	switch (num1.type) {
		case 'o':
			num1.num = octalToBinary(num1.num); break;
		case 'd':
			num1.num = decimalToBinary(num1.num); break;
		case 'x':
			num1.num = hexToBinary(num1.num); break;
	}
	
	switch (num2.type) {
		case 'o':
			num2.num = octalToBinary(num2.num); break;
		case 'd':
			num2.num = decimalToBinary(num2.num); break;
		case 'x':
			num2.num = hexToBinary(num2.num); break;
	}
	
	
	// This if/else if makes both inputs the same string length
	if (strlen(num1.num) > strlen(num2.num))
		num2.num = addZeros(num2.num,strlen(num1.num)-strlen(num2.num));
	else if (strlen(num1.num) < strlen(num2.num))
		num1.num = addZeros(num1.num,strlen(num2.num)-strlen(num1.num));
	 
	// The following block of code handles all of the operations on the two binary numbers
	// The order of the operations depends on which number is larger, and which numbers are negative
	if (op == '+') {
		if (!num1.isNeg && !num2.isNeg) {
			res.num = addBin(num1.num,num2.num);
			res.isNeg = 0;
		} else if (num1.isNeg && num2.isNeg) {
			res.num = addBin(num1.num,num2.num);
			res.isNeg = 1;
		} else if (!num1.isNeg && num2.isNeg) {
			if (strcmp(num1.num,num2.num) >= 0) {
				res.num = subBin(num1.num,num2.num);
				res.isNeg = 0;
			} else {
				res.num = subBin(num2.num,num1.num);
				res.isNeg = 1;
			}
		} else if (num1.isNeg && !num2.isNeg) {
			if (strcmp(num1.num,num2.num) >= 0) {
				res.num = subBin(num1.num,num2.num);
				res.isNeg = 1;
			} else {
				res.num = subBin(num2.num,num1.num);
				res.isNeg = 0;
			}
		}
	} else if (op == '-') {
		if (!num1.isNeg && !num2.isNeg) {
			if (strcmp(num1.num,num2.num) >= 0) {
				res.num = subBin(num1.num,num2.num);
				res.isNeg = 0;
			} else {
				res.num = subBin(num2.num,num1.num);
				res.isNeg = 1;
			}
		} else if (num1.isNeg && num2.isNeg) {
			if (strcmp(num1.num,num2.num) >= 0) {
				res.num = subBin(num1.num,num2.num);
				res.isNeg = 1;
			} else {
				res.num = subBin(num2.num,num1.num);
				res.isNeg = 0;
			}
		} else if (num1.isNeg && !num2.isNeg) {
			res.num = addBin(num1.num,num2.num);
			res.isNeg = 1;
		} else if (!num1.isNeg && num2.isNeg) {
			res.num = addBin(num1.num,num2.num);
			res.isNeg = 0;
		}
	} else if (op == '*') {
		if (!num1.isNeg && !num2.isNeg)
			res.isNeg = 0;
		else if (num1.isNeg && num2.isNeg)
			res.isNeg = 0;
		else 
			res.isNeg = 1;
		res.num = multBin(num1.num,num2.num);
	}
	
	// Removes any unnecessary leftmost zeros
	res.num = removeZeros(res.num);
	
	// This converts the binary number to the appropriate output base
	switch(res.type) {
		case 'o':
			res.num = binaryToOctal(res.num); break;
		case 'd':
			res.num = binaryToDecimal(res.num); break;
		case 'x':
			res.num = binaryToHex(res.num); break;
	}
	
	// This makes the output positive zero if it wasn't already positive
	if (strcmp(res.num,"0") == 0)
		res.isNeg = 0;
	
	// Print the negative sign if negative
	if (res.isNeg)
		printf("-");
	
	// Print the result :D
	printf("%c%s\n",res.type,res.num);
	return 0;
}