#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdio.h>

typedef struct listSymbol {
    char name[220];
    char type[220];
    char value[220];
    int length;
    struct listSymbol* next;
} symbolNode;

symbolNode* symbolTable;
symbolNode* insert();
symbolNode* findSymbol();
void putTypeIdentifierOnSymbolTable();
void concatenate();
void removeChar();
void saveTable();

symbolNode* insert(char* value) {
    symbolNode* foundNode = findSymbol(value);
    if (foundNode != NULL) {
        return foundNode;
    }
    
    symbolNode* node = (symbolNode*) malloc(sizeof(symbolNode));
    int len = strlen(value);
    char* valueToInsert = (char*) malloc(len+1);
    strcpy(valueToInsert, value);
    
    // Is it a string constant?
    int isConstant = 0;
    if (valueToInsert[0] == '"') {
        removeChar(valueToInsert, '"');
        node->length = strlen(valueToInsert);
        isConstant = 1;
        strcpy(node->type, "STRING_CTE");
        // Is it a float constant?
    } else if (strchr(valueToInsert, '.') != NULL) {
        isConstant = 1;
        strcpy(node->type, "FLOAT_CTE");
        // Is it a integer constant?
    } else if (isdigit(valueToInsert[0]) != 0) {
        isConstant = 1;
        strcpy(node->type, "INTEGER_CTE");        
    }
    
    if (isConstant == 1) {
        strcpy(node->name, "");
        node->name[0] = '_' ;
        concatenate(node->name, valueToInsert);
    } else {
        strcpy(node->name, valueToInsert);
    }

    if (isConstant == 1) {
        strcpy(node->value, valueToInsert);
    }

    node->next = symbolTable;
    symbolTable = node;
    return node;
}

void saveTable() {
    FILE *file = fopen("ts.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    symbolNode* current = symbolTable;
    fprintf(file, "NOMBRE\tTIPODATO\tVALOR\tLONGITUD\n");
    while(current != NULL) {
        fprintf(file, "%s\t%s\t%s\t%d\n", current->name, current->type, current->value, current->length);
        current = current->next;
    }
    fclose(file);
}

void concatenate(char* original, char* add) {
    original++;     
    while(*add){
        *original = *add;
        add++;
        original++;
    }
    *original = '\0';
}

void removeChar(char *s, int c){ 
    int j, n = strlen(s); 
    int i;
    for (i=j=0; i<n; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        } 
    } 
    s[j] = '\0'; 
}

symbolNode* findSymbol(char* value) {
    symbolNode* tableNode = symbolTable;
    while(tableNode != NULL){
        if ((tableNode->value != NULL && strcmp(value, tableNode->value) == 0) || (strcmp(value, tableNode->name) == 0)) {
            return tableNode;
        }
        tableNode = tableNode->next;
    }
    return NULL;
}