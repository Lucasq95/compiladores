%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "assembler.h"

void validateAsignation();
void validateType();
void validateIdDeclaration();
void validateAsignationString();
void validateCondition();
char* changeType();

char* seen[200];
int seenIndex = 0;

int flagAsigM = 0;
int flagDeclaration = 0;

int yystopparser=0;
extern yylineno;
FILE  *yyin;
ast* tree;
%}

%token  DIGITO
%token  LETRA
%token  CHAR_ESP
%token  COMMENT
%token  ID
%token  CTE_STRING
%token  CTE_ENT
%token  CTE_REAL
%token  P_A
%token  P_C
%token  C_A
%token  C_C
%token  L_A
%token  L_C
%token  PYC
%token  PTO
%token  DPTO
%token  COMA
%token  IF
%token  ELSE
%token  ENDIF
%token  VAR
%token  ENDVAR
%token  REPEAT
%token  UNTIL
%token  PRINT
%token  READ
%token  CONST
%token  INT
%token  FLOAT
%token  STRING
%token  OP_ASIG
%token  ALL_EQUALS
%token  DO
%token  CASE
%token  ENDDO
%token  DEFAULT

%left   OP_SUMA
%left   OP_RESTA
%left   OP_MULT
%left   OP_DIV
%left   AND
%left   OR
%left   NOT
%left   OP_MAX
%left   OP_MAXEQ
%left   OP_MIN
%left   OP_MINEQ
%left   OP_NEQ
%left   OP_EQ
%left   EQ

%right  MENOS_UNARIO

%type <integer_value> CTE_ENT
%type <float_value> CTE_REAL
%type <string_value> CTE_STRING
%type <string_value> ID
%type <string_value> INT
%type <string_value> STRING
%type <string_value> FLOAT
%type <ast> programa
%type <ast> program
%type <ast> cuerpo_programa
%type <ast> sentencia
%type <ast> lista_de_tipos
%type <ast> tipos_primitivos
%type <ast> asignacion_s
%type <ast> asignacion_m
%type <ast> lista_var
%type <ast> lista_exp
%type <ast> tipo_exp
%type <ast> decision
%type <ast> condiciones
%type <ast> condicion
%type <ast> iteracion
%type <ast> printear
%type <ast> obtain
%type <ast> cteNombre
%type <ast> constExp
%type <ast> expresion
%type <ast> termino
%type <ast> factor
%type <ast> all_equals
%type <ast> condition_case
%type <ast> case_solo
%type <ast> lista_cases
%type <auxLogicOperator> operador_logico

%union {
  int integer_value;
  float float_value;
  char string_value[33];
  struct treeNode* ast;
  char* auxLogicOperator;
}

%start  programa

%%
programa: program   {$$ = $1; tree = $$; printf("\nRegla 00 : Compilacion Ok\n");}
;
program: definiciones_variables cuerpo_programa   {$$ = $2; printf("\nRegla 1 : Definicion Variables + program\n");}
    |   definiciones_variables                  {printf("\nRegla 2 : Definicion Variables\n");}
;
cuerpo_programa: cuerpo_programa sentencia {flagDeclaration = 1; $$ = newNode("Cuerpo_Programa",$1,$2); printf("\nRegla 3 : Program Sentencia\n");}
    |   sentencia {$$ = $1; printf("\nRegla 4 : Sentencia\n");}
;
sentencia: asignacion_s     {$$ = $1; printf("\nRegla 5 : Asignacion Simple\n");}
    |   asignacion_m        {$$ = $1; printf("\nRegla 6 : Asignacion Multiple\n");}
    |   decision            {$$ = $1; printf("\nRegla 7 : Decision\n");}
    |   condition_case      {printf("\nRegla 67 : Condicion DO Case\n");}
    |   iteracion           {$$ = $1; printf("\nRegla 8 : Iteracion\n");}
    |   printear            {$$ = $1; printf("\nRegla 9 : Print\n");}
    |   obtain              {$$ = $1; printf("\nRegla 10 : READ\n");}
    |   cteNombre           {$$ = NULL; printf("\nRegla 11 : Constante Nombre\n");}
;
asignacion_s: ID OP_ASIG expresion  {validateAsignation($1,$3); $$ = newNode(":=",newLeaf($1),$3); printf("\nRegla 12 : Asig Simple ID := EXPRESION\n");}
    |   ID OP_ASIG CTE_STRING       {validateAsignationString($1); $$ = newNode(":=",newLeaf($1),newLeaf(getSymbolName($3,3))); printf("\nRegla 13 : Asig Simple ID := STRING\n");}
