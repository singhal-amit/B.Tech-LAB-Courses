# CIC-351 | Compiler Design LAB

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Available Programs](#available-programs)
- [License](#license)

## Introduction

This repository is dedicated to the CIC-351 [Compiler Design LAB](./Resources/List%20of%20Experiments.pdf) course instructed by Ms. Sakshi Jha. The course focuses on various phases of compiler design, including lexical analysis, syntax analysis, semantic analysis, and code generation.

## Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/amit712singhal/CD_LAB.git
   ```

2. Navigate to the project directory:

   ```sh
   cd CD_LAB
   ```

## Usage

To compile and run any of the programs, use the following commands:

### For Lex Programs:

1. Compile using `flex`:

   ```sh
   flex prg_01_basicFlexBison.l
   ```

2. Compile the generated C file:

   ```sh
   gcc lex.yy.c -o a
   ```

3. Run the program:

   ```sh
   ./a
   ```

### For Yacc Programs:

1. Compile using `bison` and `flex`:

   ```sh
   bison -d prg_03_grammarValidator.y
   flex prg_03_grammarValidator.l
   gcc lex.yy.c y.tab.c -o a
   ```

2. Run the program:

   ```sh
   ./a
   ```

### For C++ Programs:

1. Compile the program (e.g., Left Recursion Eliminator):

   ```sh
   g++ prg_09_stackOperations.cpp -o a
   ```

2. Run the compiled program:

   ```sh
   ./a
   ```

## Available Programs

1. **Lex Programs:**
   - `prg_01_basicFlexBison.l` - Basic Lex and Bison Setup
   - `prg_02.1_keywordChecker.l` - Keyword Checker using Lex
   - `prg_02.2_countTokens.l` - Token Counter using Lex

2. **Yacc Programs:**
   - `prg_03_grammarValidator.l` & `prg_03_grammarValidator.y` - Grammar Validator using Lex and Yacc
   - `prg_06_yaccExprParser.l` & `prg_06_yaccExprParser.y` - Expression Parser using Yacc
   - `prg_07_lexYaccCalculator.l` & `prg_07_lexYaccCalculator.y` - Lex and Yacc Calculator

3. **Syntax Analysis:**
   - `prg_04_leftRecursionEliminator.cpp` - Eliminates Left Recursion
   - `prg_05_leftFactoringRemover.cpp` - Removes Left Factoring
   - `prg_08_recursiveDescentParser.cpp` - Recursive Descent Parser
   - `prg_09_stackOperations.cpp` - Stack Operations for Parsing
   - `prg_11_shiftReduceParser.cpp` - Shift-Reduce Parser

4. **Semantic Analysis and Code Generation:**
   - `prg_10_leadingSetFinder.cpp` - Finds Leading Sets
   - `prg_12_firstSetCalculator.cpp` - Calculates First Sets
   - `prg_13_operatorPrecedenceChecker.cpp` - Checks Operator Precedence
   - `prg_14_intermediateCodeGen.cpp` - Intermediate Code Generation

5. **Automata and DFA:**
   - `prg_15_dfaMinimizer.cpp` - DFA Minimizer
   - `prg_16_nfaToDfaConverter.cpp` - NFA to DFA Converter

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
