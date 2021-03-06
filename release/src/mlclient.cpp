/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * \file MLCPlusPlus.cpp
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \date 2014-06-04
 */

#include <mlclient/mlclient.hpp>

#include <mlclient/logging.hpp>

namespace mlclient {



int runOnce() {

  //mlclient::LogHolder::reset();

  libraryLoggingInit();

  return 0;
}

int runOnceHelper = runOnce();


} // end namespace mlclient