;
asignacion_m: C_A {flagAsigM = 1;} lista_var C_C OP_ASIG C_A lista_exp C_C  {flagAsigM =0; $$ = incrustarArbol(); clearAsigMList(); printf("\nRegla 14 : Asignacion Multiple Lista\n");}
;
lista_var: lista_var COMA ID    {if(flagDeclaration == 0){validateIdDeclaration($3); insertIdentifier($3);} if(flagAsigM == 1){insertAsigM($3,1,0,0,0);} printf("\nRegla 15 : Lista, ID\n");}
    |   ID                      {if(flagDeclaration == 0){validateIdDeclaration($1); insertIdentifier($1);} if(flagAsigM == 1){insertAsigM($1,1,0,0,0);} printf("\nRegla 16 : Lista ID\n");}
;
lista_exp: lista_exp COMA tipo_exp   {printf("\nRegla 17 : Lista_EXP, Expresion\n");}
    |   tipo_exp {printf("\nRegla 18 : tipo_exp\n");}
;
tipo_exp: expresion {printf("\nRegla 19 : Expresion\n");}
    |   CTE_STRING {insertAsigM($1,2,0,0,1); printf("\nRegla 20 : String\n");}
;
decision: IF P_A condiciones P_C L_A cuerpo_programa L_C ELSE L_A cuerpo_programa L_C   {$$ = newNode("IF", $3, newNode("CUERPO_IF",$6,$10)); printf("\nRegla 21 : Decision con Else\n");}
    |   IF P_A condiciones P_C L_A cuerpo_programa L_C {$$ = newNode("IF", $3, $6); printf("\nRegla 22 : Decision\n");}
;
condiciones: condicion AND condicion {$$ = newNode("AND", $1, $3); printf("\nRegla 23 : cond AND cond\n");}
    |   condicion OR condicion  {$$ = newNode("OR", $1, $3); printf("\nRegla 24 : cond OR cond\n");}
    |   NOT P_A condicion P_C {$$ = newNode("NOT", $3, NULL); printf("\nRegla 25 : NOT cond\n");}
    |   condicion {$$ = $1; printf("\nRegla 26 : Condicion\n");}
    |   all_equals {$$ = $1; printf("\nRegla 63: AllEquals condicion\n");}
;
condicion: ID operador_logico factor    {validateCondition($1,$3,1); $$ = newNode($2,newLeaf($1),$3); printf("\nRegla 27 : ID Operador Logico Comparado\n");}
;
operador_logico: OP_MAX {$$ = ">"; printf("\nRegla 28 : >\n");}
    |   OP_MIN  {$$ = "<"; printf("\nRegla 29 : <\n");}
    |   OP_MINEQ {$$ = "<="; printf("\nRegla 30 : <=\n");}
    |   OP_MAXEQ {$$ = ">="; printf("\nRegla 31 : >=\n");}
    |   OP_EQ {$$ = "=="; printf("\nRegla 32 : ==\n");}
    |   OP_NEQ {$$ = "!="; printf("\nRegla 33 : !=\n");}
;
iteracion: REPEAT cuerpo_programa UNTIL condiciones     {$$ = newNode("REPEAT",newNode("UNTIL",$4,NULL),$2);printf("\nRegla 34 : Repeat\n");}
;
printear: PRINT CTE_STRING      {$$ = newNode("PRINT",newLeaf(getSymbolName($2,3)),NULL);printf("\nRegla 36 : Print String\n");}
    |   PRINT ID                {$$ = newNode("PRINT",newLeaf($2),NULL); printf("\nRegla 37 : Print ID\n");}
;
obtain: READ ID {$$ = newNode("READ",newLeaf($2),NULL); printf("\nRegla 38 : Read Variable\n");}
;
cteNombre: CONST constExp {printf("\nRegla 38' CONST constExp\n");}
;
constExp: ID OP_ASIG CTE_ENT     {validateIdDeclaration($1); putConstOnSymbolTable($1, "", $3, 0, "CONST_ENT", 1); printf("\nRegla 39 : Cte Con Nombre Entero\n");}
    |   ID OP_ASIG  CTE_STRING    {validateIdDeclaration($1); putConstOnSymbolTable($1, $3, 0, 0, "CONST_STRING", 2); printf("\nRegla 40 : Cte Con Nombre String\n");}
    |   ID OP_ASIG  CTE_REAL    {validateIdDeclaration($1); putConstOnSymbolTable($1, "", 0, $3, "CONST_FLOAT", 3); printf("\nRegla 41 : Cte Con Nombre Float\n");}
