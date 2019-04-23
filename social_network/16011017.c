#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define TRUE 1
#define FALSE 0

typedef struct NODE {
	int id;
	char* name_surname;
	int* friends;
	struct NODE* left;
	struct NODE* right;
}NODE;

//Menu functions
char showMenu();
void handleMenu(char c);
void handleOperationA();
void handleOperationB();
void handleOperationC();
void handleOperationD();
void handleOperationE();
void handleOperationF();
void handleOperationG();
void handleOperationH();
void handleExit();

//Main functions
NODE* insertNewUser(NODE* root, NODE* node);
int deleteUser(NODE** pointerToRoot, int id);
NODE* contains(NODE* root, int id);
void friends(int id);
int size(NODE* root);
int printNext(int id);
void printGreater(NODE* root);
void printInOrder(NODE* root);

//Utility functions
NODE* findNode(const NODE** pointerToRoot, int id);
NODE* findMax(const NODE** pointerToRoot);
NODE* createNode(char** arr);
char** parseString(char* str, char delimiter);
char* removeSpaceCharacter(char* str);
char* getInput();
int insertFromFile();
int insertOneByOne();

NODE* ROOT;

int main() {

	ROOT = NULL;
	handleMenu(showMenu());

	return 0;
}

char showMenu() {

	char* input;

	do {
		system("cls");
		printf("\nSelect an operation then press enter \n[type exit to terminate the program]\n");
		printf("----------------------------------\n");
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			"a. InsertNewUser",
			"b. DeleteUser",
			"c. Contains",
			"d. Friends",
			"e. Size",
			"f. PrintNext",
			"g. PrintGreater",
			"h. PrintInOrder");
		input = getInput();
	} while (strcmp(input, "a") != 0 &&
		strcmp(input, "b") != 0 &&
		strcmp(input, "c") != 0 &&
		strcmp(input, "d") != 0 &&
		strcmp(input, "e") != 0 &&
		strcmp(input, "f") != 0 &&
		strcmp(input, "g") != 0 &&
		strcmp(input, "h") != 0 &&
		strcmp(input, "exit") != 0);

	return strcmp(input, "exit") != 0 ? input[0] : 'x';

}

void handleMenu(char c) {
	switch (c)
	{
	case 'a':
		handleOperationA();
		break;
	case 'b':
		handleOperationB();
		break;
	case 'c':
		handleOperationC();
		break;
	case 'd':
		handleOperationD();
		break;
	case 'e':
		handleOperationE();
		break;
	case 'f':
		handleOperationF();
		break;
	case 'g':
		handleOperationG();
		break;
	case 'h':
		handleOperationH();
		break;
	case 'x':
		handleExit();
		break;
	}
}

void handleOperationA() {

	char* input;
	do {
		system("cls");
		printf("\nHow do you want to insert the user(s)?\n");
		printf("%s\n",
			"[type back to go to the previous screen]");
		printf("-----------------------------------------\n");
		printf("%s\n%s\n",
			"a. From a file (*.txt)",
			"b. One by one");

		input = getInput();
	} while (strcmp(input, "a") != 0 &&
		strcmp(input, "b") != 0 &&
		strcmp(input, "back") != 0);

	if (strcmp(input, "back") == 0)
		input[0] = '<';

	switch (input[0])
	{
	case 'a':
		insertFromFile();
		break;
	case 'b':
		insertOneByOne();
		break;
	case '<':
		handleMenu(showMenu());
		break;
	}

}

void handleOperationB() {

	system("cls");
	printf("\nPlease, enter the id of the user that will be deleted!\n");
	printf("%s\n%s\n",
		"[type home to go to the home screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");

	char* input = getInput();
	while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//
		if (deleteUser(&ROOT, atoi(input)))
			printf("User was deleted successfully!\n");
		else
			printf("User not found!\n");
		//

		input = getInput();
	}

	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		system("exit");
		break;
	}


}
void handleOperationC() {

	system("cls");
	printf("\nType the id number of the user to check him/her whether exists or not\n");
	printf("%s\n%s\n",
		"[type home to go to the home screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");

	char* input = getInput();
	char operation[MAX_SIZE];
	while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//
		NODE* node = contains(ROOT, atoi(input));
		if (node == NULL)
			printf("User not found!\n");
		else
			printf("%s\n", node->name_surname);
		//

		input = getInput();
	}

	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}

}


