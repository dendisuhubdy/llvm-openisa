//=== SBTUtils.h - General utilities --------------------*- C++ -*-==//
//
// Convenience functions to convert register numbers when reading
// an OpenISA binary and converting it to IR.
//
//===------------------------------------------------------------===//
#ifndef SBTUTILS_H
#define SBTUTILS_H
#include "llvm/ADT/StringMap.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/IR/Value.h"
#include <system_error>
#include <vector>
#include <utility>

namespace llvm {

namespace object {
class ObjectFile;
}

using namespace object;

unsigned conv32(unsigned regnum);
unsigned ConvFromDirective(unsigned regnum);
unsigned ConvToDirective(unsigned regnum);
unsigned ConvToDirectiveDbl(unsigned regnum);
bool error(std::error_code ec);
uint64_t GetELFOffset(const SectionRef &i);
std::vector<std::pair<uint64_t, StringRef>>
GetSymbolsList(const ObjectFile *Obj, const SectionRef &i);
llvm::StringMap<uint64_t>
GetCommonSymbolsList(const ObjectFile *Obj, uint64_t &TotalSize);
Value *GetFirstInstruction(Value *o0, Value *o1);
Value *GetFirstInstruction(Value *o0, Value *o1, Value *o2);
Value *GetFirstInstruction(Value *o0, Value *o1, Value *o2, Value *o3);
Value *GetFirstInstruction(Value *o0, Value *o1, Value *o2, Value *o3,
                           Value *o4);
uint32_t GetInstructionSize();
}
#endif
