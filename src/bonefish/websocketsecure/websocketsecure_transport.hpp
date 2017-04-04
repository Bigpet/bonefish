/**
 *  Copyright (C) 2015 Topology LP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef BONEFISH_WEBSOCKETSECURE_TRANSPORT_HPP
#define BONEFISH_WEBSOCKETSECURE_TRANSPORT_HPP

#include <bonefish/transport/wamp_transport.hpp>
#include <bonefish/websocketsecure/websocketsecure_config.hpp>

#include <memory>
#include <websocketpp/common/connection_hdl.hpp>
#include <websocketpp/server.hpp>

namespace bonefish {

class wamp_message;
class wamp_serializer;

class websocketsecure_transport : public wamp_transport
{
public:
    websocketsecure_transport(const std::shared_ptr<wamp_serializer>& serializer,
            const websocketpp::connection_hdl& handle,
            const std::shared_ptr<websocketpp::server<websocketsecure_config>>& server);

    virtual bool send_message(wamp_message&& message) override;

private:
    std::shared_ptr<wamp_serializer> m_serializer;
    websocketpp::connection_hdl m_handle;
    std::shared_ptr<websocketpp::server<websocketsecure_config>> m_server;
};

} // namespace bonefish

#endif // BONEFISH_WEBSOCKETSECURE_TRANSPORT_HPP