void handleOperationD() {
	system("cls");
	printf("\nWhich user's friends do you want to see? Please, enter an user id\n");
	printf("%s\n%s\n",
		"[type home to go to the home screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");

	char* input = getInput();
	while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//
		friends(atoi(input));
		//

		input = getInput();
	}

	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}
}
void handleOperationE() {

	char* input;
	do {
		system("cls");
		printf("\n%s\n%s\n",
			"[type home to go to the home screen]",
			"[type exit to terminate the program]");
		printf("-----------------------------------------\n");

		//
		printf("The size of the tree is %d.\n", size(ROOT));
		//

		input = getInput();
	} while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0);


	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}


}
void handleOperationF() {

	system("cls");
	printf("%s\n%s\n",
		"[type home to go to the home screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");

	char* input = getInput();
	while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//
		if (printNext(atoi(input)) == FALSE)
			printf("User not found!\n");
		//

		input = getInput();
	}

	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}


}
void handleOperationG() {

	system("cls");
	printf("%s\n%s\n",
		"[type home to go to the home screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");

	char* input = getInput();
	while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//
		NODE* node = contains(ROOT, atoi(input));
		if (node != NULL) {
			printGreater(node->right);
			printf("\n");
		}
		else {
			printf("User not found!\n");
		}
		//

		input = getInput();
	}

	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		system("exit");
		break;
	}


}
void handleOperationH() {

	char* input;
	do {
		system("cls");
		printf("\n%s\n%s\n",
			"[type home to go to the home screen]",
			"[type exit to terminate the program]");
		printf("-----------------------------------------\n");

		//
		printInOrder(ROOT);
		//

		input = getInput();
	} while (strcmp(input, "home") != 0 && strcmp(input, "exit") != 0);


	switch (input[0])
	{
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}


}
void handleExit() {
	system("exit");

}

int insertFromFile() {

	system("cls");
	printf("\nDrag and drop the file (*.txt)\n");
	printf("%s\n%s\n%s\n",
		"[type home to go to the home screen!]",
		"[type back to go to the previous screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");

	char* input = getInput();
	while (strcmp(input, "back") != 0 && strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//***
		//to remove the double quotes that are added the string when drops the file
		if (input[0] == '"' && input[strlen(input) - 1] == '"')
		{
			input++;
			input[strlen(input) - 1] = '\0';
		}

		FILE* fp = fopen(input, "r");
		if (fp == NULL) {
			printf("Unable to open the file, try again!\n");
			return FALSE;
		}
		else {

			char* temp = (int*)malloc(sizeof(char) * MAX_SIZE);
			while (fgets(temp, MAX_SIZE, fp)) {
				if (isNumber(temp[0])) {
					//Let's rid of /n coming from fgets
					temp[strlen(temp) - 1] = '\0';

					char** arr = parseString(temp, ',');
					printf("\n%s-%s was added successfully!", arr[0], arr[1]);
					NODE* node = createNode(arr);
					ROOT = insertNewUser(ROOT, node);
					temp = (int*)malloc(sizeof(char) * MAX_SIZE);

				}

			}
			printf("\n");
			fclose(fp);
			//***

			input = getInput();

		}
	}

	switch (*input)
	{
	case 'b':
		handleOperationA();
		break;
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}

	return TRUE;

}

int insertOneByOne() {
	system("cls");
	printf("\nType an input <ID,name surname,friendID1-friendID2-friendID3-....-friendIDN> \n");
	printf("%s\n%s\n%s\n",
		"[type home to go to the home screen!]",
		"[type back to go to the previous screen]",
		"[type exit to terminate the program]");
	printf("-----------------------------------------\n");



	char* input = getInput();
	while (strcmp(input, "back") != 0 && strcmp(input, "home") != 0 && strcmp(input, "exit") != 0) {

		//***
		char** arr = parseString(input, ',');
		NODE* node = createNode(arr);

		ROOT = insertNewUser(ROOT, node);
		printf("User was added successfully!\n");
		//***

		input = getInput();
	}

	switch (*input)
	{
	case 'b':
		handleOperationA();
		break;
	case 'h':
		handleMenu(showMenu());
		break;
	case 'e':
		handleExit();
		break;
	}

	return TRUE;

}
/**
*	breaks the given string into a series of tokens using the delimiter
*	@param char* str a string that will be parsed
*	@param char delimiter a single delimiter
*	@return car** an array of the tokens
*/

char** parseString(char* str, char delimiter) {

	int j = 0; // to keep track the index of the token array
	int len = strlen(str);

	char** arr = (char**)malloc(sizeof(char*));
	if (arr == NULL) {
		printf("An error has occured!");
		system("exit");
	}

	arr[j] = str; //first token
	while (*str != '\0') {
		while (*str != '\0' && *str != delimiter)
			++str;

		if (*str == delimiter) {
			arr = (char**)realloc(arr, sizeof(char*) * (++j + 1));
			if (arr == NULL) {
				printf("An error has occurred!");
				system("exit");
			}

			arr[j] = str + 1;
			*str = '\0';
			str = arr[j];
		}

	}

	arr[++j] = NULL; 

	//remove space characters that could exist at the begin or end of the string
	int i = 0;
	while (arr[i] != NULL) {
		arr[i] = removeSpaceCharacter(arr[i]);
		i++;
	}

	return arr;

}

int size(NODE* root) {
	if (root == NULL)
		return 0;
	else
		return size(root->left) + size(root->right) + 1;
}



void friends(int id) {
	NODE* node = contains(ROOT, id);
	if (node == NULL) {
		printf("User not found!\n");
	}
	else {
		printf("\nThe friend list of %s in the tree :\n--\n", node->name_surname);
		int i = 0;
		while (node->friends[i] != INT_MIN) {
			NODE* dummy = contains(ROOT, node->friends[i]);
			if (contains != NULL) {
				printf("%s\n", dummy->name_surname);
			}
			i++;
		}
	}
}


