/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * This header file includes the necessary declarations for the various
 * arithmetic and logical subexpression classes used in the expression
 * evaluation framework. It includes:
 * 
 * - SubExpression: A base class for expressions with a left operand and
 *   one or more right operands.
 * - Plus, Minus, Multiply, Divide, Mod: Classes for basic arithmetic
 *   operations.
 * - Min, Max: Classes for minimum and maximum operations.
 * - Exponent: Class for exponentiation evaluation.
 * - Avg: Class for calculating the average.
 * - Invert: Class for negation or inversion.
 * - Ternary: Class for ternary conditional expressions.
 * - Quaternary: Class for quaternary conditional expressions.
 * 
 * These classes work together to facilitate parsing and evaluating complex
 * expressions.
 */

#pragma once

#include "subexpression.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "mod.h"
#include "min.h"
#include "max.h"
#include "exponent.h"
#include "avg.h"
#include "invert.h"
#include "ternary.h"
#include "quaternary.h"