;
expresion: expresion OP_SUMA termino    {$$ = newNode("+",$1,$3); printf("\nRegla 42 : E + T\n");}
    |   expresion OP_RESTA termino      {$$ = newNode("-",$1,$3); printf("\nRegla 43 : E - T\n");}
    |   termino {$$ = $1;}
;
termino: termino OP_MULT factor     {$$ = newNode("*",$1,$3); printf("\nRegla 44 : T * F\n");}
    |   termino OP_DIV factor       {$$ = newNode("/",$1,$3); printf("\nRegla 45 : T / F\n");}
    |   factor {$$ = $1;}
;
factor: ID                  {$$ = newLeaf($1); if(flagAsigM == 1){insertAsigM($1,2,0,0,1);} printf("\nRegla 46 : ID\n");}
    |   CTE_ENT             {$$ = newLeaf(getSymbolName(&($1),1)); if(flagAsigM == 1){insertAsigM("",2,0,$1,2);} printf("\nRegla 47 : Entero\n");}
    |   CTE_REAL            {$$ = newLeaf(getSymbolName(&($1),2)); if(flagAsigM == 1){insertAsigM("",2,$1,0,3);} printf("\nRegla 48 : Real\n");}
    |   P_A expresion P_C   {$$ = $2; printf("\nRegla 49 : (E)\n");}
;
definiciones_variables: VAR definicion_variables ENDVAR {printf("\nRegla 50 : VAR def_Var ENDVAR\n");}
;
definicion_variables: definicion_variables def {printf("\nRegla 51 : Def Variable Multiple Linea\n");}
    |   def {printf("\nRegla 52 : Def Variable Simple Linea\n");}
;
def: C_A lista_de_tipos C_C DPTO C_A lista_var C_C {putTypeIdentifierOnSymbolTable(); printf("\nRegla 53 : Lista Tipos - Lista Vars\n");}
;
lista_de_tipos: lista_de_tipos COMA tipos_primitivos {printf("\nRegla 54 : Lista_Tipos, Tipo_Primitivo\n");}
    | tipos_primitivos {printf("\nRegla 55 : Tipo_Primitivo\n");}
;
tipos_primitivos:   STRING {insertTypeIdentifier($1); printf("\nRegla 56 : Tipo_Primitivo String\n");}
    |   FLOAT {insertTypeIdentifier($1); printf("\nRegla 57 : Tipo_Primitivo Float\n");}
    |   INT {insertTypeIdentifier($1); printf("\nRegla 58 : Tipo_Primitivo Int\n");}
;
all_equals: ALL_EQUALS P_A listas_exp P_C {$$ = crearNodosCondicionAllEqual(); printf("\nRegla 59: AllEquals\n");}
;
listas_exp: lista COMA listas_exp {printf("\nRegla 60: Listas de Expresiones\n");}
    | lista COMA lista {printf("\nRegla 61: Dos listas de expresiones\n");}
;
lista: C_A items C_C {cerrarListaAllEqual(); printf("\nRegla 62: Lista de expresiones\n");}
;
items: items COMA expresion {insertarNodoEnListaAllEqual($3); printf("\nRegla 63: Mas de un Item en la lista de expresiones\n");}
;
items: expresion {insertarNodoEnListaAllEqual($1); printf("\nRegla 64: Un item en la lista de expresiones\n");}
;
condition_case: DO expresion lista_cases ENDDO{printf("\nRegla 65: DO CASE\n");}
;
lista_cases: case_solo {$$ = 1; printf("\nRegla 66: CASE\n");}
    | lista_cases case_solo {$$ = $1; printf("\nRegla 67: VARIOS CASE\n");}
    // no anda
    | case_solo case_default {printf("\nRegla 70: CASE solo con DEFAULT\n");}
    | lista_cases case_solo case_default {printf("\nRegla 71: Varios CASE con DEFAULT\n");}
;
case_solo: CASE condicion cuerpo_programa {$$ = newNode("IF", $2, $3); printf("\nRegla 68: CASE solo\n");}
;
case_default: DEFAULT cuerpo_programa {printf("\nRegla 69: DEFAULT CASE");}
;
%%