//This is a simple solution to prevent the crash of the program whenever it encounters the empty line
int isNumber(char c) {
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return TRUE;
	else
		return FALSE;
}

NODE* contains(NODE* root, int id) {

	if (root == NULL) {
		return NULL;
	}
	else if (root->id == id) {
		return root;
	}
	else if (root->id < id) {
		return contains(root->right, id);
	}
	else {
		//root->id > id
		return contains(root->left, id);
	}

}

void printGreater(NODE* root) {
	if (root != NULL) {
		printInOrder(root->left);
		printf("%d %s\n", root->id, root->name_surname);
		printInOrder(root->right);
	}
}


void printInOrder(NODE* root) {

	if (root != NULL) {
		printInOrder(root->left);
		printf("%d %s\n", root->id, root->name_surname);
		printInOrder(root->right);
	}
}

NODE* insertNewUser(NODE* root, NODE* node) {

	if (root == NULL) {
		root = node;
	}
	else if (root->id > node->id) {
		root->left = insertNewUser(root->left, node);
	}
	else {
		//(root->id <= node->id)
		root->right = insertNewUser(root->right, node);
	}

	return root;
}

char* getInput() {

	//if the user does not give any input, we will want it again
	char* temp;
	do {
		temp = (char*)malloc(sizeof(char) * MAX_SIZE);
		fgets(temp, MAX_SIZE, stdin);
	} while (!strcmp(temp, "\n"));

	//remove the newline chracter 
	int len = strlen(temp);
	if ((len > 0) && (temp[len - 1] == '\n')) {
		temp[len - 1] = '\0';
	}

	temp = removeSpaceCharacter(temp);

	//let's dispose of unused space
	char* expression = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
	int i = 0;
	while (temp[i] != '\0') {
		expression[i] = temp[i];
		i++;
	}

	expression[i] = '\0';

	return expression;
}

char* removeSpaceCharacter(char* str) {

	//remove space characters that could exist at the begin or end of the string
	int len = strlen(str);
	while (str[--len] == ' ')
		str[len] = '\0';

	while (*str == ' ')
		str++;

	return str;

}


/**
*	Creates a node by using a token arr
*	char** arr an array of the tokens
*	@return NODE* the address of the created node
*/
NODE* createNode(char** arr) {

	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->id = atoi(arr[0]);
	node->name_surname = arr[1];
	node->left = NULL;
	node->right = NULL;
	node->friends = (int*)malloc(sizeof(int));

	int i = 0;
	if (arr[2] != NULL) {
		char** friendIDs = parseString(arr[2], '-');
		while (friendIDs[i] != NULL) {
			node->friends = (int*)realloc(node->friends, sizeof(int) * (i + 1));
			node->friends[i] = atoi(friendIDs[i]);
			i++;
		}



	}

	//to show the end of the friends array
	node->friends[i] = INT_MIN;

	return node;
}

int printNext(int id) {

	NODE* node = contains(ROOT, id);
	if (node != NULL) {
		printInOrder(node->left);
		printInOrder(node->right);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int deleteUser(NODE** pointerToRoot, int id) {

	NODE** delNode = findNode(pointerToRoot, id);

	if (delNode == NULL)	//If the node that wanted to delete does not exist in the tree
		return FALSE;

	if ((*delNode) == NULL) {
		return FALSE;
	}
	else if ((*delNode)->left == NULL && (*delNode)->right == NULL) {
		NODE* temp = *delNode;
		*delNode = NULL;
		free(temp);
		return TRUE;
	}
	else if ((*delNode)->left == NULL) {
		NODE* temp = *delNode;
		*delNode = (*delNode)->right;
		free(temp);
		return TRUE;
	}
	else if ((*delNode)->right == NULL) {
		NODE* temp = *delNode;
		*delNode = (*delNode)->left;
		free(temp);
		return TRUE;
	}
	else {
		//(*delNode)->left != NULL && (*delNode)->right != NULL
		NODE** maxNode = findMax(&(*delNode)->left);

		(*delNode)->id = (*maxNode)->id;
		(*delNode)->friends = (*maxNode)->friends;
		(*delNode)->name_surname = (*maxNode)->name_surname;

		deleteUser(&(*delNode)->left, (*maxNode)->id);
	}

}

NODE* findNode(const NODE** pointerToRoot, int id) {

	if ((*pointerToRoot) == NULL) {
		return NULL;
	}
	else if ((*pointerToRoot)->id < id) {
		return findNode(&(*pointerToRoot)->right, id);
	}
	else if ((*pointerToRoot)->id > id) {
		return findNode(&(*pointerToRoot)->left, id);
	}
	else {
		//(*pointerToRoot)->data = data
		return pointerToRoot;
	}

}


NODE* findMax(const NODE** pointerToRoot) {

	if ((*pointerToRoot) == NULL) {
		printf("An error has occurred!");
		exit(0);
	}
	else if ((*pointerToRoot)->right == NULL) {
		return pointerToRoot;
	}
	else {
		return findMax(&(*pointerToRoot)->right);
	}

}
