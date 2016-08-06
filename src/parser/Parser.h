/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#ifndef PARSER_H
#define PARSER_H

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <string>
#include <vector>

#include "../ast/expr/Expr.h"
#include "../utils/ArgsOptions.h"

/**
 * @brief The parser of the Brain language, it interpretes *.b, *.br or
 * *.brain files.
 */
class Parser
{
protected:
    /// The content of the source file passed to Brain.
    std::string _data;
    /// Variable that holds the current index read by the parser.
    int _index;
    /// Vector used to store expressions read from the file by the parser.
    std::vector<Expr *> _exprs;

    /**
     * @brief Returns whether of not a character is skippable by the parser, if
     * it is, it returns true, false otherwise.
     * @param c The character to be tested against.
     */
    static bool is_skippable(char c);
    /**
     * @brief Returns the token of the _data at _index.
     */
    char get_token();
    /**
     * @brief It parses the Brain code.
     * @param exprs The vector of expressions read by the constructor
     * @param level
     */
    void parse(std::vector<Expr *> &exprs, int level);
public:
    /**
     * @brief Calls parse to <i>create</i> all expressions found in the source
     * code.
     * @param source The source file as a string of characters.
     * interpreter
     */
    explicit Parser(std::string source) :
        _data(source), _index(0) { parse(_exprs, 0); }
    /**
     * @brief Generate IR code based on the Brain file passed to the parser.
     * @param M
     * @param B
     */
    void code_gen(llvm::Module *M, llvm::IRBuilder<> &B);
    /**
     * @brief
     * @param level
     */
    void debug_description(int level);

};

#endif  // PARSER_H
