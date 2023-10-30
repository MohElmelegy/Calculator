#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "STD_Types.h"
#include "BIT_MATH.h"

/****************************************Global varibles*****************************************************/

#define MAX_EXPR_SIZE 100
s8 infix[MAX_EXPR_SIZE];


struct Stack
{
    s32 top;
    unsigned capacity;
    s32 *array;
};



/****************************************API protoype*****************************************************/

struct Stack *createStack(unsigned capacity);
/**
 * @brief  isEmpty function used to check weather or not the stack is empty
 * @param  pointer to the stack which allocated
 * @return Stack Status
 *          1         : The stack is empty
 *          0         : The stack is not empty
 */

s32 isEmpty(struct Stack *stack);

/**
 * @brief  peek function used to get the stack top
 * @param  pointer to the stack which allocated
 * @return Stack Peek

 */
s32 peek(struct Stack *stack);

/**
 * @brief  pop function used to get the element which the top index points to
 * @param  pointer to the stack which allocated
 * @return last in elemet

 */
s32 pop(struct Stack *stack);

/**
 * @brief  push function used to put the element into stack
 * @param  pointer to the stack which allocated
 * @return void

 */
void push(struct Stack *stack, s32 op);

/**
 * @brief  infixToPostfix function used to convert from infix to postfix
 * @param  pointer to the array which hold the infix expression
 * @return postfix expression

 */

s8 *infixToPostfix(s8 *infix);

/**
 * @brief  evaluatePostfix function used to get the value of the enterd expression by converting it into postfix and get its value
 * @param  the infix expression
 * @return the expression value

 */

s32 evaluatePostfix(s8 *exp);

/**
 * @brief  precedence function used to check which operator has higher priority
 * @param  the operator
 * @return the return precedence of operators
 */

s8 precedence(s8 operator);

/**
 * @brief  isOperator function used to check if the scanned character is an operator
 * @param  character
 * @return
		  1 : if operator
		  0 : if not operator
 */

s8 isOperator(s8 ch);

void Init_Project(void);

#endif