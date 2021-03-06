/*
 * Copyright 2017 The Cartographer Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CARTOGRAPHER_GRPC_FRAMEWORK_RPC_HANDLER_H
#define CARTOGRAPHER_GRPC_FRAMEWORK_RPC_HANDLER_H

#include "google/protobuf/message.h"

namespace cartographer_grpc {
namespace framework {

class Rpc;
class RpcHandlerInterface {
 public:
  void SetRpc(Rpc* rpc);
};

using RpcHandlerFactory =
    std::function<std::unique_ptr<RpcHandlerInterface>(Rpc*)>;

struct RpcHandlerInfo {
  const google::protobuf::Descriptor* request_descriptor;
  const google::protobuf::Descriptor* response_descriptor;
  const RpcHandlerFactory rpc_handler_factory;
};

}  // namespace framework
}  // namespace cartographer_grpc

#endif  // CARTOGRAPHER_GRPC_FRAMEWORK_RPC_HANDLER_H