int main(int argc,char *argv[]){
    if ((yyin = fopen(argv[1], "rt")) == NULL) {
	    printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    } else {
        symbolTable = NULL;
            do {
                yyparse();
            } while(!feof(yyin));
        saveTable();
        ast treeCopy = *tree;
        printAndSaveAST(tree);
        printf("\n");
        printf("\n");
        generateAssembler(tree);
        printf("\n");
        printf("\n");
    }
    fclose(yyin);
    return 0;
}

int yyerror(void) {
    printf("\n[E] Syntax Error - line %d\n\n", yylineno);
	system ("Pause");
	exit (1);
}

void validateIdDeclaration(char* id) {
    int i = 0;
    for(i = 0; i < seenIndex; i++) {
        if(strcmp(seen[i], id) == 0) {
            fprintf(stderr, "\n[E] Identifier invalid: '%s' it has been already declared in the line: %d\n",id, yylineno);
            exit(1);
        }
    }
    seen[seenIndex] = strdup(id);
    seenIndex++;
}

void validateAsignation(char* id, ast* exp) {
    symbolNode* symbol = findSymbol(id);
    symbolNode* treeValue;
    if (strcmp(exp->value,"-") != 0) {
        treeValue = findSymbol(exp->value);
    } else {
        treeValue = findSymbol("+");
    }
    if (symbol != NULL && treeValue != NULL) {
        if((strcmp(symbol->type, "INT") == 0 || strcmp(symbol->type, "FLOAT") == 0) && (strcmp(treeValue->type, "STRING") == 0 || strcmp(treeValue->type, "CONST_STRING") == 0 )) {
            fprintf(stderr, "\n[E] Incompatible assignment, line: %d\n", yylineno);
            exit(1);
        }
        if((strcmp(symbol->type, "STRING") == 0) && (strcmp(treeValue->type, "INTEGER_CTE") == 0 || strcmp(treeValue->type, "CTE_REAL") == 0  || strcmp(treeValue->type, "CTE_ENT") == 0 || strcmp(treeValue->type, "FLOAT_CTE") == 0 || strcmp(treeValue->type, "INT") == 0 || strcmp(treeValue->type, "FLOAT") == 0 )) {
            fprintf(stderr, "\n[E] Incompatible assignment, line: %d\n", yylineno);
            exit(1);
        }
        if((strcmp(symbol->type, "INT") == 0 && (strcmp(treeValue->type, "FLOAT") == 0 || strcmp(treeValue->type, "FLOAT_CTE") == 0 || strcmp(treeValue->type, "CTE_REAL") == 0))
        || strcmp(symbol->type, "FLOAT") == 0 && (strcmp(treeValue->type, "INT") == 0 || strcmp(treeValue->type, "INTEGER_CTE") == 0 || strcmp(treeValue->type, "CTE_ENT") == 0)) {
            fprintf(stderr, "\n[E] Incompatible assignment, line: %d\n", yylineno);
            exit(1);
        }
    }
}

void validateAsignationString(char* id){
    symbolNode* symbol = findSymbol(id);
    if (strcmp(symbol->type, "STRING") != 0){
        fprintf(stderr, "\n[E] Incompatible string assignment, line: %d\n", yylineno);
        exit(1);
    }
}

void validateCondition(char* left, ast* right, int fail) {
    if(right->value != NULL) {
        symbolNode* symbolLeft = findSymbol(left);
        symbolNode* symbolRight = findSymbol(right->value);
        if(symbolRight != NULL && symbolLeft != NULL) {
            if(fail == 1 && (
                strcmp(symbolLeft->type, changeType(symbolRight->type)) != 0 ||
                strcmp(symbolLeft->type, "STRING") == 0 ||
                strcmp(changeType(symbolRight->type), "STRING") == 0)) {
                fprintf(stderr, "\n[E] Different types in condition, line: %d\n", yylineno);
                exit(1);
            }
        }
    }
}

char* changeType(char* t) {
    char* value;
    if(strcmp(t,"STRING") == 0 || strcmp(t,"INT") == 0 || strcmp(t,"FLOAT") == 0) {
        value = t;
    }else{
        if(strcmp(t,"CTE_STRING") == 0 || strcmp(t,"STRING_CTE") == 0){
            value = "STRING";
        }else if(strcmp(t,"CTE_ENT") == 0 || strcmp(t,"INTEGER_CTE") == 0){
            value = "INT";
        }else if(strcmp(t,"CTE_REAL") == 0 || strcmp(t,"FLOAT_CTE") == 0){
            value = "FLOAT";
        }
    }
    return value;
}
