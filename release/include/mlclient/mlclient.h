//
// Copyright (c) MarkLogic Corporation. All rights reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once

#ifndef MLCLIENT_H
#define MLCLIENT_H

#ifdef _WIN32

#ifdef MLCLIENT_EXPORTS
#define MLCLIENT_API __declspec(dllexport)
#else
#define MLCLIENT_API __declspec(dllimport)
#endif

#else

#define MLCLIENT_API

#endif

#endif
