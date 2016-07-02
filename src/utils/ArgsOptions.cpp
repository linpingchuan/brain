/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Luiz Peres, 2016.
 */

#include "ArgsOptions.h"

ArgsOptions *ArgsOptions::_instance = nullptr;

ArgsOptions* ArgsOptions::instance()
{
  if (!ArgsOptions::_instance)
      ArgsOptions::_instance = new ArgsOptions();
  return _instance;
}

void ArgsOptions::addOption(BrainOption option)
{
  _options |= option;
}

bool ArgsOptions::hasOption(BrainOption option)
{
  return (_options & option) == option;
}

