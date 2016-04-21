/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#ifndef INCREMENT_EXPR_H
#define INCREMENT_EXPR_H

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"

#include "Expr.h"

class IncrementExpr : public Expr
{
  protected:
    int _increment;
  public:
    IncrementExpr(int increment) : _increment(increment) { }
    void CodeGen(llvm::Module *M, llvm::IRBuilder<> &B);
    void DebugDescription(int level);
    ~IncrementExpr() {};
};

#endif